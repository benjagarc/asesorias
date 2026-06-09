# prueba-herencia.cpp — Compatible con Dev-C++ / GCC

## Propósito del programa

Demuestra herencia con un ejemplo cotidiano: **pasatiempos**. Muestra cómo la clase derivada `EscucharMusica` hereda de `Pasatiempo` y agrega su propio atributo (`genero`) y sobrescribe el método `mostrarLugar()`.

---

## Adaptaciones para Dev-C++ / GCC

| Código C++ moderno | Código en este archivo | Razón |
|---|---|---|
| `#include <string>` + `std::string nombre;` | `#include <cstring>` + `char nombre[50];` | Se evita `std::string` para compatibilidad C++98 |
| `std::string lugar;` | `char lugar[100];` | Idem |
| `std::string genero;` | `char genero[50];` | Idem |
| `Pasatiempo(string n, string l) : nombre(n), lugar(l)` | `Pasatiempo(const char* n, const char* l) { strcpy(nombre,n); strcpy(lugar,l); }` | `char[]` no se puede inicializar con lista ``: nombre(n)``; se usa `strcpy()` en el cuerpo |
| `EscucharMusica(string n, string l, string g) : Pasatiempo(n,l), genero(g)` | `EscucharMusica(const char* n, const char* l, const char* g) : Pasatiempo(n,l) { strcpy(genero,g); }` | Idem |
| `void mostrarLugar() const override` | `void mostrarLugar() const` | `override` es de C++11; se omite para compatibilidad C++98 |
| `void mostrarGenero()` sin `const` | `void mostrarGenero() const` | **Agregado `const`:** el método solo lee `genero`; `const` permite llamarlo sobre objetos constantes y es consistente con el resto de métodos de lectura |
| Métodos definidos dentro de la clase (`inline`) | Declaración dentro + implementación fuera con `::` | **Estilo del proyecto:** `void Pasatiempo::mostrarInfo()\n{\n    ...\n}` — llave en línea separada (Allman style) |
| `    protected:` / `    public:` con sangría extra | `protected:` / `public:` sin sangría | **Estilo del proyecto:** las etiquetas de acceso van al mismo nivel que `class` |

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

### Métodos `const` de solo lectura
Cuando un método **no modifica** ningún atributo del objeto, se declara como `const`. Esto tiene dos ventajas:
1. Puede llamarse sobre objetos declarados como `const`.
2. Comunica claramente al lector que el método es de solo lectura.

```cpp
// Sin const: no puede llamarse en objetos constantes
void mostrarGenero();

// Con const: correcto para un metodo de solo lectura
void mostrarGenero() const;
```

Todos los métodos de este archivo que solo leen atributos (`mostrarInfo`, `mostrarLugar`, `mostrarGenero`) son `const` por consistencia.

### La lista de inicialización del constructor base `: Pasatiempo(nom, lug)`
Esta parte **sí se mantiene** incluso con `char[]`. La lista de inicialización llama al constructor de la clase base pasando los parámetros. El constructor base luego usa `strcpy()` para copiar las cadenas en sus propios `char[]`.

---

## Cómo compilar en Dev-C++

1. Abrir **Dev-C++**
2. Ir a **File → New → Project → Console Application**
3. Agregar `prueba-herencia.cpp` al proyecto
4. Presionar **F11** para compilar y ejecutar

**Desde terminal (GCC):**
```bash
g++ -Wall -std=c++98 prueba-herencia.cpp -o prueba-herencia
./prueba-herencia
```
