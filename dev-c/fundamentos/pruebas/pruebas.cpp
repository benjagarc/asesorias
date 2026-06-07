/* ============================================================
   pruebas.cpp - GCC / Dev-C++ moderno compatible
   Tema: Archivo de pruebas y experimentos
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
using namespace std;

int main()
{
    /* int a;
    int b;
    cout << "Ingresa el primer numero" << endl;
    cin >> a;
    cout << "Ingresa el segundo numero: " << endl;
    cin >> b;

    int suma = a + b;
    int multplicacion = a * b;
    int resta = a - b;
    int division = a / b;

    cout << "La suma de los numero es: " << suma << endl;
    cout << "La resta de los numero es: " << resta << endl;
    cout << "La multplicacion de los numero es: " << multplicacion << endl;
    cout << "La division de los numero es: " << division << endl; */

    /* int final;
    cout << "Hasta donde quieres que llegue tu ciclo?" << endl;
    cin >> final;

    int i = 1;

    for (i; i <= final; i++) {
        cout << "La table de multiplicar del numero: " << i << endl;
        for (int k = 1; k <= 10; k++) {
            int multplicacion = i * k;
            cout << i << " X " << k << " = " << multplicacion << endl;
        }
    }

    cout << "Se termino el ciclo \n" << endl; */

    /* NOTA BORLAND: Los arreglos de tamano variable (VLA) NO estan
       permitidos en Borland C++ / Turbo C++.
       La linea original: int arreglo[tamano]; donde tamano es una
       variable, no es valida.

       Solucion en Borland: usar un tamano constante fijo o pedir
       al usuario un numero que no supere el maximo declarado.

       Ejemplo corregido con tamano fijo: */

    /* const int MAX_TAMANO = 100;
    int tamano;

    cout << "Ingresa el tamano del arreglo (max " << MAX_TAMANO << "): ";
    cin >> tamano;

    if (tamano > MAX_TAMANO) tamano = MAX_TAMANO;

    int arreglo[MAX_TAMANO];   <- Tamano constante en lugar de variable

    for (int i = 1; i <= tamano; i++)
    {
        cout << "Ingresa el elemento [" << i << "]" << endl;
        cin >> arreglo[i];
    }

    cout << "El contenido del arreglo es: ";
    for (int i = 1; i <= tamano; i++)
    {
        cout << arreglo[i] << ", ";
    }

    cout << "Fin de la impresion"; */

    return 0;
}
