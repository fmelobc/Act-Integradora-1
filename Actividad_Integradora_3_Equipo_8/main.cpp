/*
 * Equipo 8
 * Integrantes del equipo
 * - Rodrigo Castillo Francisco A01799191
 * - Federico José Melo B. A00833536
 *
 * Fecha de creación : 05/05/2025
 * Descripción : Aplicación para procesar una bitácora de accesos por IP
 *
 * Este programa realiza lo siguiente:
 * 1) Lee el archivo de entrada "bitacoraHeap.txt" y almacena cada línea en un vector de objetos Registro.
 * 2) Ordena los registros por dirección IP ,ignorando el puerto,  empleando el algoritmo Heap Sort.
 * 3) Guarda la bitácora ordenada en "bitacora_ordenada.txt".
 * 4) Recorre el vector ordenado y cuenta las repeticiones de cada IP, almacenando cada par (conteo, IP) en un MaxHeap.
 * 5) Extrae las diez IPs con más accesos del MaxHeap y las despliega en pantalla y en "ips_con_mayor_acceso.txt".
 * 6) Recorre las hojas del MaxHeap para encontrar, entre las IPs con al menos 3 accesos, cuál tiene el menor número de accesos y la muestra por pantalla.
 *
 * Compilar:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redirección:
 *  ./main < bitacoraHeap.txt
 *  ./main < bitacoraHeap.txt > salida.txt
 *
 * En Windows CMD:
 * main < bitacoraHeap.txt > salida.txt
 * 
 * Referencias bibliograficas:
 * GeeksforGeeks. (2025a, enero 10). C++ Classes and Objects. GeeksforGeeks. https://www.geeksforgeeks.org/c-classes-and-objects/
 * GeeksforGeeks. (2025b, enero 11). Structures in C++. GeeksforGeeks. https://www.geeksforgeeks.org/structures-in-cpp/
 * GeeksforGeeks. (2025c, enero 11). Operator Overloading in C++. GeeksforGeeks. https://www.geeksforgeeks.org/operator-overloading-cpp/
 * Ficheros en C++ — Fundamentos de Programación en C++. (s. f.). https://www2.eii.uva.es/fund_inf/cpp/temas/10_ficheros/ficheros_cpp.html
 * GeeksforGeeks. (2025d, enero 11). stringstream in C++ and its Applications. GeeksforGeeks. https://www.geeksforgeeks.org/stringstream-c-applications/
 * Ziv. (2024, 6 septiembre). cstdlib in C++ – Explained. Incredibuild. https://www.incredibuild.com/blog/cstdlib-in-c-explained
 * W3Schools.com. (s. f.). C++ Vectors. https://www.w3schools.com/cpp/cpp_vectors.asp
 * GeeksforGeeks. (2021, 28 julio). Processing strings using std::istringstream. GeeksforGeeks. https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
 * nexTRIE. (2020, 24 mayo). ostringstream C++ tutorial: Output streams operations for strings [Vídeo]. YouTube. https://www.youtube.com/watch?v=4zCqtUVAReY
 * GeeksforGeeks. (2025e, enero 9). Standard Error Stream Object cerr in C++. GeeksforGeeks. https://www.geeksforgeeks.org/cerr-standard-error-stream-object-in-cpp/
 * GeeksforGeeks. (2023, 21 septiembre). string::npos in C++ with Examples. GeeksforGeeks. https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/
 * GeeksforGeeks. (2025f, enero 11). Substring in C++. GeeksforGeeks. https://www.geeksforgeeks.org/substring-in-cpp/
 * Mahajan, U. (2022, 29 agosto). Remove Whitespace from a String in C++ – Scaler Topics. Scaler Topics. https://www.scaler.com/topics/removing-whitespace-from-a-string-in-cpp/
 * GeeksforGeeks. (2024b, diciembre 6). Remove spaces from a given string. GeeksforGeeks. https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
 * GeeksforGeeks. (2024a, abril 9). std::string::empty() in C++. GeeksforGeeks. https://www.geeksforgeeks.org/std-string-empty-in-cpp/
 * GeeksforGeeks. (2023a, marzo 5). std::stoi Function in C++. GeeksforGeeks. https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
 * Caleb Curry. (2022, 23 diciembre). Reading and Writing to Files (ifstream and ofstream) – C++ Tutorial 25 [Vídeo]. YouTube. https://www.youtube.com/watch?v=Cz4fl-TUjVk
 * GeeksforGeeks. (2024d, diciembre 9). Selection Sort. GeeksforGeeks. https://www.geeksforgeeks.org/selection-sort/
 * GeeksforGeeks. (2025g, enero 21). Bubble Sort Algorithm. GeeksforGeeks. https://www.geeksforgeeks.org/bubble-sort/
 * GeeksforGeeks. (2025h, enero 29). Merge Sort Data Structure and Algorithms Tutorials. GeeksforGeeks. https://www.geeksforgeeks.org/merge-sort/
 * What does this construction mean: bool operator == (const a& other) const? (s. f.). Stack Overflow. https://stackoverflow.com/questions/16302328/what-does-this-construction-mean-bool-operator-const-a-other-const
 * Input/output with files. (s/f). Cplusplus.com. Recuperado el 23 de marzo de 2025, de https://cplusplus.com/doc/tutorial/files/
 * GeeksforGeeks. (2025i, febrero 19). Doubly linked list tutorial. GeeksforGeeks. https://www.geeksforgeeks.org/doubly-linked-list/
 * Doubly Linked List (With code). (s. f.). Programiz. https://www.programiz.com/dsa/doubly-linked-list
 * TutorialsPoint. (2025, 25 marzo). C++ Pointer Operators. https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm
 * std::basic_string::find_first_not_of — cppreference.com. (s. f.). https://en.cppreference.com/w/cpp/string/basic_string/find_first_not_of
 * Standard library header — cppreference.com. (s. f.). https://en.cppreference.com/w/cpp/header/exception
 * GeeksforGeeks. (2024, 19 septiembre). Merge Sort for Linked Lists. GeeksforGeeks. https://www.geeksforgeeks.org/merge-sort-for-linked-list/
 * GeeksforGeeks. (2025j, febrero 19). Binary Search Algorithm Iterative and Recursive Implementation. GeeksforGeeks. https://www.geeksforgeeks.org/binary-search/
 */

// main.cpp
#include "BitacoraHeap.h"
#include <iostream>
#include <exception>
#include <fstream>

int main()
{
    try
    {
        BitacoraHeap bh;
        bh.load("bitacoraHeap.txt");
        bh.sortByIP();
        bh.saveSorted("bitacora_ordenada.txt");
        bh.buildHeap();

        auto top10 = bh.topN(10);

        std::ofstream fout("ips_con_mayor_acceso.txt");
        if (!fout)
        {
            throw std::runtime_error("No se pudo crear ips_con_mayor_acceso.txt");
        }

        std::cout << "Top 10 IPs:\n";
        for (auto &pr : top10)
        {
            std::cout << pr.first << " -> " << pr.second << "\n";
            fout << pr.first << " -> " << pr.second << "\n";
        }
        fout.close();

        auto mn = bh.minAtLeast(3);
        if (mn.second > 0)
        {
            std::cout << "\nIP con menor accesos >= 3:\n";
            std::cout << mn.first << " -> " << mn.second << "\n";
        }
        else
        {
            std::cout << "\nNo hay IPs con accesos >= 3\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return -1;
    }
    return 0;
}
