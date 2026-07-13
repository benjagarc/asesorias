#include <stdio.h>
#include <stdlib.h>  
#include <time.h> // Incluida para inicializar los números aleatorios

// Definimos el tamaño como una constante para evitar números mágicos
#define TAM 5

/* 
 * FUNCIÓN: llenarMatriz
 * DESCRIPCIÓN: Llena una matriz bidimensional con números aleatorios entre 1 y 9.
 * PARÁMETROS: 
 *   - int arregloBidi[TAM][TAM]: La matriz que se va a modificar (paso por referencia implícito).
 */
void llenarMatriz(int arregloBidi[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            // rand() % 9 genera números de 0 a 8. Al sumar 1, el rango queda de 1 a 9.
            arregloBidi[i][j] = rand() % 9 + 1;
        }
    }
}

/* 
 * FUNCIÓN: imprimirMatriz
 * DESCRIPCIÓN: Recorre una matriz bidimensional y la muestra en la consola con formato de tabla.
 * PARÁMETROS: 
 *   - int arregloBidi[TAM][TAM]: La matriz que se desea visualizar.
 */
void imprimirMatriz(int arregloBidi[TAM][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            // Se usa %2d para que los números queden alineados visualmente en columnas
            printf("%2d ", arregloBidi[i][j]);
        }
        printf("\n"); // Salto de línea al terminar cada fila
    }
}

/* 
 * FUNCIÓN: multiplicarMatrices
 * DESCRIPCIÓN: Realiza el producto matricial clásico entre dos matrices cuadradas (A x B).
 *              Multiplica cada elemento de la fila i de la matriz A por la columna j de la matriz B,
 *              y acumula la suma de esos productos en la celda [i][j] de la matriz resultante.
 * PARÁMETROS:
 *   - int matA[TAM][TAM]: Primera matriz operante (izquierda).
 *   - int matB[TAM][TAM]: Segunda matriz operante (derecha).
 *   - int matResult[TAM][TAM]: Matriz donde se almacenará el resultado definitivo del producto.
 */
void multiplicarMatrices(int matA[TAM][TAM], int matB[TAM][TAM], int matResult[TAM][TAM])
{
    // i recorre las filas de la matriz A
    for (int i = 0; i < TAM; i++)
    {
        // j recorre las columnas de la matriz 
        // [0,1] * [1,0]

        for (int j = 0; j < TAM; j++)
        {
            // Es vital inicializar la celda acumuladora en 0 antes de sumar los productos
            matResult[i][j] = 0;
            
            // k sirve para iterar de manera simultánea en la columna de A y la fila de B
            for (int k = 0; k < TAM; k++)
            // i = 0
            // j = 0
            // k = 1
            // [0,1]
            // [1,0]
            // [i,j] = 3 * 9 = 27
            // [i,j] = 1 * 6 = 6
            // [i,j] = 6 *4 = 24
            // [i,j] = 3 * 2 = 6
            // [i , j] = 8 * 6 = 48

            {
                matResult[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main()
{
    // Inicializa la semilla del generador de números aleatorios basándose en la hora del sistema.
    // Esto evita que el programa genere exactamente las mismas matrices cada vez que lo abras.
    srand(time(NULL));

    // Declaración de las matrices necesarias
    int arregloBidiA[TAM][TAM];
    int arregloBidiB[TAM][TAM];
    int arregloBidiResultado[TAM][TAM];

    // 1. Llenamos y mostramos la Matriz A
    llenarMatriz(arregloBidiA);
    printf("Matriz Uno (A):\n");
    imprimirMatriz(arregloBidiA);
    printf("\n");

    // 2. Llenamos y mostramos la Matriz B
    llenarMatriz(arregloBidiB);
    printf("Matriz Dos (B):\n");
    imprimirMatriz(arregloBidiB);
    printf("\n");

    // 3. Ejecutamos la multiplicación guardando los datos en la matriz resultado
    multiplicarMatrices(arregloBidiA, arregloBidiB, arregloBidiResultado);

    // 4. Mostramos el resultado final en consola
    printf("Resultado de la Multiplicación (A x B):\n");
    imprimirMatriz(arregloBidiResultado);

    // Esperar interacción del usuario antes de cerrar
    printf("\nPresiona Enter para salir...");
    getchar();

    return 0;
}