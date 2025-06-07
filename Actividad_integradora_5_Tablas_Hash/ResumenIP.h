#ifndef RESUMEN_IP_H
#define RESUMEN_IP_H

#include <string>
#include <ostream>

// Estructura que guarda el resumen de una IP:
//ip: la dirección IP como cadena.
//aristasSalientes: numero de aristas salientes (grado saliente).
//aristasEntrantes: numero de aristas entrantes (grado entrante).

struct ResumenIP
{
    std::string ip;
    int aristasSalientes;
    int aristasEntrantes;
    double proporcion;
};

// Sobrecarga de operador << para imprimir ResumenIP de forma amigable.
inline std::ostream &operator<<(std::ostream &os, const ResumenIP &r)
{
    os << "{ IP: " << r.ip<< " | out: " << r.aristasSalientes<< " | in: " << r.aristasEntrantes<< " | ratio: " << r.proporcion << " }";
    return os;
}

#endif
