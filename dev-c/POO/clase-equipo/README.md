# clase-equipo.cpp — Migración a Borland C++

## Propósito del programa

Demuestra la **definición de clases con métodos externos** en C++ usando el operador de resolución de ámbito `::`. La clase `EquipoDeFutbol` modela un equipo con atributos y comportamientos básicos:
- Constructor y destructor explícitos
- Métodos definidos fuera del cuerpo de la clase
- Uso del operador `::` para asociar métodos a su clase

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include<iostream>` + `#include<string>` | `#include <iostream.h>` + `#include <string.h>` | Borland requiere `.h`; `string.h` provee `strcpy()` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` es global |
| `string nombre;` | `char nombre[50];` | `std::string` no disponible; `char[]` con tamaño fijo |
| `string categoria;` | `char categoria[50];` | Idem |
| Parámetros `string` en constructor | `const char*` | Tipo correcto para cadenas en Borland |
| `this->nombre = nombre;` | `strcpy(nombre, nom);` | `char[]` no soporta asignación con `=`; se usa `strcpy()` |
| `this->categoria = categoria;` | `strcpy(categoria, cat);` | Idem |
| `this->campeonatos = campeonatos;` | `campeonatos = camp;` | `int` sí soporta `=`; se usa nombre de parámetro diferente para evitar ambigüedad |

---

## Por qué se usó cada técnica

### Definición externa de métodos con `::`
La sintaxis `NombreClase::NombreMetodo()` para definir métodos **fuera** del cuerpo de la clase es compatible con todas las versiones de C++, incluyendo Borland. Es una forma de separar la **declaración** (en la clase) de la **implementación** (en el archivo `.cpp` o más abajo en el mismo archivo).

### `const char*` en parámetros del constructor
Al declarar el constructor con `const char* nom`, la función:
1. Recibe un puntero al inicio de una cadena de caracteres
2. El `const` garantiza que no modificará los caracteres apuntados
3. Permite pasar literales como `"mexico"` directamente

### `strcpy()` en lugar de `this->nombre = nombre`
Los `char[]` en C/C++ no soportan el operador `=` para copiar contenido (copiaría la dirección del puntero, no los caracteres). `strcpy(destino, origen)` copia carácter por carácter hasta el terminador nulo `'\0'`.

En el original, `this->nombre = nombre` funcionaba porque `nombre` era `std::string`, que tiene sobrecargado el operador `=`. Con `char[]`, eso no aplica.

### Nombre de parámetros distintos al del miembro
Para evitar ambigüedad entre el parámetro `nom` y el miembro `nombre`, se usa un nombre de parámetro diferente. En el código original con `string`, `this->nombre = nombre` era explícito. Con `char[]` y `strcpy()`, se evita la confusión usando nombres distintos.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `clase-equipo.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar
