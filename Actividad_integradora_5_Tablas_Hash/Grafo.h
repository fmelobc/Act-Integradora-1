#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include <unordered_map>

/*
 *Grafo implementa un grafo dirigido cuyas “vértices” son IPs (strings)
 *y cada “arista” representa que una IP origen intentó acceder a una IP destino.
 * cargarDesdeStdin(): O(N + M)
 * cargarDesdeArchivo(): O(N + M)
 * existeIP(): O(1) promedio
 *numeroDeIPs(): O(1)
 *obtenerTodasIPs(): O(1)
 *obtenerSalientes(): O(K) con K = grado saliente de esa IP
 *obtenerGradoEntrante/Saliente: O(1)
 */

class Grafo
{
public:
    Grafo() = default;

    // Lee la bitácora desde archivo
    bool cargarDesdeArchivo(const std::string &nombreArchivo);

    // Lee la bitácora completa desde stdin
    bool cargarDesdeStdin();

    const std::vector<std::string> &obtenerTodasIPs() const;
    bool existeIP(const std::string &ip) const;
    int numeroDeIPs() const;
    std::vector<std::string> obtenerSalientes(const std::string &ip) const;
    int obtenerGradoEntrante(const std::string &ip) const;
    int obtenerGradoSaliente(const std::string &ip) const;

private:
    std::unordered_map<std::string, int> indiceDeIP;
    std::vector<std::string> listaIPs;
    std::vector<std::vector<int>> listaAdj;
    std::vector<int> gradoEntrante;
    std::vector<int> gradoSaliente;
};

#endif
