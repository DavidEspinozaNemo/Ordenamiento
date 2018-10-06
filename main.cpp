#include <QCoreApplication>
#include "PilaGenerica.cpp"
#include "cola.cpp"
#include "listadoble.cpp"
#include "listadoblecircular.cpp"
#include "listasimple.cpp"
#include "algoritmos.cpp"
#include "valoresaleatorios.h"


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
                        listaSimple<int>* listaAux = new listaSimple<int>();
                        listaDoble<int> *aux = new listaDoble<int>();
                        aux = generarNumeros(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            clock_t start = clock();
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            printf("Tiempo transcurrido: %f", ((double)clock() - start));
                            break;
                        }
                        case 2:{
                            clock_t start = clock();
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();
                            printf("Tiempo transcurrido: %f", ((double)clock() - start));
                            break;
                        }
                        case 3:{
                            clock_t start = clock();
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            printf("Tiempo transcurrido: %f", ((double)clock() - start));
                            break;
                        }
                        case 4:{
                            clock_t start = clock();
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            printf("Tiempo transcurrido: %f", ((double)clock() - start));
                            break;
                        }case 5:{
                            clock_t start = clock();
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            printf("Tiempo transcurrido: %f", ((double)clock() - start));
                            break;
                        }
                        case 10:{
                            clock_t start = clock();
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            printf("Tiempo transcurrido: %f", ((double)clock() - start));
                            break;
                        }
                        } //->Para los algoritmos

                        break;
                    }
                    case 2: //chars
                    {
                        listaSimple<char>* listaPrueba2 = new listaSimple<char>();
                        listaDoble<char> *aux = new listaDoble<char>();
                        listaSimple<char>* listaAux = new listaSimple<char>();
                        aux = generarChars(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 3: //string
                    {
                        listaSimple<string>* listaPrueba2 = new listaSimple<string>();
                        listaDoble<string> *aux = new listaDoble<string>();
                        listaSimple<string>* listaAux = new listaSimple<string>();
                        aux = generarPalabras(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 4: //Objeto
                    {
                        listaSimple<persona*>* listaPrueba2 = new listaSimple<persona*>();
                        listaSimple<persona*>* listaAux = new listaSimple<persona*>();
                        persona* persona1 = new persona("yosua",21,116830903);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(persona1);
                        }
                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
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
                        listaDoble<int> *aux = new listaDoble<int>();
                        listaDoble<int> *listaAux = new listaDoble<int>();
                        aux = generarNumeros(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 2: //chars
                    {
                        listaDoble<char>* listaPrueba2 = new listaDoble<char>();
                        listaDoble<char> *aux = new listaDoble<char>();
                        listaDoble<char> *listaAux = new listaDoble<char>();
                        aux = generarChars(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 3: //strings
                    {
                        listaDoble<string>* listaPrueba2 = new listaDoble<string>();
                        listaDoble<string> *aux = new listaDoble<string>();
                        listaDoble<string> *listaAux = new listaDoble<string>();
                        aux = generarPalabras(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 4: //objetos
                    {
                        listaDoble<persona*>* listaPrueba2 = new listaDoble<persona*>();
                        listaDoble<persona*>* listaAux = new listaDoble<persona*>();
                        persona* persona1 = new persona("yosua",21,116830903);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(persona1);
                        }
                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
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
                        listaDoble<int> *aux = new listaDoble<int>();
                        listaDobleCircular<int>* listaAux = new listaDobleCircular<int>();
                        aux = generarNumeros(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 2: //chars
                    {
                        listaDobleCircular<char>* listaPrueba2 = new listaDobleCircular<char>();
                        listaDoble<char> *aux = new listaDoble<char>();
                        listaDobleCircular<char>* listaAux = new listaDobleCircular<char>();
                        aux = generarChars(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 3: //strings
                    {
                        listaDobleCircular<string>* listaPrueba2 = new listaDobleCircular<string>();
                        listaDoble<string> *aux = new listaDoble<string>();
                        listaDobleCircular<string>* listaAux = new listaDobleCircular<string>();
                        aux = generarPalabras(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        }
                        break;
                    }
                    case 4: //objetos
                    {
                        listaDobleCircular<persona*>* listaPrueba2 = new listaDobleCircular<persona*>();
                        persona* persona1 = new persona("yosua",21,116830903);
                        listaDobleCircular<persona*>* listaAux = new listaDobleCircular<persona*>();
                        for(int x=0;x<guardaCantidad;x++){
                            listaPrueba2->insertar(persona1);
                        }
                        listaPrueba2->mostrarLista();
                        switch (guardaOr) {
                        case 1:{
                            tri_selection(listaPrueba2,(listaPrueba2->cantDatos()+1)); // FUNCIONA
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 2:{
                            tri_insertion(listaPrueba2,listaAux); //FUNCIONA;
                            listaPrueba2->mostrarLista();

                            break;
                        }
                        case 3:{
                            tri_bulle(listaPrueba2);
                            listaPrueba2->mostrarLista();
                            break;
                        }
                        case 4:{
                            tri_shaker(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();
                            break;
                        }case 5:{
                            tri_shell(listaPrueba2,listaAux);
                            listaPrueba2->mostrarLista();//FUNCIONA
                            break;
                        }
                        case 10:{
                            quicksort(listaPrueba2, 0, listaPrueba2->cantDatos());
                            listaPrueba2->mostrarLista();
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
                        listaDoble<int> *listaPrueba2 = new listaDoble<int>();

                        listaPrueba2 = generarNumeros(guardaCantidad);


                        for(int x=0;x<guardaCantidad;x++){
                            colaPrueba2->insertar(listaPrueba2->getDato(x));
                        }


                        colaPrueba2->mostrarCola(*colaPrueba2);


                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 2: //chars
                    {
                        cola<char>* colaPrueba2 = new cola<char>();
                        listaDoble<char> *aux = new listaDoble<char>();
                        aux = generarChars(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            colaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        colaPrueba2->mostrarCola(*colaPrueba2);
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 3: //String
                    {
                        cola<string>* colaPrueba2 = new cola<string>();
                        listaDoble<string> *aux = new listaDoble<string>();
                        aux = generarPalabras(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            colaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        colaPrueba2->mostrarCola(*colaPrueba2);
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 4: //objetos
                    {
                        cola<persona*>* colaPrueba2 = new cola<persona*>();
                        persona* persona1 = new persona("yosua",21,116830903);
                        for(int x=0;x<guardaCantidad;x++){
                            colaPrueba2->insertar(persona1);
                        }
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
                        listaDoble<int> *aux = new listaDoble<int>();
                        aux = generarNumeros(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            pilaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        pilaPrueba2->mostrarPila();
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 2: //chars
                    {
                        PilaGenerica<char>* pilaPrueba2 = new PilaGenerica<char>();
                        listaDoble<char> *aux = new listaDoble<char>();
                        aux = generarChars(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            pilaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        pilaPrueba2->mostrarPila();
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 3: //String
                    {
                        PilaGenerica<string>* pilaPrueba2 = new PilaGenerica<string>();
                        listaDoble<string> *aux = new listaDoble<string>();
                        aux = generarPalabras(guardaCantidad);
                        for(int x=0;x<guardaCantidad;x++){
                            pilaPrueba2->insertar(aux->getDato(x));
                        }
                        delete(aux);

                        pilaPrueba2->mostrarPila();
                        //Swich(opcionOb) ->Para los algoritmos
                        break;
                    }
                    case 4: //objetos
                    {
                        PilaGenerica<persona*>* pilaPrueba2 = new PilaGenerica<persona*>();
                        persona* persona1 = new persona("yosua",21,116830903);
                        for(int x=0;x<guardaCantidad;x++){
                            pilaPrueba2->insertar(persona1);
                        }
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
