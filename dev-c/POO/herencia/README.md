# herencia.cpp — Migración a Borland C++

## Propósito del programa

Demuestra el concepto de **herencia en POO** (Programación Orientada a Objetos):
- Clase base (`Animal`) con métodos heredables y virtuales
- Clases derivadas (`Perro`, `Gato`) que heredan y sobrescriben métodos
- Métodos propios de cada clase derivada
- **Polimorfismo** mediante punteros a la clase base y métodos `virtual`
- Destructores virtuales (buena práctica en jerarquías de herencia)

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` + `#include <string>` | `#include <iostream.h>` + `#include <string.h>` | Borland requiere `.h`; `string.h` provee `strcpy()` |
| `std::string nombre;` | `char nombre[50];` | `std::string` no disponible; `char[]` con tamaño fijo |
| `std::string raza;` | `char raza[50];` | Idem |
| `std::cout`, `std::endl` | `cout`, `endl` | Sin prefijo `std::` con `<iostream.h>` |
| `Animal(std::string nombre, int edad) : nombre(nombre), edad(edad)` | `Animal(const char* nom, int ed) { strcpy(nombre, nom); edad = ed; }` | Dos cambios: parámetro `const char*`; inicializador de lista → asignación en cuerpo |
| `: nombre(nombre)` (inicializador de lista para string) | `strcpy(nombre, nom);` | Los inicializadores de lista para `char[]` no funcionan así; se usa `strcpy()` del cuerpo |
| `std::string` en parámetros | `const char*` | Convención para pasar cadenas de solo lectura a funciones |
| `"¡Guau guau!"` | `"Guau guau!"` | Sin `¡` (carácter no ASCII básico) |
| `virtual void hacerSonido() const override` | `void hacerSonido() const` | `override` es de C++11; en Borland se omite, la semántica es la misma |
| Código comentado en `main` | Se descomentó el código | Se aprovechó para mostrar el ejemplo completo funcionando |

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
La palabra clave `override` fue introducida en **C++11** para detectar errores al sobrescribir métodos virtuales. Borland C++ 5.x no la reconoce. La omisión no afecta el comportamiento: el polimorfismo funciona igual gracias a la palabra `virtual` en la clase base.

### Destructor `virtual`
Es una buena práctica declarar el destructor de la clase base como `virtual`. Esto garantiza que cuando se elimina un objeto derivado a través de un puntero a la clase base, se llama el destructor correcto. Esta práctica es igual en todas las versiones de C++.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `herencia.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
