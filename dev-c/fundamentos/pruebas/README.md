# pruebas.cpp — Migración a Borland C++

## Propósito del programa

Archivo de **pruebas y borradores** de clase. Contiene experimentos comentados sobre:
- Operaciones aritméticas básicas con entrada del usuario
- Ciclos `for` anidados para tablas de multiplicar
- Lectura y muestra de arreglos

Todo el código está comentado porque era código experimental de práctica.

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` | `#include <iostream.h>` | Borland requiere la extensión `.h` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` y `cin` son globales |
| `int arreglo[tamano];` (VLA) | `int arreglo[MAX_TAMANO];` con constante | Los **VLA (Variable Length Arrays)** no son válidos en Borland C++/Turbo C++ |

---

## Por qué se usó cada técnica

### `#include <iostream.h>`
Cambio estándar para Borland: todos los encabezados de I/O requieren la extensión `.h`.

### Sin `using namespace std;`
Con `<iostream.h>` en Borland, `cout`, `cin` y `endl` ya están en el espacio de nombres global.

### `int arreglo[MAX_TAMANO]` — Arreglo de tamaño constante

> [!IMPORTANT]
> Este es el cambio más importante del archivo.

El código original tenía `int arreglo[tamano]` donde `tamano` es una variable leída con `cin`. Esto se llama **VLA (Variable Length Array)** y fue añadido en C99 (para C) y opcionalmente en C++14. Sin embargo:

- **Turbo C++ 3.x**: No soporta VLA
- **Borland C++ 5.x**: No soporta VLA (es anterior al estándar que los introdujo)
- **MSVC (Visual Studio)**: No soporta VLA
- **GCC/Clang**: Sí los soporta como extensión

**Solución en Borland**: Declarar el arreglo con una constante máxima:
```cpp
const int MAX_TAMANO = 100;
int arreglo[MAX_TAMANO];  // Siempre 100 slots
```
Y luego usar solo `tamano` posiciones (las que el usuario indicó).

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `pruebas.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar

> **Nota:** Al estar todo el código comentado, el programa compila pero no produce salida. Para activar cualquier sección, eliminar los comentarios `/* */` de la sección deseada.
