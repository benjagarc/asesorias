/* ============================================================
   prueba-herencia.cpp - GCC / Dev-C++ moderno compatible
   Tema: Herencia - Pasatiempos
   ============================================================
   NOTA: std::string se reemplaza por char[].
         Inicializadores de lista con string -> strcpy() en cuerpo.
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* strcpy() para cadenas char[] */
using namespace std;

class Pasatiempo {
    protected:
        char nombre[50];   /* char[] en lugar de std::string */
        char lugar[100];   /* char[] en lugar de std::string */

    public:
        Pasatiempo(const char* nom, const char* lug) {
            strcpy(nombre, nom);
            strcpy(lugar, lug);
            cout << "Constructor de pasatiempo: " << nombre << " " << lugar << endl;
        }

        virtual ~Pasatiempo() {
            cout << "Destructor de pasatiempo: " << nombre << endl;
        }

        virtual void mostrarLugar() const {
            cout << "Lugar generico" << endl;
        }

        void mostrarInfo() const {
            cout << "Nombre del hobbie: " << nombre << " Lugar: " << lugar << endl;
        }
};

class EscucharMusica : public Pasatiempo {
    private:
        char genero[50];   /* char[] en lugar de std::string */

    public:
        EscucharMusica(const char* nom, const char* lug, const char* gen)
            : Pasatiempo(nom, lug) {
            strcpy(genero, gen);
            cout << "Constructor de EscucharMusica" << endl;
        }

        virtual ~EscucharMusica() {
            cout << "Destructor de EscucharMusica: " << nombre << endl;
        }

        /* Sobrescritura en C++98: misma firma, sin 'override' */
        void mostrarLugar() const {
            cout << "Lugar para escuchar musica: " << lugar << endl;
        }

        void mostrarGenero() {
            cout << "El genero para escuchar musica es: " << genero << endl;
        }
};

int main() {
    cout << "========== CREANDO pasatiempo ==========" << endl;
    Pasatiempo pasa("leer", "Donde sea");
    pasa.mostrarInfo();
    pasa.mostrarLugar();

    EscucharMusica escMusica("escuchar musica", "donde sea", "rock");
    escMusica.mostrarLugar();
    escMusica.mostrarGenero();

    return 0;
}
