/* ============================================================
   herencia.cpp - GCC / Dev-C++ moderno compatible
   Tema: Herencia simple en POO
   ============================================================
   NOTA: std::string se reemplaza por char[] con strcpy().
         Los inicializadores de lista ": nombre(nombre)" se
         reemplazan por asignaciones con strcpy() en el cuerpo
         del constructor.
         Los metodos se definen fuera de la clase (:: scope).
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* strcpy() para cadenas char[] */
using namespace std;

/* ============================================================
   CLASE BASE
   ============================================================ */
class Animal {
protected:
    char nombre[50];   /* char[] en lugar de std::string */
    int  edad;

public:
    Animal(const char* nom, int ed);
    virtual ~Animal();
    void comer() const;
    virtual void hacerSonido() const;
    virtual void moverse() const;
    void mostrarInfo() const;
};

/* ============================================================
   CLASE DERIVADA: Perro hereda PUBLICAMENTE de Animal
   ============================================================ */
class Perro : public Animal {
private:
    char raza[50];   /* char[] en lugar de std::string */

public:
    Perro(const char* nom, int ed, const char* raz);
    ~Perro();
    void ladrar() const;
    void hacerSonido() const;
    virtual void moverse() const;
    void mostrarRaza() const;
};

/* ============================================================
   OTRA CLASE DERIVADA: Gato
   ============================================================ */
class Gato : public Animal {
public:
    Gato(const char* nom, int ed);
    virtual ~Gato();
    void hacerSonido() const;
    virtual void moverse() const;
    void aranar() const;
};

/* ============================================================
   IMPLEMENTACION: Animal
   ============================================================ */
Animal::Animal(const char* nom, int ed)
{
    /* strcpy() en lugar de asignacion directa con string */
    strcpy(nombre, nom);
    edad = ed;
    cout << "[Animal] Constructor llamado para: " << nombre << endl;
}

Animal::~Animal()
{
    cout << "[Animal] Destructor llamado para: " << nombre << endl;
}

/* Metodo que sera heredado */
void Animal::comer() const
{
    cout << nombre << " esta comiendo." << endl;
}

/* Metodo virtual para polimorfismo */
void Animal::hacerSonido() const
{
    cout << nombre << " hace un sonido generico." << endl;
}

void Animal::moverse() const
{
    cout << nombre << " movimiento generico." << endl;
}

/* Metodo para mostrar informacion */
void Animal::mostrarInfo() const
{
    cout << "Nombre: " << nombre << ", Edad: " << edad << " anios" << endl;
}

/* ============================================================
   IMPLEMENTACION: Perro
   ============================================================ */
Perro::Perro(const char* nom, int ed, const char* raz)
    : Animal(nom, ed)
{
    strcpy(raza, raz);
    cout << "[Perro] Constructor llamado para: " << nombre << endl;
}

Perro::~Perro()
{
    cout << "[Perro] Destructor llamado para: " << nombre << endl;
}

/* Metodo propio de Perro */
void Perro::ladrar() const
{
    cout << nombre << " dice: Guau guau!" << endl;
}

/* Sobrescritura del metodo virtual de Animal.
   En C++98 simplemente se repite la misma firma virtual,
   sin la palabra 'override' (que es de C++11). */
void Perro::hacerSonido() const
{
    cout << nombre << " Ladra." << endl;
}

void Perro::moverse() const
{
    cout << nombre << " camina en 4 patas." << endl;
}

/* Metodo propio que usa atributos heredados (protected) */
void Perro::mostrarRaza() const
{
    cout << nombre << " es de raza: " << raza << endl;
}

/* ============================================================
   IMPLEMENTACION: Gato
   ============================================================ */
Gato::Gato(const char* nom, int ed)
    : Animal(nom, ed)
{
    cout << "[Gato] Constructor llamado para: " << nombre << endl;
}

/* Destructor virtual: necesario para que se llame al destructor correcto
   cuando se destruye un Gato a traves de un puntero Animal* */
Gato::~Gato()
{
    cout << "[Gato] Destructor llamado para: " << nombre << endl;
}

void Gato::hacerSonido() const
{
    cout << nombre << " (un gato) maulla: Miau!" << endl;
}

void Gato::moverse() const
{
    cout << nombre << " camina en 4 patas." << endl;
}

void Gato::aranar() const
{
    cout << nombre << " esta aranando el sillon..." << endl;
}

/* ============================================================
   MAIN - Demostracion de herencia
   ============================================================ */
int main()
{
    cout << "========== CREANDO ANIMAL ==========" << endl;
    Animal animal("Animal generico", 5);
    animal.mostrarInfo();
    animal.hacerSonido();
    animal.moverse();

    cout << "========== CREANDO PERRO ==========" << endl;
    Perro cripto("Cripto", 5, "Perro de cripton");

    cout << "\n========== USANDO METODOS HEREDADOS ==========" << endl;
    cripto.mostrarInfo();    /* Heredado de Animal */
    cripto.hacerSonido();
    cripto.moverse();

    cout << "\n========== USANDO METODOS PROPIOS ==========" << endl;
    cripto.ladrar();         /* Propio de Perro */
    cripto.mostrarRaza();    /* Propio de Perro */

    cout << "\n========== CREANDO GATO ==========" << endl;
    Gato miGato("Michi", 3);
    miGato.hacerSonido();    /* Sobrescrito en Gato */
    miGato.aranar();         /* Propio de Gato */

    cout << "\n========== POLIMORFISMO CON PUNTEROS ==========" << endl;
    Animal* ptrAnimal = &cripto;
    ptrAnimal->hacerSonido(); /* Llama a Perro::hacerSonido() gracias a virtual */

    cout << "\n========== DESTRUCTORES AL SALIR ==========" << endl;
    return 0;
}
