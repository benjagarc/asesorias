# clase-dos-pares-none.cpp — Números pares e impares con `while` y `do-while`

## Descripción general

Este programa aplica el **operador módulo (`%`)** dentro de ciclos para clasificar
números como **pares** o **impares** y mostrarlos en pantalla.

- `parConWhile()` → imprime los números **pares** del 2 al 10 usando un ciclo `while`.
- `noneConDoWhile()` → imprime los números **impares** del 1 al 9 usando un ciclo `do-while`.

---

## Librería incluida

```cpp
#include <iostream>
using namespace std;
```

`<iostream>` provee `cout` y `endl` para imprimir en consola.

---

## El operador módulo `%`

El operador `%` retorna el **residuo** de una división entera.

| Expresión | Resultado | Significado |
|---|---|---|
| `4 % 2` | `0` | 4 es par (residuo cero) |
| `5 % 2` | `1` | 5 es impar (residuo uno) |
| `7 % 2` | `1` | 7 es impar |
| `10 % 2` | `0` | 10 es par |

**Regla general:**
- `i % 2 == 0` → `i` es **par**
- `i % 2 > 0` (equivalente a `i % 2 == 1`) → `i` es **impar**

---

## Funciones

### `parConWhile()`

```cpp
void parConWhile()
{
    int i = 1;
    cout << "Imprimiendo numeros pares" << endl;
    while (i < 10)
    {
        i++;
        if ((i % 2) == 0)
        {
            cout << i << endl;
        }
    }
}
```

**¿Qué hace?**

1. `i` comienza en `1`.
2. El ciclo `while` ejecuta mientras `i < 10`.
3. **Primero incrementa** `i` con `i++`.
4. Luego verifica si `i` es par con `(i % 2) == 0`.
5. Si es par, lo imprime.
6. Repite hasta que `i` llegue a `10` (incluido) y luego la condición `i < 10` se vuelve falsa.

> **Nota:** `i` arranca en `1` y se incrementa **antes** del `if`, por eso el primer
> valor evaluado es `2`. El `1` nunca se evalúa como candidato.

#### Traza de ejecución

| Iteración | `i` antes de `i++` | `i` después de `i++` | `i % 2` | ¿Imprime? |
|-----------|-------------------|----------------------|---------|-----------|
| 1 | 1 | 2 | 0 | ✅ **2** |
| 2 | 2 | 3 | 1 | ❌ |
| 3 | 3 | 4 | 0 | ✅ **4** |
| 4 | 4 | 5 | 1 | ❌ |
| 5 | 5 | 6 | 0 | ✅ **6** |
| 6 | 6 | 7 | 1 | ❌ |
| 7 | 7 | 8 | 0 | ✅ **8** |
| 8 | 8 | 9 | 1 | ❌ |
| 9 | 9 | 10 | 0 | ✅ **10** |
| — | 10 | — | — | `i < 10` es falso → sale |

**Salida en consola:**
```
Imprimiendo numeros pares
2
4
6
8
10
```

---

### `noneConDoWhile()`

```cpp
void noneConDoWhile()
{
    int i = 0;
    cout << "Dentro de none con Do While" << endl;
    do
    {
        i++;
        if ((i % 2) > 0)
        {
            cout << i << endl;
        }

    } while (i < 10);
    cout << "Termino Do WHILE: " << i << endl;
}
```

**¿Qué hace?**

1. `i` comienza en `0`.
2. **Entra al bloque sin evaluar la condición** (característica del `do-while`).
3. Incrementa `i` con `i++`.
4. Verifica si `i` es impar con `(i % 2) > 0`.
5. Si es impar, lo imprime.
6. Al final del bloque evalúa `i < 10`. Si es verdadero, repite.
7. Cuando `i` llega a `10`, la condición se vuelve falsa y sale.
8. Imprime el mensaje final con el valor de `i`.

> **Nota:** el nombre `none` en la función hace referencia a "nones" (impares en español coloquial).

#### Traza de ejecución

| Iteración | `i` antes de `i++` | `i` después de `i++` | `i % 2` | ¿Imprime? | Condición `i < 10` |
|-----------|-------------------|----------------------|---------|-----------|-------------------|
| 1 | 0 | 1 | 1 | ✅ **1** | ✅ continúa |
| 2 | 1 | 2 | 0 | ❌ | ✅ continúa |
| 3 | 2 | 3 | 1 | ✅ **3** | ✅ continúa |
| 4 | 3 | 4 | 0 | ❌ | ✅ continúa |
| 5 | 4 | 5 | 1 | ✅ **5** | ✅ continúa |
| 6 | 5 | 6 | 0 | ❌ | ✅ continúa |
| 7 | 6 | 7 | 1 | ✅ **7** | ✅ continúa |
| 8 | 7 | 8 | 0 | ❌ | ✅ continúa |
| 9 | 8 | 9 | 1 | ✅ **9** | ✅ continúa |
| 10 | 9 | 10 | 0 | ❌ | ❌ sale |

**Salida en consola:**
```
Dentro de none con Do While
1
3
5
7
9
Termino Do WHILE: 10
```

---

## Función `main()`

```cpp
int main()
{
    parConWhile();
    noneConDoWhile();
    return 0;
}
```

Simplemente llama a las dos funciones en orden y retorna `0` para indicar
que el programa terminó correctamente.

**Salida completa del programa:**
```
Imprimiendo numeros pares
2
4
6
8
10
Dentro de none con Do While
1
3
5
7
9
Termino Do WHILE: 10
```

---

## Declaraciones anticipadas (prototipos)

```cpp
void parConWhile();
void noneConDoWhile();
```

Estas líneas al inicio del archivo se llaman **prototipos** o **declaraciones anticipadas**.
Le dicen al compilador que esas funciones existen **antes** de que las encuentre definidas,
lo que permite llamarlas desde `main()` aunque estén definidas más abajo en el archivo.

---

## Comparación entre ambas funciones

| Aspecto | `parConWhile()` | `noneConDoWhile()` |
|---|---|---|
| Tipo de ciclo | `while` | `do-while` |
| `i` inicial | `1` | `0` |
| Condición de salida | `i < 10` (evalúa antes) | `i < 10` (evalúa después) |
| Filtro | `i % 2 == 0` → pares | `i % 2 > 0` → impares |
| Números impresos | 2, 4, 6, 8, 10 | 1, 3, 5, 7, 9 |
