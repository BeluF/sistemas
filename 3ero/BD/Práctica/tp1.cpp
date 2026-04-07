#include <iostream>
const int n = 4;                       // Cantidad de registros por bloque
const int PMAX = 11;                   // Límite máximo del área de datos
const int OVER = 12;                   // Posición de inicio del área de overflow
const int OMAX = 19;                   // Posición de fin de overflow
const size_t tamanioIndice = OVER / n; // Cálculo de cuántos bloques entran en el área de datos

using namespace std;

struct Registro // Estructura para los datos del archivo
{
    int clave = 0; //(0 si está vacío)
    int valor = 0;
    int direccion = 0;
};

struct Indice // Estructura para la tabla de índices
{
    int claveI;
    int direccionI;
};

Registro areaDatos[OMAX + 1];
Indice areaIndices[tamanioIndice];

/// FUNCIONES
int consulta(int clave);
bool insertar(int clave, int dato);

int main()
{
    return 0;
}

/// DESARROLLO FUNCIONES
int consulta(int clave) // Búsqueda
{
    int indexBloque = -1;                   // Variable para guardar el bloque encontrado
    for (int i = 0; i < tamanioIndice; i++) // Recorrer la tabla de índices
    {
        if (clave >= areaIndices[i].claveI) // FIjarse que la clave esté en el rango del índice actual
        {
            if (i == tamanioIndice - 1 || clave < areaIndices[i + 1].claveI) // Si es el último o si es menor al siguiente índice
            {
                indexBloque = areaIndices[i].direccionI; // GUardar la dirección de inicio del bloque
                break;
            }
        }
    }

    if (indexBloque == -1) // Si el índice no devolvió nada válido
        return -1;         // Devolver error porque la clave no existe

    int ultimoEnBloque = -1;                            // Variable para saber cuál fue el último registro cargado
    for (int i = indexBloque; i < indexBloque + n; i++) // Recorrer los registros del área de datos
    {
        if (areaDatos[i].clave == clave) // CLave encontrada
            return areaDatos[i].valor;
        if (areaDatos[i].clave != 0) // Si el lugar no está vacío
            ultimoEnBloque = i;      // Actualizar cuál es el último registro ocupado
    }

    if (ultimoEnBloque != -1 && areaDatos[ultimoEnBloque].direccion != 0) // Si el bloque terminó y tiene un puntero a overflow
    {
        int dirOF = areaDatos[ultimoEnBloque].direccion; // Ir a la dirección de overflow
        if (areaDatos[dirOF].clave == clave)             // Si la clave está en esa posición de overflow
        {
            return areaDatos[dirOF].valor;
        }
    }

    return -1; // Acá la clave no está en ningún lado
}

bool insertar(int clave, int dato)
{
    int index = -1;

    for (int i = 0; i < tamanioIndice; i++) // BUscar donde debería ir la clave
    {
        if (clave >= areaIndices[i].claveI) // Comparar con la clave del índice actual
        {
            if (i == tamanioIndice - 1 || clave < areaIndices[i + 1].claveI) // Límites del bloque
                index = i;                                                   // GUardar posición del índice
        }
    }

    if (index == -1)                                  // Si la clave es menor a todos los índices
        index = 0;                                    // 1er bloque
    int inicioBloque = areaIndices[index].direccionI; // Posición de inicio del área de datos

    int cont = 0; // Contador para saber cuántos lugares ocupados hay
    for (int i = inicioBloque; i < inicioBloque + n; i++)
    {
        if (areaDatos[i].clave != 0) // Lugar ocupado
        {
            if (areaDatos[i].clave == clave) // LA CLAVE YA EXISTE (no permitido)
                return false;
            cont++;
        }
    }

    if (cont < n) // Si hay lugar
    {
        int pos = inicioBloque + n - 1; // Arrancar desde el final del bloque

        // Mientras no llegue al inicio del bloque y el lugar anterior esté vacío o tenga una clave mayor:
        while (pos > inicioBloque && (areaDatos[pos - 1].clave == 0 || areaDatos[pos - 1].clave > clave))
        {
            areaDatos[pos] = areaDatos[pos - 1]; // MOver el registro una posición
            pos--;                               // REtroceder al de arriba para seguir comparando
        }

        // INserción
        areaDatos[pos].clave = clave;
        areaDatos[pos].valor = dato;
        areaDatos[pos].direccion = 0;

        if (pos == inicioBloque) // SI quedo primero, hay que actualizar el índice
            areaIndices[index].claveI = clave;

        if (pos == (inicioBloque + n - 1) && cont >= (n / 2)) // Si era el último lugar y el bloque tiene al menos n/2 slots ocupadso
        {
            if (inicioBloque + n >= PMAX) // Si no se pueden hacer más bloques (limite PMAX)
                cout << "REORGANIZAR: PMAX alcanzado. No se pueden abrir mas bloques." << endl;
            else // Si todavía queda espacio
                cout << "Aviso: Se deberia abrir un nuevo bloque." << endl;
        }
        return true;
    }
    else // Si el área de datos está llena --> overflow
    {
        for (int i = OVER; i <= OMAX; i++)
        {
            if (areaDatos[i].clave == 0) // Posición vacía
            {
                areaDatos[i].clave = clave;
                areaDatos[i].valor = dato;
                areaDatos[i].direccion = 0;

                areaDatos[inicioBloque + n - 1].direccion = i; // Enlazar el último del bloque con esta posición de overflow
                cout << "Se  guardo en el area de Overflow";
                return true;
            }
        }
        cout << "Reorganizar area de Overflow llena." << endl; // Error: ya no hay más espacio
    }
    return false;
}