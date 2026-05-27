#include <iostream>
#include <vector>
#include <array>
#include <iterator>   // Para ostream_iterator
#include <algorithm>  // Para copy

using namespace std;

// ============================================================
// SOBRECARGA DE OPERADOR << PARA ARREGLOS NATIVOS (opcional)
// ============================================================
// NOTA: En C++ no se puede sobrecargar para arreglos nativos
// directamente, pero sí podemos hacer una función auxiliar.

// Función plantilla para imprimir cualquier contenedor
// que tenga begin() y end() (vector, array, list, etc.)
template<typename Container>
void imprimir(const Container& c, const string& separador = " ") {
    for (const auto& elemento : c) {
        cout << elemento << separador;
    }
    cout << endl;
}

// Función específica para arreglos nativos (C-style arrays)
template<typename T, size_t N>
void imprimirArreglo(const T (&arr)[N], const string& separador = " ") {
    for (size_t i = 0; i < N; i++) {
        cout << arr[i] << separador;
    }
    cout << endl;
}

int main() {
    // ============================================================
    // 1. ARREGLO NATIVO (C-style array)
    // ============================================================
    int numeros[] = {10, 20, 30, 40, 50};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);

    cout << "=== ARREGLO NATIVO ===" << endl;

    // ❌ ESTO NO FUNCIONA COMO ESPERAS:
    cout << "cout << numeros imprime la DIRECCIÓN DE MEMORIA: ";
    cout << numeros << endl;  // Imprime algo como 0x7ffd5e8c3a80

    // ✅ FORMA CORRECTA 1: Ciclo for tradicional
    cout << "Con ciclo for: ";
    for (int i = 0; i < tamano; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // ✅ FORMA CORRECTA 2: Range-based for (foreach)
    cout << "Con range-based for: ";
    for (int n : numeros) {
        cout << n << " ";
    }
    cout << endl;

    // ✅ FORMA CORRECTA 3: Con punteros
    cout << "Con punteros: ";
    for (int* p = numeros; p < numeros + tamano; p++) {
        cout << *p << " ";
    }
    cout << endl;

    // ✅ FORMA CORRECTA 4: Función auxiliar
    cout << "Con función auxiliar: ";
    imprimirArreglo(numeros);

    // ============================================================
    // 2. STD::VECTOR (contenedor de la STL)
    // ============================================================
    vector<int> vec = {100, 200, 300, 400, 500};

    cout << "\n=== STD::VECTOR ===" << endl;

    // ❌ TAMPOCO FUNCIONA DIRECTAMENTE:
    // cout << vec << endl;  // ERROR DE COMPILACIÓN

    // ✅ Con range-based for
    cout << "Range-based for: ";
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;

    // ✅ Con iteradores
    cout << "Con iteradores: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // ✅ Con std::copy y ostream_iterator (más elegante)
    cout << "Con std::copy: ";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // ✅ Con la función plantilla
    cout << "Con función plantilla: ";
    imprimir(vec);

    // ============================================================
    // 3. STD::ARRAY (C++11, tamaño fijo como el nativo pero más seguro)
    // ============================================================
    array<int, 5> arr = {11, 22, 33, 44, 55};

    cout << "\n=== STD::ARRAY ===" << endl;

    // ✅ Con range-based for
    cout << "Range-based for: ";
    for (auto& a : arr) {
        cout << a << " ";
    }
    cout << endl;

    // ✅ Con índices
    cout << "Con índices: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ✅ Con la función plantilla
    cout << "Con función plantilla: ";
    imprimir(arr);

    // ============================================================
    // 4. ARREGLO DE STRINGS
    // ============================================================
    string frutas[] = {"Manzana", "Banana", "Cereza", "Durazno"};

    cout << "\n=== ARREGLO DE STRINGS ===" << endl;
    cout << "Frutas: ";
    imprimirArreglo(frutas, ", ");

    // ============================================================
    // 5. ARREGLO BIDIMENSIONAL (MATRIZ)
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
    // 6. RESUMEN DE LO QUE SÍ Y NO SE PUEDE
    // ============================================================
    cout << "\n=== RESUMEN ===" << endl;
    cout << "❌ cout << arregloNativo   -> Imprime DIRECCIÓN de memoria" << endl;
    cout << "❌ cout << vector           -> ERROR DE COMPILACIÓN" << endl;
    cout << "✅ Ciclo for con índices     -> Funciona con todos" << endl;
    cout << "✅ Range-based for (foreach) -> Más limpio y moderno" << endl;
    cout << "✅ std::copy + iteradores    -> Estilo funcional" << endl;
    cout << "✅ Función auxiliar          -> Reutilizable" << endl;

    return 0;
}
