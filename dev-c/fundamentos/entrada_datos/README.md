# entrada_datos.cpp — Migración a Borland C++

## Propósito del programa

Demuestra las distintas formas de **leer datos del usuario** con `cin` en C++:
- Lectura de tipos básicos (`int`, `float`, `double`, `char`)
- Lectura de múltiples valores en una sola línea
- Lectura de líneas completas con `getline`
- Lectura hasta un delimitador
- Validación de entrada con manejo de errores
- Lectura carácter por carácter con `cin.get()`
- Llenado de arreglos con `cin`
- Formulario completo

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` + `#include <limits>` | `#include <iostream.h>` | Borland requiere `.h`; `limits` no existe; `string` se reemplaza por `char[]` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` y `cin` son globales |
| `string palabra;` | `char palabra[100];` | `std::string` no disponible; se usa arreglo de 100 caracteres |
| `cin >> palabra;` | `cin >> palabra;` | Sin cambio: `cin >>` funciona igual con `char[]` |
| `string linea;` + `getline(cin, linea)` | `char linea[200];` + `cin.getline(linea, 200)` | La función global `getline()` para `std::string` no existe en Borland; se usa el método del objeto `cin.getline()` con `char[]` |
| `getline(cin, frase, '.')` | `cin.getline(frase, 200, '.')` | Idem: método del objeto con delimitador personalizado |
| `cin.ignore(numeric_limits<streamsize>::max(), '\n')` | `cin.ignore(255, '\n')` | `numeric_limits` de `<limits>` no existe en Borland; se usa el valor fijo `255` que es suficientemente grande para limpiar el buffer |
| `string nombreCompleto;` | `char nombreCompleto[100];` | Idem: `char[]` con tamaño fijo |

---

## Por qué se usó cada técnica

### `cin.getline(buffer, tamaño)` en lugar de `getline(cin, string)`
En C++ moderno, existe la función global `getline(istream&, string&)` que llena un `std::string`. En Borland, esa función no existe. En cambio, `cin` tiene un **método propio** `cin.getline(char*, int)` que hace lo mismo pero con un `char[]` de tamaño fijo. Este método existe desde las primeras versiones de C++.

### `cin.ignore(255, '\n')` en lugar de `numeric_limits`
`numeric_limits<streamsize>::max()` es una plantilla de `<limits>` que devuelve el máximo número de caracteres a ignorar. En Borland, `<limits>` no existe. La alternativa es un **número fijo grande** como `255`, que en la práctica es más que suficiente para limpiar el resto de una línea del buffer de entrada.

### `char[]` con tamaño fijo
Al no tener `std::string`, se definen arreglos de tamaño fijo. El tamaño debe elegirse pensando en el máximo esperado:
- `char palabra[100]` — para palabras sueltas
- `char linea[200]` — para líneas largas
- `char nombreCompleto[100]` — para nombres

Este es el enfoque clásico de C y funciona igual en todas las versiones de C++.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `entrada_datos.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
