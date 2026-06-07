/* ============================================================
   entrada_datos.cpp - GCC / Dev-C++ moderno compatible
   Tema: Lectura de datos con cin
   ============================================================
   NOTA: Se usan arreglos char[] y cin.getline() con buffer.
         Se usa el valor fijo 255 para limpiar el buffer de cin
         (equivalente simple a numeric_limits<streamsize>::max()).
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
using namespace std;

int main() {
    /* ============================================================
       1. LECTURA DE TIPOS BASICOS
       ============================================================ */
    cout << "=== 1. LECTURA DE TIPOS BASICOS ===" << endl;

    int entero;
    cout << "Ingresa un numero entero: ";
    cin >> entero;
    cout << "Entero leido: " << entero << endl;

    float flotante;
    cout << "Ingresa un numero flotante: ";
    cin >> flotante;
    cout << "Flotante leido: " << flotante << endl;

    double doble;
    cout << "Ingresa un numero double: ";
    cin >> doble;
    cout << "Double leido: " << doble << endl;

    char caracter;
    cout << "Ingresa un caracter: ";
    cin >> caracter;
    cout << "Caracter leido: " << caracter << endl;

    char palabra[100];   /* En Borland: char[] en lugar de std::string */
    cout << "Ingresa una palabra (sin espacios): ";
    cin >> palabra;
    cout << "Palabra leida: " << palabra << endl;

    /* ============================================================
       2. LECTURA DE MULTIPLES VALORES EN UNA LINEA
       ============================================================ */
    cout << "\n=== 2. MULTIPLES VALORES EN UNA LINEA ===" << endl;

    int a, b, c;
    cout << "Ingresa 3 numeros separados por espacio: ";
    cin >> a >> b >> c;
    cout << "Valores leidos: a=" << a << " b=" << b << " c=" << c << endl;

    /* ============================================================
       3. LECTURA DE LINEAS COMPLETAS CON GETLINE
       NOTA: En Borland se usa cin.getline(buffer, tamano)
             En lugar de la version global getline(cin, string)
       ============================================================ */
    cout << "\n=== 3. LECTURA DE LINEAS COMPLETAS (cin.getline) ===" << endl;

    /* IMPORTANTE: Limpiar el buffer antes de usar getline despues de cin >> */
    /* En C++ moderno: cin.ignore(numeric_limits<streamsize>::max(), '\n') */
    /* En Borland: cin.ignore(255, '\n') con un valor fijo grande            */
    cin.ignore(255, '\n');

    char linea[200];
    cout << "Ingresa una linea completa (con espacios): ";
    cin.getline(linea, 200);   /* Lee hasta 199 caracteres + '\0' */
    cout << "Linea leida: " << linea << endl;

    /* ============================================================
       4. LEER HASTA UN DELIMITADOR
       ============================================================ */
    cout << "\n=== 4. LEER HASTA UN DELIMITADOR ===" << endl;

    char frase[200];
    cout << "Ingresa una frase que termine con punto (.): ";
    cin.getline(frase, 200, '.');   /* Lee hasta encontrar '.' */
    cout << "Frase leida (sin el punto): " << frase << endl;

    /* Limpiar el resto del buffer */
    cin.ignore(255, '\n');

    /* ============================================================
       5. VALIDACION DE ENTRADA (manejo de errores)
       ============================================================ */
    cout << "\n=== 5. VALIDACION DE ENTRADA ===" << endl;

    int numeroValido;
    cout << "Ingresa obligatoriamente un numero entero: ";

    while (!(cin >> numeroValido)) {
        cout << "Error: eso no es un numero entero. Intenta de nuevo: ";

        /* Limpia el estado de error de cin */
        cin.clear();

        /* Descarta la entrada invalida del buffer */
        /* C++ moderno: cin.ignore(numeric_limits<streamsize>::max(), '\n') */
        /* Borland: valor fijo grande */
        cin.ignore(255, '\n');
    }
    cout << "Numero valido leido: " << numeroValido << endl;

    /* ============================================================
       6. USO DE CIN.GET() PARA LEER UN SOLO CARACTER
       ============================================================ */
    cout << "\n=== 6. CIN.GET() - UN SOLO CARACTER ===" << endl;

    char tecla;
    cout << "Presiona una tecla y Enter: ";
    cin.get(tecla);
    cout << "Tecla presionada: " << tecla << endl;

    /* ============================================================
       7. LEER UN ARREGLO CON CIN
       ============================================================ */
    cout << "\n=== 7. LEER UN ARREGLO ===" << endl;

    const int TAMANO = 5;
    int arreglo[TAMANO];

    cout << "Ingresa " << TAMANO << " numeros enteros:" << endl;
    for (int i = 0; i < TAMANO; i++) {
        cout << "  Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }

    cout << "Arreglo leido: ";
    for (int i = 0; i < TAMANO; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    /* ============================================================
       8. EJEMPLO COMPLETO: FORMULARIO
       ============================================================ */
    cout << "\n=== 8. EJEMPLO: FORMULARIO ===" << endl;

    char nombreCompleto[100];
    int edad;
    double estatura;

    cin.ignore(255, '\n');

    cout << "Nombre completo: ";
    cin.getline(nombreCompleto, 100);

    cout << "Edad: ";
    cin >> edad;

    cout << "Estatura (en metros): ";
    cin >> estatura;

    cout << "\n--- DATOS INGRESADOS ---" << endl;
    cout << "Nombre:   " << nombreCompleto << endl;
    cout << "Edad:     " << edad << " anios" << endl;
    cout << "Estatura: " << estatura << " m" << endl;

    return 0;
}
