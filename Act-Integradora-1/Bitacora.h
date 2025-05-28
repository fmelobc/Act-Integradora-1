#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>

//Clase Registro
//Almacena los campos leidos del archivo. Ademas calcula el epoch time (tiempo en segundos)
//a partir de la fehc a, asumiendo el año 2025 que no es bisiesto para facilitar la comparación de registros.

class Registro
{
public:
    std::string mes;
    std::string dia;
    std::string hora;
    std::string minuto;
    std::string segundo;
    std::string ip;
    std::string puerto;
    std::string razon;
    std::string linea;
    std::size_t tiempo;

    // Constructor por defecto
    Registro();

    //Constructor que recibe la linea del archivo
    //Se espera el formato de mes, dd:mm:ss ip:puerto razón
    Registro(const std::string &lineaRegistro);

    //Convierte el mes a número
    int mesANumero() const;

    //Devuelve el valor de tiempo calculado en el constructor
    std::size_t aSegundos() const;

    //Devuelve la fecha en formato " mes dd:mm:ss"
    std::string obtenerFecha() const;

    //SobreCarga de constructores para comparar registros.

    bool operator<(const Registro &otro) const;
    bool operator==(const Registro &otro) const;
    bool operator>(const Registro &otro) const;
    bool operator>=(const Registro &otro) const;
    bool operator<=(const Registro &otro) const;
};

// Estructura ParIndices
//Se utilza para devolver un par de indices.

struct ParIndices
{
    int indice1;
    int indice2;
};

// Funciones templates algoritmos de ordenamiento
// Para QuickSort la complejidad promedio  es O(n log n), para el peor caso es : O(n^2)
template <typename T>
void quickSortTemplate(std::vector<T> &vec, int inicio, int fin, std::size_t &comparaciones, std::size_t &swaps)
{

    if (inicio < fin)
    {
        int p = particionTemplate(vec, inicio, fin, comparaciones, swaps);
        quickSortTemplate(vec, inicio, p - 1, comparaciones, swaps);
        quickSortTemplate(vec, p + 1, fin, comparaciones, swaps);
    }
}

template <typename T>
int particionTemplate(std::vector<T> &vec, int inicio, int fin, std::size_t &comparaciones , std::size_t &swaps)
{
    T pivote = vec[fin];
    int i = inicio-1;
    for(int j = inicio;j<fin;j++)
    {
        comparaciones++;
        if(vec[j]<pivote)
        {
            i++;
            T temp = vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
            swaps++;
        }
    }
    T temp = vec[i+1];
    vec[i+1]=vec[fin];
    vec[fin]=temp;
    swaps++;
    return i+1;
}


/* // Algoritmo de Ordenamiento: Merge Sort
// Para el algoritmo MergeSort su complejidad es de O(n log n).
template <typename T>
void merge(std::vector<T> &vec, int low, int mid, int high, std::size_t &comparaciones)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = vec[low + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = vec[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        comparaciones++;

        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T> &vec, int low, int high, std::size_t &comparaciones)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(vec, low, mid, comparaciones);
        mergeSort(vec, mid + 1, high, comparaciones);
        merge(vec, low, mid, high, comparaciones);
    }
}

// Algortimo de Ordenamiento : Insertion Sort
// La complejidad para Insertion Sort es de O(n^2) el peor caso , aunque es eficiente para usarlo en
// arreglos pequeños

template <typename T>
void insertionSort(std::vector<T> &vec, int n, std::size_t &comparaciones, std::size_t &swaps)
{
    comparaciones = 0;
    swaps = 0;
    for (int i = 1; i < n; i++)
    {
        T key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            comparaciones++;
            vec[j + 1] = vec[j];
            j--;
            swaps++;
        }
        if (j >= 0)
        {
            comparaciones++;
        }
        vec[j + 1] = key;
    }
}

// Algoritmo de Ordenamiento Bubble Sort
// La complejidad de Bubble Sort es O(n^2).

template <typename T>
void bubbleSort(std::vector<T> &vec, int n, std::size_t &comparaciones, std::size_t &swaps)
{
    comparaciones = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            comparaciones++;
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                swaps++;
            }
        }
    }
}

// Algoritmo de Ordenamiento : Selection Sort
// Su complejidad para el peor caso es O(n^2).
template <typename T>
void selectionSort(std::vector<T> &vec, int n, std::size_t &comparaciones, std::size_t &swaps)
{
    comparaciones = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndice = i;
        for (int j = i + 1; j < n; j++)
        {
            comparaciones++;
            if (vec[j] < vec[minIndice])
            {
                minIndice = j;
            }
        }
        std::swap(vec[i], vec[minIndice]);
        swaps++;
    }
}

// Algoritmo de Ordenamiento : Swap Sort
// La complejidad de SwapSort es de O(n^2) para el peor caso.
template <typename T>
void swapSort(std::vector<T> &vec, int n, std::size_t &comparaciones, std::size_t &swaps)
{
    comparaciones = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            comparaciones++;
            if (vec[i] > vec[j])
            {
                std::swap(vec[i], vec[j]);
                swaps++;
            }
        }
    }
} */
// Prototipos de funciones no templadas
int busquedaBinaria(const std::vector<Registro> &vec, const Registro &consulta);
ParIndices buscarParConDiferencia(const std::vector<Registro> &vec, int D);

#endif