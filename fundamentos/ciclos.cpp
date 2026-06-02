#include <iostream>

using namespace std;

int main() {
    // ========== CICLO FOR ==========
    // Estructura: for (inicialización; condición; incremento)
    cout << "===== CICLO FOR =====" << endl;

    // For básico: del 1 al 5
    cout << "Del 1 al 5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // For con paso personalizado (de 2 en 2)
    cout << "De 2 en 2 (0-10): ";
    for (int i = 0; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    // For en reversa (de mayor a menor)
    cout << "En reversa (10 al 1): ";
    for (int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;

    // For con múltiples variables
    cout << "Múltiples variables: ";
    for (int i = 1, j = 10; i <= 5; i++, j--) {
        cout << "(" << i << "," << j << ") ";
    }
    cout << endl;

    // For con break (interrumpir antes de terminar)
    cout << "For con break en 4: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) break;
        cout << i << " ";
    }
    cout << endl;

    // For con continue (saltar una iteración)
    cout << "For con continue (saltar el 3): ";
    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue;
        cout << i << " ";
    }
    cout << endl;

    // ========== CICLO WHILE ==========
    // Estructura: while (condición) { ... }
    cout << "\n===== CICLO WHILE =====" << endl;

    int contador = 1;
    cout << "While del 1 al 5: ";
    while (contador <= 5) {
        cout << contador << " ";
        contador++;
    }
    cout << endl;

    // While como validación de entrada
    int numero = -1;
    cout << "While validando número positivo: ";
    while (numero < 0) {
        numero = 3;  // Simulamos que el usuario ingresó 3
    }
    cout << "Número válido: " << numero << endl;

    // ========== CICLO DO-WHILE ==========
    // Estructura: do { ... } while (condición);
    // Se ejecuta al menos una vez
    cout << "\n===== CICLO DO-WHILE =====" << endl;

    int x = 1;
    cout << "Do-While del 1 al 5: ";
    do {
        cout << x << " ";
        x++;
    } while (x <= 5);
    cout << endl;

    // Do-While que se ejecuta una sola vez
    int y = 100;
    cout << "Do-While que solo se ejecuta una vez: ";
    do {
        cout << y << " ";
    } while (y < 10);  // La condición es falsa desde el inicio
    cout << endl;

    // ========== CICLOS ANIDADOS ==========
    cout << "\n===== CICLOS ANIDADOS =====" << endl;

    // Tabla de multiplicar del 1 al 3
    cout << "Tablas del 1 al 3:" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << "Tabla del " << i << ": ";
        for (int j = 1; j <= 5; j++) {
            cout << i * j << " ";
        }
        cout << endl;
    }

    // Patrón con asteriscos
    cout << "\nTriángulo de asteriscos:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // ========== CICLO FOR CON ÍNDICE (estilo C++98) ==========
    // El range-based for (for : ) es de C++11.
    // En C++98 se usa la forma clásica con índice.
    cout << "\n===== FOR CON ÍNDICE (equivalente al foreach) =====" << endl;

    int numeros[] = {10, 20, 30, 40, 50};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);

    cout << "Recorriendo arreglo: ";
    for (int i = 0; i < tamano; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Nota: En C++11 se puede escribir como:
    //   for (int n : numeros) { cout << n << " "; }
    //   for (auto n : numeros) { cout << n << " "; }
    // En C++98/03 se usa el for con índice (mostrado arriba).

    return 0;
}
