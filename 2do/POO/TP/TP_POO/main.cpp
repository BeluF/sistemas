#include <iostream>  // Para entrada/salida (cout, cin)
#include <string>    // Para std::string
#include <vector>    // No se usa directamente aquí, pero es útil en C++
#include <random>    // Para generación de números aleatorios (Dado)
#include <limits>    // Para std::numeric_limits (manejo de entrada de usuario)

// --- ENUM EstadoJugador ---
// Define los posibles estados lógicos que puede tener un jugador.
enum EstadoJugador {
    Normal,
    Puente,    // Podría usarse para alguna lógica visual o de juego específica
    Castigado  // Se utiliza para Cárcel, Pozo y Posada
};

// --- CLASE Casilla (Abstracta) ---
// Define la interfaz que implementarán (por herencia) todas las casillas.
// Es abstracta, por lo que obliga a sus hijas a definir el método activar().
class Casilla {
protected:
    int numero; // Representa la posición de la casilla en el tablero (0-indexado)

public:
    // Constructor
    Casilla(int num) : numero(num) {}

    // Destructor virtual para asegurar la correcta liberación de memoria en polimorfismo
    virtual ~Casilla() {}

    // Retorna el número de la casilla (convertido a 1-indexado para mostrar)
    int getNumero() const {
        return numero;
    }

    // Método virtual puro que debe ser redefinido por cada subclase.
    // Simula el efecto de caer en esta casilla para un jugador dado.
    virtual void activar(class Jugador* jugador) = 0; // 'class Jugador*' para forward declaration
};

// --- CLASE Jugador ---
// Representa al jugador individual con su respectivo nombre, posición y penalizaciones.
class Jugador {
private:
    std::string nombre;
    int posicion;       // Índice de la casilla actual (0 a 62)
    int turnosPerdidos; // Cantidad de turnos que el jugador debe omitir
    EstadoJugador estadoEspecial; // Estado actual del jugador

public:
    // Constructor
    Jugador(const std::string& nombreJugador)
        : nombre(nombreJugador), posicion(0), turnosPerdidos(0), estadoEspecial(Normal) {}

    // Getters
    std::string getNombre() const { return nombre; }
    int getPosicion() const { return posicion; }
    int getTurnosPerdidos() const { return turnosPerdidos; }
    EstadoJugador getEstadoEspecial() const { return estadoEspecial; }

    // Setters
    void setPosicion(int nuevaPosicion) { posicion = nuevaPosicion; }
    void setTurnosPerdidos(int cantidad) { turnosPerdidos = cantidad; }
    void setEstadoEspecial(EstadoJugador estado) { estadoEspecial = estado; }

    // Métodos
    // Mueve al jugador una cantidad determinada de casillas
    void mover(int cantidad) {
        posicion += cantidad;
        std::cout << nombre << " avanza " << cantidad << " casillas. Nueva posición: " << posicion + 1 << "." << std::endl;
    }

    // Invoca al método activar de la casilla en la que se encuentra el jugador
    void aplicarEfectoCasilla(Casilla* casilla) {
        if (casilla) {
            casilla->activar(this); // 'this' es un puntero al objeto Jugador actual
        }
    }

    // Informa si el jugador debe omitir el turno
    bool estaCastigado() const {
        return turnosPerdidos > 0;
    }

    // Limpia castigos y estados especiales devolviendo al jugador a estado normal
    void resetEstado() {
        turnosPerdidos = 0;
        estadoEspecial = Normal;
        std::cout << nombre << " ha limpiado sus castigos y estados especiales." << std::endl;
    }
};

// --- CLASES DE CASILLAS CONCRETAS (Heredan de Casilla) ---

// CasillaNormal: casilla sin efecto.
class CasillaNormal : public Casilla {
public:
    CasillaNormal(int num) : Casilla(num) {}
    void activar(Jugador* jugador) override {
        std::cout << jugador->getNombre() << " está en Casilla Normal " << getNumero() + 1 << ". No hay efecto." << std::endl;
    }
};

