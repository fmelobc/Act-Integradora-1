// Registro.cpp
#include "Registro.h"
#include <sstream>
#include <algorithm>
#include <cctype>

// Constructor por defecto 
// Su complejidad es de : O(1)
Registro::Registro(): mes(""), dia(""), hora(""), minuto(""), segundo(""),ip(""), puerto(""), razon(""), linea(""), tiempo(0)
{
}

//Constructor que parsea una linea completa de la bitacora : 
// extrae el mes , dia , hora:minuto:segundo, IP, puerto y la razón
// y calcula el tiemo en segundos.
//Su complejidad es de : O(L) donde L es la longitud de la línea.
Registro::Registro(const string &lineaRegistro): linea(lineaRegistro)
{
    std::istringstream iss(lineaRegistro);

    if (!(iss >> mes))
    {
        mes = "";
    }
    if (!(iss >> dia))
    {
        dia = "";
    }

    string ts;
    if (iss >> ts)
    {
        size_t p1 = ts.find(':'), p2 = ts.find(':', p1 + 1);
        if (p1 != string::npos && p2 != string::npos)
        {
            hora = ts.substr(0, p1);
            minuto = ts.substr(p1 + 1, p2 - p1 - 1);
            segundo = ts.substr(p2 + 1);
        }
        else
        {
            hora = "0";
            minuto = "0";
            segundo = "0";
        }
    }

    string ipPuerto;
    if (iss >> ipPuerto)
    {
        size_t p = ipPuerto.find(':');
        if (p != string::npos)
        {
            ip = ipPuerto.substr(0, p);
            puerto = ipPuerto.substr(p + 1);
        }
        else
        {
            ip = ipPuerto;
            puerto = "";
        }
    }

    std::getline(iss, razon);
    if (!razon.empty() && razon[0] == ' ')
    {
        razon.erase(0, 1);
    }

    auto safeStoi = [](const string &s) -> int
    {
        if (s.empty() ||
            !std::all_of(s.begin(), s.end(),[](char c) { return std::isdigit(static_cast<unsigned char>(c)); }))
        {
            return 0;
        }
        return std::stoi(s);
    };

    int d = safeStoi(dia);
    int h = safeStoi(hora);
    int m = safeStoi(minuto);
    int s = safeStoi(segundo);

    static const int diasPrevios[13] =
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int mn = mesANumero();
    int diaAno;
    if (mn >= 1 && mn <= 12)
    {
        diaAno = diasPrevios[mn] + d;
    }
    else
    {
        diaAno = d;
    }

    tiempo = static_cast<size_t>(
        (diaAno - 1) * 24 * 3600 +
        h * 3600 +
        m * 60 +
        s);
}

// Covierte mas abreviado a número 1-12
//Su complejidad es de : O)1
int Registro::mesANumero() const
{
    if (mes == "Jan")
    {
        return 1;
    }
    else if (mes == "Feb")
    {
        return 2;
    }
    else if (mes == "Mar")
    {
        return 3;
    }
    else if (mes == "Apr")
    {
        return 4;
    }
    else if (mes == "May")
    {
        return 5;
    }
    else if (mes == "Jun")
    {
        return 6;
    }
    else if (mes == "Jul")
    {
        return 7;
    }
    else if (mes == "Aug")
    {
        return 8;
    }
    else if (mes == "Sep")
    {
        return 9;
    }
    else if (mes == "Oct")
    {
        return 10;
    }
    else if (mes == "Nov")
    {
        return 11;
    }
    else if (mes == "Dec")
    {
        return 12;
    }
    else
    {
        return 0;
    }
}

// Formatea la fecha como "Mes dd hh:mm:ss". 
// Su comlejidad es de : O(1)
string Registro::obtenerFecha() const
{
    std::ostringstream oss;
    oss << mes << " ";
    if (dia.size() < 2)
    {
        oss << "0";
    }
    oss << dia << " ";
    if (hora.size() < 2)
    {
        oss << "0";
    }
    oss << hora << ":";
    if (minuto.size() < 2)
    {
        oss << "0";
    }
    oss << minuto << ":";
    if (segundo.size() < 2)
    {
        oss << "0";
    }
    oss << segundo;
    return oss.str();
}

// Aqui se ubican la sobrecarga de operadores
bool Registro::operator<(const Registro &o) const { return tiempo < o.tiempo; }
bool Registro::operator==(const Registro &o) const { return tiempo == o.tiempo; }
bool Registro::operator>(const Registro &o) const { return tiempo > o.tiempo; }
bool Registro::operator<=(const Registro &o) const { return (tiempo < o.tiempo || tiempo == o.tiempo); }
bool Registro::operator>=(const Registro &o) const { return (tiempo > o.tiempo || tiempo == o.tiempo); }
