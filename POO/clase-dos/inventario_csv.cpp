#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;

class Producto {
public:
    int codigo;
    string nombre;
    float precio;

    Producto(int c, string n, float p);
    void mostrar();
    string toCSV();
    static Producto desdeCSV(string linea);
};

class GestorCSV {
private:
    string nombreArchivo;

public:
    GestorCSV(string archivo);
    void leerTodos();
    void agregar(Producto p);
    void actualizar(int codigo, Producto nuevo);
    void eliminar(int codigo);
};

Producto::Producto(int c, string n, float p)
{
    codigo = c;
    nombre = n;
    precio = p;
}

void Producto::mostrar()
{
    cout <<"  Codigo : " <<codigo <<endl;
    cout <<"  Nombre : " <<nombre <<endl;
    cout <<"  Precio : $" <<precio <<endl;
    cout <<"  --------------------------" <<endl;
}

string Producto::toCSV()
{
    ostringstream oss;
    oss <<codigo <<"," <<nombre <<"," <<precio;
    return oss.str();
}

Producto Producto::desdeCSV(string linea)
{
    stringstream ss(linea);
    string parteCodigo, parteNombre, partePrecio;

    getline(ss, parteCodigo, ',');
    getline(ss, parteNombre, ',');
    getline(ss, partePrecio, ',');

    int c = atoi(parteCodigo.c_str());
    float p = atof(partePrecio.c_str());

    return Producto(c, parteNombre, p);
}

GestorCSV::GestorCSV(string archivo)
{
    nombreArchivo = archivo;
}

void GestorCSV::leerTodos()
{
    ifstream archivo(nombreArchivo.c_str());

    if(!archivo.is_open())
    {
        cout <<"El archivo no existe o esta vacio." <<endl;
        return;
    }

    string linea;
    int conteo = 0;

    cout <<endl;
    cout <<"========== INVENTARIO ==========" <<endl;

    while(getline(archivo, linea))
    {
        if(linea == "")
            continue;
        Producto p = Producto::desdeCSV(linea);
        p.mostrar();
        conteo++;
    }

    if(conteo == 0)
        cout <<"No hay articulos registrados." <<endl;

    archivo.close();
}

void GestorCSV::agregar(Producto p)
{
    ofstream archivo(nombreArchivo.c_str(), ios::app);

    if(!archivo.is_open())
    {
        cout <<"Error: no se pudo abrir el archivo." <<endl;
        return;
    }

    archivo <<p.toCSV() <<endl;
    archivo.close();
    cout <<"Articulo agregado correctamente." <<endl;
}

void GestorCSV::actualizar(int codigo, Producto nuevo)
{
    ifstream archivoLectura(nombreArchivo.c_str());

    if(!archivoLectura.is_open())
    {
        cout <<"Error: no se pudo abrir el archivo." <<endl;
        return;
    }

    string contenidoNuevo = "";
    string linea;
    bool encontrado = false;

    while(getline(archivoLectura, linea))
    {
        if(linea == "")
            continue;

        Producto p = Producto::desdeCSV(linea);

        if(p.codigo == codigo)
        {
            nuevo.codigo = codigo;
            contenidoNuevo += nuevo.toCSV() + "\n";
            encontrado = true;
        }
        else
            contenidoNuevo += linea + "\n";
    }

    archivoLectura.close();

    if(!encontrado)
    {
        cout <<"No se encontro el articulo con codigo " <<codigo <<"." <<endl;
        return;
    }

    ofstream archivoEscritura(nombreArchivo.c_str());
    archivoEscritura <<contenidoNuevo;
    archivoEscritura.close();

    cout <<"Articulo actualizado correctamente." <<endl;
}

void GestorCSV::eliminar(int codigo)
{
    ifstream archivoLectura(nombreArchivo.c_str());

    if(!archivoLectura.is_open())
    {
        cout <<"Error: no se pudo abrir el archivo." <<endl;
        return;
    }

    string contenidoNuevo = "";
    string linea;
    bool encontrado = false;

    while(getline(archivoLectura, linea))
    {
        if(linea == "")
            continue;

        Producto p = Producto::desdeCSV(linea);

        if(p.codigo == codigo)
            encontrado = true;
        else
            contenidoNuevo += linea + "\n";
    }

    archivoLectura.close();

    if(!encontrado)
    {
        cout <<"No se encontro el articulo con codigo " <<codigo <<"." <<endl;
        return;
    }

    ofstream archivoEscritura(nombreArchivo.c_str());
    archivoEscritura <<contenidoNuevo;
    archivoEscritura.close();

    cout <<"Articulo eliminado correctamente." <<endl;
}

void procesarOpcion(int opcion, GestorCSV& gestor)
{
    if(opcion<0 || opcion>4)
    {
        cout <<"Opcion no valida. Elige entre 0 y 4." <<endl;
        return;
    }

    if(opcion == 0)
        return;

    switch(opcion)
    {
        case 1:
        {
            gestor.leerTodos();
            break;
        }

        case 2:
        {
            int codigo;
            string nombre;
            float precio;

            cout <<"Codigo  : ";
            cin >>codigo;
            cin.ignore();

            cout <<"Nombre  : ";
            getline(cin, nombre);

            cout <<"Precio  : ";
            cin >>precio;

            Producto nuevo(codigo, nombre, precio);
            gestor.agregar(nuevo);
            break;
        }

        case 3:
        {
            int codigo;
            string nombre;
            float precio;

            cout <<"Codigo a actualizar : ";
            cin >>codigo;
            cin.ignore();

            cout <<"Nuevo nombre        : ";
            getline(cin, nombre);

            cout <<"Nuevo precio        : ";
            cin >>precio;

            Producto nuevo(codigo, nombre, precio);
            gestor.actualizar(codigo, nuevo);
            break;
        }

        case 4:
        {
            int codigo;
            cout <<"Codigo a eliminar: ";
            cin >>codigo;
            gestor.eliminar(codigo);
            break;
        }
    }
}

int main()
{
    GestorCSV gestor("productos.csv");
    int opcion;

    do
    {
        cout <<endl;
        cout <<"================================" <<endl;
        cout <<"    SISTEMA DE INVENTARIO CSV   " <<endl;
        cout <<"================================" <<endl;
        cout <<"  1. Ver todos los articulos    " <<endl;
        cout <<"  2. Agregar articulo           " <<endl;
        cout <<"  3. Actualizar articulo        " <<endl;
        cout <<"  4. Eliminar articulo          " <<endl;
        cout <<"  0. Salir                      " <<endl;
        cout <<"================================" <<endl;
        cout <<"Elige una opcion: ";
        cin >>opcion;
        cin.ignore();

        procesarOpcion(opcion, gestor);

    } while(opcion != 0);

    cout <<endl <<"Hasta luego." <<endl;
    return 0;
}
