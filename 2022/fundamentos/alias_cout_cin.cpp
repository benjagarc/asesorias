#include <iostream>
#include <string>

using namespace std;

int main() {
    // ============================================================
    // FORMA 1: using - Traer std::cout y std::cin al alcance actual
    // ============================================================
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "=== FORMA 1: using ===" << endl;
    cout << "Ahora puedo escribir 'cout' sin el prefijo 'std::'" << endl;

    // ============================================================
    // FORMA 2: Referencias - Crear un "alias" como referencia al objeto
    // ============================================================
    // En C++98 se escribe el tipo explicitamente: std::ostream& y std::istream&
    // En C++11 se puede usar 'auto&' para deducir el tipo automaticamente.
    std::ostream& out = std::cout;   // out es una referencia a std::cout
    std::istream& in  = std::cin;    // in  es una referencia a std::cin

    out << "\n=== FORMA 2: Referencias ==="  << endl;
    out << "'out' apunta al mismo objeto que std::cout" << endl;
    out << "Escribe un numero: ";

    int numero;
    in  >> numero;            // Lee desde std::cin a traves de la referencia
    out << "Leiste: " << numero << endl;

    // ============================================================
    // FORMA 3: Punteros - Apuntar al objeto de flujo
    // ============================================================
    std::ostream* pOut = &std::cout;   // Puntero a std::cout
    std::istream* pIn = &std::cin;     // Puntero a std::cin

    *pOut << "\n=== FORMA 3: Punteros ===" << endl;
    *pOut << "'pOut' es un puntero a std::cout" << endl;
    *pOut << "Escribe una palabra: ";

    string palabra;
    *pIn >> palabra;
    *pOut << "Leíste: " << palabra << endl;

    // ============================================================
    // FORMA 4: Tipo explicito con typedef (C++98)
    // ============================================================
    // En C++11 se puede usar 'decltype' para deducir el tipo:
    //   using TipoCout = decltype(std::cout);  // C++11
    // En C++98 se usa typedef con el nombre del tipo directamente.
    typedef std::ostream TipoCout;   // TipoCout es el mismo tipo que std::ostream
    typedef std::istream TipoCin;    // TipoCin  es el mismo tipo que std::istream

    TipoCout& salida  = std::cout;
    TipoCin&  entrada = std::cin;

    salida << "\n=== FORMA 4: Alias de tipo con typedef (C++98) ===" << endl;
    salida << "TipoCout es el mismo tipo que std::ostream" << endl;
    salida << "Escribe un numero (prueba typedef): ";
    int numTypedef;
    entrada >> numTypedef;
    salida << "Leiste: " << numTypedef << endl;

    // ============================================================
    // FORMA 5: Macros (NO recomendado, solo para conocimiento)
    // ============================================================
    #define IMPRIMIR std::cout
    #define LEER std::cin

    IMPRIMIR << "\n=== FORMA 5: Macros (evitar en código real) ===" << endl;
    IMPRIMIR << "Las macros son reemplazos de texto en precompilación" << endl;

    // ============================================================
    // RESUMEN
    // ============================================================
    cout << "\n=== RESUMEN ===" << endl;
    cout << "1. using std::cout;        -> Mas comun y recomendado (C++98)" << endl;
    cout << "2. std::ostream& out=cout; -> Referencia explicita (C++98)" << endl;
    cout << "3. ostream* p = &cout;     -> Puntero al objeto (C++98)" << endl;
    cout << "4. typedef std::ostream T; -> Alias de tipo (C++98)" << endl;
    cout << "5. #define IMPRIMIR cout   -> Macro (evitar, C++98)" << endl;
    cout << "---" << endl;
    cout << "Nota: En C++11 tambien existen:" << endl;
    cout << "  auto& out = cout;        -> Deduccion de tipo automatica" << endl;
    cout << "  using T = decltype(cout);-> Alias moderno" << endl;

    return 0;
}
