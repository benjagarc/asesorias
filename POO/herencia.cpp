#include <iostream>
#include <string>

// ============================================================
// EJEMPLO DE HERENCIA SIMPLE EN POO (C++)
// ============================================================
// La herencia permite que una clase (derivada) herede atributos
// y métodos de otra clase (base), promoviendo la reutilización
// de código y la jerarquía de clases.
// ============================================================

// ------------------- CLASE BASE -------------------
class Animal {
protected:
    std::string nombre;
    int edad;

public:
    // Constructor
    Animal(std::string nombre, int edad) : nombre(nombre), edad(edad) {
        std::cout << "[Animal] Constructor llamado para: " << nombre << edad << std::endl;
    }

    // Destructor virtual (buena práctica para herencia)
    virtual ~Animal() {
        std::cout << "[Animal] Destructor llamado para: " << nombre << std::endl;
    }

    // Método que será heredado
    void comer() const {
        std::cout << nombre << " esta comiendo." << std::endl;
    }

    // Método virtual para polimorfismo
    virtual void hacerSonido() const {
        std::cout << nombre << " hace un sonido generico." << std::endl;
    }

    virtual void moverse() const {
         std::cout << nombre << " movimiento generico." << std::endl;
    }

    // Método para mostrar información
    void mostrarInfo() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << " anios" << std::endl;
    }
};





// ------------------- CLASE DERIVADA -------------------
// Perro hereda PÚBLICAMENTE de Animal
// Esto significa que los miembros public/protected de Animal
// conservan su nivel de acceso en Perro.
class Perro : public Animal {
private:
    std::string raza;

public:
    // Constructor: inicializa la parte base + atributos propios
    Perro(std::string nombre, int edad, std::string raza)
        : Animal(nombre, edad), raza(raza) {
        std::cout << "[Perro] Constructor llamado para: " << nombre << std::endl;
    }

    ~Perro() {
        std::cout << "[Perro] Destructor llamado para: " << nombre << std::endl;
    }

    // Método propio de Perro
    void ladrar() const {
        std::cout << nombre << " dice: ¡Guau guau!" << std::endl;
    }

    // Sobrescritura (override) del método virtual de Animal
    void hacerSonido() const override {
        std::cout << nombre << " Ladra." << std::endl;
    }

    virtual void moverse() const override {
         std::cout << nombre << "camina en 4 patas." << std::endl;
    }

    // Método propio que usa atributos heredados (protected)
    void mostrarRaza() const {
        std::cout << nombre << " es de raza: " << raza << std::endl;
    }


};

// ------------------- OTRA CLASE DERIVADA -------------------
class Gato : public Animal {
public:
    Gato(std::string nombre, int edad) : Animal(nombre, edad) {}

    void hacerSonido() const override {
        std::cout << nombre << " (un gato) maulla: ¡Miau!" << std::endl;
    }
    
    virtual void moverse() const override {
         std::cout << nombre << "camina en 4 patas." << std::endl;
    }

    void aranar() const {
        std::cout << nombre << " esta aranando el sillon..." << std::endl;
    }
};

// ============================================================
// MAIN - Demostración de herencia
// ============================================================
int main() {
    std::cout << "========== CREANDO ANIMAL ==========" << std::endl;
    Animal animal("Animal generico", 5);
    animal.mostrarInfo();
    animal.hacerSonido();
    animal.moverse();
    
    std::cout << "========== CREANDO PERRO ==========" << std::endl;
    Perro cripto("Cripto", 5, "Perro de cripton");
    std::cout << "\n========== USANDO METODOS HEREDADOS ==========" << std::endl;
    cripto.mostrarInfo();    // Heredado de Animal
    cripto.hacerSonido();
    cripto.moverse();

    // std::cout << "\n========== USANDO METODOS HEREDADOS ==========" << std::endl;
    // miPerro.mostrarInfo();    // Heredado de Animal
    // miPerro.comer();          // Heredado de Animal

    // std::cout << "\n========== USANDO METODOS PROPIOS ==========" << std::endl;
    // miPerro.ladrar();         // Propio de Perro
    // miPerro.mostrarRaza();    // Propio de Perro

    // std::cout << "\n========== POLIMORFISMO ==========" << std::endl;
    // miPerro.hacerSonido();    // Sobrescrito en Perro

    // std::cout << "\n========== CREANDO GATO ==========" << std::endl;
    // Gato miGato("Michi", 3);
    // miGato.hacerSonido();     // Sobrescrito en Gato
    // miGato.aranar();          // Propio de Gato

    // std::cout << "\n========== PUNTEROS A CLASE BASE ==========" << std::endl;
    // Animal* ptrAnimal = &miPerro;
    // ptrAnimal->hacerSonido(); // Llama a Perro::hacerSonido() gracias a virtual

    // std::cout << "\n========== DESTRUCTORES AL SALIR ==========" << std::endl;
    return 0;
}