// CasillaOca: desplaza al jugador a la siguiente oca y vuelve a tirar (lógica simplificada).
class CasillaOca : public Casilla {
public:
    CasillaOca(int num) : Casilla(num) {}
    void activar(Jugador* jugador) override {
        std::cout << "¡" << jugador->getNombre() << " en Casilla Oca " << getNumero() + 1 << "! ¡De Oca en Oca y tiro porque me toca!" << std::endl;

        // Lógica simplificada de salto a la siguiente Oca.
        // En un juego real, esto implicaría buscar la próxima CasillaOca en el tablero.
        // Para esta prueba, usamos saltos fijos o un simple avance.
        // Asumiendo que las Ocas están en 5, 9, 14, 18, 23, 27, 32, 36, 41, 45, 50, 54, 59 (índices).
        if (getNumero() == 5) {
            jugador->setPosicion(9); // Salta de Casilla 6 a Casilla 10
        } else if (getNumero() == 9) {
            jugador->setPosicion(14); // Salta de Casilla 10 a Casilla 15
        } else if (getNumero() == 14) {
            jugador->setPosicion(18); // Salta de Casilla 15 a Casilla 19
        } else if (getNumero() == 18) {
            jugador->setPosicion(23); // Salta de Casilla 19 a Casilla 24
        } else if (getNumero() == 23) {
            jugador->setPosicion(27); // Salta de Casilla 24 a Casilla 28
        } else if (getNumero() == 27) {
            jugador->setPosicion(32); // Salta de Casilla 28 a Casilla 33
        } else if (getNumero() == 32) {
            jugador->setPosicion(36); // Salta de Casilla 33 a Casilla 37
        } else if (getNumero() == 36) {
            jugador->setPosicion(41); // Salta de Casilla 37 a Casilla 42
        } else if (getNumero() == 41) {
            jugador->setPosicion(45); // Salta de Casilla 42 a Casilla 46
        } else if (getNumero() == 45) {
            jugador->setPosicion(50); // Salta de Casilla 46 a Casilla 51
        } else if (getNumero() == 50) {
            jugador->setPosicion(54); // Salta de Casilla 51 a Casilla 55
        } else if (getNumero() == 54) {
            jugador->setPosicion(59); // Salta de Casilla 55 a Casilla 60
        }
        // La última Oca (59) puede no tener una siguiente Oca o ir a la meta.
        // Para esta prueba, si no hay más Ocas adelante, simplemente se queda.

        std::cout << jugador->getNombre() << " se mueve a la casilla " << jugador->getPosicion() + 1 << "." << std::endl;
        // NOTA: La lógica de "volver a tirar" debe ser manejada por la clase Juego
        // si Casilla::activar() no devuelve un flag para ello. Para esta prueba,
        // simplemente se ejecuta el efecto de movimiento.
    }
};

// CasillaPuente: desplaza al jugador de la casilla 6 a la casilla 12.
class CasillaPuente : public Casilla {
public:
    CasillaPuente(int num) : Casilla(num) {}
    void activar(Jugador* jugador) override {
        std::cout << "¡" << jugador->getNombre() << " en Casilla Puente " << getNumero() + 1 << "! ¡De la 6 a la 12!" << std::endl;
        // La Casilla 6 es índice 5, la Casilla 12 es índice 11
        if (getNumero() == 5) { // Si el jugador cae en la casilla 6 (índice 5)
            jugador->setPosicion(11); // Mueve a la casilla 12 (índice 11)
            jugador->setEstadoEspecial(Puente); // Opcional: marca el estado Puente
            std::cout << jugador->getNombre() << " se mueve al final del puente, a la casilla 12." << std::endl;
        } else {
            std::cout << "Este puente no tiene un destino fijo en esta implementación de prueba." << std::endl;
        }
    }
};

// CasillaCastigo: representa las penalizaciones (Posada, Cárcel y Pozo).
class CasillaCastigo : public Casilla {
public:
    CasillaCastigo(int num) : Casilla(num) {}
    void activar(Jugador* jugador) override {
        int turnosPerdidos = 0;
        std::string tipoCastigo = "";

        // Mapeo de casillas específicas a diferentes castigos
        if (getNumero() == 19) { // Casilla 20 (La Posada)
            turnosPerdidos = 1;
            tipoCastigo = "La Posada";
        } else if (getNumero() == 31) { // Casilla 32 (El Pozo)
            turnosPerdidos = 2; // O hasta que otro jugador caiga aquí
            tipoCastigo = "El Pozo";
        } else if (getNumero() == 42) { // Casilla 43 (La Cárcel)
            turnosPerdidos = 3;
            tipoCastigo = "La Cárcel";
        } else {
            turnosPerdidos = 1; // Castigo por defecto si no es una casilla específica
            tipoCastigo = "Castigo Genérico";
        }

        jugador->setTurnosPerdidos(jugador->getTurnosPerdidos() + turnosPerdidos);
        jugador->setEstadoEspecial(Castigado);

        std::cout << "¡" << jugador->getNombre() << " en Casilla de Castigo " << getNumero() + 1 << " (" << tipoCastigo << ")! Pierde " << turnosPerdidos << " turno(s)." << std::endl;
    }
};


