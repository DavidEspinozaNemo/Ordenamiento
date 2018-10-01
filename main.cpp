#include <QCoreApplication>
#include "algoritmos.cpp"
#include "cola.cpp"
#include "PilaGenerica.cpp"
#include "listadoble.cpp"
#include "listadoblecircular.cpp"
#include "listasimple.cpp"
#include "claseextra.cpp"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <fstream>
#include "commonobject.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    //Principales funciones del menu.
        //Primero carga las palabras necesarias en una listadoble. yuyuyuyuyuyu
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
            */

        //Pregunta, Que estructura quiere usar?
        int opcionEs = 0, opcionOb = 0, opcionOr = 0, cantidadObjetos = 0;
        int guardaEs=0,guardaOb=0,guardaOr=0,guardaCantidad=0;
        cout << "Para salir inserte -1.";
        do{
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
            cout << "Que estructura quiere utilizar?\n";
            cout << "Para lista simple digite --------- 1.\n";
            cout << "Para lista doble digite ---------- 2.\n";
            cout << "Para lista doble circular digite - 3.\n";
            cout << "Para cola digite ----------------- 4.\n";
            cout << "Para pila digite ----------------- 5.\n";

            cin >> opcionEs;
            guardaEs = opcionEs;
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
                cout << "Para Objeto digite -- 4.\n";
                cin >> opcionOb;
                guardaOb = opcionOb;
                if(opcionOb > 4 || opcionOb <= 0) {
                    cout << "Opcion inexistente.\n";
                }
                else{
                    cout << "Cuantos objetos quiere?\n";
                    cin >> cantidadObjetos;
                    guardaCantidad = cantidadObjetos;
                    if(cantidadObjetos <= 0){
                        cout << "Cantidad invalida.\n";
                    }
                    else{
                        //cout << "Se crearon " <<cantidadObjetos<<" de tipo "<< opcionOb;

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
                    guardaOr = opcionOr;
                    if( opcionOr > 10 || opcionOr < -1) cout << "Obcion incorrecta.\n";
                    else{
                        cout << "Algoritmo  "<<opcionOr<<": .....\n";
                        opcionOr = -1;
                    }
                }while(opcionOr > 0);


            switch (guardaEs) {
            case 1:
            {
                switch (guardaOb) {
                case 1:
                {
                    listaSimple<int>* listaPrueba2 = new listaSimple<int>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar(3,0,0);
                    }

                    listaPrueba2->mostrarLista();

                    break;
                }
                case 2:
                {
                    listaSimple<char>* listaPrueba2 = new listaSimple<char>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar('a',0,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 3:
                {
                    listaSimple<string>* listaPrueba2 = new listaSimple<string>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar("hola",1,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 4:
                {
                    listaSimple<persona*>* listaPrueba2 = new listaSimple<persona*>();
                    persona* persona1 = new persona("yosua",21,116830903);
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar(persona1,0,1);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                }
            break;
            }
            case 2:
            {
                switch (guardaOb) {
                case 1:
                {
                    listaDoble<int>* listaPrueba2 = new listaDoble<int>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar(3,0,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 2:
                {
                    listaDoble<char>* listaPrueba2 = new listaDoble<char>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar('a',0,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 3:
                {
                    listaDoble<string>* listaPrueba2 = new listaDoble<string>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar("hola",1,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 4:
                {
                    listaDoble<persona*>* listaPrueba2 = new listaDoble<persona*>();
                    persona* persona1 = new persona("yosua",21,116830903);
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar(persona1,0,1);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                }
            break;
            }
            case 3:{

                switch (guardaOb) {
                case 1:
                {
                    listaDobleCircular<int>* listaPrueba2 = new listaDobleCircular<int>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar(3,0,0);
                    }
                    listaPrueba2->mostrarLista();



                    break;
                }
                case 2:
                {
                    listaDobleCircular<char>* listaPrueba2 = new listaDobleCircular<char>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar('a',0,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 3:
                {
                    listaDobleCircular<string>* listaPrueba2 = new listaDobleCircular<string>();
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar("hola",1,0);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                case 4:
                {
                    listaDobleCircular<persona*>* listaPrueba2 = new listaDobleCircular<persona*>();
                    persona* persona1 = new persona("yosua",21,116830903);
                    for(int x=0;x<guardaCantidad;x++){
                        listaPrueba2->insertar(persona1,0,1);
                    }
                    listaPrueba2->mostrarLista();

                    break;
                }
                }
                break;
            }
            case 4:
            {
                switch (guardaOb) {
                case 1:
                {
                    cola<int>* colaPrueba2 = new cola<int>();
                    for(int x=0;x<guardaCantidad;x++){
                        colaPrueba2->insertar(3,0,0);
                    }
                    colaPrueba2->mostrarCola(*colaPrueba2);
                    break;
                }
                case 2:
                {
                    cola<char>* colaPrueba2 = new cola<char>();
                    for(int x=0;x<guardaCantidad;x++){
                        colaPrueba2->insertar('a',0,0);
                    }
                    colaPrueba2->mostrarCola(*colaPrueba2);
                    break;
                }
                case 3:
                {
                    cola<string>* colaPrueba2 = new cola<string>();
                    for(int x=0;x<guardaCantidad;x++){
                        colaPrueba2->insertar("hola",1,0);
                    }
                    colaPrueba2->mostrarCola(*colaPrueba2);
                    break;
                }
                case 4:
                {
                    cola<persona*>* colaPrueba2 = new cola<persona*>();
                    persona* persona1 = new persona("yosua",21,116830903);
                    for(int x=0;x<guardaCantidad;x++){
                        colaPrueba2->insertar(persona1,1,0);
                    }
                    colaPrueba2->mostrarCola(*colaPrueba2);

                    break;
                }
                }
                break;
            }
            case 5:{
                switch (guardaOb) {
                case 1:
                {
                    PilaGenerica<int>* pilaPrueba2 = new PilaGenerica<int>();
                    for(int x=0;x<guardaCantidad;x++){
                        pilaPrueba2->insertar(3,0,0);
                    }
                    pilaPrueba2->mostrarPila();
                    break;
                }
                case 2:
                {
                    PilaGenerica<char>* pilaPrueba2 = new PilaGenerica<char>();
                    for(int x=0;x<guardaCantidad;x++){
                        pilaPrueba2->insertar('a',0,0);
                    }
                    pilaPrueba2->mostrarPila();
                    break;
                }
                case 3:
                {
                    PilaGenerica<string>* pilaPrueba2 = new PilaGenerica<string>();
                    for(int x=0;x<guardaCantidad;x++){
                        pilaPrueba2->insertar("hola",1,0);
                    }
                    pilaPrueba2->mostrarPila();
                    break;
                }
                case 4:
                {
                    PilaGenerica<persona*>* pilaPrueba2 = new PilaGenerica<persona*>();
                    persona* persona1 = new persona("yosua",21,116830903);
                    for(int x=0;x<guardaCantidad;x++){
                        pilaPrueba2->insertar(persona1,1,0);
                    }
                    pilaPrueba2->mostrarPila();

                    break;
                }
                }
                break;
            }

            }

            }while(opcionEs > 0);


        /*
        //tri_shell(l); //FUNCIONA
    //tri_insertion(l) //FUNCIONA;
    //tri_selection(l,20); // FUNCIONA
    //tri_gnome(l); //FUNCIONA

*/
    return a.exec();
}
