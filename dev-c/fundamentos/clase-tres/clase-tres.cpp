#include <iostream> 

using namespace std;

void tablaTres () {
    int i = 1;
    // 2 x 1 =2   
    // 2 x 2 =4   
    // 2 x 3 =6   
    // 2 x 4 =8   
    // 2 x 5 =10
    cout << "Tabla de multiplicar del numero 3" << endl;

    do
    {

        cout << " 3 x " << i << " = " << (3*i) << endl;
        i++;
    } while (i <= 10);
}

void cincoACien() {

    cout << "Se van a imprimir los numero de 5 en 5 hasta el 100"<< endl;
    int i = 1;
    do {
        cout << ( 5 * i) << endl;
        i++;
    } while (i <= 20);
    
}

// void cincoACienSumando() {
//     cout << "Se van a imprimir los numero de 5 en 5 hasta el 100"<< endl;

//    int i = 5;
//     do {
//         cout << ( 5 + i) << endl;
//         i+= 5;
//     } while (i <= 95);
// }

// void cincoACienSumando() {
//     cout << "Se van a imprimir los numero de 5 en 5 hasta el 100"<< endl;

//     int i = 0;
//     do {
//         cout << ( 5 + i) << endl;
//         i+= 5;
//     } while (i <= 95);
// }

void cincoACienSumando() {
    cout << "Se van a imprimir los numero de 5 en 5 hasta el 100"<< endl;

    int i = 5;
    do {
        cout << (i) << endl;
        i+= 5;
    } while (i <= 100);
}

int main() {
    cout << "Dentro de main" << endl; 
    // tablaTres();
    // cincoACien();
    cincoACienSumando();
    return 0;
}