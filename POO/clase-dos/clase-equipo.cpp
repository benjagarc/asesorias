#include<iostream>
#include<string>

using namespace std;

class EquipoDeFutbol {
protected:
    string nombre;
    string categoria;
    int campeonatos;

public:
    EquipoDeFutbol(string nombre, string categoria, int campeonatos);
    ~EquipoDeFutbol();
    void perder();
    void entrenar();
    void viajar();
};

EquipoDeFutbol::EquipoDeFutbol(string nombre, string categoria, int campeonatos)
{
    this->nombre = nombre;
    this->categoria = categoria;
    this->campeonatos = campeonatos;
    cout <<"Equipo de futbol iniciado: " <<nombre <<" " <<categoria <<" " <<campeonatos <<endl;
}

EquipoDeFutbol::~EquipoDeFutbol()
{
    cout <<"Equipo de futbol destructor: " <<nombre <<" " <<categoria <<" " <<campeonatos <<endl;
}

void EquipoDeFutbol::perder()
{
    cout <<"El equipo " <<nombre <<" perdio" <<endl;
}

void EquipoDeFutbol::entrenar()
{
    cout <<"El equipo " <<nombre <<" entrena" <<endl;
}

void EquipoDeFutbol::viajar()
{
    cout <<"El equipo " <<nombre <<" viaja" <<endl;
}

int main()
{
    EquipoDeFutbol mexico("mexico", "pais", 10);
    mexico.entrenar();
    mexico.perder();
    mexico.viajar();
    return 0;
}
