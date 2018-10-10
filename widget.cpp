#include "widget.h"
#include "ui_widget.h"
#include "pilagenerica.cpp"
#include "cola.cpp"
#include "listadoble.cpp"
#include "listadoblecircular.cpp"
#include "listasimple.cpp"
#include "algoritmos.cpp"
#include "valoresaleatorios.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString p0 = ui->comboBox->currentText();    //Seleccion de la estructura
    QString p1 = ui->comboBox_2->currentText();  //Seleccion de objeto
    QString p2 = ui->comboBox_3->currentText();  //Seleccion de algoritmo
    QString textoplano = ui->scrollArea->findChild<QTextBrowser*>("textBrowser")->toPlainText();
    //Obtencion de la informacion del TextBox
    int opcionEs, opcionOb, opcionOr, cantidadObjetos = 10;

    if(p0.compare("listaSimple") == 0) opcionEs = 1;
    else if(p0.compare("listaDoble") == 0) opcionEs = 2;
    else if(p0.compare("listaDobleCircular") == 0) opcionEs = 3;
    else if(p0.compare("cola") == 0) opcionEs = 4;
    else if(p0.compare("pila") == 0) opcionEs = 5;
    else opcionEs = 0;

    if(p1.compare("Numero") == 0) opcionOb = 1;
    else if(p1.compare("Letra") == 0) opcionOb = 2;
    else if(p1.compare("Palabra") == 0) opcionOb = 3;
    else if(p1.compare("Objeto") == 0) opcionOb = 4;
    else opcionOb = 0;

    if(p2.compare("Seleccion") == 0) opcionOr = 1;
    else if(p2.compare("Insercion") == 0) opcionOr = 2;
    else if(p2.compare("Burbuja") == 0) opcionOr = 3;
    else if(p2.compare("Burbuja Bidireccional") == 0) opcionOr = 4;
    else if(p2.compare("Shell") == 0) opcionOr = 5;
    else if(p2.compare("HeapSort") == 0) opcionOr = 6;
    else if(p2.compare("MergeSort") == 0) opcionOr = 7;
    else if(p2.compare("RadixSort") == 0) opcionOr = 8;
    else if(p2.compare("BinSort") == 0) opcionOr = 9;
    else if(p2.compare("QuickSort") == 0) opcionOr = 10;
    else opcionOr = 0;

    switch (opcionEs) {
    case 1: //Caso para la listaSimple
    {
        switch (opcionOb) {
        case 1: //numeros
        {
            listaSimple<int>* listaPrueba2 = new listaSimple<int>();
            generarNumeros(listaPrueba2,cantidadObjetos);
            listaSimple<int>* listaAux = new listaSimple<int>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
                radixsort(listaPrueba2, new listaSimple<int>(),listaPrueba2->cantDatos());
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
            generarChars(listaPrueba2, cantidadObjetos);
            listaSimple<char>* listaAux = new listaSimple<char>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarPalabras(listaPrueba2, cantidadObjetos);
            listaSimple<string>* listaAux = new listaSimple<string>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarPersonas(listaPrueba2, cantidadObjetos);
            listaPrueba2->mostrarLista();

            switch (opcionOr) {
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
        switch (opcionOb) {
        case 1: //numeros
        {
            listaDoble<int>* listaPrueba2 = new listaDoble<int>();
            generarNumeros(listaPrueba2,cantidadObjetos);
            listaDoble<int> *listaAux = new listaDoble<int>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarChars(listaPrueba2, cantidadObjetos);
            listaDoble<char> *listaAux = new listaDoble<char>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarPalabras(listaPrueba2, cantidadObjetos);
            listaDoble<string> *listaAux = new listaDoble<string>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarPersonas(listaPrueba2, cantidadObjetos);
            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
        switch (opcionOb) {
        case 1: //numeros
        {
            listaDobleCircular<int>* listaPrueba2 = new listaDobleCircular<int>();
            generarNumeros(listaPrueba2,cantidadObjetos);
            listaDobleCircular<int>* listaAux = new listaDobleCircular<int>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarChars(listaPrueba2, cantidadObjetos);
            listaDobleCircular<char>* listaAux = new listaDobleCircular<char>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarPalabras(listaPrueba2, cantidadObjetos);
            listaDobleCircular<string>* listaAux = new listaDobleCircular<string>();

            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
            generarPersonas(listaPrueba2, cantidadObjetos);
            listaPrueba2->mostrarLista();
            switch (opcionOr) {
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
        switch (opcionOr)
        {
        case 1: //Numeros
        {
            cola<int>* colaPrueba2 = new cola<int>();
            generarNumeros(colaPrueba2,cantidadObjetos);

            colaPrueba2->mostrarCola(*colaPrueba2);


            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        case 2: //chars
        {
            cola<char>* colaPrueba2 = new cola<char>();
            generarChars(colaPrueba2, cantidadObjetos);

            colaPrueba2->mostrarCola(*colaPrueba2);
            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        case 3: //String
        {
            cola<string>* colaPrueba2 = new cola<string>();
            generarPalabras(colaPrueba2, cantidadObjetos);

            colaPrueba2->mostrarCola(*colaPrueba2);
            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        case 4: //objetos
        {
            cola<persona*>* colaPrueba2 = new cola<persona*>();
            generarPersonas(colaPrueba2, cantidadObjetos);
            colaPrueba2->mostrarCola(*colaPrueba2);

            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        }
        break;
    }
    case 5: //Caso para la pila
    {
        switch (opcionOr) {
        case 1: //numeros
        {
            PilaGenerica<int>* pilaPrueba2 = new PilaGenerica<int>();
            generarNumeros(pilaPrueba2,cantidadObjetos);

            pilaPrueba2->mostrarPila();
            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        case 2: //chars
        {
            PilaGenerica<char>* pilaPrueba2 = new PilaGenerica<char>();
            generarChars(pilaPrueba2, cantidadObjetos);

            pilaPrueba2->mostrarPila();
            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        case 3: //String
        {
            PilaGenerica<string>* pilaPrueba2 = new PilaGenerica<string>();
            generarPalabras(pilaPrueba2, cantidadObjetos);

            pilaPrueba2->mostrarPila();
            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        case 4: //objetos
        {
            PilaGenerica<persona*>* pilaPrueba2 = new PilaGenerica<persona*>();
            generarPersonas(pilaPrueba2, cantidadObjetos);
            pilaPrueba2->mostrarPila();

            //Swich(opcionOb) ->Para los algoritmos
            break;
        }
        }
        break;
    }

    }
//



    ui->scrollArea->findChild<QTextBrowser*>("textBrowser")->setText(textoplano+"\n"+p0+"\n"+p1+"\n"+p2);
}
