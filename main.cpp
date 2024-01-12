#include <iostream>

using namespace std;

/* Se dispone de un lote de valores enteros positivos que finaliza con un número
negativo.
El lote está dividido en sublotes por medio de valores cero. Desarrollar un programa que
determine e informe:
a) por cada sublote el promedio de valores
b) el total de sublotes procesados
c) el valor máximo del conjunto, indicando en que sublote se encontró y la posición
relativa del mismo dentro del sublote
d) valor mínimo de cada sublote
Nota: el lote puede estar vacío (primer valor negativo), o puede haber uno, varios o todos los
sublotes vacíos (ceros consecutivos)  */

int main()
{
    int valor, lote = 1, suma, pos, maximo = 0, maximo_lote, pos_maximo_lote, minimo;
    while(valor >= 0){
        suma = 0;
        pos = 0;
        cout << "Ingresar un valor para el sublote " << lote << endl;
        cin >> valor;
        minimo = valor;

        // ========== Division de sublotes ==========
        while(valor > 0){
            suma += valor;
            pos++;

            if(valor > maximo){
                maximo = valor;
                maximo_lote = lote;
                pos_maximo_lote = pos;
            }

            if(valor < minimo){
                minimo = valor;
            }

            cout << "Ingresar un valor para el sublote " << lote << endl;
            cin >> valor;
        }
        // ==========================================

        if(pos){
            cout << "Promedio de sublote " << lote << ": " << (float) suma / pos << endl;
            cout << "El valor minimo ingresado es el " << minimo << endl;
        }
        else{
            cout << "Sublote vacio." << endl;
        }

        lote++;
    }
    if(maximo){
        cout << "Cantidad de sublotes ingresados: " << lote - 1 << endl;
        cout << "El maximo valor ingresado es el " << maximo << " en el sublote " << maximo_lote << " en la posicion " << pos_maximo_lote << "." << endl;
    }
    else{
        cout << "No se ingresaron valores." << endl;
    }
    return 0;
}
