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
    auto& out = std::cout;   // out es una referencia a std::cout
    auto& in = std::cin;     // in es una referencia a std::cin

    out << "\n=== FORMA 2: Referencias ===" << endl;
    out << "'out' apunta al mismo objeto que std::cout" << endl;
    out << "Escribe un número: ";

    int numero;
    in >> numero;            // Lee desde std::cin a través de la referencia
    out << "Leíste: " << numero << endl;

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
    // FORMA 4: Alias de tipo con decltype (útil en plantillas)
    // ============================================================
    using TipoCout = decltype(std::cout);   // TipoCout = std::ostream
    using TipoCin = decltype(std::cin);     // TipoCin = std::istream

    TipoCout& salida = std::cout;           // Referencia usando el alias de tipo
    TipoCin& entrada = std::cin;

    salida << "\n=== FORMA 4: Alias de tipo con decltype ===" << endl;
    salida << "TipoCout es el mismo tipo que std::ostream&" << endl;

    // ============================================================
    // FORMA 5: Macros (NO recomendado, solo para conocimiento)
    // ============================================================
    #define IMPRIMIR std::cout
    #define LEER std::cin

    IMPRIMIR << "\n=== FORMA 5: Macros (evitar en código real) ===" << endl;
    IMPRIMIR << "Las macros son reemplazos de texto en precompilación" << endl;

    // ============================================================
    // FORMA 6: Namespace alias + using
    // ============================================================
    namespace io = std;   // Alias del namespace std

    io::cout << "\n=== FORMA 6: Alias de namespace ===" << endl;
    io::cout << "Puedes escribir 'io::cout' en vez de 'std::cout'" << endl;

    // ============================================================
    // RESUMEN
    // ============================================================
    cout << "\n=== RESUMEN ===" << endl;
    cout << "1. using std::cout;      -> Más común y recomendado" << endl;
    cout << "2. auto& out = cout;     -> Referencia al objeto" << endl;
    cout << "3. ostream* p = &cout;   -> Puntero al objeto" << endl;
    cout << "4. using Tipo = decltype(cout); -> Alias de tipo" << endl;
    cout << "5. #define IMPRIMIR cout -> Macro (evitar)" << endl;
    cout << "6. namespace io = std;   -> Alias de namespace" << endl;

    return 0;
}
