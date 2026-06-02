#include <iostream>
#include <fstream>
#include <string>
#include <sstream>   // Para ostringstream y stringstream
using namespace std;

// ============================================================
//   SISTEMA DE INVENTARIO - OPERACIONES CON ARCHIVO CSV
// ============================================================
// Este programa permite:
//   - Leer todos los artículos del inventario
//   - Agregar un artículo nuevo
//   - Actualizar un artículo existente
//   - Eliminar un artículo
//
// Los datos se guardan en un archivo de texto llamado
// "productos.csv" donde cada línea tiene el formato:
//   codigo,nombre,precio
//   Ejemplo: 101,Silla de oficina,350.50
//
// Conceptos de POO que se practican:
//   - Clases y Objetos
//   - Constructor
//   - Métodos (funciones dentro de una clase)
//   - Método estático (static)
//   - Atributos públicos y privados
// ============================================================


// ============================================================
//                      CLASE: Producto
// ============================================================
// Representa UN solo artículo del inventario.
// Cada objeto de esta clase guarda el código, nombre
// y precio de un artículo.
// ============================================================
class Producto {
public:
    int    codigo;   // Número identificador único del artículo
    string nombre;   // Nombre del artículo
    float  precio;   // Precio en pesos

    // ----------------------------------------------------------
    // Constructor
    // Se ejecuta automáticamente cuando se crea un objeto.
    // Recibe los tres datos del artículo y los guarda.
    // Uso: Producto p(101, "Silla", 350.50);
    // ----------------------------------------------------------
    Producto(int c, string n, float p) {
        codigo = c;
        nombre = n;
        precio = p;
    }

    // ----------------------------------------------------------
    // Método: mostrar
    // Imprime los datos del artículo en pantalla con formato.
    // ----------------------------------------------------------
    void mostrar() {
        cout << "  Codigo : " << codigo        << endl;
        cout << "  Nombre : " << nombre        << endl;
        cout << "  Precio : $" << precio       << endl;
        cout << "  --------------------------" << endl;
    }

    // ----------------------------------------------------------
    // Método: toCSV
    // Convierte el objeto a una línea en formato CSV.
    // Ejemplo de salida: "101,Silla de oficina,350.5"
    // Esta línea es la que se guarda en el archivo.
    // ----------------------------------------------------------
    string toCSV() {
        ostringstream oss;
        oss << codigo << "," << nombre << "," << precio;
        return oss.str();
    }

    // ----------------------------------------------------------
    // MÉTODO ESTÁTICO: desdeCSV
    // ----------------------------------------------------------
    // "static" significa que este método pertenece a la CLASE,
    // no a un objeto en particular. Se puede llamar así:
    //
    //   Producto p = Producto::desdeCSV("101,Silla,350.5");
    //
    // Nótese el uso de "::" en lugar de un objeto.
    //
    // Su función es leer una línea del CSV y convertirla
    // en un objeto Producto listo para usar en el programa.
    // ----------------------------------------------------------
    static Producto desdeCSV(string linea) {
        stringstream ss(linea);
        string parteCodigo, parteNombre, partePrecio;

        // Dividir la línea usando la coma como separador
        getline(ss, parteCodigo, ',');
        getline(ss, parteNombre, ',');
        getline(ss, partePrecio, ',');

        int   c = atoi(parteCodigo.c_str());  // Texto -> número entero
        float p = atof(partePrecio.c_str());  // Texto -> número decimal

        return Producto(c, parteNombre, p);
    }
};


// ============================================================
//                     CLASE: GestorCSV
// ============================================================
// Se encarga de TODAS las operaciones con el archivo CSV.
// Actúa como intermediario entre el programa y el archivo.
//
// Conoce el nombre del archivo y sabe cómo:
//   - Abrir el archivo y leer su contenido
//   - Escribir líneas nuevas al final
//   - Reescribir el archivo para actualizar o eliminar
// ============================================================
class GestorCSV {
private:
    string nombreArchivo;  // Nombre del archivo CSV que se gestiona

public:
    // ----------------------------------------------------------
    // Constructor: recibe el nombre del archivo CSV
    // Uso: GestorCSV gestor("productos.csv");
    // ----------------------------------------------------------
    GestorCSV(string archivo) {
        nombreArchivo = archivo;
    }

