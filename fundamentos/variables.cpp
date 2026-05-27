#include <iostream>
#include <string>

using namespace std;

int main() {
    // ========== TIPOS DE DATOS ENTEROS ==========
    int edad = 25;                 // Entero estándar
    short int corto = 100;         // Entero corto
    long int largo = 1000000;      // Entero largo
    long long int muyLargo = 9000000000000;
    unsigned int positivo = 50;    // Solo positivos

    // ========== TIPOS DE DATOS DECIMALES ==========
    float peso = 65.5f;            // Precisión simple
    double altura = 1.7534;        // Precisión doble
    long double precisa = 3.141592653589793;

    // ========== TIPO CARÁCTER ==========
    char letra = 'A';
    char codigo = 65;              // ASCII de 'A'

    // ========== TIPO BOOLEANO ==========
    bool esMayor = true;           // true o false
    bool activo = false;

    // ========== TIPO CADENA ==========
    string nombre = "Juan";
    string apellido = "Pérez";

    // ========== DECLARACIÓN SIN INICIALIZAR ==========
    int sinValor;                  // Declaración
    sinValor = 10;                 // Asignación posterior

    // ========== DECLARACIÓN MÚLTIPLE ==========
    int a, b, c;
    a = 1; b = 2; c = 3;

    // ========== CONSTANTES ==========
    const int DIAS_SEMANA = 7;
    const double PI = 3.14159;
    const string VERSION = "1.0.0";
    int suma = a + b;

    // ========== IMPRESIÓN DE VARIABLES ==========
    cout << "===== VARIABLES Y TIPOS DE DATOS =====" << endl;
    cout << "Edad (int): " << edad << endl;
    cout << "Corto (short): " << corto << endl;
    cout << "Largo (long): " << largo << endl;
    cout << "Muy largo (long long): " << muyLargo << endl;
    cout << "Positivo (unsigned): " << positivo << endl;
    cout << "Peso (float): " << peso << endl;
    cout << "Altura (double): " << altura << endl;
    cout << "Precisa (long double): " << precisa << endl;
    cout << "Letra (char): " << letra << endl;
    cout << "Código ASCII 65 (char): " << codigo << endl;
    cout << "Es mayor (bool): " << esMayor << " (1=true, 0=false)" << endl;
    cout << "Activo (bool): " << activo << endl;
    cout << "Nombre (string): " << nombre << " " << apellido << endl;
    cout << "Sin valor inicial: " << sinValor << endl;
    cout << "Múltiples variables: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Días de la semana (const): " << DIAS_SEMANA << endl;
    cout << "PI (const): " << PI << endl;
    cout << "Versión (const): " << VERSION << endl;

    // ========== TAMAÑO EN BYTES ==========
    cout << "\n===== TAMAÑO EN BYTES =====" << endl;
    cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(float): " << sizeof(float) << " bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(char): " << sizeof(char) << " bytes" << endl;
    cout << "sizeof(bool): " << sizeof(bool) << " bytes" << endl;

    cout << "Suma de los valor " << suma << endl;

    return 0;
}
