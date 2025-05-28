/*
 * Equipo 8
 * Integrantes del equipo
 * - Rodrigo Castillo Francisco A01799191
 * - Federico José Melo B. A00833536
 *
 * Fecha de creación : 04/04/2025

 * Descripción : Aplicacion para el procesamiento de una bitacora de intentos de ataque de red.abort
 *
 * Este programa realiza lo siguiente:
 * 1- Lee el archivo entrada "bitacoraData.txt" y alamacena cada linea de registro en una listadoblemente ligada (Doubly Linked List) de objetos 
 * de la clase Registro.
 * 
 * 2- Cada objeto Rwegistro alamcena los campos : mes , dia , hora , minuto , segundo, direccion Ip, puerto y razón.Además , calcula un valor "tiempo"
 *( tipo epoch  que permite ordenar los registros por fecha.
 * 
 * 3- Ordena la bitácora por fecha (mes , día , hora y segundo) mas reciente a mas antigua utilizando MergeSort.
 * 
 * 4-Mediante redireccion solicita las fechas de inicio y fin de busqueda, mostrando en la pantalla las líneas leidas  y luego versiones limpias de ellas
 * 
 * 5- Verifica que las fechas existan en la bitacora y que le intervalo ingresado sea válido.
 *
 * 6- Implementa un algoritmo de busqueda binaria adaptado para la lista ordenada para localizar las posiciones correspondientes a cada fecha.
 *
 * 7- Extrae y almacena en "resultado_busqueda.txt" los registros dell intervalo cerrado , y tambien los despliega en pantalla.
 * 
 * 8- Almacena la biacora ordenada en "bitacora_Ordenada.txt"
 *
 * Compilar:
 * Compilación con debug:
 *  g++ -std=c++17 *.cpp -Wall -g -o main
 *
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redireccion (input and output):
 *  ./main < TestCases-ActInt2\example01.txt
 *  ./main < TestCases-ActInt2\example01>salida.txt
 *
 * En el caso de Windows (VSCode) terminal Cmd es :
 * main< TestCases-ActInt2\example01.txt
 * main< TestCases-ActInt2\example01.txt > salida.txt
 * 
 * Referencias bibliograficas:
 * GeeksforGeeks. (2025a, enero 10). C++ Classes and Objects. GeeksforGeeks. https://www.geeksforgeeks.org/c-classes-and-objects/
 * GeeksforGeeks. (2025b, enero 11). Structures in C++. GeeksforGeeks. https://www.geeksforgeeks.org/structures-in-cpp/
 * GeeksforGeeks. (2025b, enero 11). Operator Overloading in C++. GeeksforGeeks. https://www.geeksforgeeks.org/operator-overloading-cpp/
 * Ficheros en C++ — Fundamentos de Programación en C++. (s. f.). https://www2.eii.uva.es/fund_inf/cpp/temas/10_ficheros/ficheros_cpp.html
 * GeeksforGeeks. (2025c, enero 11). stringstream in C++ and its Applications. GeeksforGeeks. https://www.geeksforgeeks.org/stringstream-c-applications/
 * Ziv. (2024, 6 septiembre). cstdlib in C++ – Explained. Incredibuild. https://www.incredibuild.com/blog/cstdlib-in-c-explained
 * W3Schools.com. (s. f.). https://www.w3schools.com/cpp/cpp_vectors.asp
 * GeeksforGeeks. (2021, 28 julio). Processing strings using std::istringstream. GeeksforGeeks. https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
 * nexTRIE. (2020, 24 mayo). ostringstream C++ tutorial: Output streams operations for strings [Vídeo]. YouTube. https://www.youtube.com/watch?v=4zCqtUVAReY
 * GeeksforGeeks. (2025a, enero 9). Standard Error Stream Object cerr in C++. GeeksforGeeks. https://www.geeksforgeeks.org/cerr-standard-error-stream-object-in-cpp/
 * GeeksforGeeks. (2023, 21 septiembre). string::npos in C++ with Examples. GeeksforGeeks. https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/
 * GeeksforGeeks. (2025f, enero 11). Substring in C++. GeeksforGeeks. https://www.geeksforgeeks.org/substring-in-cpp/
 * Mahajan, U. (2022, 29 agosto). Remove Whitespace from a String in C++ - Scaler Topics. Scaler Topics. https://www.scaler.com/topics/removing-whitespace-from-a-string-in-cpp/
 * GeeksforGeeks. (2024b, diciembre 6). Remove spaces from a given string. GeeksforGeeks. https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
 * GeeksforGeeks. (2024a, abril 9). std::string::empty() in C++. GeeksforGeeks. https://www.geeksforgeeks.org/std-string-empty-in-cpp/
 * GeeksforGeeks. (2023a, marzo 5). std::stoi Function in C++. GeeksforGeeks. https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
 * Caleb Curry. (2022, 23 diciembre). Reading and Writing to Files (ifstream and ofstream) - C++ Tutorial 25 [Vídeo]. YouTube. https://www.youtube.com/watch?v=Cz4fl-TUjVk
 * GeeksforGeeks. (2024d, diciembre 9). Selection Sort. GeeksforGeeks. https://www.geeksforgeeks.org/selection-sort/
 * GeeksforGeeks. (2025g, enero 21). Bubble Sort Algorithm. GeeksforGeeks. https://www.geeksforgeeks.org/bubble-sort/
 * GeeksforGeeks. (2025h, enero 29). Merge Sort Data Structure and Algorithms Tutorials. GeeksforGeeks. https://www.geeksforgeeks.org/merge-sort/
 * What does this construction mean: bool operator == (const a& other) const;? (s. f.). Stack Overflow. https://stackoverflow.com/questions/16302328/what-does-this-construction-mean-bool-operator-const-a-other-const
 * Input/output with files. (s/f). Cplusplus.com. Recuperado el 23 de marzo de 2025, de https://cplusplus.com/doc/tutorial/files/
 * GeeksforGeeks. (2025, 19 febrero). Doubly linked list tutorial. GeeksforGeeks. https://www.geeksforgeeks.org/doubly-linked-list/
 * Doubly Linked List (With code). (s. f.). https://www.programiz.com/dsa/doubly-linked-list
 * TutorialsPoint. (2025, 25 marzo). C++ Pointer Operators. https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm
 * std::basic_string::find_first_not_of - cppreference.com. (s. f.). https://en.cppreference.com/w/cpp/string/basic_string/find_first_not_of
 * Standard library header  - cppreference.com. (s. f.). https://en.cppreference.com/w/cpp/header/exception
 * GeeksforGeeks. (2024, 19 septiembre). Merge Sort for Linked Lists. GeeksforGeeks. https://www.geeksforgeeks.org/merge-sort-for-linked-list/
 *  GeeksforGeeks. (2025j, febrero 19). Binary Search Algorithm Iterative and Recursive Implementation. GeeksforGeeks. https://www.geeksforgeeks.org/binary-search/
 */