    // ----------------------------------------------------------
    // Método: leerTodos
    // Abre el archivo y muestra cada artículo en pantalla.
    // ----------------------------------------------------------
    void leerTodos() {
        ifstream archivo(nombreArchivo.c_str());

        if (!archivo.is_open()) {
            cout << "El archivo no existe o esta vacio." << endl;
            return;
        }

        string linea;
        int conteo = 0;

        cout << endl;
        cout << "========== INVENTARIO ==========" << endl;

        while (getline(archivo, linea)) {
            if (linea == "") continue;              // Ignorar líneas vacías
            Producto p = Producto::desdeCSV(linea); // Convertir línea en objeto
            p.mostrar();
            conteo++;
        }

        if (conteo == 0) {
            cout << "No hay articulos registrados." << endl;
        }

        archivo.close();
    }

    // ----------------------------------------------------------
    // Método: agregar
    // Añade un artículo al FINAL del archivo CSV.
    // ios::app = modo "append" (agregar sin borrar lo existente)
    // ----------------------------------------------------------
    void agregar(Producto p) {
        ofstream archivo(nombreArchivo.c_str(), ios::app);

        if (!archivo.is_open()) {
            cout << "Error: no se pudo abrir el archivo." << endl;
            return;
        }

        archivo << p.toCSV() << endl;
        archivo.close();
        cout << "Articulo agregado correctamente." << endl;
    }

    // ----------------------------------------------------------
    // Método: actualizar
    // Reemplaza los datos de un artículo buscando por código.
    //
    // Estrategia (no se puede editar una línea directamente):
    //   1. Leer todo el archivo línea por línea
    //   2. Si el código coincide, sustituir por los datos nuevos
    //   3. Reescribir el archivo completo con los cambios
    // ----------------------------------------------------------
    void actualizar(int codigo, Producto nuevo) {
        ifstream archivoLectura(nombreArchivo.c_str());

        if (!archivoLectura.is_open()) {
            cout << "Error: no se pudo abrir el archivo." << endl;
            return;
        }

        string contenidoNuevo = "";
        string linea;
        bool encontrado = false;

        while (getline(archivoLectura, linea)) {
            if (linea == "") continue;

            Producto p = Producto::desdeCSV(linea);

            if (p.codigo == codigo) {
                nuevo.codigo = codigo;                   // Conservar el código original
                contenidoNuevo += nuevo.toCSV() + "\n"; // Guardar la versión actualizada
                encontrado = true;
            } else {
                contenidoNuevo += linea + "\n";          // Conservar las demás líneas tal cual
            }
        }

        archivoLectura.close();

        if (!encontrado) {
            cout << "No se encontro el articulo con codigo " << codigo << "." << endl;
            return;
        }

        // Reescribir el archivo completo con el contenido modificado
        ofstream archivoEscritura(nombreArchivo.c_str());
        archivoEscritura << contenidoNuevo;
        archivoEscritura.close();

        cout << "Articulo actualizado correctamente." << endl;
    }

    // ----------------------------------------------------------
    // Método: eliminar
    // Borra un artículo del archivo buscando por código.
    //
    // Estrategia (igual que actualizar):
    //   1. Leer todo el archivo línea por línea
    //   2. Si el código coincide, NO copiar esa línea
    //   3. Reescribir el archivo sin la línea eliminada
    // ----------------------------------------------------------
    void eliminar(int codigo) {
        ifstream archivoLectura(nombreArchivo.c_str());

        if (!archivoLectura.is_open()) {
            cout << "Error: no se pudo abrir el archivo." << endl;
            return;
        }

        string contenidoNuevo = "";
        string linea;
        bool encontrado = false;

        while (getline(archivoLectura, linea)) {
            if (linea == "") continue;

            Producto p = Producto::desdeCSV(linea);

            if (p.codigo == codigo) {
                encontrado = true;      // Esta línea se omite (no se copia)
            } else {
                contenidoNuevo += linea + "\n";
            }
        }

        archivoLectura.close();

        if (!encontrado) {
            cout << "No se encontro el articulo con codigo " << codigo << "." << endl;
            return;
        }

        ofstream archivoEscritura(nombreArchivo.c_str());
        archivoEscritura << contenidoNuevo;
        archivoEscritura.close();

        cout << "Articulo eliminado correctamente." << endl;
    }
};


