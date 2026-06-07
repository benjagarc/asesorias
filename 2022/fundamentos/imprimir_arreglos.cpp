#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ============================================================
// IMPRIMIR ARREGLOS EN C++ (estilo C++98/03)
// ============================================================
// En C++98 no existe range-based for ni auto.
// La forma estándar es recorrer con un ciclo for y un índice.
// ============================================================

// ============================================================
// Función auxiliar: imprime un arreglo de enteros
// Recibe: el arreglo y su tamaño como parámetros separados
// (En C++ los arreglos no saben su propio tamaño)
// ============================================================
void imprimirArregloInt(int arr[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ============================================================
// Función auxiliar: imprime un vector de enteros
// ============================================================
void imprimirVector(const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    // ============================================================
    // 1. ARREGLO NATIVO (C-style array)
    // ============================================================
    int numeros[] = {10, 20, 30, 40, 50};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    //            ↑ tamaño total en bytes / tamaño de un elemento

    cout << "=== ARREGLO NATIVO ===" << endl;

    // ✗ ESTO NO FUNCIONA COMO ESPERAS:
    cout << "cout << numeros imprime la DIRECCION DE MEMORIA: ";
    cout << numeros << endl;  // Imprime algo como 0x7ffd5e8c3a80

    // ✓ FORMA CORRECTA: Ciclo for con índice (C++98)
    cout << "Con ciclo for e indice: ";
    for (int i = 0; i < tamano; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // ✓ Con punteros (también C++98)
    cout << "Con punteros: ";
    for (int* p = numeros; p < numeros + tamano; p++) {
        cout << *p << " ";
    }
    cout << endl;

    // ✓ Con función auxiliar
    cout << "Con funcion auxiliar: ";
    imprimirArregloInt(numeros, tamano);

    // ============================================================
    // 2. STD::VECTOR (contenedor de la STL — disponible desde C++98)
    // ============================================================
    vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(400);
    vec.push_back(500);
    // Nota: en C++11 se puede inicializar así: vector<int> vec = {100, 200, ...};
    // En C++98 se usa push_back() para agregar elementos.

    cout << "\n=== STD::VECTOR ===" << endl;

    // ✓ Con for e índice
    cout << "Con for e indice: ";
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // ✓ Con iteradores (C++98)
    cout << "Con iteradores: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // ✓ Con función auxiliar
    cout << "Con funcion auxiliar: ";
    imprimirVector(vec);

    // ============================================================
    // 3. ARREGLO DE STRINGS
    // ============================================================
    string frutas[] = {"Manzana", "Banana", "Cereza", "Durazno"};
    int cantFrutas = sizeof(frutas) / sizeof(frutas[0]);

    cout << "\n=== ARREGLO DE STRINGS ===" << endl;
    cout << "Frutas: ";
    for (int i = 0; i < cantFrutas; i++) {
        cout << frutas[i];
        if (i < cantFrutas - 1) cout << ", ";
    }
    cout << endl;

    // ============================================================
    // 4. ARREGLO BIDIMENSIONAL (MATRIZ)
    // ============================================================
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "\n=== MATRIZ 3x3 ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // ============================================================
    // 5. RESUMEN DE LO QUE SI Y NO SE PUEDE
    // ============================================================
    cout << "\n=== RESUMEN ===" << endl;
    cout << "No:  cout << arregloNativo   -> Imprime DIRECCION de memoria" << endl;
    cout << "No:  cout << vector          -> ERROR DE COMPILACION" << endl;
    cout << "Si:  for (int i=0; i<n; i++) -> Funciona con todos (C++98)" << endl;
    cout << "Si:  vector<T>::iterator     -> Iteradores STL (C++98)" << endl;
    cout << "Si:  funcion auxiliar        -> Reutilizable (C++98)" << endl;
    cout << "---" << endl;
    cout << "Nota: En C++11 se puede usar range-based for:" << endl;
    cout << "  for (int n : arreglo) { cout << n; }  // C++11 en adelante" << endl;

    return 0;
}
