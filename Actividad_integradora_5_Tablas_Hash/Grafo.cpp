#include "Grafo.h"
#include <fstream>
#include <sstream>
#include <iostream>

//cargarDesdeArchivo: O(N + M) N = número de IPs, M = número de incidencias.

bool Grafo::cargarDesdeArchivo(const std::string &nombreArchivo)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        std::cerr << "Error: no se pudo abrir '" << nombreArchivo << "'." << std::endl;
        return false;
    }

    int nIPs = 0;
    int mIncidencias = 0;
    archivo >> nIPs >> mIncidencias;
    if (archivo.fail())
    {
        std::cerr << "Error: formato inválido al leer nIPs y mIncidencias." << std::endl;
        archivo.close();
        return false;
    }

    indiceDeIP.reserve(static_cast<size_t>(nIPs) * 2);
    listaIPs.reserve(nIPs);
    listaAdj.reserve(nIPs);
    gradoEntrante.assign(nIPs, 0);
    gradoSaliente.assign(nIPs, 0);

    std::string ip;
    for (int i = 0; i < nIPs; i++)
    {
        archivo >> ip;
        indiceDeIP[ip] = i;
        listaIPs.push_back(ip);
        listaAdj.emplace_back();
    }

    std::string lineaAux;
    std::getline(archivo, lineaAux);

    std::string linea;
    linea.reserve(256);
    for (int i = 0; i < mIncidencias; i++)
    {
        if (!std::getline(archivo, linea))
        {
            break;
        }
        if (linea.empty())
        {
            i--;
            continue;
        }

        std::istringstream iss(linea);
        std::string mes, dia, hora, oriConPuerto, destConPuerto;
        iss >> mes >> dia >> hora >> oriConPuerto >> destConPuerto;
        if (iss.fail())
        {
            continue;
        }

        std::size_t pos1 = oriConPuerto.find(':');
        std::size_t pos2 = destConPuerto.find(':');
        if (pos1 == std::string::npos || pos2 == std::string::npos)
        {
            continue;
        }
        std::string ipOrigen = oriConPuerto.substr(0, pos1);
        std::string ipDestino = destConPuerto.substr(0, pos2);

        auto itO = indiceDeIP.find(ipOrigen);
        if (itO == indiceDeIP.end())
        {
            continue;
        }
        auto itD = indiceDeIP.find(ipDestino);
        if (itD == indiceDeIP.end())
        {
            continue;
        }

        int idxO = itO->second;
        int idxD = itD->second;
        listaAdj[idxO].push_back(idxD);
        gradoSaliente[idxO]++;
        gradoEntrante[idxD]++;
    }

    archivo.close();
    return true;
}

bool Grafo::cargarDesdeStdin()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nIPs = 0;
    int mIncidencias = 0;
    std::cin >> nIPs >> mIncidencias;
    if (std::cin.fail())
    {
        std::cerr << "Error: formato inválido al leer nIPs y mIncidencias desde stdin." << std::endl;
        return false;
    }

    indiceDeIP.reserve(static_cast<size_t>(nIPs) * 2);
    listaIPs.reserve(nIPs);
    listaAdj.reserve(nIPs);
    gradoEntrante.assign(nIPs, 0);
    gradoSaliente.assign(nIPs, 0);

    std::string ip;
    for (int i = 0; i < nIPs; i++)
    {
        std::cin >> ip;
        indiceDeIP[ip] = i;
        listaIPs.push_back(ip);
        listaAdj.emplace_back();
    }

    std::string lineaAux;
    std::getline(std::cin, lineaAux);

    std::string linea;
    linea.reserve(256);
    for (int i = 0; i < mIncidencias; i++)
    {
        if (!std::getline(std::cin, linea))
        {
            break;
        }
        if (linea.empty())
        {
            i--;
            continue;
        }

        std::istringstream iss(linea);
        std::string mes, dia, hora, oriConPuerto, destConPuerto;
        iss >> mes >> dia >> hora >> oriConPuerto >> destConPuerto;
        if (iss.fail())
        {
            continue;
        }

        std::size_t pos1 = oriConPuerto.find(':');
        std::size_t pos2 = destConPuerto.find(':');
        if (pos1 == std::string::npos || pos2 == std::string::npos)
        {
            continue;
        }
        std::string ipOrigen = oriConPuerto.substr(0, pos1);
        std::string ipDestino = destConPuerto.substr(0, pos2);

        auto itO = indiceDeIP.find(ipOrigen);
        if (itO == indiceDeIP.end())
        {
            continue;
        }
        auto itD = indiceDeIP.find(ipDestino);
        if (itD == indiceDeIP.end())
        {
            continue;
        }

        int idxO = itO->second;
        int idxD = itD->second;
        listaAdj[idxO].push_back(idxD);
        gradoSaliente[idxO]++;
        gradoEntrante[idxD]++;
    }

    return true;
}

const std::vector<std::string> &Grafo::obtenerTodasIPs() const
{
    return listaIPs;
}

bool Grafo::existeIP(const std::string &ip) const
{
    return (indiceDeIP.find(ip) != indiceDeIP.end());
}

int Grafo::numeroDeIPs() const
{
    return static_cast<int>(listaIPs.size());
}

std::vector<std::string> Grafo::obtenerSalientes(const std::string &ip) const
{
    std::vector<std::string> resultado;
    auto it = indiceDeIP.find(ip);
    if (it == indiceDeIP.end())
    {
        return resultado;
    }
    else
    {
        int idx = it->second;
        const auto &vecIndices = listaAdj[idx];
        resultado.reserve(vecIndices.size());
        for (int destIdx : vecIndices)
        {
            resultado.push_back(listaIPs[destIdx]);
        }
        return resultado;
    }
}

int Grafo::obtenerGradoEntrante(const std::string &ip) const
{
    auto it = indiceDeIP.find(ip);
    if (it == indiceDeIP.end())
    {
        return 0;
    }
    else
    {
        return gradoEntrante[it->second];
    }
}

int Grafo::obtenerGradoSaliente(const std::string &ip) const
{
    auto it = indiceDeIP.find(ip);
    if (it == indiceDeIP.end())
    {
        return 0;
    }
    else
    {
        return gradoSaliente[it->second];
    }
}
