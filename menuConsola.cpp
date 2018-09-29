#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <fstream>
#include "algoritmos.h"
#include "algortimoslibro.h"
#include "commonobject.h"

using namespace std;


int main()
{
    //Principales funciones del menu.
    //Primero carga las palabras necesarias en una listadoble.
    listaDoble<listaDoble<char>> *biblioteca = new listaDoble<listaDoble<char>>();
    //Cargo las palabras.
    char c;
    cout << " Lectura y escritura del archivo anterior\n";

    ifstream fichero1("Biblioteca", ios::in);
    //Ese es un ejemplo de como guardar un Commobject Palabra
    listaDoble<char> *LaPalabra = new listaDoble<char>();
    Palabra *aux = new Palabra(LaPalabra);

    while(fichero1.get(c)){
        if(c == ',') {
            biblioteca->insertar(*LaPalabra);
            LaPalabra = new listaDoble<char>();
            cout << "\n (";
            aux->printDato();
            cout << " )\n";
            aux = new Palabra(LaPalabra);
            cout << " -> ";
        }
        else {
            aux->insertarElemento(c);
            cout.put(c);
        }
    }
    cout << " Fin\n";
    fichero1.close();


    //Pregunta, Que estructura quiere usar?
    int opcionEs = 0, opcionOb = 0, opcionOr = 0, cantidadObjetos = 0;
    cout << "Para salir inserte -1.";
    do{
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout << "Que estructura quiere utilizar?\n";
        cout << "Para cola digite ----------------- 1.\n";
        cout << "Para pila digite ----------------- 2.\n";
        cout << "Para lista simple digite --------- 3.\n";
        cout << "Para lista doble digite ---------- 4.\n";
        cout << "Para lista doble circular digite - 5.\n";
        cin >> opcionEs;
        cout << "Usted eligio la opcion ..." << opcionEs<< "\n";
        if(opcionEs < 0) break;

        //Creacion de objetos
        opcionOb = 0;
        if(opcionEs < 5 || opcionEs > 0) do{
            cantidadObjetos = 0;
            cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
            cout << "Que objeto quiere ordenar?\n";
            cout << "Para Numero digite -- 1.\n";
            cout << "Para Letra digite --- 2.\n";
            cout << "Para Palabra digite - 3.\n";
            cin >> opcionOb;
            if(opcionOb > 3 || opcionOb <= 0) {
                cout << "Opcion inexistente.\n";
            }
            else{
                cout << "Cuantos objetos quiere?\n";
                cin >> cantidadObjetos;
                if(cantidadObjetos <= 0){
                    cout << "Cantidad invalida.\n";
                }
                else{
                    cout << "Se crearon " <<cantidadObjetos<<" de tipo "<< opcionOb;
                    opcionOb = -3;
                }
            }
        }while(opcionOb > 0);

        //Obciones para ordenar
        if(opcionOb == -3) do{
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
                cout << "Que algoritmo quiere utilizar?\n";
                cout << "Para Seleccion digite --------------- 1.\n";
                cout << "Para Insercion digite --------------- 2.\n";
                cout << "Para Burbuja digite ----------------- 3.\n";
                cout << "Para Burbuja Bidireccional digite --- 4.\n";
                cout << "Para Shell digite ------------------- 5.\n";
                cout << "Para HeapSort digite ---------------- 6.\n";
                cout << "Para MergeSort digite --------------- 7.\n";
                cout << "Para RadixSort digite --------------- 8.\n";
                cout << "Para BinSort digite ----------------- 9.\n";
                cout << "Para QuickSort digite --------------- 10.\n";
                cin >> opcionOr;
                if( opcionOr > 10 || opcionOr < -1) cout << "Obcion incorrecta.\n";
                else{
                    cout << "Algoritmo  "<<opcionOr<<": .....\n";
                    opcionOr = -1;
                }
            }while(opcionOr > 0);

        }while(opcionEs > 0);

    return 0;
}
