# clase-uno.cpp — Migración a Borland C++

## Propósito del programa

Demuestra el uso básico del **ciclo `for`** en C++:
- Recorrido de 2 en 2
- Tabla de multiplicar
- Impresión de números pares e impares
- Uso del operador módulo `%` para filtrar valores

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` | `#include <iostream.h>` | Borland C++ 5.x requiere el encabezado con extensión `.h`. La versión sin extensión corresponde al estándar C++98 actualizado que Borland no implementa completamente. |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, Borland expone `cout`, `cin` y `endl` en el espacio de nombres global directamente. No es necesario (ni siempre válido) usar `using namespace std;`. |

---

## Por qué se usó cada técnica

### `#include <iostream.h>`
Borland C++ 5.x (y Turbo C++ 3.x) fueron creados antes de que el comité de C++ estandarizara los encabezados sin extensión `.h` (eso ocurrió en C++98). Por eso, la biblioteca de entrada/salida se llama `iostream.h` y no `iostream`.

### Sin `using namespace std;`
Cuando se incluye `<iostream.h>` (la versión de Borland), los símbolos `cout`, `cin`, `endl`, etc., ya están disponibles globalmente. Añadir `using namespace std;` sería incorrecto porque el espacio de nombres `std` no existe en esa versión del encabezado.

### Ciclos `for` con variable declarada en el `for`
La declaración `for (int i = ...)` fue introducida en C++ desde sus primeras versiones y es compatible con Borland C++ 5.x sin ningún cambio.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `clase-uno.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
