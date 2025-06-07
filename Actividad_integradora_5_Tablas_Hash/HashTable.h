#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <string>
#include <functional>
#include <stdexcept>
#include <iostream>
#include "ResumenIP.h"

/*
*TablaHash implementa un arreglo de Entries de tamaño primo “tamMax”,
*usando direccionamiento abierto con prueba cuadrática para manejar colisiones.
*- setTamMax(M): O(M) para asignar el vector
*- add(r): O(1) promedio, O(M) peor caso
*- find(ip): O(1) promedio, O(M) peor caso
*- getDatoEn(i): O(1)
*- getColisiones(), getNumElementos(), getAlfa(): O(1)
*- print(): O(M)
*/


class TablaHash
{
public:
    struct Entry
    {
        bool used;       // false = libre, true = ocupado
        ResumenIP value; // solo válido si used == true

        Entry(): used(false)
        {
        }
    };

    // Constructor: inicializa miembros a cero/vacíos
    TablaHash(): tamMax(0), numElementos(0), colisiones(0)
    {
        tabla.clear();
    }

    // Destructor: limpia el vector y reinicia valores
    ~TablaHash()
    {
        tabla.clear();
        tamMax = 0;
        numElementos = 0;
        colisiones = 0;
    }

    // Fija el tamaño primo de la tabla y reinicia contadores
    void setTamMax(int tamano)
    {
        tamMax = tamano;
        numElementos = 0;
        colisiones = 0;
        tabla.assign(tamMax, Entry());
    }

    // Inserta un ResumenIP; lanza excepción si tabla llena o clave duplicada
    void add(const ResumenIP &entrada)
    {
        if (numElementos == tamMax)
        {
            throw std::out_of_range("Tabla llena");
        }
        int h0 = hashPrimario(entrada.ip);
        for (int i = 0; i < tamMax; i++)
        {
            int idx = hashSondeo(h0, i);
            if (!tabla[idx].used)
            {
                // Celda libre inserta aqui
                tabla[idx].used = true;
                tabla[idx].value = entrada;
                numElementos++;
                return;
            }
            else
            {
                // La celda está ocupada
                if (tabla[idx].value.ip == entrada.ip)
                {
                    // Ya existe la misma IP en la tabla
                    throw std::out_of_range("Clave ya existe");
                }
                else
                {
                    // Colision con una IP distinta
                    colisiones++;
                }
            }
        }

        // lanzamos excepción si no hay espacio es imposible 
        throw std::out_of_range("No se encontró posición libre");
    }

    // Busca la IP; retorna el índice o -1 si no está
    int find(const std::string &ip) const
    {
        if (tamMax == 0)
        {
            return -1;
        }
        int h0 = hashPrimario(ip);
        for (int i = 0; i < tamMax; i++)
        {
            int idx = hashSondeo(h0, i);
            if (!tabla[idx].used)
            {
                // Celda libre → la IP no está insertada
                return -1;
            }
            else
            {
                if (tabla[idx].value.ip == ip)
                {
                    // Encontramos la IP
                    return idx;
                }
                // Sino, seguimos con la siguiente prueba cuadrática
            }
        }
        return -1;
    }

    // Retorna el ResumenIP en la celda 'indice' (se asume válido)
    ResumenIP getDatoEn(int indice) const
    {
        return tabla[indice].value;
    }

    // Retorna cuántas colisiones ocurrieron durante todas las inserciones
    unsigned int getColisiones() const
    {
        return colisiones;
    }

    // Retorna cuántos elementos (celda ocupada) hay en la tabla
    int getNumElementos() const
    {
        return numElementos;
    }

    // Retorna factor de carga = numElementos / tamMax
    double getAlfa() const
    {
        if (tamMax == 0)
        {
            return 0.0;
        }
        else
        {
            return static_cast<double>(numElementos) / static_cast<double>(tamMax);
        }
    }

    // Imprime en pantalla todas las celdas ocupadas
    void print() const
    {
        std::cout << "Contenido de TablaHash (tamMax = " << tamMax << ")\n";
        for (int i = 0; i < tamMax; i++)
        {
            if (tabla[i].used)
            {
                std::cout << "  Celda[" << i << "] = " << tabla[i].value << "\n";
            }
        }
        std::cout << std::endl;
    }

private:
    int tamMax;               // tamaño del arreglo (primo)
    int numElementos;         // cuántos elementos insertados
    unsigned int colisiones;  // cuántas colisiones en total
    std::vector<Entry> tabla; // arreglo de Entries

    // Funcin hash primaria: std::hash<string>(clave) % tamMax
    int hashPrimario(const std::string &clave) const
    {
        std::hash<std::string> hasher;
        size_t h = hasher(clave);
        return static_cast<int>(h % static_cast<size_t>(tamMax));
    }

    // Prueba cuadratica
    int hashSondeo(int h0, int i) const
    {
        long long sq = static_cast<long long>(i) * i;
        long long idx = static_cast<long long>(h0) + sq;
        return static_cast<int>(idx % tamMax);
    }
};

#endif 
