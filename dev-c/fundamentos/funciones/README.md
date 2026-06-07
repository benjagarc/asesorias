# funciones.cpp — Migración a Borland C++

## Propósito del programa

Demuestra los distintos tipos de **funciones en C++**:
- Prototipos (declaración anticipada)
- Funciones con retorno de diferentes tipos
- Funciones `void` (sin retorno)
- Parámetros por defecto
- Sobrecarga de funciones (mismo nombre, distintos tipos)
- Funciones recursivas (factorial, Fibonacci)
- Paso por referencia (`int&`)
- Funciones que modifican múltiples variables mediante referencias
- Funciones que reciben arreglos
- Equivalentes de funciones anónimas (lambdas de C++11)

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` | `#include <iostream.h>` | Borland requiere `.h`; `string` STL no se usa |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` es global |
| `bool esPar(int numero)` | `int esPar(int numero)` | `bool` no disponible en Turbo C++ 3.x; se usa `int` |
| `return (numero % 2) == 0;` | `return (numero % 2) == 0;` | Sin cambio: devuelve `1` o `0` (equivalente a `true`/`false`) |
| `void saludar(string nombre)` | `void saludar(const char* nombre)` | `string` → `const char*`; el `const` evita modificar el literal |
| `void repetirMensaje(string mensaje, int veces = 3)` | `void repetirMensaje(const char* mensaje, int veces = 3)` | Idem |
| `"¿Es 4 par? Sí/No"` | `"Es 4 par? Si/No"` | Sin caracteres especiales (¿, í) que no se muestran correctamente en DOS |
| `"¡Hola, "` | `"Hola, "` | Sin `¡` inicial |
| `auto f = [](int n) { return n*n; };` (C++11) | `int cuadrado(int n) { return n * n; }` | Las lambdas no existen en Borland; se usan funciones nombradas |

---

## Por qué se usó cada técnica

### `const char*` en lugar de `string`
Para pasar texto a funciones, `const char*` es el puntero a un arreglo de caracteres. El `const` indica que la función **no modificará** el texto original. Es la forma estándar de C y C++ antiguo para pasar cadenas de texto.

### `int` en lugar de `bool` para `esPar()`
En Turbo C++ 3.x el tipo `bool` no existe. En Borland C++ 5.x sí existe, pero usar `int` garantiza máxima compatibilidad. El operador ternario `? :` y las condiciones `if` funcionan igual con `int`: `0` es falso, cualquier otro valor es verdadero.

### Paso por referencia `int&`
El paso por referencia (`int&`) es una característica de C++ desde sus primeras versiones y es **totalmente compatible** con Borland C++ 5.x. Permite modificar la variable original sin usar punteros.

### Sobrecarga de funciones
La sobrecarga también es compatible con Borland desde sus primeras versiones. El compilador distingue cuál versión usar según el tipo de los argumentos.

### Funciones recursivas
La recursión no tiene cambios: es un concepto fundamental de C++ compatible con cualquier versión del compilador.

### Funciones en lugar de lambdas
Las **funciones lambda** fueron introducidas en **C++11**. Borland C++ 5.x no las soporta. El equivalente es declarar una función normal con nombre, exactamente como se hacía en C++98.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `funciones.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
