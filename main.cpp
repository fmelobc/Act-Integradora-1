/*
 * Equipo 8
 * Integrantes del equipo
 * - Rodrigo Castillo Francisco A01799191
 * - Federico José Melo B. A00833536
 *
 * Fecha de creación : 16/03/2025

 * Descripción : Aplicación para el procesameinto de una bitácora de intentos de ataque hacia una red.
 *
 * Este programa realiza lo siguiente:
 * 1- Lee el archivo entrada "bitacoraData.txt" y alamacena cada renglón en un vector de objetos de la clase Registro.Cada renglón representa
 * un intento de ataque y además se asume que los registros ocurren en 2025.
 *
 * 2- Utiliza metodos y sobrecarga de operadores en la clase Registro para almacenar todos los campos de archivo(mes, día, hora, minuto, segundo,
 * dirección IP, puerto y razón) y calcular un valor "tiempo " con el formato epoch time que permite ordenar los registros por fecha.
 *
 * 3- Ordena la bitácora por fecha (mes , día , hora y segundo) utilizando varios algoritmos de ordenamiento para probar quien es el mejor.
 *
 * 4-Despliega en la pantalla el nombre del mejor algoritmo de ordenamiento empleado, junto con el número total de de comparaciones y swaps,
 * dependiendo del mejor algoritmo que se obtenga.
 *
 * 5- Almacena la bitácora ordenada en el archivo "bitacora_Ordenada.txt" conservando exactamente el mismo formato que el archivo original.
 *
 * 6- Implementa un algoritmo de busqueda binaria para realizar B operaciones de consulta por fecha F en la bitácora ordenada , devolviendo el índice de registro,
 * encontrado o -1 si no se encuentra y almacena los resultados en el archivo "resultados_busqueda.txt".
 *
 * 7-Implementa un algoritmo eficiente para localizar el primer par de registros donde su diferencia en tiempo (convertida en días) sea exactamente D.
 * Este algoritmo devulve el par de índices de dichos registros o -1 si es que no existe. El resultado se añade al final del archivo "resultados_busqueda.txt"
 *
 * Parametros de entrada:
 * -Archivo "bitacoraData.txt" con registros en el formato :
 *  Mes dd::hh::ss ip:puerto razón.
 *
 * -Entrada redirigida desde un archivo de prueba con el siguiente formato:
 *  La línea 1 indica Un entero B que se relaciona a la cantidad de operaciones de busqueda.
 *  La linea 2 a B+1 : Significa que cada linea contiene una fecha en el formato " mes , dd , hh:mm:ss"
 *  La linea B+2 es un entero D que indicea la diferencia en días para buscar el primer par de registros.
 *
 * Salida:
 * En la pantalla se imprime:abort
 * a)El nombre del algoritmo de ordenamiento utilizado
 * b)El numero total de comparaciones realizadas
 * c)El numero total de swaps
 * d)El numero total de operaciones de busqueda por fecha solicitada
 * e)El numero total de busquedas exitosas
 * f)El numero total de busquedas no exitosas
 * g) La busqueda del primer par de registros con D dias de diferencia y además para cada registro encontrado su indice en el vector seguido de la linea completa.
 *

 * Compilar:
 * Compilación con debug:
 *  g++ -std=c++17 *.cpp -Wall -g -o main
 *
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redireccion (input and output):
 *  ./main < TestCases-ActInt01\test01.txt
 *  ./main < TestCases-ActInt01\test01 > salida.txt
 *
 * En el caso de Windows (VSCode) terminal Cmd es :
 * main < TestCases-ActInt01\test01.txt
 * main< TestCases-ActInt01\test01.txt > salida.txt
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
 * GeeksforGeeks. (2025j, febrero 19). Binary Search Algorithm Iterative and Recursive Implementation. GeeksforGeeks. https://www.geeksforgeeks.org/binary-search/
 */

#include "Bitacora.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <chrono>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::ostringstream;
using std::string;
using std::vector;

// -------------------------------
// Implementación del constructor por defecto de la clase Registro
// Inicializa todos los atributos con valores vacíos o 0
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

    // Convierte día, hora, minuto y segundo a enteros
    int intDia = !dia.empty() ? std::stoi(dia) : 0;
    int intHora = !hora.empty() ? std::stoi(hora) : 0;
    int intMinuto = !minuto.empty() ? std::stoi(minuto) : 0;
    int intSegundo = !segundo.empty() ? std::stoi(segundo) : 0;

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

