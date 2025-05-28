#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <cstddef>

using std::string;
using std::size_t;


 // Clase Registro: almacena un evento de la bitácora

class Registro {
public:
    Registro();                                 // Su complejidad es de: O(1)
    Registro(const string &lineaRegistro);      // Su complejidad es de: O(L)

    int mesANumero() const;                     // Su complejidad es de: O(1)
    size_t aSegundos() const;                   // Su complejidad es de: O(1)
    string obtenerFecha() const;                // Su complejidad es de: O(1)

    bool operator<(const Registro &otro) const; // Su complejidad es de: O(1)
    bool operator==(const Registro &otro) const;// Su complejidad es de: O(1)
    bool operator>(const Registro &otro) const; // Su complejidad es de: O(1)
    bool operator<=(const Registro &otro) const;// Su complejidad es de: O(1)
    bool operator>=(const Registro &otro) const;// Su complejidad es de: O(1)

    string mes, dia, hora, minuto, segundo;
    string ip, puerto, razon, linea;
    size_t tiempo;
};

#endif // REGISTRO_H
