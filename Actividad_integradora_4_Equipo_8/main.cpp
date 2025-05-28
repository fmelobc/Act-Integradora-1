/* Equipo 8
 * Integrantes del equipo
 * - Rodrigo Castillo Francisco A01799191
 * - Federico José Melo B. A00833536
 *
 * Fecha de creación : 25/05/2025
 *
 *1. Lectura y mapeo de IPs
 *Lee de la entrada estándar dos enteros n (IPs) y m (incidencias).
 *Carga en un vector las n direcciones IP únicas.
 *Asigna a cada IP un índice entero para referenciarla internamente.
 *
 * 2. Construcción del grafo
 *Usa una clase Graph con lista de adyacencia (LinkedList) para modelar un
 *grafo dirigido y ponderado.
 *Cada incidencia aporta una arista desde la IP de origen a la IP de destino,
 *guardando el peso indicado.
 *
 * 3. Grado de salida de cada IP
 *Calcula cuántas aristas salen de cada nodo (grado de salida).
 *Guarda en “grados_ips.txt” un listado con:
 *
 * 4. Top-5 de IPs con más conexiones
 *Inserta (grado, índice) en una clase Heap propia (max-heap).
 *Extrae las 5 IPs con mayor grado y escribe en “mayores_grados_ips.txt”:
 *
 * 5. Identificación del “bot master”
 *El primer elemento extraído del heap se considera “bot master”.
 *Imprime en pantalla:
 *Bot master: <IP>
 *Primera conexión: <Fecha completa>
 *(Se almacena durante la lectura el timestamp más temprano de cada IP).
 *
 * 6. Caminos mínimos desde el bot master
 *Si el grafo es ponderado, aplica Dijkstra (sin usar std::priority_queue).
 *Guarda en “distancia_botmaster.txt”
 *
 * 7. IP de mayor esfuerzo
 *Encuentra la IP con distancia máxima (no infinita) desde el bot master.
 *Imprime en pantalla:
 *IP de mayor esfuerzo: <IP>
 *
 * 8. Reconstrucción del camino de ataque
 *Recorre el vector de predecesores generado por Dijkstra del más lejano al
 *bot master, invierte el orden y lo guarda en “ataque_botmaster.txt”:
 *# Camino de ataque
 *<bot master>
 *
 * Compilar:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redirección:
 * ./main <bitacoraGrafos.txt
 * En Windows CMD:
 * main<bitacoraGrafos.txt
 * 
 * Referencias bibliográficas
* Referencias bibliográficas (formato APA):
 * GeeksforGeeks. (2024). Linked List | Set 1 (Introduction). Recuperado de https://www.geeksforgeeks.org/linked-list-set-1-introduction/
 * GeeksforGeeks. (2024). Linked List | Set 2 (Insertion). Recuperado de https://www.geeksforgeeks.org/linked-list-set-2-insertion/
 * GeeksforGeeks. (2024). Linked List | Set 3 (Deletion). Recuperado de https://www.geeksforgeeks.org/linked-list-set-3-deletion/
 * GeeksforGeeks. (2024). Queue | Set 1 (Introduction and Array Implementation). Recuperado de https://www.geeksforgeeks.org/queue-linked-list-implementation/
 * GeeksforGeeks. (2024). Queue | Set 2 (Linked List Implementation). Recuperado de https://www.geeksforgeeks.org/queue-linked-list-implementation/
 * GeeksforGeeks. (2024). Stack | Set 1 (Introduction). Recuperado de https://www.geeksforgeeks.org/stack-data-structure-introduction/
 * GeeksforGeeks. (2024). Heap Data Structure | Set 1 (Introduction to Heap). Recuperado de https://www.geeksforgeeks.org/heap-data-structure/
 * GeeksforGeeks. (2024). Heap Sort | Set 1 (Introduction to Heap Sort). Recuperado de https://www.geeksforgeeks.org/heap-sort/
 * GeeksforGeeks. (2024). Dijkstra’s Algorithm | Greedy Algo-7. Recuperado de https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 * GeeksforGeeks. (2024). Breadth First Search or BFS for a Graph. Recuperado de https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
 * GeeksforGeeks. (2024). Depth First Search or DFS for a Graph. Recuperado de https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
 * GeeksforGeeks. (2024). Adjacency List vs Adjacency Matrix. Recuperado de https://www.geeksforgeeks.org/graph-and-its-representations/
 * GeeksforGeeks. (2024). Time Complexity Analysis. Recuperado de https://www.geeksforgeeks.org/analysis-algorithms-small-o-notations/
 * Cplusplus.com. (2024). std::vector. Recuperado de https://cplusplus.com/reference/vector/vector/
 * Cplusplus.com. (2024). std::map. Recuperado de https://cplusplus.com/reference/map/map/
 * Cplusplus.com. (2024). std::string. Recuperado de https://cplusplus.com/reference/string/string/
 * Cplusplus.com. (2024). std::algorithm. Recuperado de https://cplusplus.com/reference/algorithm/
 * Cplusplus.com. (2024). std::tie. Recuperado de https://cplusplus.com/reference/tuple/tie/
 * Cplusplus.com. (2024). std::swap. Recuperado de https://cplusplus.com/reference/utility/swap/
 * Cplusplus.com. (2024). File streams (fstream). Recuperado de https://cplusplus.com/reference/fstream/fstream/
 * Cplusplus.com. (2024). <iostream>. Recuperado de https://cplusplus.com/reference/iostream/
 * StackOverflow. (2024). stoi throwing invalid_argument. Recuperado de https://stackoverflow.com/questions/14308436/c11-stoi-throwing-stdinvalid-argument
 * StackOverflow. (2024). substr usage in C++. Recuperado de https://stackoverflow.com/questions/3800983/what-does-this-expression-mean-substr0-2
 * StackOverflow. (2024). make_heap example in C++. Recuperado de https://stackoverflow.com/questions/8091410/ways-to-use-make-heap
 * ISO. (2017). ISO/IEC 14882:2017 - Programming languages — C++. Recuperado de https://isotc.iso.org/livelink/livelink?func=ll&objId=2035156&objAction=Open
 * Microsoft Docs. (2024). Getting Started with g++ on Windows. Recuperado de https://docs.microsoft.com/cpp/build/gcc-support
 * Tutorialspoint. (2024). C++ Linked List. Recuperado de https://www.tutorialspoint.com/cplusplus/cpp_linked_list.htm
 * Tutorialspoint. (2024). C++ Priority Queue vs Heap. Recuperado de https://www.tutorialspoint.com/data_structures_algorithms/priority_queue_vs_heap.htm
 * CPPReference. (2024). std::priority_queue. Recuperado de https://en.cppreference.com/w/cpp/container/priority_queue
 * Educative. (2024). Graph Algorithms in C++. Recuperado de https://www.educative.io/collection/page/graph-algorithms-in-cpp 
 */

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "Graph.h"
#include "QueueLinkedList.h"
#include "Heap.h"

