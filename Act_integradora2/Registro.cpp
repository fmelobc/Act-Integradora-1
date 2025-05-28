#include "Registro.h"
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <algorithm>


using std::endl;
using std::istringstream;
using std::ostringstream;
using std::string;

// Implementación del constructor por defecto de la clase Registro
// Inicializa todos los atributos con valores vacíos o 0.
// -------------------------------
Registro::Registro() : tiempo(0)
{
    mes = "";
    dia = "";
    hora = "";
    minuto = "";
    segundo = "";
    ip = "";
    puerto = "";
    razon = "";
    linea = "";
}
// -------------------------------
// Constructor que recibe una línea de texto de la bitácora
// Extrae y asigna cada parte del registro (fecha, IP, razón, etc.)
// También calcula el tiempo en formato epoch (segundos desde el inicio del año)
// -------------------------------
Registro::Registro(const string &lineaRegistro)
{
    linea = lineaRegistro; // Guarda la línea completa

    istringstream iss(lineaRegistro); // Permite dividir el string por tokens usando espacio

    // Extrae el mes y el día
    if (!(iss >> mes))
        mes = " ";
    if (!(iss >> dia))
        dia = " ";

    // Extrae la hora, minuto y segundo a partir del string "hh:mm:ss"
    string tiempoStr;
    if (iss >> tiempoStr)
    {
        size_t pos = tiempoStr.find(":");
        size_t pos2 = tiempoStr.find(":", pos + 1);
        if ((pos != string::npos) && (pos2 != string::npos))
        {
            hora = tiempoStr.substr(0, pos);
            minuto = tiempoStr.substr(pos + 1, pos2 - pos - 1);
            segundo = tiempoStr.substr(pos2 + 1);
        }
        else
        {
            hora = "0";
            minuto = "0";
            segundo = "0";
        }
    }

    // Extrae IP y puerto a partir del string "IP:puerto"
    string ipPuerto;
    if (iss >> ipPuerto)
    {
        size_t pos = ipPuerto.find(":");
        if (pos != string::npos)
        {
            ip = ipPuerto.substr(0, pos);
            puerto = ipPuerto.substr(pos + 1);
        }
        else
        {
            ip = ipPuerto;
            puerto = "";
        }
    }

    // Extrae la razón (el resto de la línea)
    getline(iss, razon);
    if ((!razon.empty()) && (razon[0] == ' '))
    {
        razon.erase(0, 1);
    }

    // Validar y convertir los campos numericos
    auto safeStoi= [](const string &s)->int
    {
        if(s.empty()||!std::all_of(s.begin(), s.end(),::isdigit))
        {
            return 0;
        }
        return std::stoi(s);
    };

    // Convierte día, hora, minuto y segundo a enteros
    int intDia = safeStoi(dia);
    int intHora = safeStoi(hora);
    int intMinuto = safeStoi(minuto);
    int intSegundo = safeStoi(segundo);

    // Calcula el día del año a partir del mes
    int diasPrevios[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int mesNum = mesANumero();
    int diaDelAño = diasPrevios[mesNum] + intDia;

    // Convierte todo a segundos desde el inicio del año
    tiempo = (diaDelAño - 1) * 24 * 3600 + intHora * 3600 + intMinuto * 60 + intSegundo;
}

// -------------------------------
// Convierte el nombre del mes a su número correspondiente
// -------------------------------
int Registro::mesANumero() const
{
    if (mes == "Jan")
        return 1;
    if (mes == "Feb")
        return 2;
    if (mes == "Mar")
        return 3;
    if (mes == "Apr")
        return 4;
    if (mes == "May")
        return 5;
    if (mes == "Jun")
        return 6;
    if (mes == "Jul")
        return 7;
    if (mes == "Aug")
        return 8;
    if (mes == "Sep")
        return 9;
    if (mes == "Oct")
        return 10;
    if (mes == "Nov")
        return 11;
    if (mes == "Dec")
        return 12;
    return 0;
}

// -------------------------------
// Devuelve el tiempo en segundos desde el inicio del año
// -------------------------------
std::size_t Registro::aSegundos() const
{
    return tiempo;
}

// -------------------------------
// Devuelve la fecha completa como string en formato "Mes dd hh:mm:ss"
// -------------------------------
string Registro::obtenerFecha() const
{
    ostringstream oss;
    oss << mes << " ";
    if (dia.length() < 2)
        oss << "0";
    oss << dia << " ";
    if (hora.length() < 2)
        oss << "0";
    oss << hora << ":";
    if (minuto.length() < 2)
        oss << "0";
    oss << minuto << ":";
    if (segundo.length() < 2)
        oss << "0";
    oss << segundo;
    return oss.str();
}

// -------------------------------
// Sobrecarga de operadores para comparar objetos Registro
// -------------------------------
bool Registro::operator<(const Registro &otro) const { return aSegundos() < otro.aSegundos(); }
bool Registro::operator==(const Registro &otro) const { return aSegundos() == otro.aSegundos(); }
bool Registro::operator<=(const Registro &otro) const { return (*this < otro) || (*this == otro); }
bool Registro::operator>=(const Registro &otro) const { return (*this > otro) || (*this == otro); }
bool Registro::operator>(const Registro &otro) const { return otro < *this; }
