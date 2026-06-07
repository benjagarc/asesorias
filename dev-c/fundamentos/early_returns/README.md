# early_returns.cpp — Migración a Borland C++

## Propósito del programa

Demuestra la técnica de **early returns** (retornos anticipados) y **guard clauses** en C++, comparando con el enfoque de `if-else` anidados:
- Validación de usuario con múltiples condiciones
- División segura con early return en caso de error
- Búsqueda en arreglo con salida temprana al encontrar el elemento
- Guard clauses en funciones `void`

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` | `#include <iostream.h>` + `#include <string.h>` | Borland requiere `.h`; `string.h` provee las funciones para cadenas `char[]` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` y `endl` son globales |
| `bool iniciarSesion(string u, string p, int edad)` | `int iniciarSesion(char* u, char* p, int edad)` | Dos cambios: `bool` → `int`; `string` → `char*` |
| `usuario.empty()` | `strlen(usuario) == 0` | Los `char[]` no tienen métodos; `strlen()` de `<string.h>` mide la longitud |
| `password.empty()` | `strlen(password) == 0` | Idem |
| `password.length() >= 6` | `strlen(password) >= 6` | `strlen()` devuelve el número de caracteres |
| `usuario == "admin"` | `strcmp(usuario, "admin") == 0` | Los `char[]` no se comparan con `==`; hay que usar `strcmp()` |
| `usuario != "admin"` | `strcmp(usuario, "admin") != 0` | `strcmp` devuelve 0 si son iguales, ≠0 si son diferentes |
| `bool hayStock`, `bool usuarioActivo` | `int hayStock`, `int usuarioActivo` | Se usan `int` en lugar de `bool` para máxima compatibilidad |
| `return true;` / `return false;` | `return 1;` / `return 0;` | Consistente con usar `int` en lugar de `bool` |
| `char usuario1[] = ""` (simulación) | Idem | No requiere cambio; `char[]` vacío ya es válido en C/C++ |

---

## Por qué se usó cada técnica

### `char*` y `char[]` en lugar de `string`
En Borland con `<iostream.h>`, `std::string` no está disponible. Los **arreglos de caracteres** (`char[]`) son la forma original de manejar texto en C/C++. Se pasan como `char*` a las funciones, que es el equivalente de un puntero al primer elemento del arreglo.

### `strlen()` — Longitud de cadena
La función `strlen()` de `<string.h>` cuenta los caracteres de un `char[]` hasta encontrar el carácter nulo `'\0'`. Reemplaza al método `.empty()` y `.length()` de `std::string`.

### `strcmp()` — Comparación de cadenas
En C/C++, el operador `==` comparar **direcciones de memoria**, no el contenido de los `char[]`. Para comparar el contenido de dos cadenas, se usa `strcmp()`:
- Devuelve `0` si son iguales
- Devuelve `< 0` si la primera es "menor"
- Devuelve `> 0` si la primera es "mayor"

### `int` en lugar de `bool`
Para máxima compatibilidad entre Borland 5.x y Turbo C++ 3.x, se usa `int` con valores `1` (true) y `0` (false). El operador ternario `? :` y los `if` funcionan igual con `int`.

### La técnica de early return en sí
La técnica de early return **no cambia** entre versiones de C++. Es un patrón de código, no una característica del lenguaje. Funciona igual en Borland, Turbo C++ y cualquier compilador moderno.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `early_returns.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
