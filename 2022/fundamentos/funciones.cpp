#include <iostream>
#include <string>

using namespace std;

// ========== DECLARACIÓN (PROTOTIPO) DE FUNCIONES ==========
// Se declaran antes de main() para que el compilador las conozca
int sumar(int a, int b);
int cuadrado(int n);
int sumaSimple(int a, int b);
double calcularAreaCirculo(double radio);
bool esPar(int numero);
void saludar(string nombre);
void imprimirSeparador();

// ========== FUNCIÓN CON VALOR POR DEFECTO ==========
void repetirMensaje(string mensaje, int veces = 3);

// ========== FUNCIÓN SOBRECARGADA ==========
int multiplicar(int a, int b);
double multiplicar(double a, double b);

// ========== FUNCIÓN RECURSIVA ==========
int factorial(int n);
int fibonacci(int n);

// ========== FUNCIÓN CON PASO POR REFERENCIA ==========
void duplicarValor(int &numero);
void intercambiar(int &a, int &b);

// ========== FUNCIÓN QUE DEVUELVE MÚLTIPLES VALORES (con referencias) ==========
void obtenerMinMax(int a, int b, int &minimo, int &maximo);

// ========== FUNCIÓN CON ARREGLO COMO PARÁMETRO ==========
int sumarArreglo(int arr[], int tamano);

int main() {
    cout << "===== FUNCIONES EN C++ =====" << endl;

    // Llamada a función con retorno y parámetros
    int resultado = sumar(5, 3);
    cout << "sumar(5, 3) = " << resultado << endl;

    // Llamada a función con valores decimales
    double area = calcularAreaCirculo(5.0);
    cout << "Área de círculo con radio 5: " << area << endl;

    // Llamada a función booleana
    cout << "¿Es 4 par? " << (esPar(4) ? "Sí" : "No") << endl;
    cout << "¿Es 7 par? " << (esPar(7) ? "Sí" : "No") << endl;

    // Llamada a función void (sin retorno)
    saludar("María");

    imprimirSeparador();

    // Función con parámetros por defecto
    cout << "Mensaje repetido 3 veces (por defecto):" << endl;
    repetirMensaje("Hola");
    cout << "Mensaje repetido 2 veces (especificado):" << endl;
    repetirMensaje("Adiós", 2);

    imprimirSeparador();

    // Sobrecarga de funciones
    cout << "multiplicar(int): " << multiplicar(5, 3) << endl;
    cout << "multiplicar(double): " << multiplicar(5.5, 2.0) << endl;

    imprimirSeparador();

    // Funciones recursivas
    cout << "Factorial de 5: " << factorial(5) << endl;
    cout << "Fibonacci (posición 7): " << fibonacci(7) << endl;

    imprimirSeparador();

    // Paso por referencia
    int valor = 10;
    cout << "Valor antes: " << valor << endl;
    duplicarValor(valor);
    cout << "Valor después de duplicar: " << valor << endl;

    int x = 20, y = 50;
    cout << "Antes del intercambio: x=" << x << ", y=" << y << endl;
    intercambiar(x, y);
    cout << "Después del intercambio: x=" << x << ", y=" << y << endl;

    imprimirSeparador();

    // Función con múltiples valores de retorno (mediante referencias)
    int minVal, maxVal;
    obtenerMinMax(42, 17, minVal, maxVal);
    cout << "Entre 42 y 17 -> Mínimo: " << minVal << ", Máximo: " << maxVal << endl;

    imprimirSeparador();

    // Función con arreglo
    int numeros[] = {5, 10, 15, 20, 25};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    int sumaTotal = sumarArreglo(numeros, tamano);
    cout << "Suma del arreglo: " << sumaTotal << endl;

    imprimirSeparador();

    // Funciones nombradas en lugar de lambdas (C++98/03)
    // En C++11 se pueden escribir como: auto f = [](int n) { return n*n; };
    // En C++98 se usa una funcion nombrada con prototipo al inicio del archivo.
    cout << "Funcion cuadrado(6): " << cuadrado(6) << endl;
    cout << "Funcion sumaSimple(4, 9): " << sumaSimple(4, 9) << endl;

    return 0;
}

// ========== DEFINICIÓN DE FUNCIONES ==========

// Función simple con retorno entero
int sumar(int a, int b) {
    return a + b;
}

// Función con retorno double
double calcularAreaCirculo(double radio) {
    const double PI = 3.14159;
    return PI * radio * radio;
}

// Función que retorna booleano
bool esPar(int numero) {
    return (numero % 2) == 0;
}

// Función void (no retorna nada)
void saludar(string nombre) {
    cout << "¡Hola, " << nombre << "! Bienvenido a C++." << endl;
}

// Función void sin parámetros
void imprimirSeparador() {
    cout << "--------------------------" << endl;
}

// Función con parámetro por defecto
void repetirMensaje(string mensaje, int veces) {
    for (int i = 0; i < veces; i++) {
        cout << "  [" << (i + 1) << "] " << mensaje << endl;
    }
}

// Sobrecarga: multiplicar enteros
int multiplicar(int a, int b) {
    return a * b;
}

// Sobrecarga: multiplicar decimales
// Mismo nombre, diferentes tipos de parámetros
double multiplicar(double a, double b) {
    return a * b;
}

// Función recursiva: factorial
// n! = n * (n-1) * (n-2) * ... * 1
int factorial(int n) {
    if (n <= 1) {
        return 1;  // Caso base
    }
    return n * factorial(n - 1);  // Llamada recursiva
}

// Función recursiva: fibonacci
// 0, 1, 1, 2, 3, 5, 8, 13, 21...
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Caso base
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Llamada recursiva
}

// Paso por referencia: modifica la variable original
void duplicarValor(int &numero) {
    numero = numero * 2;
}

// Intercambio de valores usando referencias
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Múltiples valores de retorno mediante parámetros por referencia
void obtenerMinMax(int a, int b, int &minimo, int &maximo) {
    if (a < b) {
        minimo = a;
        maximo = b;
    } else {
        minimo = b;
        maximo = a;
    }
}

// Función que recibe un arreglo
int sumarArreglo(int arr[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }
    return suma;
}

// ========== EQUIVALENTES C++98 DE LAS LAMBDAS ==========
// En C++11 se escriben como funciones anónimas (lambda):
//   auto cuadrado = [](int n) -> int { return n * n; };
// En C++98/03 se declaran como funciones normales con nombre.

int cuadrado(int n) {
    return n * n;
}

int sumaSimple(int a, int b) {
    return a + b;
}
