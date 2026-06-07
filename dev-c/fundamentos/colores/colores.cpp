/* ============================================================
   colores.cpp - GCC / Dev-C++ moderno compatible
   Tema: Colores y estilos de texto en consola
   ============================================================
   NOTA: <conio.h> (textcolor, cprintf) era exclusivo de Borland/DOS.
         En GCC/Windows moderno se usan codigos de escape ANSI:
           \033[CODIGOm  -> activa el color/estilo
           \033[0m       -> resetea todo al color por defecto
         Codigos de color de texto: 30-37 (normal), 90-97 (brillante)
         Codigos de color de fondo: 40-47
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
using namespace std;

/* ============================================================
   CONSTANTES ANSI (reemplazan las de conio.h)
   ============================================================ */
#define RESET       "\033[0m"
#define NEGRO       "\033[30m"
#define ROJO        "\033[31m"
#define VERDE       "\033[32m"
#define AMARILLO    "\033[33m"
#define AZUL        "\033[34m"
#define MAGENTA     "\033[35m"
#define CIAN        "\033[36m"
#define BLANCO      "\033[37m"
/* Colores brillantes */
#define B_ROJO      "\033[91m"
#define B_VERDE     "\033[92m"
#define B_AMARILLO  "\033[93m"
#define B_AZUL      "\033[94m"
#define B_MAGENTA   "\033[95m"
#define B_CIAN      "\033[96m"
#define B_BLANCO    "\033[97m"
/* Fondos */
#define F_NEGRO     "\033[40m"
#define F_ROJO      "\033[41m"
#define F_VERDE     "\033[42m"
#define F_AMARILLO  "\033[43m"
#define F_AZUL      "\033[44m"
#define F_MAGENTA   "\033[45m"
#define F_CIAN      "\033[46m"
#define F_BLANCO    "\033[47m"

/* Funcion auxiliar: imprime texto con color y luego resetea */
void imprimirConColor(const char* codigoAnsi, const char* texto) {
    cout << codigoAnsi << texto << RESET << endl;
}

void imprimirConFondo(const char* colorTexto, const char* colorFondo, const char* texto) {
    cout << colorTexto << colorFondo << " " << texto << " " << RESET << endl;
}

int main() {
    /* ============================================================
       1. COLORES DE TEXTO BASICOS
       ============================================================ */
    cout << "=== 1. COLORES DE TEXTO ===" << endl;
    imprimirConColor(ROJO,     "Texto en Rojo");
    imprimirConColor(VERDE,    "Texto en Verde");
    imprimirConColor(AMARILLO, "Texto en Amarillo");
    imprimirConColor(AZUL,     "Texto en Azul");
    imprimirConColor(MAGENTA,  "Texto en Magenta");
    imprimirConColor(CIAN,     "Texto en Cian");
    imprimirConColor(BLANCO,   "Texto en Blanco");

    /* ============================================================
       2. COLORES BRILLANTES
       ============================================================ */
    cout << "\n=== 2. COLORES BRILLANTES ===" << endl;
    imprimirConColor(B_ROJO,     "Rojo brillante");
    imprimirConColor(B_VERDE,    "Verde brillante");
    imprimirConColor(B_AMARILLO, "Amarillo brillante");
    imprimirConColor(B_AZUL,     "Azul brillante");
    imprimirConColor(B_CIAN,     "Cian brillante");

    /* ============================================================
       3. ESTILOS
       ============================================================ */
    cout << "\n=== 3. ESTILOS ===" << endl;
    cout << "\033[1m" << "Texto en Negrita" << RESET << endl;      /* Negrita */
    cout << "\033[4m" << "Texto Subrayado"  << RESET << endl;      /* Subrayado */

    /* ============================================================
       4. COLORES DE FONDO
       ============================================================ */
    cout << "\n=== 4. COLORES DE FONDO ===" << endl;
    imprimirConFondo(BLANCO, F_ROJO,     "Fondo rojo");
    imprimirConFondo(NEGRO,  F_VERDE,    "Fondo verde");
    imprimirConFondo(NEGRO,  F_AMARILLO, "Fondo amarillo");
    imprimirConFondo(BLANCO, F_AZUL,     "Fondo azul");

    /* ============================================================
       5. TEXTO + FONDO COMBINADOS (badges de estado)
       ============================================================ */
    cout << "\n=== 5. TEXTO + FONDO ===" << endl;
    cout << BLANCO << F_AZUL    << " INFO  "      << RESET << " ";
    cout << BLANCO << F_VERDE   << " OK  "         << RESET << " ";
    cout << BLANCO << F_AMARILLO << " ADVERTENCIA " << RESET << " ";
    cout << BLANCO << F_ROJO    << " ERROR "       << RESET << endl;

    /* ============================================================
       6. EJEMPLO PRACTICO: MENSAJES DE ESTADO
       ============================================================ */
    cout << "\n=== 6. EJEMPLO PRACTICO ===" << endl;
    cout << B_VERDE  << "[OK] " << RESET << "Operacion completada" << endl;
    cout << B_AMARILLO << "[!!] " << RESET << "Advertencia: espacio bajo" << endl;
    cout << B_ROJO   << "[XX] " << RESET << "Error: archivo no encontrado" << endl;
    cout << B_CIAN   << "[ii] " << RESET << "Informacion: proceso iniciado" << endl;

    /* ============================================================
       7. RESETEAR SIEMPRE AL FINAL
       ============================================================ */
    cout << "\n=== 7. SIEMPRE RESETEA AL FINAL ===" << endl;
    cout << ROJO << "Sin reset, todo sigue rojo..." << endl;
    /* Olvide resetear! */

    cout << RESET;   /* Reseteamos aqui */
    cout << "Ahora el texto vuelve a la normalidad." << endl;

    return 0;
}
