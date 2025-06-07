#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Grafo.h"
#include "HashTable.h"
#include "ResumenIP.h"
/*
 * Equipo 8
 * Integrantes del equipo
 * - Rodrigo Castillo Francisco A01799191
 * - Federico José Melo B. A00833536
 *
 * Fecha de creación : 22/05/2025
 *Este programa realiza el análisis de una bitácora de accesos entre IPs construyendo un grafo dirigido,
 *luego crea varias tablas hash con direccionamiento abierto y prueba cuadrática para almacenar resúmenes (grados entrante/saliente y proporción) de cada IP,
 *cuenta las colisiones en cada tamaño, genera un informe de colisiones en colisiones.txt y un resumen detallado de IPs clave con sus destinos ordenados en resultados_completos.txt.
 * Compilar:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redirección:
 * ./main < bitacoraGrafos.txt
 * En Windows CMD:
 * main< bitacoraGrafos.txt
 *
 * Referencias bibliográficas:
 *GeeksforGeeks. (2024, enero 15). Hashing Data Structure. Recuperado de https://www.geeksforgeeks.org/hashing-data-structure/
 *GeeksforGeeks. (2023, diciembre 5). Collision Resolution Techniques in Hashing. Recuperado de https://www.geeksforgeeks.org/collision-resolution-techniques-in-hashing/
 *GeeksforGeeks. (2024, febrero 20). Open Addressing in Hashing | Set 1 (Linear Probing, Quadratic Probing and Double Hashing). Recuperado de https://www.geeksforgeeks.org/open-addressing-in-hashing-set-1-linear-probing-quadratic-probing-and-double-hashing/
 *GeeksforGeeks. (2023, noviembre 10). Load Factor of Hashing. Recuperado de https://www.geeksforgeeks.org/load-factor-of-hashing/
 *GeeksforGeeks. (2024, abril 10). Graph and its representations. Recuperado de https://www.geeksforgeeks.org/graph-and-its-representations/
 *GeeksforGeeks. (2023, octubre 22). Adjacency List vs Adjacency Matrix. Recuperado de https://www.geeksforgeeks.org/adjacency-list-vs-adjacency-matrix/
 *GeeksforGeeks. (2024, marzo 1). C++ STL: unordered_map. Recuperado de https://www.geeksforgeeks.org/unordered_map-c/
 *Wikipedia. (2024). Hash table. Recuperado de https://en.wikipedia.org/wiki/Hash_table
 *Wikipedia. (2024). Open addressing. Recuperado de https://en.wikipedia.org/wiki/Open_addressing
 *Wikipedia. (2024). Graph (discrete mathematics). Recuperado de https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)
 *Wikipedia. (2024). Denial-of-service attack. Recuperado de https://en.wikipedia.org/wiki/Denial-of-service_attack
 *CPPReference. (2024). std::unordered_map. Recuperado de https://en.cppreference.com/w/cpp/container/unordered_map
 *TutorialsPoint. (2024). Hash Table Data Structure. Recuperado de https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm
 *Oracle. (2024). Java™ Platform SE 17 Documentation: HashMap. Recuperado de https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/HashMap.html
 *Cloudflare. (2023, agosto 15). What is a DDoS Attack? Recuperado de https://www.cloudflare.com/learning/ddos/what-is-a-ddos-attack/
 *IBM Knowledge Center. (2024). Hash table algorithm. Recuperado de https://www.ibm.com/docs/en/zos/2.4.0?topic=algorithm-hash-table
 *Microsoft Docs. (2024). Hash Tables in .NET. Recuperado de https://docs.microsoft.com/dotnet/standard/collections/hash-tables
 *StackOverflow. (2023). What is the time complexity of hashing? Recuperado de https://stackoverflow.com/questions/3040184/what-is-the-time-complexity-of-hashing
 *Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3ra ed.). MIT Press.
 * Sedgewick, R., & Wayne, K. (2011). Algorithms (4ta ed.). Addison-Wesley Professional.
 *
 *La fase de lectura y construcción del grafo es O(N + M).
 * El bucle que inserta N entradas en la tabla hash es O(N) promedio.
 * La generación de archivos es O(N + C), donde C = total de colisiones.
 * En conjunto, main.cpp corre en O(N + M + C) promedio.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <array>

#include "Grafo.h"
#include "HashTable.h"
#include "ResumenIP.h"

// Verifica si un entero x es primo
static bool esPrimo(int x)
{
    if (x <= 1)
    {
        return false;
    }
    else
    {
        if (x <= 3)
        {
            return true;
        }
        else
        {
            if ((x % 2) == 0 || (x % 3) == 0)
            {
                return false;
            }
            else
            {
                for (int i = 5; i * i <= x; i += 6)
                {
                    if ((x % i) == 0 || (x % (i + 2)) == 0)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
}

// Retorna el siguiente primo >= x
static int siguientePrimo(int x)
{
    while (!esPrimo(x))
    {
        x++;
    }
    return x;
}

// Parsea una IP en un array de 4 enteros: "A.B.C.D"
static std::array<int, 4> parsearIP(const std::string &ip)
{
    std::array<int, 4> octetos = {0, 0, 0, 0};
    int inicio = 0;
    for (int i = 0; i < 4; i++)
    {
        size_t pos = ip.find('.', inicio);
        std::string parte;
        if (i < 3)
        {
            if (pos == std::string::npos)
            {
                return {0, 0, 0, 0};
            }
            else
            {
                parte = ip.substr(inicio, pos - inicio);
                inicio = static_cast<int>(pos) + 1;
            }
        }
        else
        {
            parte = ip.substr(inicio);
        }
        try
        {
            octetos[i] = std::stoi(parte);
        }
        catch (...)
        {
            octetos[i] = 0;
        }
    }
    return octetos;
}

// Comparador para ordenar IPs en orden numérico descendente
static bool ipDescendente(const std::string &ip1, const std::string &ip2)
{
    std::array<int, 4> o1 = parsearIP(ip1);
    std::array<int, 4> o2 = parsearIP(ip2);
    for (int i = 0; i < 4; i++)
    {
        if (o1[i] != o2[i])
        {
            return (o1[i] > o2[i]);
        }
    }
    return false;
}

// Construye el resumen completo de una IP (string) según el grafo
static std::string construirResumenIP(const std::string &ip, const Grafo &grafo)
{
    std::ostringstream oss;
    if (!grafo.existeIP(ip))
    {
        oss << "IP: " << ip << "\n";
        oss << "Error: no encontrada en la bitacora.\n\n";
        return oss.str();
    }
    else
    {
        int outc = grafo.obtenerGradoSaliente(ip);
        int inc = grafo.obtenerGradoEntrante(ip);
        double ratio;
        if (inc == 0)
        {
            ratio = static_cast<double>(outc);
        }
        else
        {
            ratio = static_cast<double>(outc) / static_cast<double>(inc);
        }
        oss << "IP: " << ip << "\n";
        oss << "Total de direcciones accesadas desde la IP: " << outc << "\n";
        oss << "Total de direcciones que intentaron acceder a la IP: " << inc << "\n";
        oss << "Relacion entre el número de direcciones accesadas y que intentaron acceder a la IP: "
            << std::fixed << std::setprecision(2) << ratio << "\n";
        std::vector<std::string> destinos = grafo.obtenerSalientes(ip);
        std::sort(destinos.begin(), destinos.end(), ipDescendente);
        oss << "Lista de direcciones accesadas:\n";
        for (const auto &d : destinos)
        {
            oss << d << "\n";
        }
        oss << "\n";
        return oss.str();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 1) Leer grafo desde stdin
    Grafo grafo;
    if (!grafo.cargarDesdeStdin())
    {
        std::cerr << "Error al leer la bitacora desde stdin.\n";
        return 1;
    }
    else
    {
    }

    // 2) Calcular colisiones
    int totalIPs = grafo.numeroDeIPs();
    std::vector<double> factores = {1.5, 2.0, 3.0};
    std::vector<std::pair<int, int>> resultadosColisiones;

    std::cout << "------- Conteo de colisiones por tamaño de tabla -------\n";
    std::vector<std::string> listaTodasIPs = grafo.obtenerTodasIPs();

    for (double f : factores)
    {
        int candidato = static_cast<int>(f * totalIPs);
        int tamTabla = siguientePrimo(candidato);

        TablaHash tabla;
        tabla.setTamMax(tamTabla);

        for (const auto &ip : listaTodasIPs)
        {
            ResumenIP r;
            r.ip = ip;
            r.aristasSalientes = grafo.obtenerGradoSaliente(ip);
            r.aristasEntrantes = grafo.obtenerGradoEntrante(ip);
            if (r.aristasEntrantes == 0)
            {
                r.proporcion = static_cast<double>(r.aristasSalientes);
            }
            else
            {
                r.proporcion = static_cast<double>(r.aristasSalientes) / static_cast<double>(r.aristasEntrantes);
            }
            tabla.add(r);
        }

        int col = static_cast<int>(tabla.getColisiones());
        std::cout << "TamTabla = " << tamTabla << "  ->  Colisiones = " << col << "\n";
        resultadosColisiones.emplace_back(tamTabla, col);
    }

    std::cout << "---------------------------------------------------------\n\n";

    // 3) Guardar 'colisiones.txt'
    {
        std::ofstream out("colisiones.txt");
        if (!out.is_open())
        {
            std::cerr << "Error: no se pudo crear 'colisiones.txt'.\n";
            return 1;
        }
        else
        {
            out << std::left << std::setw(20) << "TamTabla"
                << std::setw(20) << "Colisiones" << "\n";
            out << "-------------------------------------\n";
            for (auto &par : resultadosColisiones)
            {
                out << std::left << std::setw(20) << par.first
                    << std::setw(20) << par.second << "\n";
            }
            out.close();
        }
    }

    std::cout << "Archivo 'colisiones.txt' generado con éxito.\n\n";

    // 4) Generar 'resultados_completos.txt'
    std::vector<std::string> ipsDeInteres = {
        "50.84.64.169",
        "73.89.221.25",
        "185.109.34.183",
        "115.157.160.175",
        "2.139.111.106"};

    {
        std::ofstream fout("resultados_completos.txt");
        if (!fout.is_open())
        {
            std::cerr << "Error: no se pudo crear 'resultados_completos.txt'.\n";
            return 1;
        }
        else
        {
            fout << "Tabla comparativa de colisiones para distintos tamaños de tabla hash:\n\n";
            fout << "TamTabla            Colisiones\n";
            fout << "-------------------------------------\n";
            for (auto &par : resultadosColisiones)
            {
                fout << std::left << std::setw(20) << par.first << std::setw(20) << par.second << "\n";
            }
            fout << "\n";

            for (const auto &ip : ipsDeInteres)
            {
                if (ip == "50.84.64.169")
                {
                    fout << "Resumen para la IP sospechosa de DDoS (" << ip << "):\n\n";
                }
                else
                {
                    fout << "Resumen para IP de prueba " << ip << ":\n\n";
                }
                fout << construirResumenIP(ip, grafo);
            }

            fout.close();
        }
    }

    std::cout << "Archivo 'resultados_completos.txt' generado con éxito.\n\n";

    std::cout << "Proceso completado. Revise los archivos generados.\n";
    return 0;
}