#include "Registro.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <exception>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::ostringstream;
using std::string;
using std::vector;

// Funcion para limpiar la cadena de entrada.
//Elimina el prefijo ("fecha inicio: y "fecha fin") y recorta los espacios al inicio y final.
string limpiarFecha(const string &linea)
{
    string res = linea;
    const string prefInicio = "fecha inicio:";
    const string preFin = "fecha fin:";
    if (res.find(prefInicio) != std::string::npos)
    {
        res = res.substr(prefInicio.length());
    }
    else if (res.find(preFin) != string::npos)
    {
        res = res.substr(preFin.length());
    }
    // Elimnar los espacios en blanco al inicio
    size_t start = res.find_first_not_of(" \t");
    size_t end = res.find_last_not_of(" \t");

    if (start != string::npos && end != std::string::npos)
    {
        res = res.substr(start, end - start + 1);
    }
    return res;
}

int main()
{
    try
    {
        // Abre el archivo bitácora y carga los registros 
        ifstream fin("bitacoraData.txt");
        if (!fin)
        {
            throw std::runtime_error("Error al abrir bitacoraData.txt");
        }

        DoublyLinkedList<Registro> lista;
        string linea;
        while (getline(fin, linea))
        {
            if (!linea.empty())
            {
                Registro reg(linea);
                lista.push_back(reg);
            }
        }
        fin.close();

        // Ordena la lista en orden descendente (por fecha y hora) usando mergeSort
        lista.sort();

        // Guarda la bitácora ordenada en el archivo "bitacora_Ordenada"
        ofstream foutOrdenada("bitacora_Ordenada.txt");
        if (!foutOrdenada)
        {
            throw std::runtime_error("Error al abrir bitacora_Ordenada.txt");
        }
        DLLNode<Registro> *current = lista.getHead();
        while (current)
        {
            foutOrdenada << current->getData().linea << "\n";
            current = current->getNext();
        }
        foutOrdenada.close();

        // Lectura del intervalo de fechas mediante redireccion
        string fechaInicioR, fechaFinR;
        getline(cin, fechaInicioR);
        //Si la linea leida no contiene el prefijo esperado se descarta y se lee otra
        if (fechaInicioR.find("fechaInicio:") == string::npos)
        {
            getline(cin, fechaInicioR);
        }
        //Se despliga la linea tal como viene
        cout << fechaInicioR << endl;

        getline(cin, fechaFinR);
        if (fechaFinR.find("fecha fin:") == string::npos)
        {
            getline(cin, fechaFinR);
        }
        cout << fechaFinR << endl;

        string fechaInicio = limpiarFecha(fechaInicioR);
        string fechaFin = limpiarFecha(fechaFinR);

        // Se crea los objetos Registro a partir de las fechas asignadas
        Registro regInicio(fechaInicio);
        Registro regFin(fechaFin);

        // Busqueda binaria que se adapta para la lista doblemente enlazada ordenada descendentemente
        int posFin = lista.binarySearch(regFin);
        int posInicio = lista.binarySearch(regInicio);
        if (posFin == -1 || posInicio == -1)
        {
            cout << "Una de las fechas no se encontro en la bitacora por lo tanto que se terminara la ejecucion." << endl;
            return -1;
        }
        if (posFin > posInicio)
        {
            cout << "El intervalo ingresado no es valido ( la fecha de inicio es mayor que la fecha de fin en la bitacora. )" << std::endl;
            return -1;
        }

        //Se extrae el intervalo cerrado de registros
        vector<string> resultados;
        DLLNode<Registro> *nodoInicio = lista.getNodeAt(posFin);
        int index = posFin;
        while (nodoInicio && index <= posInicio)
        {
            resultados.push_back(nodoInicio->getData().linea);
            nodoInicio = nodoInicio->getNext();
            index++;
        }

        //Guarda el resultado de la busqueda en "resultado_busqueda.txt"
        ofstream foutBusqueda("resultado_busqueda.txt");
        if (!foutBusqueda)
        {
            throw std::runtime_error("Error al abrir resultado_busqueda.txt");
        }
        foutBusqueda << "Resultados de la busqueda en el intervalo cerrado:\n";
        for (const auto &line : resultados)
        {

            foutBusqueda << line << "\n";
        }
        foutBusqueda.close();

        //Despliega en la terminal el resultadp ( numero de resgistros y la lista de resgistros)

        cout << "\nResultado: " << resultados.size() << " Registros" << endl;
        for (const auto &line : resultados)
        {

            cout << line << endl;
        }
        cout << "\nEl resultado de la busqueda se ha almacenado en resultado_busqueda.txt" << endl;
    }
    catch (exception &e)
    {
        cerr << "Exception : " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
