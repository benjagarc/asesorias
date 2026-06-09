# herencia.cpp — Compatible con Dev-C++ / GCC

## Propósito del programa

Demuestra el concepto de **herencia en POO** (Programación Orientada a Objetos):
- Clase base (`Animal`) con métodos heredables y virtuales
- Clases derivadas (`Perro`, `Gato`) que heredan y sobrescriben métodos
- Métodos propios de cada clase derivada
- **Polimorfismo** mediante punteros a la clase base y métodos `virtual`
- Destructores virtuales en **todas** las clases de la jerarquía (base y derivadas)

---

## Adaptaciones para Dev-C++ / GCC

| Código C++ moderno | Código en este archivo | Razón |
|---|---|---|
| `#include <string>` + `std::string nombre;` | `#include <cstring>` + `char nombre[50];` | Se evita `std::string` para máxima compatibilidad con GCC en modo C++98 |
| `this->nombre = nombre;` | `strcpy(this->nombre, nom);` | `char[]` no admite asignación directa; `strcpy()` copia el contenido |
| `Animal(string n, int e) : nombre(n)` | `Animal(const char* n, int e) { strcpy(nombre, n); }` | Lista de inicialización con `char[]` no funciona así; se asigna en el cuerpo |
| `std::string` en parámetros | `const char*` | Convención para pasar cadenas de solo lectura |
| `virtual void hacerSonido() const override` | `void hacerSonido() const` | `override` es de C++11; se omite para compatibilidad C++98 |
| Clase `Gato` sin destructor | `virtual ~Gato() { ... }` | **Agregado:** destructor virtual en todas las clases derivadas para garantizar que el destructor correcto se llame mediante punteros `Animal*` |
| Métodos definidos dentro de la clase (`inline`) | Declaración dentro + implementación fuera con `::` | **Estilo del proyecto:** `void Animal::comer()\n{\n    ...\n}` — llave en línea separada (Allman style) |

---

## Por qué se usó cada técnica

### `char nombre[50]` — Atributo de cadena en la clase
En lugar de `std::string`, se usa un arreglo de caracteres de tamaño fijo como miembro de clase. Es la forma de C++ clásico (compatible con Borland) de almacenar texto en objetos.

### `strcpy(nombre, nom)` — Copia de cadenas en el constructor
El operador `=` con `char[]` copia la **dirección**, no el contenido. Para copiar el texto en sí, se usa `strcpy()` de `<string.h>`:
```cpp
strcpy(destino, origen);  // Copia el contenido de 'origen' en 'destino'
```

### `const char*` en parámetros del constructor
Cuando una función recibe una cadena que no va a modificar, se declara como `const char*`. Esto permite pasar literales de texto directamente: `Animal("Cripto", 5)`.

### `virtual` y polimorfismo
Los métodos `virtual` y el polimorfismo mediante punteros a clase base son características de C++ desde sus primeras versiones. Son **100% compatibles** con Borland C++ 5.x sin ningún cambio.

### Sin `override`
La palabra clave `override` fue introducida en **C++11**. Se omite en este archivo para mantener compatibilidad con el estándar C++98/03. El polimorfismo funciona igual gracias a `virtual` en la clase base.

### Destructor `virtual` en todas las clases derivadas
Es obligatorio declarar el destructor de la clase base como `virtual` **y recomendable** hacerlo también en las clases derivadas. Esto garantiza que al destruir un `Gato` o `Perro` a través de un puntero `Animal*`, se llame el destructor correcto en toda la cadena de herencia:

```cpp
Animal* a = new Gato("Michi", 3);
delete a;  // Sin virtual ~Gato(), el destructor de Gato no se llamaria
```

Las tres clases (`Animal`, `Perro`, `Gato`) ahora declaran su destructor con `virtual` y muestran un mensaje en consola para facilitar el seguimiento del ciclo de vida de los objetos.

---

## Cómo compilar en Dev-C++

1. Abrir **Dev-C++**
2. Ir a **File → New → Project → Console Application**
3. Agregar `herencia.cpp` al proyecto (o abrir el archivo directamente)
4. Presionar **F11** para compilar y ejecutar

**Desde terminal (GCC):**
```bash
g++ -Wall -std=c++98 herencia.cpp -o herencia
./herencia
```