// --- CLASE Dado ---
// Simula la tirada de un dado, devolviendo un número aleatorio entre 1 y 6.
class Dado {
private:
    std::mt19937 generador;             // Motor de números aleatorios Mersenne Twister
    std::uniform_int_distribution<> distribucion; // Distribución uniforme para el rango [1, 6]

public:
    // Constructor: Inicializa el generador con una semilla de tiempo.
    Dado() : generador(std::random_device()()), distribucion(1, 6) {}

    // Método tirar(): Simula el lanzamiento del dado.
    int tirar() {
        return distribucion(generador);
    }
};

// --- CLASE Tablero ---
// Estructura contenedora de las 63 casillas de juego.
class Tablero {
private:
    Casilla** casillas;       // Arreglo dinámico de punteros a objetos Casilla
    int cantidadCasillas; // Total de casillas en el tablero

public:
    // Constructor: Inicializa el tablero con una cantidad específica de casillas.
    Tablero(int totalCasillas) : cantidadCasillas(totalCasillas) {
        casillas = new Casilla*[cantidadCasillas];
    }

    // Destructor: Libera la memoria asignada dinámicamente para las casillas.
    ~Tablero() {
        for (int i = 0; i < cantidadCasillas; ++i) {
            delete casillas[i]; // Libera cada objeto Casilla
        }
        delete[] casillas; // Libera el arreglo de punteros
    }

    // Método inicializar(): Crea cada casilla e instancia el tipo que corresponda.
    void inicializar() {
        std::cout << "Inicializando tablero con " << cantidadCasillas << " casillas..." << std::endl;
        for (int i = 0; i < cantidadCasillas; ++i) {
            // Lógica para instanciar diferentes tipos de casillas según el juego de la Oca.
            // Se usa i+1 para referirse al número de casilla en las reglas (1-63).
            if (i == 5 || i == 9 || i == 14 || i == 18 || i == 23 || i == 27 || i == 32 || i == 36 || i == 41 || i == 45 || i == 50 || i == 54 || i == 59) {
                casillas[i] = new CasillaOca(i); // Casillas de la Oca
            } else if (i == 6 || i == 12) { // Casilla 7 (índice 6) y Casilla 13 (índice 12) son puentes en algunas versiones
                casillas[i] = new CasillaPuente(i); // Casillas del Puente
            } else if (i == 19 || i == 31 || i == 42 || i == 52 || i == 58) { // Casillas de Castigo
                casillas[i] = new CasillaCastigo(i);
            } else {
                casillas[i] = new CasillaNormal(i); // Casillas normales por defecto
            }
        }
        std::cout << "Tablero inicializado." << std::endl;
    }

    // Método getCasilla(int pos): Accede a la casilla según el número.
    Casilla* getCasilla(int pos) const {
        if (pos >= 0 && pos < cantidadCasillas) {
            return casillas[pos];
        }
        std::cerr << "Error: Posición de casilla fuera de rango: " << pos + 1 << std::endl;
        return nullptr;
    }

    // Método mostrar(): Imprime un resumen del estado del tablero.
    void mostrar() const {
        std::cout << "\n--- Estado del Tablero ---" << std::endl;
        for (int i = 0; i < cantidadCasillas; ++i) {
            std::cout << (i + 1); // Muestra el número de casilla (1-indexado)
            if (i < cantidadCasillas - 1) {
                std::cout << " - ";
            }
        }
        std::cout << "\n--------------------------" << std::endl;
    }

    // Retorna la cantidad total de casillas en el tablero.
    int getCantidadCasillas() const {
        return cantidadCasillas;
    }
};

// --- CLASE Juego ---
// La clase principal que coordina todo el sistema del juego de la Oca.
class Juego {
private:
    Jugador** jugadores;       // Arreglo de punteros a objetos Jugador
    int cantidadJugadores;     // Total de jugadores en partida
    Tablero* tablero;          // Objeto Tablero (composición)
    Dado dado;                 // Instancia del dado
    int turnoActual;           // Índice del jugador que tiene el turno
    bool terminado;            // Indica si hay un ganador

    const static int CASILLA_META = 62; // La última casilla (63) es el índice 62

public:
    // Constructor
    Juego() : jugadores(nullptr), cantidadJugadores(0), tablero(nullptr), turnoActual(0), terminado(false) {}

    // Destructor: Libera la memoria asignada dinámicamente.
    ~Juego() {
        if (jugadores) {
            for (int i = 0; i < cantidadJugadores; ++i) {
                delete jugadores[i]; // Libera cada Jugador
            }
            delete[] jugadores; // Libera el arreglo de punteros
        }
        delete tablero; // Libera el Tablero
    }

