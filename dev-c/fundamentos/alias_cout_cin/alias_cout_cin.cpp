/* ============================================================
   alias_cout_cin.cpp - GCC / Dev-C++ moderno compatible
   Tema: Formas de referirse a cout y cin
   ============================================================
   NOTA: Se usan headers estandar C++ (sin .h) para compilar
         con GCC/MinGW (Dev-C++ 6.x, Code::Blocks, etc.).
         'using namespace std' reemplaza el espacio global
         que Borland agregaba automaticamente con <iostream.h>.
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* Para funciones de cadenas char[] */
using namespace std;

int main() {
    /* ============================================================
       FORMA 1: Acceso directo (en Borland ya es global)
       En C++ moderno: using std::cout; using std::cin;
       En Borland con iostream.h: cout y cin ya son globales
       ============================================================ */
    cout << "=== FORMA 1: Acceso directo (ya global en Borland) ===" << endl;
    cout << "Con <iostream.h>, cout es global sin necesidad de std::" << endl;

    /* ============================================================
       FORMA 2: Referencias - Crear un "alias" como referencia al objeto
       En C++98 se escribe el tipo explicitamente: ostream& y istream&
       ============================================================ */
    ostream& out = cout;   /* out es una referencia a cout */
    istream& in  = cin;    /* in  es una referencia a cin  */

    out << "\n=== FORMA 2: Referencias ===" << endl;
    out << "'out' apunta al mismo objeto que cout" << endl;
    out << "Escribe un numero: ";

    int numero;
    in  >> numero;
    out << "Leiste: " << numero << endl;

    /* ============================================================
       FORMA 3: Punteros - Apuntar al objeto de flujo
       ============================================================ */
    ostream* pOut = &cout;   /* Puntero a cout */
    istream* pIn  = &cin;    /* Puntero a cin  */

    *pOut << "\n=== FORMA 3: Punteros ===" << endl;
    *pOut << "'pOut' es un puntero a cout" << endl;
    *pOut << "Escribe una palabra: ";

    char palabra[100];       /* En Borland: char[] en lugar de std::string */
    *pIn >> palabra;
    *pOut << "Leiste: " << palabra << endl;

    /* ============================================================
       FORMA 4: Tipo explícito con typedef (compatible C++98 y Borland)
       En C++11 moderno: using TipoCout = decltype(std::cout);
       En Borland/C++98: typedef con el tipo directamente
       ============================================================ */
    typedef ostream TipoCout;   /* TipoCout es el mismo tipo que ostream */
    typedef istream TipoCin;    /* TipoCin  es el mismo tipo que istream */

    TipoCout& salida  = cout;
    TipoCin&  entrada = cin;

    salida << "\n=== FORMA 4: Alias de tipo con typedef (C++98) ===" << endl;
    salida << "TipoCout es el mismo tipo que ostream" << endl;
    salida << "Escribe un numero (prueba typedef): ";
    int numTypedef;
    entrada >> numTypedef;
    salida << "Leiste: " << numTypedef << endl;

    /* ============================================================
       FORMA 5: Macros (NO recomendado, solo para conocimiento)
       ============================================================ */
    #define IMPRIMIR cout
    #define LEER     cin

    IMPRIMIR << "\n=== FORMA 5: Macros (evitar en codigo real) ===" << endl;
    IMPRIMIR << "Las macros son reemplazos de texto en precompilacion" << endl;

    /* ============================================================
       RESUMEN
       ============================================================ */
    cout << "\n=== RESUMEN ===" << endl;
    cout << "1. cout directo         -> Global en Borland con <iostream.h>" << endl;
    cout << "2. ostream& out = cout; -> Referencia explicita (C++98)" << endl;
    cout << "3. ostream* p = &cout;  -> Puntero al objeto (C++98)" << endl;
    cout << "4. typedef ostream T;   -> Alias de tipo (C++98)" << endl;
    cout << "5. #define IMPRIMIR cout-> Macro (evitar, C++98)" << endl;
    cout << "---" << endl;
    cout << "Diferencia vs C++ moderno:" << endl;
    cout << "  Moderno: #include <iostream> + using namespace std;" << endl;
    cout << "  Borland: #include <iostream.h>  (cout ya es global)" << endl;

    return 0;
}
