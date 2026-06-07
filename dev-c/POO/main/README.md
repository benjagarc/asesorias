# main.cpp — Migración a Borland C++

## Propósito del programa

Programa mínimo ("Hello World") que sirve como **punto de partida** para cualquier proyecto en Borland C++. Demuestra la estructura básica de un programa en C++.

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` | `#include <iostream.h>` | Borland requiere el encabezado con extensión `.h` |
| `std::cout << "..." << std::endl;` | `cout << "..." << endl;` | Con `<iostream.h>`, `cout` y `endl` son globales; no se necesita el prefijo `std::` |

---

## Por qué se usó cada técnica

### `#include <iostream.h>` — El encabezado correcto en Borland

La diferencia entre las dos versiones refleja la **evolución histórica de C++**:

| Versión | Encabezado | Namespace |
|---|---|---|
| Turbo C++ / Borland C++ (antes de C++98) | `<iostream.h>` | Global (sin `std::`) |
| C++98 estándar moderno | `<iostream>` | `std::` |

El comité de estandarización de C++ decidió en 1998 mover todos los símbolos al namespace `std` y crear versiones sin `.h` de los encabezados. Borland C++ 5.x fue creado antes o al inicio de ese proceso, por lo que mantiene la versión con `.h`.

### Sin `std::`
Con `<iostream.h>`, los nombres `cout`, `cin` y `endl` están en el **espacio de nombres global**. Usar `std::cout` causaría un error de compilación en Borland porque el namespace `std` no existe en ese encabezado.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `main.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
