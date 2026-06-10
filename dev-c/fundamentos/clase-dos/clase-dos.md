# clase-dos.cpp — Ciclos `while` y `do-while`

## Descripción general

Este programa demuestra el funcionamiento de los ciclos **`while`** y **`do-while`** en C++.
El usuario ingresa un número entero y el programa cuenta cuántas veces se incrementa un
contador `i` hasta que **deja de ser menor** que ese número, usando cada uno de los dos ciclos.

---

## Librerías incluidas

```cpp
#include <stdio.h>    // Para printf() y scanf()
#include <conio.h>    // Para getch() (solo en Windows/Dev-C++)
#include <iostream>   // Para cout y endl
using namespace std;
```

| Librería | Propósito |
|---|---|
| `<stdio.h>` | Entrada/salida estilo C (`printf`, `scanf`) |
| `<conio.h>` | Funciones de consola como `getch()` (pausa la pantalla) |
| `<iostream>` | Entrada/salida estilo C++ (`cout`, `cin`) |

---

## Funciones

### `funcionamientoWhile(int numero)`

```cpp
int funcionamientoWhile(int numero) {
    int i = 0;
    while(numero > i){
        i++;
        printf("El valor de i es %d:  \n", i);
        cout << "La condicion es: " << (numero > i) << endl;
    }
    return i;
}
```

**¿Qué hace?**

1. Declara `i = 0`.
2. **Evalúa la condición ANTES** de entrar al bloque: `numero > i`.
3. Si la condición es verdadera, entra al bloque, incrementa `i` e imprime su valor.
4. Repite hasta que `numero > i` sea **falso**.
5. Retorna el valor final de `i`.

> **Característica clave del `while`:** si la condición es falsa desde el inicio,
> el cuerpo del ciclo **nunca se ejecuta**.

#### Traza de ejecución — ejemplo con `numero = 3`

| Iteración | `i` al entrar | Condición `3 > i` | `i` después de `i++` | Condición `3 > i` (después) |
|-----------|--------------|-------------------|----------------------|-----------------------------|
| 1 | 0 | ✅ verdadero | 1 | ✅ verdadero |
| 2 | 1 | ✅ verdadero | 2 | ✅ verdadero |
| 3 | 2 | ✅ verdadero | 3 | ❌ falso |
| — | 3 | ❌ falso → sale | — | — |

**Salida en consola:**
```
El valor de i es 1:
La condicion es: 1
El valor de i es 2:
La condicion es: 1
El valor de i es 3:
La condicion es: 0
```
Retorna `3`.

---

### `funcionamientoDoWhile(int numero)`

```cpp
int funcionamientoDoWhile(int numero) {
    int i = 0;
    do {
        i++;
    } while(numero > i);
    cout << "Termino Do WHILE: " << i << endl;
    return i;
}
```

**¿Qué hace?**

1. Declara `i = 0`.
2. **Entra al bloque SIN evaluar la condición** primero.
3. Incrementa `i`.
4. **Al final** evalúa `numero > i`. Si es verdadero, repite; si es falso, sale.
5. Imprime el valor final de `i` y lo retorna.

> **Característica clave del `do-while`:** el cuerpo se ejecuta **al menos una vez**,
> incluso si la condición es falsa desde el inicio.

#### Traza de ejecución — ejemplo con `numero = 3`

| Iteración | `i` antes del bloque | `i` después de `i++` | Condición `3 > i` |
|-----------|---------------------|----------------------|-------------------|
| 1 | 0 | 1 | ✅ verdadero |
| 2 | 1 | 2 | ✅ verdadero |
| 3 | 2 | 3 | ❌ falso → sale |

**Salida en consola:**
```
Termino Do WHILE: 3
```
Retorna `3`.

---

## Función `main()`

```cpp
int main() {
    int numero;
    printf("Ingrese un numero entero: \n");
    scanf("%d", &numero);
    int resultadoWhile    = funcionamientoWhile(numero);
    int resultadoDoWhile  = funcionamientoDoWhile(numero);
    printf("El resultado en while es %d:", resultadoWhile);
    printf("El resultado en do while es %d:", resultadoDoWhile);
    return 0;
}
```

**Flujo paso a paso:**

1. Se declara la variable `numero`.
2. `printf` muestra el mensaje pidiendo un número.
3. `scanf("%d", &numero)` lee el entero que escribe el usuario y lo guarda en `numero`.
   - El `&` es el **operador de dirección**: le dice a `scanf` dónde en memoria guardar el valor.
4. Se llama a `funcionamientoWhile(numero)` y su resultado se guarda en `resultadoWhile`.
5. Se llama a `funcionamientoDoWhile(numero)` y su resultado se guarda en `resultadoDoWhile`.
6. Se imprimen ambos resultados con `printf`.
7. `return 0` indica que el programa terminó correctamente.

---

## Diferencia clave: `while` vs `do-while`

| Característica | `while` | `do-while` |
|---|---|---|
| ¿Cuándo evalúa la condición? | **Antes** de ejecutar el bloque | **Después** de ejecutar el bloque |
| ¿Puede no ejecutarse nunca? | ✅ Sí, si la condición es falsa al inicio | ❌ No, siempre ejecuta al menos una vez |
| Sintaxis | `while (condicion) { }` | `do { } while (condicion);` |

---

## Código comentado (versiones anteriores)

El archivo contiene bloques de código comentado con `//`. Estas son versiones previas
del mismo ejercicio que muestran la evolución del código:

```cpp
// int whilefuncion(int opcion) { ... }
// int dowhilefuncion(int opcion) { ... }
// main() { ... }
```

Esas versiones usaban `printf` y `scanf` directamente sin encapsular en funciones separadas.
Están comentadas para preservar el historial sin eliminarlas.
