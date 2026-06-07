# inventario_csv.cpp — Migración a Borland C++

## Propósito del programa

Sistema **CRUD (Crear, Leer, Actualizar, Eliminar)** de inventario usando un archivo CSV como base de datos persistente. Demuestra:
- Clases con métodos estáticos (`static`)
- Lectura y escritura de archivos con `fstream`
- Parseo de cadenas CSV
- Menú interactivo con `do-while`
- Paso por referencia en funciones (`GestorCSV&`)

---

## Cambios realizados

Este es el archivo con **más cambios estructurales** de toda la migración:

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include<iostream>` | `#include <iostream.h>` | Borland requiere `.h` |
| `#include<fstream>` | `#include <fstream.h>` | Borland requiere `.h` |
| `#include<string>` | `#include <string.h>` | Se usa `strcpy`, `strlen`, `strtok` de C |
| `#include<sstream>` | `#include <stdio.h>` | `sstream` no existe en Borland; se usa `sprintf` |
| `#include<cstdlib>` | `#include <stdlib.h>` | Nombre con `.h` para Borland |
| `using namespace std;` | *(eliminado)* | Con `iostream.h`, los símbolos son globales |
| `string nombre;` en clase | `char nombre[100];` | `std::string` no disponible |
| `string nombreArchivo;` en clase | `char nombreArchivo[200];` | Idem |
| `ostringstream oss; oss << codigo << "," << nombre...` | `sprintf(buffer, "%d,%s,%.2f", codigo, nombre, precio)` | `ostringstream` no existe; `sprintf` escribe texto formateado en un buffer |
| `return oss.str();` | Escribe en `char* buffer` pasado como parámetro | `sprintf` no devuelve string; escribe en un buffer externo |
| `string toCSV()` devuelve string | `void toCSV(char* buffer, int bufSize)` | Escribe en buffer en lugar de retornar string |
| `stringstream ss(linea); getline(ss, parte, ',')` | `strtok(copia, ",")` | `sstream` no existe; `strtok` divide una cadena en tokens |
| `linea == ""` | `strlen(linea) == 0` | `char[]` no tiene operador `==` con literales |
| `string contenidoNuevo = ""; contenidoNuevo += linea + "\n"` | `char lineas[MAX_LINEAS][300];` + bucle de copia | Sin concatenación de strings; se usa un arreglo 2D de `char` |
| `ifstream archivo(nombreArchivo.c_str())` | `ifstream archivo(nombreArchivo)` | `char[]` ya es `char*`; `.c_str()` innecesario |
| `cin.ignore(numeric_limits<streamsize>::max(), '\n')` | `cin.ignore(255, '\n')` | `numeric_limits` no existe en Borland |
| `getline(cin, nombre)` | `cin.getline(nombre, 100)` | Versión de método con `char[]` |

---

## Por qué se usó cada técnica

### `sprintf()` en lugar de `ostringstream`
`ostringstream` (de `<sstream>`) es una clase que construye un `string` paso a paso con el operador `<<`. En Borland, `<sstream>` no existe. `sprintf()` de `<stdio.h>` hace lo mismo pero escribiendo en un buffer de `char`:

```cpp
// C++ moderno:
ostringstream oss;
oss << codigo << "," << nombre << "," << precio;
string resultado = oss.str();

// Borland:
char buffer[300];
sprintf(buffer, "%d,%s,%.2f", codigo, nombre, precio);
// buffer ahora contiene "101,Leche,25.50"
```

`sprintf` usa **especificadores de formato** al estilo de `printf`:
- `%d` → entero (`int`)
- `%s` → cadena (`char*`)
- `%.2f` → flotante con 2 decimales

### `strtok()` en lugar de `stringstream + getline`
`strtok()` de `<string.h>` divide una cadena en **tokens** (partes) separados por un delimitador:

```cpp
char copia[] = "101,Leche,25.50";
char* token1 = strtok(copia, ",");  // "101"
char* token2 = strtok(NULL,  ",");  // "Leche"
char* token3 = strtok(NULL,  ",");  // "25.50"
```

> **Importante:** `strtok` **modifica** la cadena original (inserta `'\0'` en los separadores). Por eso se trabaja sobre una **copia** de la línea.

### `char lineas[MAX_LINEAS][300]` — Buffer de líneas
Para las operaciones de actualizar y eliminar, el original acumulaba el nuevo contenido en un `string`. En Borland, se usa un **arreglo 2D de caracteres**:
- Primera dimensión: hasta 200 líneas (`MAX_LINEAS = 200`)
- Segunda dimensión: hasta 300 caracteres por línea

Esto permite leer todas las líneas, modificar o filtrar las necesarias, y luego reescribir el archivo completo.

### `archivo.getline(linea, 300)` en lugar de `getline(archivo, linea)`
La función global `getline(istream&, string&)` requiere `std::string`. Con `char[]`, se usa el método `getline()` del objeto `ifstream` directamente, que recibe un buffer y su tamaño.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `inventario_csv.cpp` al proyecto
4. Crear un archivo `productos.csv` vacío en la carpeta del proyecto
5. Presionar **F9** para compilar y ejecutar

> **Nota:** El archivo `productos.csv` debe estar en el mismo directorio donde se ejecuta el programa.
