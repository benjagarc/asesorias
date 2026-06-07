#include <iostream>
#include <string>

using namespace std;

class Pasatiempo {
    protected:
        std::string nombre;
        std::string lugar;
    
    public:

        Pasatiempo(string nombre, string lugar) : nombre(nombre), lugar(lugar) {
            cout << "Constructor de pasatiempo: " << nombre << lugar << endl;
        }
        virtual ~Pasatiempo( ){
            cout << "Destructor de pasatiempo: " << nombre << endl;
        }
        
         virtual void mostrarLugar() const{
            cout << "Lugar generico" << endl;
        }

        void mostrarInfo() const{
            cout << "Nombre del hobbie"  << nombre << " Lugar: " << lugar << endl;
        }
};

class EscucharMusica: public Pasatiempo {
    private: 
        std::string genero;
    public:
         EscucharMusica(string nombre, string lugar, string genero)
            : Pasatiempo(nombre, lugar), genero(genero) {
            cout << "Constructor de EscucharMusica" << endl;
        }
        virtual ~EscucharMusica( ){
            cout << "Destructor de pasatiempo: " << nombre << endl;
        }

        // Sobrescritura en C++98: misma firma, sin 'override'
        void mostrarLugar() const {
            cout << "Lugar para escuichar musica: " << lugar << endl;
        }

        void mostrarGenero() {
           cout << "El genero para escuchar musica es: " << genero << endl; 
        }

};

int main() {
    cout << "========== CREANDO pasatiempo ==========" << std::endl;
    Pasatiempo pasa("leer", "Donde sea");
    pasa.mostrarInfo();
    pasa.mostrarLugar();
    EscucharMusica escMusica("escuchar musica", "donde sea", "rock");
    escMusica.mostrarLugar();
    escMusica.mostrarGenero();
    return 0;
}