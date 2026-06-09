# inventario_csv.cpp — Compatible con Dev-C++ / GCC

## Propósito del programa

Sistema **CRUD (Crear, Leer, Actualizar, Eliminar)** de inventario usando un archivo CSV como base de datos persistente. Demuestra:
- Clases con métodos estáticos (`static`)
- Lectura y escritura de archivos con `fstream`
- Parseo de cadenas CSV
- Menú interactivo con `do-while`
- Paso por referencia en funciones (`GestorCSV&`)

---

## Adaptaciones para Dev-C++ / GCC

Este archivo utiliza técnicas de C clásico (`char[]`, `strtok`, `sprintf`) compatibles con GCC/MinGW en Dev-C++:

| Código C++ moderno | Código en este archivo | Razón |
|---|---|---|
| `#include <iostream>` | `#include <iostream>` | Estándar GCC sin `.h` |
| `#include <fstream>` | `#include <fstream>` | Estándar GCC sin `.h` |
| `#include <string>` | `#include <cstring>` | Se usa `strcpy`, `strlen`, `strtok` de C |
| `#include <sstream>` | `#include <cstdio>` | `sstream` existe pero se usa `snprintf` para máxima compatibilidad |
| `string nombre;` en clase | `char nombre[100];` | `std::string` se evita para compatibilidad C++98 |
| `string nombreArchivo;` en clase | `char nombreArchivo[200];` | Idem |
| `ostringstream oss; oss << codigo << ","...` | `snprintf(buffer, bufSize, "%d,%s,%.2f", ...)` | **`snprintf` con límite de buffer** en lugar de `sprintf` sin límite |
| `return oss.str();` | Escribe en `char* buffer` pasado como parámetro | `snprintf` escribe en un buffer externo |
| `string toCSV()` devuelve string | `void toCSV(char* buffer, int bufSize)` | Escribe en buffer; `bufSize` se usa en `snprintf` para evitar overflow |
| `stringstream ss(linea); getline(ss, parte, ',')` | `strtok(copia, ",")` | Técnica de C clásico para dividir cadenas en tokens |
| `linea == ""` | `strlen(linea) == 0` | `char[]` no tiene operador `==` con literales |
| `string contenidoNuevo += linea + "\n"` | `char lineas[MAX_LINEAS][300];` + bucle de copia | Sin concatenación de strings; se usa arreglo 2D de `char` |
| `ifstream archivo(nombreArchivo.c_str())` | `ifstream archivo(nombreArchivo)` | `char[]` ya es `char*`; `.c_str()` innecesario |
| `cin.ignore(numeric_limits<streamsize>::max(), '\n')` | `cin.ignore(255, '\n')` | Evita depender de `<limits>` |
| `getline(cin, nombre)` | `cin.getline(nombre, 100)` | Versión del método para `char[]` |

---

## Por qué se usó cada técnica

### `snprintf()` en lugar de `sprintf()`
`sprintf()` escribe en un buffer sin verificar su tamaño, lo que puede causar **buffer overflow** si el contenido es demasiado largo. `snprintf()` recibe el tamaño máximo como segundo argumento:

```cpp
// Antes (inseguro - no verifica el tamaño del buffer):
char buffer[300];
springf(buffer, "%d,%s,%.2f", codigo, nombre, precio);

// Ahora (seguro - respeta el tamaño declarado):
snprintf(buffer, bufSize, "%d,%s,%.2f", codigo, nombre, precio);
// buffer ahora contiene "101,Leche,25.50" y no puede exceder bufSize bytes
```

El parámetro `bufSize` ya existía en la firma `void toCSV(char* buffer, int bufSize)` pero era ignorado. Ahora se usa correctamente en `snprintf`.

`snprintf` usa los mismos **especificadores de formato** que `printf`:
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

## Cómo compilar en Dev-C++

1. Abrir **Dev-C++**
2. Ir a **File → New → Project → Console Application**
3. Agregar `inventario_csv.cpp` al proyecto
4. Crear un archivo `productos.csv` vacío en la carpeta del proyecto
5. Presionar **F11** para compilar y ejecutar

**Desde terminal (GCC):**
```bash
g++ -Wall -std=c++98 inventario_csv.cpp -o inventario_csv
./inventario_csv
```

> **Nota:** El archivo `productos.csv` debe estar en el mismo directorio donde se ejecuta el programa.
