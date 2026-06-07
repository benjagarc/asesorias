/* ============================================================
   clase-equipo.cpp - GCC / Dev-C++ moderno compatible
   Tema: Clase con definicion externa de metodos
   ============================================================
   NOTA: std::string se reemplaza por char[].
         this->nombre = nombre -> strcpy(this->nombre, nombre)
         Los metodos se definen fuera de la clase (:: scope).
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <cstring>      /* strcpy() para cadenas char[] */
using namespace std;

class EquipoDeFutbol {
protected:
    char nombre[50];      /* char[] en lugar de string */
    char categoria[50];   /* char[] en lugar de string */
    int  campeonatos;

public:
    EquipoDeFutbol(const char* nombre, const char* categoria, int campeonatos);
    ~EquipoDeFutbol();
    void perder();
    void entrenar();
    void viajar();
};

EquipoDeFutbol::EquipoDeFutbol(const char* nom, const char* cat, int camp)
{
    /* strcpy() en lugar de asignacion directa con string */
    strcpy(nombre, nom);
    strcpy(categoria, cat);
    campeonatos = camp;
    cout << "Equipo de futbol iniciado: " << nombre << " " << categoria << " " << campeonatos << endl;
}

EquipoDeFutbol::~EquipoDeFutbol()
{
    cout << "Equipo de futbol destructor: " << nombre << " " << categoria << " " << campeonatos << endl;
}

void EquipoDeFutbol::perder()
{
    cout << "El equipo " << nombre << " perdio" << endl;
}

void EquipoDeFutbol::entrenar()
{
    cout << "El equipo " << nombre << " entrena" << endl;
}

void EquipoDeFutbol::viajar()
{
    cout << "El equipo " << nombre << " viaja" << endl;
}

int main()
{
    EquipoDeFutbol mexico("mexico", "pais", 10);
    mexico.entrenar();
    mexico.perder();
    mexico.viajar();
    return 0;
}
