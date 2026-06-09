/* ============================================================
   prueba-herencia.cpp - GCC / Dev-C++ moderno compatible
   Tema: Herencia - Pasatiempos
   ============================================================
   NOTA: std::string se reemplaza por char[].
         Inicializadores de lista con string -> strcpy() en cuerpo.
         Los metodos se definen fuera de la clase (:: scope).
         Sin 'virtual': el main usa objetos directos, no punteros.
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* strcpy() para cadenas char[] */
using namespace std;

class Pasatiempo {
protected:
    char nombre[50];   /* char[] en lugar de std::string */
    char lugar[100];   /* char[] en lugar de std::string */

public:
    Pasatiempo(const char* nom, const char* lug);
    ~Pasatiempo();
    void mostrarLugar() const;
    void mostrarInfo() const;
};

class EscucharMusica : public Pasatiempo {
private:
    char genero[50];   /* char[] en lugar de std::string */

public:
    EscucharMusica(const char* nom, const char* lug, const char* gen);
    ~EscucharMusica();
    void mostrarLugar() const;
    void mostrarGenero() const;   /* const: solo lectura de 'genero' */
};

/* ============================================================
   IMPLEMENTACION: Pasatiempo
   ============================================================ */
Pasatiempo::Pasatiempo(const char* nom, const char* lug)
{
    strcpy(nombre, nom);
    strcpy(lugar, lug);
    cout << "Constructor de pasatiempo: " << nombre << " " << lugar << endl;
}

Pasatiempo::~Pasatiempo()
{
    cout << "Destructor de pasatiempo: " << nombre << endl;
}

void Pasatiempo::mostrarLugar() const
{
    cout << "Lugar generico" << endl;
}

void Pasatiempo::mostrarInfo() const
{
    cout << "Nombre del hobbie: " << nombre << " Lugar: " << lugar << endl;
}

/* ============================================================
   IMPLEMENTACION: EscucharMusica
   ============================================================ */
EscucharMusica::EscucharMusica(const char* nom, const char* lug, const char* gen)
    : Pasatiempo(nom, lug)
{
    strcpy(genero, gen);
    cout << "Constructor de EscucharMusica" << endl;
}

EscucharMusica::~EscucharMusica()
{
    cout << "Destructor de EscucharMusica: " << nombre << endl;
}

/* Sobrescritura en C++98: misma firma, sin 'override' */
void EscucharMusica::mostrarLugar() const
{
    cout << "Lugar para escuchar musica: " << lugar << endl;
}

/* const: el metodo solo lee 'genero', no modifica el objeto */
void EscucharMusica::mostrarGenero() const
{
    cout << "El genero para escuchar musica es: " << genero << endl;
}

int main()
{
    cout << "========== CREANDO pasatiempo ==========" << endl;
    Pasatiempo pasa("leer", "Donde sea");
    pasa.mostrarInfo();
    pasa.mostrarLugar();

    EscucharMusica escMusica("escuchar musica", "donde sea", "rock");
    escMusica.mostrarLugar();
    escMusica.mostrarGenero();

    return 0;
}
