#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
using std::string;
//Clase Registro
//Almacena los campos leidos del archivo. Ademas calcula el epoch time (tiempo en segundos)
//a partir de la fecha, asumiendo el año 2025 que no es bisiesto para facilitar la comparación de registros.

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

    //SobreCarga de constructores para comparar registros por su valor tiempo

    bool operator<(const Registro &otro) const;
    bool operator==(const Registro &otro) const;
    bool operator>(const Registro &otro) const;
    bool operator>=(const Registro &otro) const;
    bool operator<=(const Registro &otro) const;
};

#endif
