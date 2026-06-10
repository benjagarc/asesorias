/* ============================================================
   clase-dos.cpp — Ciclos while y do-while (version moderna)
   Tema  : Funcionamiento interno de while y do-while
   Autor : Clase Dos — Dev-C++ / GCC
   ============================================================
   Descripcion:
     El usuario ingresa un numero entero.
     El programa cuenta cuantas veces se incrementa un contador 'i'
     hasta que deja de ser menor que ese numero, usando:
       - funcionamientoWhile()    → con ciclo while
       - funcionamientoDoWhile()  → con ciclo do-while

     Ambas funciones retornan el valor final de 'i' y lo imprimen.
   ============================================================ */

// ---- Librerias ----
// #include <iostream>     /* GCC: iostream estandar sin .h */
// using namespace std;

#include <stdio.h>      // Para printf() y scanf() — entrada/salida estilo C
#include <conio.h>      // Para getch() — pausa la consola (solo Windows/Dev-C++)
#include <iostream>     // Para cout y endl — entrada/salida estilo C++

using namespace std;    // Permite escribir "cout" en lugar de "std::cout"


// ============================================================
// CODIGO COMENTADO — Versiones anteriores del ejercicio
// ============================================================
// Las siguientes funciones son una version previa mas simple.
// Estaban escritas en estilo C puro (printf/scanf/getch) y sin
// separar la logica en funciones con nombre descriptivo.
// Se conservan comentadas como referencia historica del proceso.
// ============================================================

// int whilefuncion(int opcion)
// {
//    int i=0;
//    while(opcion>i)   // Repite mientras opcion > i
//    {
//    	i++;
//    }
//    return i;
// }

// int dowhilefuncion(int opcion)
// {
//    int i=0;
//    do
//    {
//    	i++;
//    }
//    while(opcion>i);  // La condicion se evalua AL FINAL
//    return i;
// }

// main()
// {
//    int opcion;
//    printf("Ingrese un numero entero: \n");
//    scanf("%d",&opcion);
//    printf("El resultado en el whiles es %d: \n",whilefuncion(opcion));
//    printf("El resultado en el dowhile es %d: ",dowhilefuncion(opcion));
//    getch();   // Pausa antes de cerrar la ventana
// }


// ------------------------------------------------------------
// PROTOTIPOS (Declaraciones anticipadas)
// Informan al compilador que estas funciones existen antes de
// que aparezca su definicion. Necesario cuando main() las llama
// pero estan definidas despues.
// ------------------------------------------------------------
int funcionamientoWhile(int numero);
int funcionamientoDoWhile(int numero);


// ============================================================
// FUNCION: funcionamientoWhile(int numero)
// Parametro: numero — el limite hasta el cual contar
// Retorno  : int    — el valor final de i (igual a numero)
//
// Logica:
//   Usa un ciclo 'while'. La condicion se evalua ANTES de cada
//   iteracion. Si al inicio 'numero <= 0', el cuerpo nunca se ejecuta.
//
//   Ejemplo con numero = 3:
//     i=0 → 3>0 ✅ → i++ → i=1 → imprime
//     i=1 → 3>1 ✅ → i++ → i=2 → imprime
//     i=2 → 3>2 ✅ → i++ → i=3 → imprime
//     i=3 → 3>3 ❌ → sale del while
//   Retorna: 3
// ============================================================
int funcionamientoWhile(int numero) {
    int i = 0;  // Contador inicializado en 0

    // Traza de referencia para numero = 3:
    // i = 0; i < 3  → entra
    // i = 1; i < 3  → entra
    // i = 2; i < 3  → entra
    // i = 3; i < 3  → NO entra (condicion falsa, sale)

    // El 'while' evalua la condicion ANTES de ejecutar el bloque.
    // Si 'numero > i' es falso desde el inicio, no se ejecuta ni una vez.
    while(numero > i){
        i++;    // Incrementa el contador en cada iteracion

        // Imprime el valor actual de i en cada paso
        printf("El valor de i es %d:  \n", i);

        // Imprime si la condicion sigue siendo verdadera (1) o ya es falsa (0)
        // Esto ayuda a visualizar cuando el ciclo esta a punto de terminar
        cout << "La condicion es: " << (numero > i) << endl;
    }
    return i;   // Retorna el valor final de i (deberia ser igual a 'numero')
}


// ============================================================
// FUNCION: funcionamientoDoWhile(int numero)
// Parametro: numero — el limite hasta el cual contar
// Retorno  : int    — el valor final de i (igual a numero)
//
// Logica:
//   Usa un ciclo 'do-while'. El bloque se ejecuta PRIMERO y la
//   condicion se evalua AL FINAL. Garantiza al menos una iteracion.
//
//   Diferencia clave vs while:
//     Si numero = 0 → while NO ejecuta nada, do-while ejecuta UNA VEZ.
//
//   Ejemplo con numero = 3:
//     i=0 → entra (sin verificar) → i++ → i=1 → 3>1 ✅ continua
//     i=1 → entra → i++ → i=2 → 3>2 ✅ continua
//     i=2 → entra → i++ → i=3 → 3>3 ❌ sale
//   Retorna: 3
// ============================================================
// Valor inicial de i comentado como referencia: 0
int funcionamientoDoWhile (int numero) {
    int i = 0;  // Contador inicializado en 0

    do {
        i++;    // Incrementa el contador (se ejecuta siempre, al menos una vez)
    } while(numero > i);    // La condicion se evalua DESPUES del bloque

    // Imprime cuantas iteraciones se realizaron (valor final de i)
    cout << "Termino Do WHILE: " << i << endl;
    return i;   // Retorna el valor final de i
}


// ============================================================
// FUNCION PRINCIPAL: main()
// Punto de entrada del programa.
// Lee un numero del usuario, llama a ambas funciones e imprime resultados.
// ============================================================
int main() {
    int numero;     // Variable donde se guarda el numero que ingresa el usuario

    // Solicita al usuario que ingrese un numero entero
    printf("Ingrese un numero entero: \n");

    // Lee el numero desde la consola y lo guarda en la direccion de memoria de 'numero'.
    // El simbolo '&' es el operador de direccion: le indica a scanf donde guardar el valor.
    scanf("%d", &numero);

    // Llama a la version con 'while' y guarda el resultado
    int resultadoWhile = funcionamientoWhile(numero);

    // Llama a la version con 'do-while' y guarda el resultado
    int resultadoDoWhile = funcionamientoDoWhile(numero);

    // Imprime el resultado del while
    // Nota: el tercer argumento "\n" es ignorado por printf (solo acepta 2 para %d),
    //       pero no causa un error critico.
    printf("El resultado en while es %d:", resultadoWhile ,"\n");

    // Imprime el resultado del do-while
    printf("El resultado en do while es %d:", resultadoDoWhile);

    // cout << "El resultado en el while es: " << resultadoWhile << endl;  // Alternativa C++

    return 0;   // 0 = el programa termino sin errores
}
