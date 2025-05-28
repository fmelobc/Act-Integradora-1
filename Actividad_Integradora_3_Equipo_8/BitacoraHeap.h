// BitacoraHeap.h
#ifndef BITACORA_HEAP_H
#define BITACORA_HEAP_H

#include <vector>
#include <string>
#include "Registro.h"
#include "MaxHeap.h"

// Clase BitacoraHeap
// Proceso bitacora, ordena por IP y cuenta las frecuencias 
class BitacoraHeap
{
public:
    void load(const std::string &filename); // Lee el archivo
    void sortByIP(); // Heap Sort por IP
    void saveSorted(const std::string &filename) const; //Guarda ordenados
    void buildHeap(); // Cuenta y asi heap
    std::vector<std::pair<std::string, int>> topN(int N); // Top N en MaxHeap
    std::pair<std::string, int> minAtLeast(int minCount) const; // Minimo >= count

private:
    std::vector<Registro> records;
    MaxHeap<std::pair<int, std::string>> pqMax;
    void heapify(int n, int i);
};

#endif // BITACORA_HEAP_H
