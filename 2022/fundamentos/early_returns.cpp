#include <iostream>
#include <string>

using namespace std;

// ============================================================
// EJEMPLO 1: Validación de usuario CON if-else anidados
// ============================================================
bool iniciarSesionAnidado(string usuario, string password, int edad) {
    if (!usuario.empty()) {
        if (!password.empty()) {
            if (password.length() >= 6) {
                if (edad >= 18) {
                    if (usuario == "admin") {
                        return true;
                    } else {
                        cout << "Usuario no reconocido" << endl;
                        return false;
                    }
                } else {
                    cout << "Debes ser mayor de edad" << endl;
                    return false;
                }
            } else {
                cout << "Contraseña muy corta" << endl;
                return false;
            }
        } else {
            cout << "Password vacío" << endl;
            return false;
        }
    } else {
        cout << "Usuario vacío" << endl;
        return false;
    }
}

// ============================================================
// EJEMPLO 2: La MISMA validación CON early returns
// ============================================================
bool iniciarSesionEarlyReturn(string usuario, string password, int edad) {
    if (usuario.empty()) {
        cout << "Usuario vacío" << endl;
        return false;  // ← Early return: sale inmediatamente
    }

    if (password.empty()) {
        cout << "Password vacío" << endl;
        return false;  // ← Early return
    }

    if (password.length() < 6) {
        cout << "Contraseña muy corta" << endl;
        return false;  // ← Early return
    }

    if (edad < 18) {
        cout << "Debes ser mayor de edad" << endl;
        return false;  // ← Early return
    }

    if (usuario != "admin") {
        cout << "Usuario no reconocido" << endl;
        return false;  // ← Early return
    }

    // Si llegamos aquí, TODO está bien
    return true;
}

// ============================================================
// EJEMPLO 3: Early return con cálculos
// ============================================================
int dividirAnidado(int a, int b) {
    if (b != 0) {
        int resultado = a / b;
        return resultado;
    } else {
        cout << "Error: división por cero" << endl;
        return 0;
    }
}

int dividirEarlyReturn(int a, int b) {
    if (b == 0) {
        cout << "Error: división por cero" << endl;
        return 0;  // ← Early return
    }

    // Flujo principal sin indentación extra
    int resultado = a / b;
    return resultado;
}

// ============================================================
// EJEMPLO 4: Búsqueda en arreglo con early return
// ============================================================
bool contieneAnidado(int arr[], int tamano, int buscado) {
    bool encontrado = false;

    for (int i = 0; i < tamano; i++) {
        if (arr[i] == buscado) {
            encontrado = true;
        }
    }

    return encontrado;
}

bool contieneEarlyReturn(int arr[], int tamano, int buscado) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == buscado) {
            return true;  // ← Early return: encontró, no sigue buscando
        }
    }

    return false;  // Solo se llega aquí si NO se encontró
}

// ============================================================
// EJEMPLO 5: Early return con void (guard clause)
// ============================================================
void procesarPedidoAnidado(bool hayStock, bool usuarioActivo, double monto) {
    if (hayStock) {
        if (usuarioActivo) {
            if (monto > 0) {
                cout << "Pedido procesado por $" << monto << endl;
            } else {
                cout << "Monto inválido" << endl;
            }
        } else {
            cout << "Usuario inactivo" << endl;
        }
    } else {
        cout << "Sin stock" << endl;
    }
}

void procesarPedidoGuardClause(bool hayStock, bool usuarioActivo, double monto) {
    // Guard clauses: validar y salir lo antes posible
    if (!hayStock) {
        cout << "Sin stock" << endl;
        return;  // ← Early return en función void
    }

    if (!usuarioActivo) {
        cout << "Usuario inactivo" << endl;
        return;  // ← Early return
    }

    if (monto <= 0) {
        cout << "Monto inválido" << endl;
        return;  // ← Early return
    }

    // Flujo principal limpio, sin anidación
    cout << "Pedido procesado por $" << monto << endl;
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "=== EARLY RETURNS EN C++ ===" << endl;
    cout << "Los early returns NO son una palabra clave del lenguaje." << endl;
    cout << "Son una tecnica de estilo para escribir codigo mas limpio." << endl;

    cout << "\n--- Comparacion: if-else anidado vs early return ---" << endl;

    cout << "\nCon if-else anidado:" << endl;
    bool r1 = iniciarSesionAnidado("", "pass123", 20);
    cout << "Resultado: " << (r1 ? "OK" : "FALLO") << endl;

    cout << "\nCon early returns:" << endl;
    bool r2 = iniciarSesionEarlyReturn("", "pass123", 20);
    cout << "Resultado: " << (r2 ? "OK" : "FALLO") << endl;

    cout << "\n--- Early return en void (guard clauses) ---" << endl;
    procesarPedidoGuardClause(false, true, 100);   // Sin stock
    procesarPedidoGuardClause(true, false, 100);   // Usuario inactivo
    procesarPedidoGuardClause(true, true, -10);    // Monto inválido
    procesarPedidoGuardClause(true, true, 150);    // Éxito

    cout << "\n--- Early return en busqueda (optimizacion) ---" << endl;
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Buscar 7: " << (contieneEarlyReturn(numeros, 10, 7) ? "ENCONTRADO" : "NO") << endl;
    cout << "Buscar 99: " << (contieneEarlyReturn(numeros, 10, 99) ? "ENCONTRADO" : "NO") << endl;

    return 0;
}
