# alias_cout_cin.cpp — Migración a Borland C++

## Propósito del programa

Demuestra las distintas formas de **referirse a `cout` y `cin`** en C++:
1. Acceso directo (global en Borland)
2. Referencias (`ostream&`, `istream&`)
3. Punteros (`ostream*`, `istream*`)
4. `typedef` como alias de tipo
5. `#define` como macro de preprocesador

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` | `#include <iostream.h>` + `#include <string.h>` | Borland requiere los encabezados con extensión `.h` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, todos los símbolos son globales |
| `using std::cout; using std::cin; using std::endl;` | *(eliminado)* | Innecesario: ya son globales con Borland |
| `std::ostream& out = std::cout;` | `ostream& out = cout;` | Sin el prefijo `std::` porque no existe el namespace en la versión Borland |
| `std::istream& in = std::cin;` | `istream& in = cin;` | Idem |
| `std::ostream* pOut = &std::cout;` | `ostream* pOut = &cout;` | Idem |
| `std::istream* pIn = &std::cin;` | `istream* pIn = &cin;` | Idem |
| `typedef std::ostream TipoCout;` | `typedef ostream TipoCout;` | Sin prefijo `std::` |
| `typedef std::istream TipoCin;` | `typedef istream TipoCin;` | Sin prefijo `std::` |
| `string palabra;` → `*pIn >> palabra;` | `char palabra[100];` → `*pIn >> palabra;` | `std::string` no está disponible con `<iostream.h>`; se usa `char[]` |
| `auto& out = cout;` (C++11) | *(eliminado del resumen)* | `auto` como deducción de tipo no existe en Borland; solo se documenta la diferencia |
| `using T = decltype(cout);` (C++11) | *(eliminado del resumen)* | `decltype` no existe en Borland; `typedef` es el equivalente C++98 |

---

## Por qué se usó cada técnica

### `ostream&` y `istream&` sin prefijo `std::`
En Borland C++ con `<iostream.h>`, los tipos `ostream` e `istream` **no están dentro del namespace `std`**. Están en el espacio de nombres global. Por eso se escriben directamente sin el prefijo `std::`.

### `char palabra[100]` en lugar de `string`
La clase `std::string` es parte de la **STL estándar** y requiere `#include <string>` (sin `.h`). Este encabezado no está disponible en Borland con su sistema de headers `.h`. La alternativa es usar arreglos de caracteres estilo C.

### `typedef ostream TipoCout`
El `typedef` es la forma de C++98 para crear alias de tipos. En C++11 se introdujo `using T = tipo;`, pero Borland no soporta esa sintaxis. `typedef` funciona perfectamente en Borland.

### `#define IMPRIMIR cout`
Las macros del preprocesador (`#define`) existen desde C y son totalmente compatibles con cualquier versión de C++, incluyendo Borland. Se incluyen solo como referencia educativa, ya que **no se recomienda** en código real por la falta de verificación de tipos.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `alias_cout_cin.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
