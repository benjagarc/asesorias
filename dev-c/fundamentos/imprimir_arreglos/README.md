# imprimir_arreglos.cpp — Migración a Borland C++

## Propósito del programa

Demuestra las formas de **imprimir arreglos** en C++:
- Por qué `cout << arreglo` imprime una dirección de memoria
- Recorrido correcto con ciclo `for` e índice
- Recorrido con aritmética de punteros
- Uso de funciones auxiliares para imprimir
- Arreglos manuales como alternativa a `std::vector`
- Arreglos bidimensionales de `char[][]` como alternativa a `string[]`
- Matrices 2D

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` + `#include <vector>` | `#include <iostream.h>` | Borland requiere `.h`; `vector` y `string` STL se reemplazan por alternativas nativas |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` es global |
| `vector<int> vec;` | `int vec[10]; int vecTamano = 0;` | `std::vector` no es confiable en Borland antiguo; se usa un arreglo con capacidad máxima fija y un contador manual |
| `vec.push_back(100);` | `vec[vecTamano++] = 100;` | Equivalente manual: se asigna el valor en la posición actual y se incrementa el contador |
| `vec.size()` | `vecTamano` | Variable entera que lleva la cuenta de elementos insertados |
| `vector<int>::iterator it = vec.begin();` | `int* p = vec;` | En arreglos nativos, un puntero ya actúa como iterador |
| `for (...it != vec.end()...) *it` | `for (...p < vec + vecTamano...) *p` | Aritmética de punteros: mismo concepto que iteradores |
| `void imprimirVector(const vector<int>& v)` | `void imprimirArregloConPuntero(int* arr, int tamano)` | Se reemplaza el parámetro `vector` por puntero + tamaño |
| `string frutas[] = {"Manzana", ...}` | `char frutas[4][20] = {"Manzana", ...}` | `string` no disponible; se usa arreglo 2D de `char` con tamaño máximo por cadena |

---

## Por qué se usó cada técnica

### Arreglo nativo `int[]` en lugar de `vector<int>`
`std::vector` es parte de la **STL (Standard Template Library)**, que en Borland C++ 5.x está disponible pero con limitaciones. Para máxima compatibilidad y claridad educativa, se usa el **arreglo nativo de C** con un entero separado que lleva la cuenta de elementos.

### `int vec[10]; int vecTamano = 0;` — Arreglo con capacidad fija
El patrón clásico para manejar una colección dinámica sin `vector`:
- Se declara un arreglo con capacidad máxima (`10` en este caso)
- Se usa un entero `vecTamano` para rastrear cuántos elementos hay realmente
- `vec[vecTamano++] = valor;` agrega un elemento y avanza el contador

### Aritmética de punteros `int* p = numeros`
Un puntero en C/C++ puede usarse para recorrer un arreglo:
- `p = numeros` → apunta al primer elemento
- `p++` → avanza al siguiente elemento
- `p < numeros + tamano` → condición de fin del recorrido

Esto es equivalente a los iteradores de `vector` pero con sintaxis de puntero crudo.

### `char frutas[4][20]` en lugar de `string frutas[]`
Un arreglo bidimensional de caracteres es la forma de C para manejar una lista de cadenas:
- La primera dimensión `[4]` es el número de cadenas
- La segunda dimensión `[20]` es el máximo de caracteres por cadena (incluyendo `'\0'`)

`cout << frutas[i]` funciona correctamente porque `frutas[i]` es un `char*` apuntando al inicio de cada cadena.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `imprimir_arreglos.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
