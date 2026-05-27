#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    // ============================================================
    // 1. LECTURA DE TIPOS BÁSICOS
    // ============================================================
    cout << "=== 1. LECTURA DE TIPOS BÁSICOS ===" << endl;

    int entero;
    cout << "Ingresa un número entero: ";
    cin >> entero;
    cout << "Entero leído: " << entero << endl;

    float flotante;
    cout << "Ingresa un número flotante: ";
    cin >> flotante;
    cout << "Flotante leído: " << flotante << endl;

    double doble;
    cout << "Ingresa un número double: ";
    cin >> doble;
    cout << "Double leído: " << doble << endl;

    char caracter;
    cout << "Ingresa un carácter: ";
    cin >> caracter;
    cout << "Carácter leído: " << caracter << endl;

    string palabra;
    cout << "Ingresa una palabra (sin espacios): ";
    cin >> palabra;
    cout << "Palabra leída: " << palabra << endl;

    // ============================================================
    // 2. LECTURA DE MÚLTIPLES VALORES EN UNA LÍNEA
    // ============================================================
    cout << "\n=== 2. MÚLTIPLES VALORES EN UNA LÍNEA ===" << endl;

    int a, b, c;
    cout << "Ingresa 3 números separados por espacio: ";
    cin >> a >> b >> c;
    cout << "Valores leídos: a=" << a << " b=" << b << " c=" << c << endl;

    // ============================================================
    // 3. LECTURA DE LÍNEAS COMPLETAS CON GETLINE
    // ============================================================
    cout << "\n=== 3. LECTURA DE LÍNEAS COMPLETAS (getline) ===" << endl;

    // IMPORTANTE: Limpiar el buffer antes de usar getline después de cin >>
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string linea;
    cout << "Ingresa una línea completa (con espacios): ";
    getline(cin, linea);
    cout << "Línea leída: " << linea << endl;

    // ============================================================
    // 4. LEER HASTA UN DELIMITADOR
    // ============================================================
    cout << "\n=== 4. LEER HASTA UN DELIMITADOR ===" << endl;

    string frase;
    cout << "Ingresa una frase que termine con punto (.): ";
    getline(cin, frase, '.');
    cout << "Frase leída (sin el punto): " << frase << endl;

    // Limpiar el resto del buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ============================================================
    // 5. VALIDACIÓN DE ENTRADA (manejo de errores)
    // ============================================================
    cout << "\n=== 5. VALIDACIÓN DE ENTRADA ===" << endl;

    int numeroValido;
    cout << "Ingresa obligatoriamente un número entero: ";

    while (!(cin >> numeroValido)) {
        cout << "Error: eso no es un número entero. Intenta de nuevo: ";

        // Limpia el estado de error de cin
        cin.clear();

        // Descarta la entrada inválida del buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Número válido leído: " << numeroValido << endl;

    // ============================================================
    // 6. USO DE CIN.GET() PARA LEER UN SOLO CARÁCTER
    // ============================================================
    cout << "\n=== 6. CIN.GET() - UN SOLO CARÁCTER ===" << endl;

    char tecla;
    cout << "Presiona una tecla y Enter: ";
    cin.get(tecla);
    cout << "Tecla presionada: " << tecla << endl;

    // ============================================================
    // 7. LEER UN ARREGLO CON CIN
    // ============================================================
    cout << "\n=== 7. LEER UN ARREGLO ===" << endl;

    const int TAMANO = 5;
    int arreglo[TAMANO];

    cout << "Ingresa " << TAMANO << " números enteros:" << endl;
    for (int i = 0; i < TAMANO; i++) {
        cout << "  Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }

    cout << "Arreglo leído: ";
    for (int i = 0; i < TAMANO; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // ============================================================
    // 8. EJEMPLO COMPLETO: FORMULARIO
    // ============================================================
    cout << "\n=== 8. EJEMPLO: FORMULARIO ===" << endl;

    string nombreCompleto;
    int edad;
    double estatura;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre completo: ";
    getline(cin, nombreCompleto);

    cout << "Edad: ";
    cin >> edad;

    cout << "Estatura (en metros): ";
    cin >> estatura;

    cout << "\n--- DATOS INGRESADOS ---" << endl;
    cout << "Nombre:   " << nombreCompleto << endl;
    cout << "Edad:     " << edad << " años" << endl;
    cout << "Estatura: " << estatura << " m" << endl;

    return 0;
}
