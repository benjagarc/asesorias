#include <iostream>

using namespace std;

int main() {

    cout << "===== CICLO FOR =====" << endl;

    // For básico: del 1 al 5
    cout << "Del 1 al 10 de 2 en 2: " << endl;
    for (int i = 2; i < 10; i+= 2) {
        cout << i << " " << endl;
    }
    cout << endl;

    int numero = 9;

    for (int i = 1; i <= 10; i++) {
        cout << numero << " x "<< i << " = " << numero * i << endl;
    }

    for (int i = 1; i <= 20; i+= 2) {
       cout << i << endl;
    }

    for (int i = 0; i <= 20; i+= 2) {
       cout << i << endl;
    }

    cout << "====================" << endl;

    for(int i = 1; i <= 10; i++) {
        int res = i % 2;
        if( res != 0) {
            cout << i << endl;
        }
    }


    return 0;
}