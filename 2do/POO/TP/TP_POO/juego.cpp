#include "juego.h"   // Incluye la declaración de la clase Juego
#include <iostream>  // Para std::cout, std::cerr, std::cin
#include <limits>    // Para std::numeric_limits
#include <typeinfo>  // Para typeid, útil para depuración o lógica específica de tipo de casilla

// Constructor de la clase Juego
// Inicializa los atributos principales del juego.
Juego::Juego() : jugadores(nullptr), cantidadJugadores(0), tablero(nullptr), turnoActual(0), terminado(false) {
    // Dado se inicializa automáticamente por su constructor por defecto
}

// Destructor de la clase Juego
// Libera la memoria asignada dinámicamente para los jugadores y el tablero.
Juego::~Juego() {
    if (jugadores) {
        for (int i = 0; i < cantidadJugadores; ++i) {
            delete jugadores[i]; // Libera cada objeto Jugador individual
        }
        delete[] jugadores; // Libera el arreglo de punteros a Jugador
    }
    delete tablero; // Libera el objeto Tablero (composición)
}

// Implementación del método iniciar()
// Pide la cantidad y los nombres de los jugadores al usuario.
// Inicializa el arreglo dinámico de jugadores y el tablero.
void Juego::iniciar() {
    std::cout << "--- ¡Bienvenido al Juego de la Oca! ---" << std::endl;

    // Solicitar cantidad de jugadores
    do {
        std::cout << "¿Cuántos jugadores van a participar? (2-4): ";
        std::cin >> cantidadJugadores;
        if (std::cin.fail() || cantidadJugadores < 2 || cantidadJugadores > 4) {
            std::cout << "Número de jugadores inválido. Por favor, ingresa un número entre 2 y 4." << std::endl;
            std::cin.clear(); // Limpiar el flag de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar el resto de la línea
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer después de la entrada válida
            break;
        }
    } while (true);

    // Inicializar jugadores
    jugadores = new Jugador*[cantidadJugadores];
    for (int i = 0; i < cantidadJugadores; ++i) {
        std::string nombreJugador;
        std::cout << "Ingrese el nombre del Jugador " << i + 1 << ": ";
        std::getline(std::cin, nombreJugador);
        jugadores[i] = new Jugador(nombreJugador);
    }

    // Inicializar tablero (63 casillas, de 0 a 62)
    tablero = new Tablero(63); // La Oca tiene 63 casillas
    tablero->inicializar();

    std::cout << "\n¡El juego ha comenzado con " << cantidadJugadores << " jugadores!" << std::endl;
    mostrarEstado();
}

