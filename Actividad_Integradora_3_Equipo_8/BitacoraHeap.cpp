// BitacoraHeap.cpp
#include "BitacoraHeap.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>

// Con load lee todas las lineas de bitacoraHeap.txt
// Su complejidad es de : O(n)
void BitacoraHeap::load(const std::string &filename)
{
    std::ifstream fin(filename);
    if (!fin)
    {
        throw std::runtime_error("No se pudo abrir " + filename);
    }
    records.clear();
    std::string linea;
    while (std::getline(fin, linea))
    {
        if (!linea.empty())
        {
            records.emplace_back(linea);
        }
    }
}
// Repara subpárbol para HeapSort por IP
// Su complejidad es de : O(log n)
void BitacoraHeap::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && records[l].ip > records[largest].ip)
    {
        largest = l;
    }
    if (r < n && records[r].ip > records[largest].ip)
    {
        largest = r;
    }
    if (largest != i)
    {
        std::swap(records[i], records[largest]);
        heapify(n, largest);
    }
}

// sortByIP aplica el Heap Sort sobre records.ip
// Su complejidad es de : O(n log n)
void BitacoraHeap::sortByIP()
{
    int n = static_cast<int>(records.size());
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(n, i);
    }
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(records[0], records[i]);
        heapify(i, 0);
    }
}

// Guarda la bitacora ordenada
// Su complejidad es de : O(n)
void BitacoraHeap::saveSorted(const std::string &filename) const
{
    std::ofstream fout(filename);
    if (!fout)
    {
        throw std::runtime_error("No se pudo crear " + filename);
    }
    for (auto &r : records)
    {
        fout << r.linea << "\n";
    }
}

// builHeap : Cuenta las frecuencias con unordered_map y 
// llena MaxHeap de pares (conteo , Ip).
// Su complejidad es de : O(n + u log u)
void BitacoraHeap::buildHeap()
{
    while (!pqMax.isEmpty())
    {
        pqMax.pop();
    }
    std::unordered_map<std::string, int> cnt;
    for (auto &r : records)
    {
        ++cnt[r.ip];
    }
    for (auto &p : cnt)
    {
        pqMax.push({p.second, p.first});
    }
}

// topN extrae  las N IPd más frecuentes del MaxHeap
// Su complejidad es de O(N log u )
std::vector<std::pair<std::string, int>> BitacoraHeap::topN(int N)
{
    std::vector<std::pair<std::string, int>> res;
    for (int k = 0; k < N && !pqMax.isEmpty(); ++k)
    {
        auto p = pqMax.top();
        pqMax.pop();
        res.emplace_back(p.second, p.first);
    }
    return res;
}

// minAtLeast : recorre las hijas del MaxHeap para 
// encontrar la IP con conteo mínimo 
// Su complejidad es de : O(u)
std::pair<std::string, int> BitacoraHeap::minAtLeast(int minCount) const
{
    const auto &A = pqMax.getData();
    int n = static_cast<int>(A.size());
    int start = n / 2;
    std::pair<std::string, int> best = {"", INT_MAX};
    for (int i = start; i < n; ++i)
    {
        auto &pr = A[i];
        if (pr.first >= minCount)
        {
            if (pr.first < best.second)
            {
                best = {pr.second, pr.first};
            }
        }
    }
    if (best.second == INT_MAX)
    {
        return {"", 0};
    }
    return best;
}
