/* ============================================================
   variables.cpp - GCC / Dev-C++ moderno compatible
   Tema: Variables, tipos de datos y constantes
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
using namespace std;

int main() {
    /* ========== TIPOS DE DATOS ENTEROS ========== */
    int edad = 25;                 /* Entero estandar */
    short int corto = 100;         /* Entero corto */
    long int largo = 1000000L;     /* Entero largo */
    /* NOTA: long long int no existe en Borland C++ / Turbo C++.
       Se usa long int, que en sistemas de 32 bits soporta hasta ~2,147,483,647 */
    long int muyLargo = 2000000000L;
    unsigned int positivo = 50;    /* Solo positivos */

    /* ========== TIPOS DE DATOS DECIMALES ========== */
    float peso = 65.5;             /* Precision simple */
    double altura = 1.7534;        /* Precision doble */
    long double precisa = 3.14159265358979;

    /* ========== TIPO CARACTER ========== */
    char letra = 'A';
    char codigo = 65;              /* ASCII de 'A' */

    /* ========== TIPO BOOLEANO ========== */
    /* NOTA: En Borland C++ 5.x el tipo 'bool' esta disponible.
       En Turbo C++ 3.x no existe: se usa int con 1 = true, 0 = false */
    int esMayor = 1;               /* 1 = true */
    int activo = 0;                /* 0 = false */

    /* ========== TIPO CADENA ========== */
    /* NOTA: std::string no esta disponible en Borland antiguo con iostream.h.
       Se usan arreglos de char (cadenas estilo C) */
    char nombre[] = "Juan";
    char apellido[] = "Perez";     /* Sin tilde: DOS no muestra caracteres extendidos */

    /* ========== DECLARACION SIN INICIALIZAR ========== */
    int sinValor;                  /* Declaracion */
    sinValor = 10;                 /* Asignacion posterior */

    /* ========== DECLARACION MULTIPLE ========== */
    int a, b, c;
    a = 1; b = 2; c = 3;

    /* ========== CONSTANTES ========== */
    const int DIAS_SEMANA = 7;
    const double PI = 3.14159;
    const char* VERSION = "1.0.0"; /* const string -> const char* en Borland */
    int suma = a + b;

    /* ========== IMPRESION DE VARIABLES ========== */
    cout << "===== VARIABLES Y TIPOS DE DATOS =====" << endl;
    cout << "Edad (int): " << edad << endl;
    cout << "Corto (short): " << corto << endl;
    cout << "Largo (long): " << largo << endl;
    cout << "Muy largo (long): " << muyLargo << endl;
    cout << "Positivo (unsigned): " << positivo << endl;
    cout << "Peso (float): " << peso << endl;
    cout << "Altura (double): " << altura << endl;
    cout << "Precisa (long double): " << precisa << endl;
    cout << "Letra (char): " << letra << endl;
    cout << "Codigo ASCII 65 (char): " << codigo << endl;
    cout << "Es mayor (int como bool): " << esMayor << " (1=true, 0=false)" << endl;
    cout << "Activo (int como bool): " << activo << endl;
    cout << "Nombre (char[]): " << nombre << " " << apellido << endl;
    cout << "Sin valor inicial: " << sinValor << endl;
    cout << "Multiples variables: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Dias de la semana (const): " << DIAS_SEMANA << endl;
    cout << "PI (const): " << PI << endl;
    cout << "Version (const char*): " << VERSION << endl;

    /* ========== TAMANO EN BYTES ========== */
    cout << "\n===== TAMANO EN BYTES =====" << endl;
    cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(float): " << sizeof(float) << " bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(char): " << sizeof(char) << " bytes" << endl;

    cout << "Suma de los valores: " << suma << endl;

    return 0;
}
