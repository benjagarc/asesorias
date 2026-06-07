#include <iostream>

using namespace std;

// ============================================================
// CÓDIGOS DE ESCAPE ANSI PARA COLORES
// ============================================================
// Estructura: \033[<código>m
// \033 es el carácter de escape (también se puede usar \x1B)

// --- COLORES DE TEXTO ---
const string RESET     = "\033[0m";
const string NEGRO     = "\033[30m";
const string ROJO      = "\033[31m";
const string VERDE     = "\033[32m";
const string AMARILLO  = "\033[33m";
const string AZUL      = "\033[34m";
const string MAGENTA   = "\033[35m";
const string CIAN      = "\033[36m";
const string BLANCO    = "\033[37m";

// --- COLORES DE TEXTO (BRILLANTES/CLAROS) ---
const string ROJO_CLARO     = "\033[91m";
const string VERDE_CLARO    = "\033[92m";
const string AMARILLO_CLARO = "\033[93m";
const string AZUL_CLARO     = "\033[94m";
const string MAGENTA_CLARO  = "\033[95m";
const string CIAN_CLARO     = "\033[96m";
const string BLANCO_CLARO   = "\033[97m";

// --- COLORES DE FONDO ---
const string FONDO_NEGRO    = "\033[40m";
const string FONDO_ROJO     = "\033[41m";
const string FONDO_VERDE    = "\033[42m";
const string FONDO_AMARILLO = "\033[43m";
const string FONDO_AZUL     = "\033[44m";
const string FONDO_MAGENTA  = "\033[45m";
const string FONDO_CIAN     = "\033[46m";
const string FONDO_BLANCO   = "\033[47m";

// --- ESTILOS ---
const string NEGRITA        = "\033[1m";
const string SUBRAYADO      = "\033[4m";
const string PARPADEO       = "\033[5m";
const string INVERSO        = "\033[7m";  // Invierte texto y fondo

int main() {
    // ============================================================
    // 1. COLORES DE TEXTO BÁSICOS
    // ============================================================
    cout << "=== 1. COLORES DE TEXTO ===" << endl;
    cout << ROJO      << "Texto en Rojo"      << RESET << endl;
    cout << VERDE     << "Texto en Verde"     << RESET << endl;
    cout << AMARILLO  << "Texto en Amarillo"  << RESET << endl;
    cout << AZUL      << "Texto en Azul"      << RESET << endl;
    cout << MAGENTA   << "Texto en Magenta"   << RESET << endl;
    cout << CIAN      << "Texto en Cian"      << RESET << endl;
    cout << BLANCO    << "Texto en Blanco"    << RESET << endl;

    // ============================================================
    // 2. COLORES BRILLANTES
    // ============================================================
    cout << "\n=== 2. COLORES BRILLANTES ===" << endl;
    cout << ROJO_CLARO     << "Rojo brillante"     << RESET << endl;
    cout << VERDE_CLARO    << "Verde brillante"    << RESET << endl;
    cout << AMARILLO_CLARO << "Amarillo brillante" << RESET << endl;
    cout << AZUL_CLARO     << "Azul brillante"     << RESET << endl;
    cout << CIAN_CLARO     << "Cian brillante"     << RESET << endl;

    // ============================================================
    // 3. ESTILOS DE TEXTO
    // ============================================================
    cout << "\n=== 3. ESTILOS ===" << endl;
    cout << NEGRITA   << "Texto en negrita"   << RESET << endl;
    cout << SUBRAYADO << "Texto subrayado"    << RESET << endl;
    cout << PARPADEO  << "Texto parpadeante"  << RESET << endl;
    cout << INVERSO   << "Texto invertido"    << RESET << endl;

    // ============================================================
    // 4. COMBINAR COLORES + ESTILOS
    // ============================================================
    cout << "\n=== 4. COMBINACIONES ===" << endl;
    cout << NEGRITA + ROJO     << "Rojo en negrita"         << RESET << endl;
    cout << SUBRAYADO + VERDE  << "Verde subrayado"         << RESET << endl;
    cout << NEGRITA + AMARILLO << "Amarillo negrita"        << RESET << endl;
    cout << NEGRITA + CIAN     << "Cian negrita brillante"  << RESET << endl;

    // ============================================================
    // 5. COLORES DE FONDO
    // ============================================================
    cout << "\n=== 5. COLORES DE FONDO ===" << endl;
    cout << FONDO_ROJO     << BLANCO_CLARO << " Fondo rojo "    << RESET << endl;
    cout << FONDO_VERDE    << NEGRO        << " Fondo verde "   << RESET << endl;
    cout << FONDO_AMARILLO << NEGRO        << " Fondo amarillo "<< RESET << endl;
    cout << FONDO_AZUL     << BLANCO_CLARO << " Fondo azul "    << RESET << endl;

    // ============================================================
    // 6. TEXTO + FONDO COMBINADOS
    // ============================================================
    cout << "\n=== 6. TEXTO + FONDO ===" << endl;
    cout << NEGRITA + BLANCO + FONDO_AZUL    << "  INFO  " << RESET << " ";
    cout << NEGRITA + BLANCO + FONDO_VERDE   << "  OK  "   << RESET << " ";
    cout << NEGRITA + BLANCO + FONDO_AMARILLO << " ADVERTENCIA " << RESET << " ";
    cout << NEGRITA + BLANCO + FONDO_ROJO    << " ERROR "   << RESET << endl;

    // ============================================================
    // 7. EJEMPLO PRÁCTICO: MENSAJES DE ESTADO
    // ============================================================
    cout << "\n=== 7. EJEMPLO PRÁCTICO ===" << endl;

    cout << "[" << VERDE_CLARO << "✓" << RESET << "] Operación completada" << endl;
    cout << "[" << AMARILLO_CLARO << "⚠" << RESET << "] Advertencia: espacio bajo" << endl;
    cout << "[" << ROJO_CLARO << "✗" << RESET << "] Error: archivo no encontrado" << endl;
    cout << "[" << CIAN_CLARO << "i" << RESET << "] Información: proceso iniciado" << endl;

    // ============================================================
    // 8. RESETEAR SIEMPRE AL FINAL
    // ============================================================
    cout << "\n=== 8. SIEMPRE USA RESET ===" << endl;
    cout << ROJO << "Sin RESET, ";
    cout << "todo lo siguiente sigue rojo..." << endl;
    // ¡Oops! Falta RESET

    cout << RESET; // Reseteamos aquí para limpiar
    cout << "Ahora el texto vuelve a la normalidad." << endl;

    return 0;
}
