/* ============================================================
   early_returns.cpp - GCC / Dev-C++ moderno compatible
   Tema: Early returns y guard clauses
   ============================================================
   NOTA: Se usan arreglos char[] y funciones de <cstring>:
           strlen()  -> longitud de la cadena
           strcmp()  -> comparar cadenas
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* strlen(), strcmp() para cadenas char[] */
using namespace std;

/* ============================================================
   EJEMPLO 1: Validacion de usuario CON if-else anidados
   ============================================================ */
int iniciarSesionAnidado(char* usuario, char* password, int edad) {
    if (strlen(usuario) > 0) {
        if (strlen(password) > 0) {
            if (strlen(password) >= 6) {
                if (edad >= 18) {
                    if (strcmp(usuario, "admin") == 0) {
                        return 1;   /* true */
                    } else {
                        cout << "Usuario no reconocido" << endl;
                        return 0;   /* false */
                    }
                } else {
                    cout << "Debes ser mayor de edad" << endl;
                    return 0;
                }
            } else {
                cout << "Contrasena muy corta" << endl;
                return 0;
            }
        } else {
            cout << "Password vacio" << endl;
            return 0;
        }
    } else {
        cout << "Usuario vacio" << endl;
        return 0;
    }
}

/* ============================================================
   EJEMPLO 2: La MISMA validacion CON early returns
   ============================================================ */
int iniciarSesionEarlyReturn(char* usuario, char* password, int edad) {
    if (strlen(usuario) == 0) {
        cout << "Usuario vacio" << endl;
        return 0;  /* Early return: sale inmediatamente */
    }

    if (strlen(password) == 0) {
        cout << "Password vacio" << endl;
        return 0;  /* Early return */
    }

    if (strlen(password) < 6) {
        cout << "Contrasena muy corta" << endl;
        return 0;  /* Early return */
    }

    if (edad < 18) {
        cout << "Debes ser mayor de edad" << endl;
        return 0;  /* Early return */
    }

    if (strcmp(usuario, "admin") != 0) {
        cout << "Usuario no reconocido" << endl;
        return 0;  /* Early return */
    }

    /* Si llegamos aqui, TODO esta bien */
    return 1;
}

/* ============================================================
   EJEMPLO 3: Early return con calculos
   ============================================================ */
int dividirAnidado(int a, int b) {
    if (b != 0) {
        int resultado = a / b;
        return resultado;
    } else {
        cout << "Error: division por cero" << endl;
        return 0;
    }
}

int dividirEarlyReturn(int a, int b) {
    if (b == 0) {
        cout << "Error: division por cero" << endl;
        return 0;  /* Early return */
    }

    /* Flujo principal sin indentacion extra */
    int resultado = a / b;
    return resultado;
}

/* ============================================================
   EJEMPLO 4: Busqueda en arreglo con early return
   ============================================================ */
int contieneAnidado(int arr[], int tamano, int buscado) {
    int encontrado = 0;   /* false */

    for (int i = 0; i < tamano; i++) {
        if (arr[i] == buscado) {
            encontrado = 1;   /* true */
        }
    }

    return encontrado;
}

int contieneEarlyReturn(int arr[], int tamano, int buscado) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == buscado) {
            return 1;  /* Early return: encontro, no sigue buscando */
        }
    }

    return 0;  /* Solo se llega aqui si NO se encontro */
}

/* ============================================================
   EJEMPLO 5: Early return con void (guard clause)
   ============================================================ */
void procesarPedidoAnidado(int hayStock, int usuarioActivo, double monto) {
    if (hayStock) {
        if (usuarioActivo) {
            if (monto > 0) {
                cout << "Pedido procesado por $" << monto << endl;
            } else {
                cout << "Monto invalido" << endl;
            }
        } else {
            cout << "Usuario inactivo" << endl;
        }
    } else {
        cout << "Sin stock" << endl;
    }
}

void procesarPedidoGuardClause(int hayStock, int usuarioActivo, double monto) {
    /* Guard clauses: validar y salir lo antes posible */
    if (!hayStock) {
        cout << "Sin stock" << endl;
        return;  /* Early return en funcion void */
    }

    if (!usuarioActivo) {
        cout << "Usuario inactivo" << endl;
        return;  /* Early return */
    }

    if (monto <= 0) {
        cout << "Monto invalido" << endl;
        return;  /* Early return */
    }

    /* Flujo principal limpio, sin anidacion */
    cout << "Pedido procesado por $" << monto << endl;
}

/* ============================================================
   MAIN
   ============================================================ */
int main() {
    cout << "=== EARLY RETURNS EN C++ ===" << endl;
    cout << "Los early returns NO son una palabra clave del lenguaje." << endl;
    cout << "Son una tecnica de estilo para escribir codigo mas limpio." << endl;

    cout << "\n--- Comparacion: if-else anidado vs early return ---" << endl;

    char usuario1[] = "";
    char pass1[] = "pass123";

    cout << "\nCon if-else anidado:" << endl;
    int r1 = iniciarSesionAnidado(usuario1, pass1, 20);
    cout << "Resultado: " << (r1 ? "OK" : "FALLO") << endl;

    cout << "\nCon early returns:" << endl;
    int r2 = iniciarSesionEarlyReturn(usuario1, pass1, 20);
    cout << "Resultado: " << (r2 ? "OK" : "FALLO") << endl;

    cout << "\n--- Early return en void (guard clauses) ---" << endl;
    procesarPedidoGuardClause(0, 1, 100);   /* Sin stock */
    procesarPedidoGuardClause(1, 0, 100);   /* Usuario inactivo */
    procesarPedidoGuardClause(1, 1, -10);   /* Monto invalido */
    procesarPedidoGuardClause(1, 1, 150);   /* Exito */

    cout << "\n--- Early return en busqueda (optimizacion) ---" << endl;
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Buscar 7: "  << (contieneEarlyReturn(numeros, 10, 7)  ? "ENCONTRADO" : "NO") << endl;
    cout << "Buscar 99: " << (contieneEarlyReturn(numeros, 10, 99) ? "ENCONTRADO" : "NO") << endl;

    return 0;
}
