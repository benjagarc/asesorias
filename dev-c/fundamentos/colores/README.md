# colores.cpp — Migración a Borland C++

## Propósito del programa

Demuestra cómo aplicar **colores y estilos de texto** en la consola de Borland C++:
- Colores básicos y brillantes de texto
- Colores de fondo
- Combinaciones texto + fondo (badges de estado)
- Mensajes de estado con prefijos visuales
- Importancia de resetear colores al final

---

## Cambios realizados

| Código original (C++ moderno) | Código Borland C++ | Razón |
|---|---|---|
| `#include <iostream>` | `#include <iostream.h>` + `#include <conio.h>` | Borland requiere `.h`; `conio.h` provee `textcolor()` y `textbackground()` |
| `using namespace std;` | *(eliminado)* | Con `<iostream.h>`, `cout` ya es global |
| `const string ROJO = "\033[31m";` | *(eliminado)* — sustituido por `textcolor(RED)` | Los códigos ANSI no funcionan en la consola DOS/Borland |
| `const string RESET = "\033[0m";` | `textcolor(LIGHTGRAY); textbackground(BLACK);` | No existe RESET como código ANSI en Borland; se restablece manualmente |
| `cout << ROJO << "texto" << RESET` | `textcolor(RED); cprintf("texto\r\n");` | `cprintf` respeta los colores establecidos por `textcolor()` |
| `NEGRITA + ROJO` (concatenación de strings) | `textcolor(RED);` (llamada directa) | Los colores en Borland son estados del terminal, no strings concatenables |
| `"✓"`, `"⚠"`, `"✗"` (Unicode) | `"[OK]"`, `"[!!]"`, `"[XX]"` | La consola DOS no soporta Unicode; se usan equivalentes ASCII |
| Colores brillantes con `\033[91m..97m` | `LIGHTRED`, `LIGHTGREEN`, etc. | Las constantes `LIGHT*` de `conio.h` son el equivalente en Borland |

---

## Por qué se usó cada técnica

### `<conio.h>` — La librería de consola de Borland
`conio.h` (**Console I/O**) es una biblioteca **específica de Borland/Turbo C++** (y de compiladores de DOS/Windows) que provee funciones para controlar directamente la consola:

| Función | Descripción |
|---|---|
| `textcolor(n)` | Cambia el color del texto (0–15) |
| `textbackground(n)` | Cambia el color de fondo (0–7) |
| `cprintf(fmt, ...)` | Imprime texto respetando los colores activos |
| `clrscr()` | Limpia la pantalla |
| `gotoxy(x, y)` | Mueve el cursor a una posición específica |

### Por qué `cprintf` en lugar de `cout`
`cout` de `<iostream.h>` no respeta los colores establecidos por `textcolor()`. Para que el texto aparezca con el color correcto, hay que usar **`cprintf()`**, que es parte de `conio.h` y sí interactúa con la paleta de colores de la consola DOS.

### Constantes de color de `conio.h`
```
BLACK=0    BLUE=1      GREEN=2     CYAN=3
RED=4      MAGENTA=5   BROWN=6     LIGHTGRAY=7
DARKGRAY=8 LIGHTBLUE=9 LIGHTGREEN=10 LIGHTCYAN=11
LIGHTRED=12 LIGHTMAGENTA=13 YELLOW=14 WHITE=15
```

### `LIGHTGRAY` como "reset"
En Borland, no existe un código de "reset". El color por defecto de la consola es `LIGHTGRAY` sobre `BLACK`, por lo que restaurar esos valores es equivalente al `\033[0m` de los terminales modernos.

### Sin caracteres Unicode
La consola DOS usa la **página de código 437** (ASCII extendido), que no incluye `✓`, `⚠` ni `✗`. Se reemplazan por texto ASCII: `[OK]`, `[!!]`, `[XX]`, `[ii]`.

---

## Cómo compilar en Borland C++ 5.x

1. Abrir **Borland C++ IDE**
2. Crear un nuevo proyecto de tipo **Console Application**
3. Agregar `colores.cpp` al proyecto
4. Presionar **F9** para compilar y ejecutar

> **Nota:** Este programa requiere ejecutarse dentro de la consola de Borland o en una ventana de DOS para que los colores se muestren correctamente.
