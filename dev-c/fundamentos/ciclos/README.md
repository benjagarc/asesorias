# ciclos.cpp — Migración a Borland C++

## Propósito del programa

Demuestra los **tres tipos de ciclos** en C++ y sus variantes:
- `for` básico, con paso personalizado, en reversa y con múltiples variables
- `for` con `break` y `continue`
- `while` y `do-while`
- Ciclos anidados (tablas de multiplicar, triángulos)
- Recorrido de arreglos con índice (equivalente al foreach moderno)

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` | `#include <iostream.h>` | Borland requiere el encabezado con extensión `.h` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout`, `cin` y `endl` son globales |
| Comentarios con acentos/tildes | Comentarios sin acentos | La consola DOS no muestra correctamente caracteres extendidos en el código fuente |

---

## Por qué se usó cada técnica

### `#include <iostream.h>`
La versión histórica de Borland C++ implementa la biblioteca de I/O como `iostream.h`. Esta versión pone todos los símbolos (`cout`, `cin`, `endl`) en el espacio de nombres **global**, no en `std`.

### Sin `using namespace std;`
Redundante e incorrecto con `<iostream.h>`: los nombres ya son globales. Agregarlo generaría un error de compilación en Borland porque el namespace `std` no existe en ese encabezado.

### Estructuras de ciclos (`for`, `while`, `do-while`)
Todas estas estructuras de control existen desde las primeras versiones de C++ y son **100% compatibles** con Borland C++ 5.x sin ningún cambio.

### `sizeof(numeros) / sizeof(numeros[0])`
Técnica estándar de C/C++ para calcular el tamaño de un arreglo nativo. Disponible en todas las versiones del lenguaje.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `ciclos.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
