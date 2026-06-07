/* ============================================================
   imprimir_arreglos.cpp - GCC / Dev-C++ moderno compatible
   Tema: Imprimir arreglos (arrays) en C++
   ============================================================
   NOTA: Se usan arreglos nativos int[] con tamano fijo.
         std::string se reemplaza por char[][].
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
using namespace std;

/* ============================================================
   Funcion auxiliar: imprime un arreglo de enteros
   Recibe: el arreglo y su tamano como parametros separados
   (En C++ los arreglos no saben su propio tamano)
   ============================================================ */
void imprimirArregloInt(int arr[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* ============================================================
   Funcion auxiliar: imprime un arreglo de enteros (recibe puntero)
   Equivalente de la funcion con vector: misma logica, arreglo nativo
   ============================================================ */
void imprimirArregloConPuntero(int* arr, int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    /* ============================================================
       1. ARREGLO NATIVO (C-style array)
       ============================================================ */
    int numeros[] = {10, 20, 30, 40, 50};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    /*             ^ tamano total en bytes / tamano de un elemento */

    cout << "=== ARREGLO NATIVO ===" << endl;

    /* Esto NO funciona como esperas: */
    cout << "cout << numeros imprime la DIRECCION DE MEMORIA: ";
    cout << numeros << endl;  /* Imprime algo como 0xFFE8 */

    /* FORMA CORRECTA: Ciclo for con indice (C++98/Borland) */
    cout << "Con ciclo for e indice: ";
    for (int i = 0; i < tamano; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    /* Con punteros (tambien C++98/Borland) */
    cout << "Con punteros: ";
    for (int* p = numeros; p < numeros + tamano; p++) {
        cout << *p << " ";
    }
    cout << endl;

    /* Con funcion auxiliar */
    cout << "Con funcion auxiliar: ";
    imprimirArregloInt(numeros, tamano);

    /* ============================================================
       2. ARREGLO MANUAL (equivalente de vector con push_back)
          En Borland se usa un arreglo con un contador
       ============================================================ */
    /* NOTA: En C++ moderno se usa vector<int>:
         vector<int> vec;
         vec.push_back(100); ...
       En Borland la opcion mas portable es un arreglo con indice manual */
    int vec[10];      /* Arreglo con capacidad maxima */
    int vecTamano = 0;

    /* Equivalente de push_back: */
    vec[vecTamano++] = 100;
    vec[vecTamano++] = 200;
    vec[vecTamano++] = 300;
    vec[vecTamano++] = 400;
    vec[vecTamano++] = 500;

    cout << "\n=== ARREGLO MANUAL (equivalente de vector) ===" << endl;

    /* Con for e indice */
    cout << "Con for e indice: ";
    for (int i = 0; i < vecTamano; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    /* Con punteros */
    cout << "Con punteros: ";
    for (int* p = vec; p < vec + vecTamano; p++) {
        cout << *p << " ";
    }
    cout << endl;

    /* Con funcion auxiliar */
    cout << "Con funcion auxiliar: ";
    imprimirArregloConPuntero(vec, vecTamano);

    /* ============================================================
       3. ARREGLO DE STRINGS (char bidimensional)
       ============================================================ */
    /* NOTA: En C++ moderno: string frutas[] = {"Manzana", ...};
       En Borland: char frutas[][20] (arreglo 2D de caracteres) */
    char frutas[4][20] = {"Manzana", "Banana", "Cereza", "Durazno"};
    int cantFrutas = 4;

    cout << "\n=== ARREGLO DE STRINGS (char[][]) ===" << endl;
    cout << "Frutas: ";
    for (int i = 0; i < cantFrutas; i++) {
        cout << frutas[i];
        if (i < cantFrutas - 1) cout << ", ";
    }
    cout << endl;

    /* ============================================================
       4. ARREGLO BIDIMENSIONAL (MATRIZ)
       ============================================================ */
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

    /* ============================================================
       5. RESUMEN
       ============================================================ */
    cout << "\n=== RESUMEN ===" << endl;
    cout << "No:  cout << arregloNativo    -> Imprime DIRECCION de memoria" << endl;
    cout << "Si:  for (int i=0; i<n; i++)  -> Funciona con todos (C++98/Borland)" << endl;
    cout << "Si:  puntero int*             -> Recorre con aritmetica de punteros" << endl;
    cout << "Si:  funcion auxiliar         -> Reutilizable (C++98/Borland)" << endl;
    cout << "---" << endl;
    cout << "Diferencia vs C++ moderno:" << endl;
    cout << "  Moderno: vector<int> vec; vec.push_back(n);" << endl;
    cout << "  Borland: int vec[MAX]; vec[i++] = n;" << endl;
    cout << "  Moderno: string frutas[] = {...};" << endl;
    cout << "  Borland: char frutas[][20] = {...};" << endl;

    return 0;
}