// -------------------------------
// Búsqueda binaria: busca un Registro en el vector ordenado
// Retorna el índice si lo encuentra, -1 si no existe
// Realiza una búsqueda en el vector ordenado para encontrar un registro con la fecha dada.
// Su complejidad es el O(n log n)
// -------------------------------
int busquedaBinaria(const vector<Registro> &vec, const Registro &consulta)
{
    int inicio = 0;
    int fin = vec.size() - 1;
    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        if (vec[medio] == consulta)
            return medio;
        else if (vec[medio] < consulta)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

// -------------------------------
// Busca el primer par de registros cuya diferencia de tiempo sea exactamente D días
// Devuelve los índices del par o (-1, -1) si no existe
// -------------------------------
ParIndices buscarParConDiferencia(const vector<Registro> &vec, int D)
{
    ParIndices resultado{-1, -1};
    int n = vec.size();
    if (n < 2)
        return resultado;

    std::size_t diffObjetivo = (std::size_t)D * 24 * 3600;
    int i = 0, j = 1;

    while (i < n && j < n)
    {
        std::size_t diff = (vec[j].aSegundos() >= vec[i].aSegundos()) ? vec[j].aSegundos() - vec[i].aSegundos() : 0;

        if (diff == diffObjetivo)
        {
            resultado.indice1 = i;
            resultado.indice2 = j;
            return resultado;
        }
        else if (diff < diffObjetivo)
            j++;
        else
            i++;

        if (i == j)
            j++;
    }
    return resultado;
}

// -------------------------------
// Clona un vector de registros (copia independiente para cada algoritmo)
// -------------------------------
vector<Registro> clonarVector(const vector<Registro> &original)
{
    return original;
}

// -------------------------------
// Función principal del programa
// -------------------------------
int main()
{
    // Abre el archivo bitácora y carga los registros al vector
    ifstream fin("bitacoraData.txt");
    if (!fin)
    {
        cerr << "No se pudo abrir el archivo compruebe si esta todo bien" << endl;
        return -1;
    }

    vector<Registro> registros;
    string linea;
    while (getline(fin, linea))
    {
        if (!linea.empty())
        {
            Registro reg(linea);
            registros.push_back(reg);
        }
    }
    fin.close();

    // Ejecuta diferentes algoritmos de ordenamiento para comparar eficiencia
    // cout << "Ejecutando algoritmo de Ordenamiento" << endl;

    // Cada bloque usa un algoritmo diferente sobre una copia del vector original
    // --- QuickSort ---
    /* {
        vector<Registro> vecOrdenar = clonarVector(registros);
        std::size_t comparaciones = 0, swaps = 0;
        auto startTime = std::chrono::high_resolution_clock::now();
        quickSortTemplate(vecOrdenar, 0, vecOrdenar.size() - 1, comparaciones, swaps);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        cout << "QuickSort:" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "Tiempo de ejecucion (ms): " << totalTime << endl;
        cout << "------------------------------------------" << endl << endl;
    } */
/*     // Repite el proceso con Insertion, Bubble, Selection, Swap y Merge Sort
    // ...
    // --- MergeSort ---
    {
        vector<Registro> vecOrdenar = clonarVector(registros);
        std::size_t comparaciones = 0;
        auto startTime = std::chrono::high_resolution_clock::now();
        mergeSort(vecOrdenar, 0, vecOrdenar.size() - 1, comparaciones);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        cout << "MergeSort:" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
        cout << "Tiempo de ejecucion (ms): " << totalTime << endl;
        cout << "------------------------------------------" << endl << endl;
    }

    // --- InsertionSort ---
    {
        vector<Registro> vecOrdenar = clonarVector(registros);
        std::size_t comparaciones = 0, swaps = 0;
        auto startTime = std::chrono::high_resolution_clock::now();
        insertionSort(vecOrdenar, vecOrdenar.size(), comparaciones, swaps);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        cout << "InsertionSort:" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "Tiempo de ejecucion (ms): " << totalTime << endl;
        cout << "------------------------------------------" << endl << endl;
    }

    // --- BubbleSort Optimizado ---
    {
        vector<Registro> vecOrdenar = clonarVector(registros);
        std::size_t comparaciones = 0, swaps = 0;
        auto startTime = std::chrono::high_resolution_clock::now();
        bubbleSort(vecOrdenar, vecOrdenar.size(), comparaciones, swaps);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        cout << "BubbleSort (Optimizado):" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "Tiempo de ejecucion (ms): " << totalTime << endl;
        cout << "------------------------------------------" << endl << endl;
    }

    // --- SelectionSort ---
    {
        vector<Registro> vecOrdenar = clonarVector(registros);
        std::size_t comparaciones = 0, swaps = 0;
        auto startTime = std::chrono::high_resolution_clock::now();
        selectionSort(vecOrdenar, vecOrdenar.size(), comparaciones, swaps);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        cout << "SelectionSort:" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "Tiempo de ejecucion (ms): " << totalTime << endl;
        cout << "------------------------------------------" << endl << endl;
    }

    // --- SwapSort ---
    {
        vector<Registro> vecOrdenar = clonarVector(registros);
        std::size_t comparaciones = 0, swaps = 0;
        auto startTime = std::chrono::high_resolution_clock::now();
        swapSort(vecOrdenar, vecOrdenar.size(), comparaciones, swaps);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        cout << "SwapSort:" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "Tiempo de ejecucion (ms): " << totalTime << endl;
        cout << "------------------------------------------" << endl << endl;
    }
 */

    // Ordena la bitácora final con QuickSort (considerado el mejor aquí)
    std::size_t comparaciones = 0, swaps = 0;
    quickSortTemplate(registros, 0, registros.size() - 1, comparaciones, swaps);

    // Guarda la bitácora ordenada en el archivo
    ofstream fout("bitacora_Ordenada.txt");
    for (std::size_t i = 0; i < registros.size(); i++)
        fout << registros[i].linea << "\n";
    fout << "\n";
    fout.close();

    // Procesa las búsquedas redirigidas desde archivo test.txt
    int B;
    cin >> B;
    cin.ignore();

    // Lee B fechas de búsqueda
    vector<Registro> consultas;
    for (int i = 0; i < B; i++)
    {
        string consultaLine;
        getline(cin, consultaLine);
        Registro reg(consultaLine);
        consultas.push_back(reg);
    }

    // Lee la diferencia D en días
    int D;
    cin >> D;

    // Realiza B búsquedas binaria y escribe los resultados en archivo
    int totalConsultas = B;
    int exitosas = 0, fallidas = 0;
    ofstream foutBusqueda("resultados_Busqueda.txt");
    foutBusqueda << " Resultados de la busqueda : " << "\n";

    for (int i = 0; i < B; i++)
    {
        int indice = busquedaBinaria(registros, consultas[i]);
        if (indice != -1)
        {
            exitosas++;
            foutBusqueda << "[" << indice << "]" << registros[indice].linea << "\n";
        }
        else
        {
            fallidas++;
            foutBusqueda << "Fecha no encontrada : " << consultas[i].linea << "\n";
        }
    }

    // Busca el primer par con D días de diferencia
    foutBusqueda << "\nBusqueda del primer par de resgistros con " << D << " dias de diferencia : " << "\n";
    ParIndices parRes = buscarParConDiferencia(registros, D);
    if (parRes.indice1 != -1)
    {
        foutBusqueda << "[" << parRes.indice1 << "]" << registros[parRes.indice1].linea << "\n";
        foutBusqueda << "[" << parRes.indice2 << "]" << registros[parRes.indice2].linea << "\n";
    }
    else
    {
        foutBusqueda << "No existen esos registros" << "\n";
    }
    foutBusqueda.close();

    // Muestra los resultados en pantalla
    cout << "QuickSort" << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Swaps: " << swaps << endl;
    cout << endl;
    cout << "Numero total de operaciones de busqueda por fecha solicitada : " << totalConsultas << endl;
    cout << "Numero total de busqudads exitosas : " << exitosas << endl;
    cout << "Numero total de busquedas no exitosas : " << fallidas << endl;
    cout << endl;
    cout << "Busqueda del primer par de registros con : " << D << "dias de diferencia : " << endl;

    if (parRes.indice1 != -1)
    {
        cout << "[" << parRes.indice1 << "]" << registros[parRes.indice1].linea << endl;
        cout << "[" << parRes.indice2 << "]" << registros[parRes.indice2].linea << endl;
    }
    else
    {
        cout << "No existe dicho par de registros" << endl;
    }

    return 0;
}
