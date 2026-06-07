/* ============================================================
   inventario_csv.cpp - GCC / Dev-C++ moderno compatible
   Tema: Sistema CRUD con archivo CSV
   ============================================================
   Headers actualizados a estandar C++ (sin .h):
   1. <fstream>   en lugar de <fstream.h>
   2. <cstdlib>   en lugar de <stdlib.h> (atoi, atof)
   3. <cstdio>    en lugar de <stdio.h>  (sprintf)
   4. <cstring>   en lugar de <string.h> (strcpy, strtok, etc.)
   5. using namespace std -> da acceso a cout, cin, endl, etc.
   El resto del codigo (sprintf, strtok, char[], ifstream, ofstream)
   es C++ estandar y compila sin cambios en GCC.
   ============================================================ */
#include <iostream>     /* GCC: iostream estandar sin .h */
#include <fstream>      /* GCC: fstream estandar sin .h */
#include <cstring>      /* strcpy(), strcmp(), strlen(), strtok() */
#include <cstdlib>      /* atoi(), atof() */
#include <cstdio>       /* sprintf() */
using namespace std;

/* ============================================================
   CLASE Producto
   ============================================================ */
class Producto {
public:
    int   codigo;
    char  nombre[100];   /* char[] en lugar de string */
    float precio;

    Producto(int c, const char* n, float p);
    void mostrar();
    void toCSV(char* buffer, int bufSize);       /* Escribe CSV en buffer */
    static Producto desdeCSV(const char* linea); /* Parsea una linea CSV */
};

/* ============================================================
   CLASE GestorCSV
   ============================================================ */
class GestorCSV {
private:
    char nombreArchivo[200];   /* char[] en lugar de string */

public:
    GestorCSV(const char* archivo);
    void leerTodos();
    void agregar(Producto p);
    void actualizar(int codigo, Producto nuevo);
    void eliminar(int codigo);
};

/* ============================================================
   IMPLEMENTACION: Producto
   ============================================================ */
Producto::Producto(int c, const char* n, float p)
{
    codigo = c;
    strcpy(nombre, n);
    precio = p;
}

void Producto::mostrar()
{
    cout << "  Codigo : " << codigo << endl;
    cout << "  Nombre : " << nombre << endl;
    cout << "  Precio : $" << precio << endl;
    cout << "  --------------------------" << endl;
}

/* En C++ moderno: ostringstream oss; oss << codigo << "," << nombre...
   En Borland: sprintf() de <stdio.h> para construir el string en un buffer */
void Producto::toCSV(char* buffer, int bufSize)
{
    sprintf(buffer, "%d,%s,%.2f", codigo, nombre, precio);
    /* sprintf escribe la cadena formateada en 'buffer' */
    /* %.2f -> float con 2 decimales */
}

/* En C++ moderno: stringstream ss(linea); getline(ss, parte, ',')...
   En Borland: strtok() de <string.h> para dividir por comas */
Producto Producto::desdeCSV(const char* linea)
{
    /* strtok modifica la cadena, necesitamos una copia */
    char copia[300];
    strcpy(copia, linea);

    /* strtok(cadena, delimitador) devuelve tokens separados por ',' */
    char* parteCodigo = strtok(copia, ",");
    char* parteNombre = strtok(NULL,  ",");   /* NULL -> continua en la misma cadena */
    char* partePrecio = strtok(NULL,  ",");

    int   c = 0;
    float p = 0.0;
    char  n[100] = "";

    if (parteCodigo) c = atoi(parteCodigo);
    if (parteNombre) strcpy(n, parteNombre);
    if (partePrecio) p = (float)atof(partePrecio);

    return Producto(c, n, p);
}

/* ============================================================
   IMPLEMENTACION: GestorCSV
   ============================================================ */
GestorCSV::GestorCSV(const char* archivo)
{
    strcpy(nombreArchivo, archivo);
}

void GestorCSV::leerTodos()
{
    /* En Borland: ifstream acepta char* directamente (sin .c_str()) */
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        cout << "El archivo no existe o esta vacio." << endl;
        return;
    }

    char linea[300];
    int conteo = 0;

    cout << endl;
    cout << "========== INVENTARIO ==========" << endl;

    while (archivo.getline(linea, 300))
    {
        if (strlen(linea) == 0)
            continue;
        Producto p = Producto::desdeCSV(linea);
        p.mostrar();
        conteo++;
    }

    if (conteo == 0)
        cout << "No hay articulos registrados." << endl;

    archivo.close();
}

