#include "Bitacora.h"

using std::vector;
using std::string;
using std::size_t;
using std::swap;

// -------------------------------
// Búsqueda binaria: busca un Registro en el vector ordenado
// Retorna el índice si lo encuentra, -1 si no existe
// Realiza una búsqueda en el vector ordenado para encontrar un registro con la fecha dada.
// Su complejidad es el O(n log n)
// -------------------------------
int busquedaBinaria(const vector<Registro> &vec, const Registro &consulta)
{
    int inicio = 0;
    int fin = vec.size() - 1;
    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        if (vec[medio] == consulta)
            return medio;
        else if (vec[medio] < consulta)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

// -------------------------------
// Busca el primer par de registros cuya diferencia de tiempo sea exactamente D días
// Devuelve los índices del par o (-1, -1) si no existe
// -------------------------------
ParIndices buscarParConDiferencia(const vector<Registro> &vec, int D)
{
    ParIndices resultado{-1, -1};
    int n = vec.size();
    if (n < 2)
        return resultado;

    std::size_t diffObjetivo = (std::size_t)D * 24 * 3600;
    int i = 0, j = 1;

    while (i < n && j < n)
    {
        std::size_t diff = (vec[j].aSegundos() >= vec[i].aSegundos()) ? vec[j].aSegundos() - vec[i].aSegundos() : 0;

        if (diff == diffObjetivo)
        {
            resultado.indice1 = i;
            resultado.indice2 = j;
            return resultado;
        }
        else if (diff < diffObjetivo)
            j++;
        else
            i++;

        if (i == j)
            j++;
    }
    return resultado;
}