// Estructura para timestamps
typedef struct
{
    int mon, day, hh, mm, ss;
} TimeStamp;

// Convierte mes abreviado a número O(1)
int mon2int(const std::string &m)
{
    static const std::vector<std::string> months = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < (int)months.size(); ++i)
    {
        if (months[i] == m)
        {
            return i + 1;
        }
    }
    return 0;
}

// Parsea "Sep 17 00:54:39" a TimeStamp O(1)
TimeStamp parseTS(const std::string &s)
{
    TimeStamp t;
    t.mon = mon2int(s.substr(0, 3));
    t.day = std::stoi(s.substr(4, 2));
    t.hh = std::stoi(s.substr(7, 2));
    t.mm = std::stoi(s.substr(10, 2));
    t.ss = std::stoi(s.substr(13, 2));
    return t;
}

bool operator<(const TimeStamp &a, const TimeStamp &b)
{
    return std::tie(a.mon, a.day, a.hh, a.mm, a.ss) < std::tie(b.mon, b.day, b.hh, b.mm, b.ss);
}

int main()
{
    using namespace std;

    // Lectura de archivo de bitácora O(n + m)
    ifstream fin("bitacoraGrafos.txt");
    if (!fin)
    {
        cerr << "Error: no se pudo abrir bitacoraGrafros.txt" << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;
    vector<string> ips(n);
    for (int i = 0; i < n; ++i)
    {
        fin >> ips[i];
    }

    map<string, int> ipToIdx;
    for (int i = 0; i < n; ++i)
    {
        ipToIdx[ips[i]] = i;
    }

    Graph<string> G(true, true);
    for (auto &ip : ips)
    {
        G.addNode(ip);
    }

    vector<TimeStamp> firstTS(n, {13, 0, 0, 0, 0});
    vector<string> firstStr(n);

    string month, day, timeStr, origFull, destFull;
    int weight;
    string reason;

    for (int i = 0; i < m; ++i)
    {
        fin >> month >> day >> timeStr >> origFull >> destFull >> weight;
        getline(fin, reason); // rest of line ignored
        string ts = month + " " + day + " " + timeStr;

        string oriIP = origFull.substr(0, origFull.find(':'));
        string dstIP = destFull.substr(0, destFull.find(':'));
        int u = ipToIdx[oriIP];
        int v = ipToIdx[dstIP];

        G.addEdge(u, v, weight);
        TimeStamp tcur = parseTS(ts);
        if (tcur < firstTS[u])
        {
            firstTS[u] = tcur;
            firstStr[u] = ts;
        }
    }
    fin.close();

    // 1) Grados de salida O(n)
    ofstream fg("grados_ips.txt");
    fg << "# IP\tGradoSalida" << endl;
    for (int i = 0; i < n; ++i)
    {
        fg << ips[i] << "\t" << G.getDegree(i) << endl;
    }
    fg.close();

    // 2) Top 5 IPs con mayor grado usando Heap O(n log n)
    Heap<pair<int, int>> heap;
    for (int i = 0; i < n; ++i)
    {
        heap.push({G.getDegree(i), i});
    }
    ofstream fm("mayores_grados_ips.txt");
    fm << "# IP\tGradoSalida" << endl;
    vector<pair<int, int>> top5;
    for (int k = 0; k < 5 && !heap.empty(); ++k)
    {
        pair<int, int> g = heap.top();
        heap.pop();
        top5.push_back(g);
        fm << ips[g.second] << "\t" << g.first << endl;
    }
    fm.close();

    int bmIdx = top5[0].second;
    cout << "Bot master: " << ips[bmIdx] << endl;
    cout << "Primera conexion: " << firstStr[bmIdx] << endl;

    // 3) Camino más corto (Dijkstra), O(n^2 + m)
    auto results = G.dijkstra(bmIdx);
    vector<int> dist = results.first;
    vector<int> prev = results.second;

    ofstream fd("distancia_botmaster.txt");
    fd << "# IP\tDistancia" << endl;
    for (int i = 0; i < n; ++i)
    {
        int d;
        if (dist[i] == INF)
        {
            d = -1;
        }
        else
        {
            d = dist[i];
        }
        fd << ips[i] << "\t" << d << endl;
    }
    fd.close();

    // 4) IP de mayor esfuerzo O(n)
    int farIdx = -1;
    int maxD = -1;
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] != INF && dist[i] > maxD)
        {
            maxD = dist[i];
            farIdx = i;
        }
    }
    cout << "IP de mayor esfuerzo: " << ips[farIdx] << endl;

    // 5) Camino de ataque reconstrucción O(n)
    vector<int> path;
    for (int cur = farIdx; cur != -1; cur = prev[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    ofstream fa("ataque_botmaster.txt");
    fa << "# Camino de ataque" << endl;
    for (int idx : path)
    {
        fa << ips[idx] << endl;
    }
    fa.close();

    return 0;
}
