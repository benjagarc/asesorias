# variables.cpp — Migración a Borland C++

## Propósito del programa

Demuestra los **tipos de datos primitivos** disponibles en C++:
- Enteros (`int`, `short`, `long`, `unsigned`)
- Decimales (`float`, `double`, `long double`)
- Carácter (`char`)
- Booleano (`bool` / `int` como sustituto)
- Cadenas de texto (`string` → `char[]`)
- Constantes con `const`
- `sizeof` para conocer el tamaño en bytes de cada tipo

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` | `#include <iostream.h>` | Borland requiere los encabezados con extensión `.h`; `string` STL no es necesario al usar `char[]` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` y `endl` son globales |
| `long long int muyLargo = 9000000000000` | `long int muyLargo = 2000000000L` | `long long` no existe en Borland/Turbo C++. Se usa `long int` (32 bits, máximo ~2.1 mil millones) |
| `bool esMayor = true;` | `int esMayor = 1;` | En Turbo C++ 3.x, `bool` no existe. En Borland 5.x sí existe, pero se usa `int` para máxima compatibilidad |
| `string nombre = "Juan";` | `char nombre[] = "Juan";` | `std::string` no está disponible con `iostream.h`. Se usan arreglos de `char` (cadenas estilo C) |
| `string apellido = "Pérez";` | `char apellido[] = "Perez";` | Además del cambio de tipo, se eliminó la tilde: la consola DOS muestra caracteres extendidos incorrectamente |
| `const string VERSION = "1.0.0";` | `const char* VERSION = "1.0.0";` | `std::string` no disponible; `const char*` es el equivalente en C puro |
| `float peso = 65.5f;` | `float peso = 65.5;` | El sufijo `f` es de C++98 moderno; en Borland puede generar advertencias; se omite |

---

## Por qué se usó cada técnica

### `char[]` en lugar de `string`
En Borland C++ con `<iostream.h>`, la clase `string` de la STL no está disponible o no funciona correctamente. La alternativa histórica son los **arreglos de caracteres estilo C**, que son la forma original de manejar texto en C y C++ antes de la STL.

### `int` en lugar de `bool`
El tipo `bool` fue añadido al estándar en C++98. Turbo C++ 3.x (anterior a ese estándar) no lo implementa. Borland C++ 5.x sí lo tiene, pero usar `int` con valores `0` y `1` garantiza compatibilidad máxima entre versiones antiguas del compilador.

### `long int` en lugar de `long long`
`long long` fue introducido en C++11. Borland C++ 5.x no lo soporta. El tipo más grande disponible es `long int`, que en sistemas de 32 bits almacena hasta **2,147,483,647**.

### `const char*` en lugar de `const string`
Para constantes de texto, `const char*` es el equivalente directo en C y en versiones antiguas de C++. Es eficiente y no requiere ninguna clase adicional.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `variables.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