// Implementación del método jugarTurno()
// Gestiona un turno completo para el jugador actual.
void Juego::jugarTurno() {
    if (terminado) {
        return; // No se juega si el juego ya terminó
    }

    Jugador* jugadorActual = jugadores[turnoActual];
    std::cout << "\n--- Turno de " << jugadorActual->getNombre() << " (Posición actual: " << jugadorActual->getPosicion() + 1 << ") ---" << std::endl;

    // Verificar si el jugador está castigado
    if (jugadorActual->estaCastigado()) {
        std::cout << jugadorActual->getNombre() << " está castigado y pierde el turno. Turnos restantes de castigo: " << jugadorActual->getTurnosPerdidos() << std::endl;
        jugadorActual->setTurnosPerdidos(jugadorActual->getTurnosPerdidos() - 1); // Decrementar turno de castigo
        avanzarTurno(); // Pasar al siguiente jugador
        return;
    }

    // Tirar el dado
    int tirada = dado.tirar();
    std::cout << jugadorActual->getNombre() << " tiró el dado y obtuvo un " << tirada << "." << std::endl;

    // Calcular nueva posición
    int nuevaPosicion = jugadorActual->getPosicion() + tirada;

    // Lógica para no pasarse de la meta (casilla 63)
    if (nuevaPosicion >= CASILLA_META) {
        nuevaPosicion = CASILLA_META; // El jugador llega a la casilla 63
        jugadorActual->setPosicion(nuevaPosicion);
        std::cout << jugadorActual->getNombre() << " llega a la meta en la casilla 63." << std::endl;
        // No hay necesidad de activar la casilla 63 si ya es la meta y significa victoria
    } else {
        jugadorActual->mover(tirada); // Mover al jugador
    }

    // Obtener la casilla a la que llegó el jugador y aplicar su efecto
    Casilla* casillaLlegada = tablero->getCasilla(jugadorActual->getPosicion());
    if (casillaLlegada) {
        jugadorActual->aplicarEfectoCasilla(casillaLlegada);

        // --- IMPORTANTE: Lógica para "volver a tirar" en CasillaOca ---
        // Esto es un punto de coordinación con tu compañero.
        // Si CasillaOca::activar() no retorna un valor para indicar un turno extra,
        // o si no modifica un flag en el jugador, deberás acordar cómo Juego lo detectará.
        // Una opción sería que Jugador tenga un método como 'tieneTurnoExtra()'
        // que CasillaOca pueda modificar. O que 'activar' en Casilla devuelva un bool.
        // Por ahora, asumimos que el turno extra de la Oca se gestiona internamente
        // o que tu compañero lo implementará de forma que Juego no necesite saber el tipo exacto de casilla aquí
        // para decidir si avanza el turno. Si necesita un turno extra, *NO* llames a avanzarTurno().
        //
        // Ejemplo (requiere cambio en Casilla.h y CasillaOca.h para que activar retorne bool):
        // if (casillaLlegada->activar(jugadorActual)) { // Si activar() retorna true para turno extra
        //     std::cout << jugadorActual->getNombre() << " tiene un turno extra por la Casilla Oca." << std::endl;
        // } else {
        //     avanzarTurno(); // Pasar al siguiente jugador
        // }
    }


    // Verificar ganador después de aplicar el efecto (si el efecto de la casilla no es la meta)
    // Se verifica aquí porque un efecto podría mover al jugador a la casilla final.
    verificarGanador();

    // Si el juego no ha terminado y no hubo una lógica de "turno extra" que lo impida,
    // avanzar al siguiente jugador. Si se implementa el turno extra, esta llamada debe ser condicional.
    if (!terminado) {
        // Si hay una lógica para "turno extra" (ej. en CasillaOca),
        // este 'avanzarTurno()' solo debería ejecutarse si NO hay un turno extra.
        // Por simplicidad, y sin la interfaz acordada, se avanza siempre.
        avanzarTurno();
    }
}

// Implementación del método verificarGanador()
// Determina si algún jugador ha alcanzado exactamente la casilla 63 (índice 62).
void Juego::verificarGanador() {
    for (int i = 0; i < cantidadJugadores; ++i) {
        if (jugadores[i]->getPosicion() == CASILLA_META) {
            std::cout << "\n¡FELICITACIONES! " << jugadores[i]->getNombre() << " ha llegado a la casilla 63 y ha GANADO el juego!" << std::endl;
            terminado = true;
            return; // Un ganador, terminamos la verificación
        }
    }
}

// Implementación del método mostrarEstado()
// Imprime un resumen del estado actual del juego.
void Juego::mostrarEstado() const {
    std::cout << "\n--- Estado Actual del Juego ---" << std::endl;
    tablero->mostrar(); // Muestra el estado del tablero
    std::cout << "\nPosiciones de los Jugadores:" << std::endl;
    for (int i = 0; i < cantidadJugadores; ++i) {
        std::cout << "- " << jugadores[i]->getNombre() << ": Casilla " << jugadores[i]->getPosicion() + 1;
        if (jugadores[i]->estaCastigado()) {
            std::cout << " (Castigado, pierde " << jugadores[i]->getTurnosPerdidos() << " turno(s))";
        }
        std::cout << std::endl;
    }
    std::cout << "Turno actual: " << jugadores[turnoActual]->getNombre() << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

// Implementación del método estaTerminado()
// Retorna true si el juego ha terminado.
bool Juego::estaTerminado() const {
    return terminado;
}

// Método auxiliar para avanzar al siguiente turno.
void Juego::avanzarTurno() {
    turnoActual = (turnoActual + 1) % cantidadJugadores;
}