void GestorCSV::agregar(Producto p)
{
    ofstream archivo(nombreArchivo, ios::app);

    if (!archivo.is_open())
    {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    char linea[300];
    p.toCSV(linea, 300);
    archivo << linea << endl;
    archivo.close();
    cout << "Articulo agregado correctamente." << endl;
}

void GestorCSV::actualizar(int codigo, Producto nuevo)
{
    ifstream archivoLectura(nombreArchivo);

    if (!archivoLectura.is_open())
    {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    /* Acumulamos el nuevo contenido en un buffer de lineas */
    /* En C++ moderno: string contenidoNuevo = ""; contenidoNuevo += linea + "\n";
       En Borland: arreglo de lineas con tamano maximo */
    const int MAX_LINEAS = 200;
    char lineas[MAX_LINEAS][300];
    int numLineas = 0;
    int encontrado = 0;

    char linea[300];
    while (archivoLectura.getline(linea, 300))
    {
        if (strlen(linea) == 0)
            continue;

        Producto p = Producto::desdeCSV(linea);

        if (p.codigo == codigo)
        {
            nuevo.codigo = codigo;
            nuevo.toCSV(lineas[numLineas], 300);
            encontrado = 1;
        }
        else
        {
            strcpy(lineas[numLineas], linea);
        }
        numLineas++;
    }

    archivoLectura.close();

    if (!encontrado)
    {
        cout << "No se encontro el articulo con codigo " << codigo << "." << endl;
        return;
    }

    ofstream archivoEscritura(nombreArchivo);
    for (int i = 0; i < numLineas; i++)
    {
        archivoEscritura << lineas[i] << endl;
    }
    archivoEscritura.close();

    cout << "Articulo actualizado correctamente." << endl;
}

void GestorCSV::eliminar(int codigo)
{
    ifstream archivoLectura(nombreArchivo);

    if (!archivoLectura.is_open())
    {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    const int MAX_LINEAS = 200;
    char lineas[MAX_LINEAS][300];
    int numLineas = 0;
    int encontrado = 0;

    char linea[300];
    while (archivoLectura.getline(linea, 300))
    {
        if (strlen(linea) == 0)
            continue;

        Producto p = Producto::desdeCSV(linea);

        if (p.codigo == codigo)
        {
            encontrado = 1;
            /* No copiamos esta linea -> queda eliminada */
        }
        else
        {
            strcpy(lineas[numLineas], linea);
            numLineas++;
        }
    }

    archivoLectura.close();

    if (!encontrado)
    {
        cout << "No se encontro el articulo con codigo " << codigo << "." << endl;
        return;
    }

    ofstream archivoEscritura(nombreArchivo);
    for (int i = 0; i < numLineas; i++)
    {
        archivoEscritura << lineas[i] << endl;
    }
    archivoEscritura.close();

    cout << "Articulo eliminado correctamente." << endl;
}

/* ============================================================
   Funcion auxiliar para el menu
   ============================================================ */
void procesarOpcion(int opcion, GestorCSV& gestor)
{
    if (opcion < 0 || opcion > 4)
    {
        cout << "Opcion no valida. Elige entre 0 y 4." << endl;
        return;
    }

    if (opcion == 0)
        return;

    switch (opcion)
    {
        case 1:
        {
            gestor.leerTodos();
            break;
        }

        case 2:
        {
            int   codigo;
            char  nombre[100];
            float precio;

            cout << "Codigo  : ";
            cin  >> codigo;
            cin.ignore(255, '\n');

            cout << "Nombre  : ";
            cin.getline(nombre, 100);

            cout << "Precio  : ";
            cin  >> precio;

            Producto nuevo(codigo, nombre, precio);
            gestor.agregar(nuevo);
            break;
        }

        case 3:
        {
            int   codigo;
            char  nombre[100];
            float precio;

            cout << "Codigo a actualizar : ";
            cin  >> codigo;
            cin.ignore(255, '\n');

            cout << "Nuevo nombre        : ";
            cin.getline(nombre, 100);

            cout << "Nuevo precio        : ";
            cin  >> precio;

            Producto nuevo(codigo, nombre, precio);
            gestor.actualizar(codigo, nuevo);
            break;
        }

        case 4:
        {
            int codigo;
            cout << "Codigo a eliminar: ";
            cin  >> codigo;
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
        cout << endl;
        cout << "================================" << endl;
        cout << "    SISTEMA DE INVENTARIO CSV   " << endl;
        cout << "================================" << endl;
        cout << "  1. Ver todos los articulos    " << endl;
        cout << "  2. Agregar articulo           " << endl;
        cout << "  3. Actualizar articulo        " << endl;
        cout << "  4. Eliminar articulo          " << endl;
        cout << "  0. Salir                      " << endl;
        cout << "================================" << endl;
        cout << "Elige una opcion: ";
        cin  >> opcion;
        cin.ignore(255, '\n');

        procesarOpcion(opcion, gestor);

    } while (opcion != 0);

    cout << endl << "Hasta luego." << endl;
    return 0;
}