// ============================================================
//                   FUNCIÓN: procesarOpcion
// ============================================================
// Contiene la lógica de cada opción del menú.
//
// EARLY RETURN: lo primero que hace es verificar si la opción
// es válida. Si no lo es, imprime un aviso y RETORNA de
// inmediato, evitando ejecutar el resto del código.
//
// Esto es el patrón "early return" (retorno anticipado):
//   - Se validan las condiciones de error al inicio.
//   - Si hay un problema, se sale de la función enseguida.
//   - El caso "feliz" (opción válida) queda limpio y plano.
// ============================================================
void procesarOpcion(int opcion, GestorCSV& gestor) {

    // ----------------------------------------------------------
    // EARLY RETURN #1 — opción fuera de rango
    // Si el usuario escribió algo que no está en el menú,
    // avisamos y salimos de inmediato. No se ejecuta nada más.
    // ----------------------------------------------------------
    if (opcion < 0 || opcion > 4) {
        cout << "Opcion no valida. Elige entre 0 y 4." << endl;
        return;   // <-- salida anticipada
    }

    // ----------------------------------------------------------
    // EARLY RETURN #2 — opción "Salir"
    // Si el usuario elige 0, no hay nada que procesar aquí.
    // El bucle do-while en main() se encargará de terminar.
    // ----------------------------------------------------------
    if (opcion == 0) {
        return;   // <-- salida anticipada
    }

    // A partir de aquí sabemos que opcion está entre 1 y 4.
    // El switch maneja cada caso sin necesidad de else anidados.
    switch (opcion) {

        case 1: {
            // ---- VER TODOS ----
            gestor.leerTodos();
            break;
        }

        case 2: {
            // ---- AGREGAR ----
            int    codigo;
            string nombre;
            float  precio;

            cout << "Codigo  : ";
            cin  >> codigo;
            cin.ignore();

            cout << "Nombre  : ";
            getline(cin, nombre);   // getline permite capturar espacios

            cout << "Precio  : ";
            cin  >> precio;

            Producto nuevo(codigo, nombre, precio);
            gestor.agregar(nuevo);
            break;
        }

        case 3: {
            // ---- ACTUALIZAR ----
            int    codigo;
            string nombre;
            float  precio;

            cout << "Codigo a actualizar : ";
            cin  >> codigo;
            cin.ignore();

            cout << "Nuevo nombre        : ";
            getline(cin, nombre);

            cout << "Nuevo precio        : ";
            cin  >> precio;

            Producto nuevo(codigo, nombre, precio);
            gestor.actualizar(codigo, nuevo);
            break;
        }

        case 4: {
            // ---- ELIMINAR ----
            int codigo;
            cout << "Codigo a eliminar: ";
            cin  >> codigo;
            gestor.eliminar(codigo);
            break;
        }
    }
}


// ============================================================
//                       FUNCIÓN MAIN
// ============================================================
// Punto de entrada del programa.
// Crea el gestor y muestra el menú en un bucle
// hasta que el usuario elija salir (opción 0).
//
// Delega el procesamiento de cada opción a procesarOpcion(),
// que aplica el patrón early return internamente.
// ============================================================
int main() {
    GestorCSV gestor("productos.csv");
    int opcion;

    do {
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
        cin.ignore();   // Limpiar el buffer del teclado antes de leer texto

        procesarOpcion(opcion, gestor);

    } while (opcion != 0);

    cout << endl << "Hasta luego." << endl;
    return 0;
}
