// ============================================================
// clase-dos-pares-none.cpp
// Tema  : Ciclos while y do-while + operador modulo (%)
// Autor : Clase Dos — Dev-C++ / GCC
//
// Descripcion:
//   Este programa muestra el uso del operador modulo (%) para
//   clasificar numeros como pares o impares dentro de ciclos.
//
//   - parConWhile()    → imprime numeros PARES   del 2 al 10 (ciclo while)
//   - noneConDoWhile() → imprime numeros IMPARES del 1 al  9 (ciclo do-while)
// ============================================================

#include <iostream>     // Necesario para usar cout y endl

using namespace std;    // Permite escribir "cout" en lugar de "std::cout"

// ------------------------------------------------------------
// PROTOTIPOS (Declaraciones anticipadas)
// Le avisan al compilador que estas funciones existen antes de
// que encuentre su definicion mas abajo. Esto permite llamarlas
// desde main() sin importar el orden en que esten escritas.
// ------------------------------------------------------------
void parConWhile();
void noneConDoWhile();

// ============================================================
// FUNCION: parConWhile()
// Retorno: void (no regresa ningun valor)
//
// Logica:
//   Usa un ciclo 'while' para recorrer numeros del 1 al 10.
//   Dentro del ciclo, el operador % verifica si el numero es par.
//   Un numero es par cuando su residuo al dividir entre 2 es 0.
//     Ejemplo: 6 % 2 = 0  → par
//              7 % 2 = 1  → impar
// ============================================================
void parConWhile()
{
    int i = 1;  // Contador. Empieza en 1 (se incrementa antes del if,
                // por eso el primer valor evaluado sera 2).

    cout << "Imprimiendo numeros pares" << endl;

    // El ciclo while evalua la condicion ANTES de ejecutar el bloque.
    // Si 'i' ya fuera >= 10 al inicio, el bloque nunca se ejecutaria.
    while (i < 10)
    {
        i++;    // Incrementamos i PRIMERO (pre-filtro: empieza desde 2)

        // Condicion par: el residuo de dividir i entre 2 debe ser 0
        // i % 2 == 0  →  i es par  →  se imprime
        // i % 2 != 0  →  i es impar →  se ignora
        if ((i % 2) == 0)
        {
            cout << i << endl;  // Imprime: 2, 4, 6, 8, 10
        }
    }
    // Al salir del while, i vale 10 (la condicion i < 10 se volvio falsa)
}

// ============================================================
// FUNCION: noneConDoWhile()
// Retorno: void (no regresa ningun valor)
//
// Logica:
//   Usa un ciclo 'do-while' para recorrer numeros del 1 al 10.
//   Dentro del ciclo, el operador % verifica si el numero es impar.
//   Un numero es impar cuando su residuo al dividir entre 2 es mayor a 0.
//     Ejemplo: 5 % 2 = 1  → impar (1 > 0 es verdadero)
//              6 % 2 = 0  → par   (0 > 0 es falso)
//
//   "None" = "nones" (impares en español coloquial)
// ============================================================
void noneConDoWhile()
{
    int i = 0;  // Contador. Empieza en 0; se incrementa al inicio del bloque,
                // por eso el primer valor evaluado sera 1.

    cout << "Dentro de none con Do While" << endl;

    // El ciclo do-while ejecuta el bloque UNA VEZ primero,
    // y DESPUES evalua la condicion. Garantiza al menos una ejecucion.
    do
    {
        i++;    // Incrementamos i al inicio de cada iteracion

        // Condicion impar: el residuo de dividir i entre 2 debe ser mayor a 0
        // i % 2 > 0  →  i es impar →  se imprime
        // i % 2 == 0 →  i es par   →  se ignora
        if ((i % 2) > 0)
        {
            cout << i << endl;  // Imprime: 1, 3, 5, 7, 9
        }

    } while (i < 10);  // La condicion se evalua AQUI, al final de cada iteracion.
                       // Cuando i llega a 10, la condicion es falsa y el ciclo termina.

    // Mensaje de cierre: muestra el valor final de i (siempre sera 10)
    cout << "Termino Do WHILE: " << i << endl;
}

// ============================================================
// FUNCION PRINCIPAL: main()
// Punto de entrada del programa. Se ejecuta primero.
// Llama a las dos funciones en orden y termina.
// ============================================================
int main()
{
    parConWhile();      // 1. Imprime los pares del 2 al 10 con while
    noneConDoWhile();   // 2. Imprime los impares del 1 al 9 con do-while
    return 0;           // 0 = el programa termino sin errores
}