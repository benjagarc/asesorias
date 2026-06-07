# prueba-herencia.cpp — Migración a Borland C++

## Propósito del programa

Demuestra herencia con un ejemplo cotidiano: **pasatiempos**. Muestra cómo la clase derivada `EscucharMusica` hereda de `Pasatiempo` y agrega su propio atributo (`genero`) y sobrescribe el método `mostrarLugar()`.

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` | `#include <iostream.h>` + `#include <string.h>` | Borland requiere `.h`; `string.h` provee `strcpy()` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` y `endl` son globales |
| `std::string nombre;` | `char nombre[50];` | `std::string` no disponible con `<iostream.h>` |
| `std::string lugar;` | `char lugar[100];` | Idem |
| `std::string genero;` | `char genero[50];` | Idem |
| `Pasatiempo(string nom, string lug) : nombre(nom), lugar(lug)` | `Pasatiempo(const char* nom, const char* lug) { strcpy(nombre,nom); strcpy(lugar,lug); }` | `char[]` no se puede inicializar con lista `: nombre(nom)`; se usa `strcpy()` en el cuerpo |
| `EscucharMusica(string n, string l, string g) : Pasatiempo(n,l), genero(g)` | `EscucharMusica(const char* n, const char* l, const char* g) : Pasatiempo(n,l) { strcpy(genero,g); }` | Idem |
| `std::string` en el tipo de retorno implícito | `char[]` gestionado manualmente | Sin cambios adicionales necesarios en la lógica |
| `void mostrarLugar() const override` | `void mostrarLugar() const` | `override` es de C++11; se omite en Borland |

---

## Por qué se usó cada técnica

### Inicialización de `char[]` en constructores
En C++, los miembros que son **arreglos de caracteres** (`char[]`) no pueden inicializarse mediante la lista de inicialización del constructor (`: nombre(nom)` solo funciona para tipos con constructor propio, como `std::string`). La solución en Borland es inicializarlos en el **cuerpo del constructor** con `strcpy()`:

```cpp
// C++ moderno con string:
Pasatiempo(string nom) : nombre(nom) {}

// Borland con char[]:
Pasatiempo(const char* nom) {
    strcpy(nombre, nom);
}
```

### `const char*` vs `string` en parámetros
`const char*` es un **puntero a caracteres constantes** — es decir, la función puede leer los caracteres pero no modificarlos. Esto permite pasar literales de texto como `"rock"` directamente:
```cpp
EscucharMusica("escuchar musica", "donde sea", "rock");
```

### La lista de inicialización del constructor base `: Pasatiempo(nom, lug)`
Esta parte **sí se mantiene** incluso con `char[]`. La lista de inicialización llama al constructor de la clase base pasando los parámetros. El constructor base luego usa `strcpy()` para copiar las cadenas en sus propios `char[]`.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `prueba-herencia.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