    // Método iniciar(): Pide nombres e inicializa jugadores y tablero.
    void iniciar() {
        std::cout << "--- ¡Bienvenido al Juego de la Oca! ---" << std::endl;

        do {
            std::cout << "¿Cuántos jugadores van a participar? (2-4): ";
            std::cin >> cantidadJugadores;
            if (std::cin.fail() || cantidadJugadores < 2 || cantidadJugadores > 4) {
                std::cout << "Número de jugadores inválido. Ingresa un número entre 2 y 4." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        } while (true);

        jugadores = new Jugador*[cantidadJugadores];
        for (int i = 0; i < cantidadJugadores; ++i) {
            std::string nombreJugador;
            std::cout << "Ingrese el nombre del Jugador " << i + 1 << ": ";
            std::getline(std::cin, nombreJugador);
            jugadores[i] = new Jugador(nombreJugador);
        }

        tablero = new Tablero(63); // 63 casillas (índices 0 a 62)
        tablero->inicializar();

        std::cout << "\n¡El juego ha comenzado con " << cantidadJugadores << " jugadores!" << std::endl;
        mostrarEstado();
    }

    // Método jugarTurno(): Gestiona el turno del jugador actual.
    void jugarTurno() {
        if (terminado) return;

        Jugador* jugadorActual = jugadores[turnoActual];
        std::cout << "\n--- Turno de " << jugadorActual->getNombre() << " (Posición actual: " << jugadorActual->getPosicion() + 1 << ") ---" << std::endl;

        if (jugadorActual->estaCastigado()) {
            std::cout << jugadorActual->getNombre() << " está castigado y pierde el turno. Turnos restantes: " << jugadorActual->getTurnosPerdidos() << "." << std::endl;
            jugadorActual->setTurnosPerdidos(jugadorActual->getTurnosPerdidos() - 1);
            avanzarTurno();
            return;
        }

        int tirada = dado.tirar();
        std::cout << jugadorActual->getNombre() << " tiró el dado y obtuvo un " << tirada << "." << std::endl;

        int nuevaPosicion = jugadorActual->getPosicion() + tirada;

        // Lógica de "pasarse de la meta" (casilla 63)
        if (nuevaPosicion >= CASILLA_META) {
            nuevaPosicion = CASILLA_META; // Se queda exactamente en la meta
            jugadorActual->setPosicion(nuevaPosicion);
            std::cout << jugadorActual->getNombre() << " llega a la meta en la casilla 63." << std::endl;
        } else {
            jugadorActual->mover(tirada);
        }

        // Aplicar el efecto de la casilla a la que llegó
        Casilla* casillaLlegada = tablero->getCasilla(jugadorActual->getPosicion());
        if (casillaLlegada) {
            jugadorActual->aplicarEfectoCasilla(casillaLlegada);
        }

        // Verificar si hay un ganador después de aplicar el efecto
        verificarGanador();

        // Si no hay ganador, avanzar al siguiente turno
        // Aquí NO se maneja el "turno extra" de la Oca explícitamente, ya que activar() no retorna un flag.
        // Si se implementara, esta llamada a avanzarTurno() sería condicional.
        if (!terminado) {
            avanzarTurno();
        }
    }

    // Método verificarGanador(): Determina si algún jugador alcanzó la casilla 63.
    void verificarGanador() {
        for (int i = 0; i < cantidadJugadores; ++i) {
            if (jugadores[i]->getPosicion() == CASILLA_META) {
                std::cout << "\n¡FELICITACIONES! " << jugadores[i]->getNombre() << " ha llegado a la casilla 63 y ha GANADO el juego!" << std::endl;
                terminado = true;
                return;
            }
        }
    }

    // Método mostrarEstado(): Imprime un resumen del estado actual.
    void mostrarEstado() const {
        std::cout << "\n--- Estado Actual del Juego ---" << std::endl;
        tablero->mostrar();
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

    // Método estaTerminado(): Retorna true si el juego ha terminado.
    bool estaTerminado() const {
        return terminado;
    }

private:
    // Método auxiliar para avanzar al siguiente turno.
    void avanzarTurno() {
        turnoActual = (turnoActual + 1) % cantidadJugadores;
    }
};

// --- Función principal (main) ---
int main() {
    Juego miJuego;      // Crea una instancia del juego

    miJuego.iniciar();  // Inicia la configuración (pide jugadores, inicializa tablero)

    // Bucle principal del juego: continúa mientras el juego no haya terminado
    while (!miJuego.estaTerminado()) {
        miJuego.jugarTurno();     // Ejecuta un turno
        miJuego.mostrarEstado();  // Muestra el estado actualizado

        // Pausa la ejecución para ver cada turno
        std::cout << "\nPresiona Enter para continuar al siguiente turno...";
        // Limpia el buffer de entrada para evitar problemas con entradas anteriores
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nFin del juego. ¡Gracias por jugar!" << std::endl;

    return 0; // El programa finaliza con éxito
}
