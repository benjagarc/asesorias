/* ============================================================
   funciones.cpp - GCC / Dev-C++ moderno compatible
   Tema: Funciones en C++ (prototipos, sobrecarga, recursion,
         paso por referencia, valores por defecto)
   ============================================================
   NOTA: std::string se reemplaza por char* (cadenas C).
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
using namespace std;

/* ========== DECLARACION (PROTOTIPO) DE FUNCIONES ========== */
/* Se declaran antes de main() para que el compilador las conozca */
int sumar(int a, int b);
int cuadrado(int n);
int sumaSimple(int a, int b);
double calcularAreaCirculo(double radio);
int esPar(int numero);              /* bool -> int en Borland antiguo */
void saludar(const char* nombre);   /* string -> const char* */
void imprimirSeparador();

/* ========== FUNCION CON VALOR POR DEFECTO ========== */
void repetirMensaje(const char* mensaje, int veces = 3);

/* ========== FUNCION SOBRECARGADA ========== */
int    multiplicar(int a, int b);
double multiplicar(double a, double b);

/* ========== FUNCION RECURSIVA ========== */
int factorial(int n);
int fibonacci(int n);

/* ========== FUNCION CON PASO POR REFERENCIA ========== */
void duplicarValor(int &numero);
void intercambiar(int &a, int &b);

/* ========== FUNCION QUE DEVUELVE MULTIPLES VALORES (con referencias) ========== */
void obtenerMinMax(int a, int b, int &minimo, int &maximo);

/* ========== FUNCION CON ARREGLO COMO PARAMETRO ========== */
int sumarArreglo(int arr[], int tamano);

int main() {
    cout << "===== FUNCIONES EN C++ =====" << endl;

    /* Llamada a funcion con retorno y parametros */
    int resultado = sumar(5, 3);
    cout << "sumar(5, 3) = " << resultado << endl;

    /* Llamada a funcion con valores decimales */
    double area = calcularAreaCirculo(5.0);
    cout << "Area de circulo con radio 5: " << area << endl;

    /* Llamada a funcion que devuelve int como booleano */
    cout << "Es 4 par? " << (esPar(4) ? "Si" : "No") << endl;
    cout << "Es 7 par? " << (esPar(7) ? "Si" : "No") << endl;

    /* Llamada a funcion void (sin retorno) */
    saludar("Maria");

    imprimirSeparador();

    /* Funcion con parametros por defecto */
    cout << "Mensaje repetido 3 veces (por defecto):" << endl;
    repetirMensaje("Hola");
    cout << "Mensaje repetido 2 veces (especificado):" << endl;
    repetirMensaje("Adios", 2);

    imprimirSeparador();

    /* Sobrecarga de funciones */
    cout << "multiplicar(int): "    << multiplicar(5, 3)       << endl;
    cout << "multiplicar(double): " << multiplicar(5.5, 2.0)   << endl;

    imprimirSeparador();

    /* Funciones recursivas */
    cout << "Factorial de 5: "        << factorial(5)  << endl;
    cout << "Fibonacci (posicion 7): " << fibonacci(7)  << endl;

    imprimirSeparador();

    /* Paso por referencia */
    int valor = 10;
    cout << "Valor antes: " << valor << endl;
    duplicarValor(valor);
    cout << "Valor despues de duplicar: " << valor << endl;

    int x = 20, y = 50;
    cout << "Antes del intercambio: x=" << x << ", y=" << y << endl;
    intercambiar(x, y);
    cout << "Despues del intercambio: x=" << x << ", y=" << y << endl;

    imprimirSeparador();

    /* Funcion con multiples valores de retorno (mediante referencias) */
    int minVal, maxVal;
    obtenerMinMax(42, 17, minVal, maxVal);
    cout << "Entre 42 y 17 -> Minimo: " << minVal << ", Maximo: " << maxVal << endl;

    imprimirSeparador();

    /* Funcion con arreglo */
    int numeros[] = {5, 10, 15, 20, 25};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    int sumaTotal = sumarArreglo(numeros, tamano);
    cout << "Suma del arreglo: " << sumaTotal << endl;

    imprimirSeparador();

    /* Funciones nombradas (equivalente C++98 de las lambdas de C++11) */
    cout << "Funcion cuadrado(6): "      << cuadrado(6)      << endl;
    cout << "Funcion sumaSimple(4, 9): " << sumaSimple(4, 9) << endl;

    return 0;
}

/* ========== DEFINICION DE FUNCIONES ========== */

int sumar(int a, int b) {
    return a + b;
}

double calcularAreaCirculo(double radio) {
    const double PI = 3.14159;
    return PI * radio * radio;
}

int esPar(int numero) {
    return (numero % 2) == 0;   /* Devuelve 1 (true) o 0 (false) */
}

void saludar(const char* nombre) {
    cout << "Hola, " << nombre << "! Bienvenido a C++." << endl;
}

void imprimirSeparador() {
    cout << "--------------------------" << endl;
}

void repetirMensaje(const char* mensaje, int veces) {
    for (int i = 0; i < veces; i++) {
        cout << "  [" << (i + 1) << "] " << mensaje << endl;
    }
}

int multiplicar(int a, int b) {
    return a * b;
}

double multiplicar(double a, double b) {
    return a * b;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;            /* Caso base */
    }
    return n * factorial(n - 1);  /* Llamada recursiva */
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;            /* Caso base */
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  /* Llamada recursiva */
}

void duplicarValor(int &numero) {
    numero = numero * 2;
}

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void obtenerMinMax(int a, int b, int &minimo, int &maximo) {
    if (a < b) {
        minimo = a;
        maximo = b;
    } else {
        minimo = b;
        maximo = a;
    }
}

int sumarArreglo(int arr[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }
    return suma;
}

/* ========== EQUIVALENTES C++98 DE LAS LAMBDAS ========== */
/* En C++11: auto cuadrado = [](int n) -> int { return n * n; }; */
/* En C++98/Borland: funcion nombrada normal                       */
int cuadrado(int n) {
    return n * n;
}

int sumaSimple(int a, int b) {
    return a + b;
}
