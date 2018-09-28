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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int tipo_estructura,tipo_dato;
    cout<<"Ingrese el tipo de estructura"<<endl;
    cout<<"1)lista Simple"<<endl;
    cout<<"2)lista Doble"<<endl;
    cin>>tipo_estructura;
    cout<<"Ingrese el tipo de dato para la estructura"<<endl;
    cout<<"1)Integer"<<endl;
    cout<<"2)Char"<<endl;
    cout<<"3)String"<<endl;
    cout<<"4)Objeto"<<endl;
    cin>>tipo_dato;

    switch (tipo_estructura) {
    case 1:
    {
        switch (tipo_dato) {
        case 1:
        {
            listaSimple<int>* listaPrueba2 = new listaSimple<int>();
            listaPrueba2->insertar(8,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(3,0,0);
            listaPrueba2->mostrarLista();
            //tri_bulle(listaPrueba2); //FUNCIONA
            //listaPrueba2->mostrarLista();
            break;
        }
        case 2:
        {
            listaSimple<char>* listaPrueba2 = new listaSimple<char>();
            listaPrueba2->insertar('a',0,0);
            listaPrueba2->insertar('s',0,0);
            listaPrueba2->insertar('d',0,0);
            listaPrueba2->insertar('f',0,0);
            listaPrueba2->insertar('g',0,0);
            listaPrueba2->insertar('h',0,0);
            listaPrueba2->insertar('j',0,0);
            listaPrueba2->mostrarLista();
            break;
        }
        case 3:
        {
            listaSimple<string>* listaPrueba2 = new listaSimple<string>();
            listaPrueba2->insertar("hola",1,0);
            listaPrueba2->insertar("alla",1,0);
            listaPrueba2->insertar("bala",1,0);
            listaPrueba2->insertar("cala",1,0);
            listaPrueba2->insertar("dado",1,0);
            listaPrueba2->insertar("ente",1,0);
            listaPrueba2->insertar("yuyu",1,0);
            listaPrueba2->insertar("ytyt",1,0);
            listaPrueba2->mostrarLista();
            break;
        }
        case 4:
        {
            listaSimple<persona*>* listaPrueba2 = new listaSimple<persona*>();
            persona* persona1 = new persona("yosua",21,116830903);

            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->mostrarLista();
            break;
        }
        }
    break;
    }
    case 2:
    {
        switch (tipo_dato) {
        case 1:
        {
            listaDoble<int>* listaPrueba2 = new listaDoble<int>();
            listaPrueba2->insertar(8,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(3,0,0);
            listaPrueba2->mostrarLista();
            //tri_bulle(listaPrueba2); //FUNCIONA
            //listaPrueba2->mostrarLista();


            break;
        }
        case 2:
        {
            listaDoble<char>* listaPrueba2 = new listaDoble<char>();
            listaPrueba2->insertar('a',0,0);
            listaPrueba2->insertar('s',0,0);
            listaPrueba2->insertar('d',0,0);
            listaPrueba2->insertar('f',0,0);
            listaPrueba2->insertar('g',0,0);
            listaPrueba2->insertar('h',0,0);
            listaPrueba2->insertar('j',0,0);
            listaPrueba2->mostrarLista();
            break;
        }
        case 3:
        {
            listaDoble<string>* listaPrueba2 = new listaDoble<string>();
            listaPrueba2->insertar("hola",1,0);
            listaPrueba2->insertar("alla",1,0);
            listaPrueba2->insertar("bala",1,0);
            listaPrueba2->insertar("cala",1,0);
            listaPrueba2->insertar("dado",1,0);
            listaPrueba2->insertar("ente",1,0);
            listaPrueba2->insertar("yuyu",1,0);
            listaPrueba2->insertar("ytyt",1,0);
            listaPrueba2->mostrarLista();
            break;
        }
        case 4:
        {
            listaDoble<persona*>* listaPrueba2 = new listaDoble<persona*>();
            persona* persona1 = new persona("yosua",21,116830903);

            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->mostrarLista();
            break;
        }
        }
    break;
    }
    case 3:
        switch (tipo_dato) {
        case 1:
        {
            listaDobleCircular<int>* listaPrueba2 = new listaDobleCircular<int>();
            listaPrueba2->insertar(8,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(1,0,0);
            listaPrueba2->insertar(3,0,0);
            listaPrueba2->mostrarLista();
            //tri_bulle(listaPrueba2); //FUNCIONA
            //listaPrueba2->mostrarLista();


            break;
        }
        case 2:
        {
            listaDobleCircular<char>* listaPrueba2 = new listaDobleCircular<char>();
            listaPrueba2->insertar('a',0,0);
            listaPrueba2->insertar('s',0,0);
            listaPrueba2->insertar('d',0,0);
            listaPrueba2->insertar('f',0,0);
            listaPrueba2->insertar('g',0,0);
            listaPrueba2->insertar('h',0,0);
            listaPrueba2->insertar('j',0,0);
            listaPrueba2->mostrarLista();
            break;
        }
        case 3:
        {
            listaDobleCircular<string>* listaPrueba2 = new listaDobleCircular<string>();
            listaPrueba2->insertar("hola",1,0);
            listaPrueba2->insertar("alla",1,0);
            listaPrueba2->insertar("bala",1,0);
            listaPrueba2->insertar("cala",1,0);
            listaPrueba2->insertar("dado",1,0);
            listaPrueba2->insertar("ente",1,0);
            listaPrueba2->insertar("yuyu",1,0);
            listaPrueba2->insertar("ytyt",1,0);
            listaPrueba2->mostrarLista();
            break;
        }
        case 4:
        {
            listaDobleCircular<persona*>* listaPrueba2 = new listaDobleCircular<persona*>();
            persona* persona1 = new persona("yosua",21,116830903);

            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->insertar(persona1,0,1);
            listaPrueba2->mostrarLista();
            break;
        }
        }

    }

/*

    //tri_shell(l); //FUNCIONA
    //tri_insertion(l) //FUNCIONA;
    //tri_selection(l,20); // FUNCIONA
    //tri_gnome(l); //FUNCIONA

*/
    return a.exec();
}
