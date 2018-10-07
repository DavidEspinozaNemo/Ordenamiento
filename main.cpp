#include <QCoreApplication>
#include "PilaGenerica.cpp"
#include "cola.cpp"
#include "listadoble.cpp"
#include "listadoblecircular.cpp"
#include "listasimple.cpp"
#include "algoritmos.cpp"
#include "valoresaleatorios.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Pregunta, Que estructura quiere usar?
            int opcionEs = 0, opcionOb = 0, opcionOr = 0, cantidadObjetos = 0;
            int guardaEs=0,guardaOb=0,guardaOr=0,guardaCantidad=0;
            cout << "Para salir inserte -1.";
            do{
                cout << "-"
                           "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
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
                case 1: //Caso para la listaSimple
                {
                    switch (guardaOb) {
                    case 1: //numeros
                    {
                        listaSimple<int>* listaPrueba2 = new listaSimple<int>();
                        generarNumeros(listaPrueba2,guardaCantidad);
                        listaSimple<int>* listaAux = new listaSimple<int>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";

                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 8:{
                            clock_t start = clock();
                            radixsort(listaPrueba2, new listaSimple<int>(),listaPrueba2->cantDatos()-1);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        } //->Para los algoritmos

                        break;
                    }
                    case 2: //chars
                    {
                        listaSimple<char>* listaPrueba2 = new listaSimple<char>();
                        generarChars(listaPrueba2, guardaCantidad);
                        listaSimple<char>* listaAux = new listaSimple<char>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 3: //string
                    {
                        listaSimple<string>* listaPrueba2 = new listaSimple<string>();
                        generarPalabras(listaPrueba2, guardaCantidad);
                        listaSimple<string>* listaAux = new listaSimple<string>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 4: //Objeto
                    {
                        listaSimple<persona*>* listaPrueba2 = new listaSimple<persona*>();
                        listaSimple<persona*>* listaAux = new listaSimple<persona*>();
                        generarPersonas(listaPrueba2, guardaCantidad);
                        listaPrueba2->mostrarLista();

                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    }
                break;
                }
                case 2: //Caso pala la lista Doble
                {
                    switch (guardaOb) {
                    case 1: //numeros
                    {
                        listaDoble<int>* listaPrueba2 = new listaDoble<int>();
                        generarNumeros(listaPrueba2,guardaCantidad);
                        listaDoble<int> *listaAux = new listaDoble<int>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 2: //chars
                    {
                        listaDoble<char>* listaPrueba2 = new listaDoble<char>();
                        generarChars(listaPrueba2, guardaCantidad);
                        listaDoble<char> *listaAux = new listaDoble<char>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 3: //strings
                    {
                        listaDoble<string>* listaPrueba2 = new listaDoble<string>();
                        generarPalabras(listaPrueba2, guardaCantidad);
                        listaDoble<string> *listaAux = new listaDoble<string>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 4: //objetos
                    {
                        listaDoble<persona*>* listaPrueba2 = new listaDoble<persona*>();
                        listaDoble<persona*>* listaAux = new listaDoble<persona*>();
                        generarPersonas(listaPrueba2, guardaCantidad);
                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quickSort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    }
                break;
                }
                case 3: //Caso para la lista Doble circular
                {
                    switch (guardaOb) {
                    case 1: //numeros
                    {
                        listaDobleCircular<int>* listaPrueba2 = new listaDobleCircular<int>();
                        generarNumeros(listaPrueba2,guardaCantidad);
                        listaDobleCircular<int>* listaAux = new listaDobleCircular<int>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            listaPrueba2->insertar(0); //insertar una cabeza
                            listaPrueba2->cambio(0,listaPrueba2->cantDatos());
                            quickSort(listaPrueba2, 1, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 2: //chars
                    {
                        listaDobleCircular<char>* listaPrueba2 = new listaDobleCircular<char>();
                        generarChars(listaPrueba2, guardaCantidad);
                        listaDobleCircular<char>* listaAux = new listaDobleCircular<char>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            listaPrueba2->insertar('*'); //insertar una cabeza
                            listaPrueba2->cambio(0,listaPrueba2->cantDatos());
                            quickSort(listaPrueba2, 1, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 3: //strings
                    {
                        listaDobleCircular<string>* listaPrueba2 = new listaDobleCircular<string>();
                        generarPalabras(listaPrueba2, guardaCantidad);
                        listaDobleCircular<string>* listaAux = new listaDobleCircular<string>();

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            listaPrueba2->insertar("->inicio"); //insertar una cabeza
                            listaPrueba2->cambio(0,listaPrueba2->cantDatos());
                            quickSort(listaPrueba2, 1, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    case 4: //objetos
                    {
                        listaDobleCircular<persona*>* listaPrueba2 = new listaDobleCircular<persona*>();
                        listaDobleCircular<persona*>* listaAux = new listaDobleCircular<persona*>();
                        generarPersonas(listaPrueba2, guardaCantidad);
                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            listaPrueba2->insertar(new persona("Nadie",0,1000000)); //insertar una cabeza
                            listaPrueba2->cambio(0,listaPrueba2->cantDatos());
                            quickSort(listaPrueba2, 1, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            cout << "\nTiempo transcurrido: " << ((double)clock() - start)<<"\n";
                            break;
                        }
                        }
                        break;
                    }
                    }
                break;
                }
                case 4: //Caso para la cola
                {
                    switch (guardaOb)
                    {
                    case 1: //Numeros
                    {
                        cola<int>* colaPrueba2 = new cola<int>();
                        generarNumeros(colaPrueba2,guardaCantidad);

                        colaPrueba2->mostrarCola(*colaPrueba2);


                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 2: //chars
                    {
                        cola<char>* colaPrueba2 = new cola<char>();
                        generarChars(colaPrueba2, guardaCantidad);

                        colaPrueba2->mostrarCola(*colaPrueba2);
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 3: //String
                    {
                        cola<string>* colaPrueba2 = new cola<string>();
                        generarPalabras(colaPrueba2, guardaCantidad);

                        colaPrueba2->mostrarCola(*colaPrueba2);
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 4: //objetos
                    {
                        cola<persona*>* colaPrueba2 = new cola<persona*>();
                        generarPersonas(colaPrueba2, guardaCantidad);
                        colaPrueba2->mostrarCola(*colaPrueba2);

                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    }
                    break;
                }
                case 5: //Caso para la pila
                {
                    switch (guardaOb) {
                    case 1: //numeros
                    {
                        PilaGenerica<int>* pilaPrueba2 = new PilaGenerica<int>();
                        generarNumeros(pilaPrueba2,guardaCantidad);

                        pilaPrueba2->mostrarPila();
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 2: //chars
                    {
                        PilaGenerica<char>* pilaPrueba2 = new PilaGenerica<char>();
                        generarChars(pilaPrueba2, guardaCantidad);

                        pilaPrueba2->mostrarPila();
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 3: //String
                    {
                        PilaGenerica<string>* pilaPrueba2 = new PilaGenerica<string>();
                        generarPalabras(pilaPrueba2, guardaCantidad);

                        pilaPrueba2->mostrarPila();
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 4: //objetos
                    {
                        PilaGenerica<persona*>* pilaPrueba2 = new PilaGenerica<persona*>();
                        generarPersonas(pilaPrueba2, guardaCantidad);
                        pilaPrueba2->mostrarPila();

                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    }
                    break;
                }

                }

                }while(opcionEs > 0);





    return a.exec();
}
