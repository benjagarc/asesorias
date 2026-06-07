/* ============================================================
   herencia.cpp - GCC / Dev-C++ moderno compatible
   Tema: Herencia simple en POO
   ============================================================
   NOTA: std::string se reemplaza por char[] con strcpy().
         Los inicializadores de lista ": nombre(nombre)" se
         reemplazan por asignaciones con strcpy() en el cuerpo
         del constructor.
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* strcpy(), strcat() para cadenas char[] */
using namespace std;

/* ============================================================
   CLASE BASE
   ============================================================ */
class Animal {
protected:
    char nombre[50];   /* char[] en lugar de std::string */
    int  edad;

public:
    /* Constructor: usa strcpy en lugar de inicializador de lista */
    Animal(const char* nom, int ed) {
        strcpy(nombre, nom);
        edad = ed;
        cout << "[Animal] Constructor llamado para: " << nombre << endl;
    }

    /* Destructor virtual (buena practica para herencia) */
    virtual ~Animal() {
        cout << "[Animal] Destructor llamado para: " << nombre << endl;
    }

    /* Metodo que sera heredado */
    void comer() const {
        cout << nombre << " esta comiendo." << endl;
    }

    /* Metodo virtual para polimorfismo */
    virtual void hacerSonido() const {
        cout << nombre << " hace un sonido generico." << endl;
    }

    virtual void moverse() const {
        cout << nombre << " movimiento generico." << endl;
    }

    /* Metodo para mostrar informacion */
    void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " anios" << endl;
    }
};


/* ============================================================
   CLASE DERIVADA: Perro hereda PUBLICAMENTE de Animal
   ============================================================ */
class Perro : public Animal {
private:
    char raza[50];   /* char[] en lugar de std::string */

public:
    /* Constructor: inicializa la parte base + atributos propios */
    Perro(const char* nom, int ed, const char* raz)
        : Animal(nom, ed) {
        strcpy(raza, raz);
        cout << "[Perro] Constructor llamado para: " << nombre << endl;
    }

    ~Perro() {
        cout << "[Perro] Destructor llamado para: " << nombre << endl;
    }

    /* Metodo propio de Perro */
    void ladrar() const {
        cout << nombre << " dice: Guau guau!" << endl;
    }

    /* Sobrescritura del metodo virtual de Animal.
       En C++98 simplemente se repite la misma firma virtual,
       sin la palabra 'override' (que es de C++11). */
    void hacerSonido() const {
        cout << nombre << " Ladra." << endl;
    }

    virtual void moverse() const {
        cout << nombre << " camina en 4 patas." << endl;
    }

    /* Metodo propio que usa atributos heredados (protected) */
    void mostrarRaza() const {
        cout << nombre << " es de raza: " << raza << endl;
    }
};

/* ============================================================
   OTRA CLASE DERIVADA: Gato
   ============================================================ */
class Gato : public Animal {
public:
    Gato(const char* nom, int ed) : Animal(nom, ed) {}

    void hacerSonido() const {
        cout << nombre << " (un gato) maulla: Miau!" << endl;
    }

    virtual void moverse() const {
        cout << nombre << " camina en 4 patas." << endl;
    }

    void aranar() const {
        cout << nombre << " esta aranando el sillon..." << endl;
    }
};

/* ============================================================
   MAIN - Demostracion de herencia
   ============================================================ */
int main() {
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
