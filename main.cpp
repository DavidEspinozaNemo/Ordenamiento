#include <QCoreApplication>
#include "algoritmos.cpp"
#include "cola.cpp"
#include "PilaGenerica.cpp"
#include "listadoble.cpp"
#include "listadoblecircular.cpp"
#include "listasimple.cpp"
#include "claseextra.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

/*
    listaSimple<int>* listaPrueba = new listaSimple<int>();
    listaPrueba->insertar(8);
    listaPrueba->insertar(1);
    listaPrueba->insertar(1);
    listaPrueba->insertar(1);
    listaPrueba->insertar(1);
    listaPrueba->insertar(1);
    listaPrueba->insertar(3);
    listaPrueba->mostrarLista();
    listaPrueba->cambio(1,5);
    listaPrueba->mostrarLista();

    listaDoble<int>* listaPrueba2 = new listaDoble<int>();
    listaPrueba2->insertar(8);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(3);
    listaPrueba2->mostrarLista();
    listaPrueba2->cambio(1,5);
    listaPrueba2->mostrarLista();



*/
    listaDobleCircular<int>* listaPrueba2 = new listaDobleCircular<int>();
    listaPrueba2->insertar(8);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(1);
    listaPrueba2->insertar(3);
    listaPrueba2->mostrarLista();
    listaPrueba2->cambio(1,5);
    listaPrueba2->mostrarLista();
/*
    //int l[20] = {6, 8, 7, 3, 10, 19, 13, 5, 2, 1, 15, 20, 9, 14, 12, 11, 16, 18, 4, 17};
    //char l[20] = {'x', 'z', 'l', 'k', 'j', 'h', 'g', 'f', 'd', 's', 'a', 'o', 'i', 'u', 'y', 't', 'r', 'e', 'w', 'q'};
    //string s[20]= {"hola","hola2","hola3","hola4","hola5","hola6"};
    for(int i=0;i<=19;i++){
        cout<<l[i]<<"-";
    }
    cout<<endl;

    //tri_bulle(l); //FUNCIONA
    //tri_shell(l); //FUNCIONA
    //tri_insertion(l) //FUNCIONA;
    //tri_selection(l,20); // FUNCIONA
    //tri_gnome(l); //FUNCIONA

    for(int i=0;i<=19;i++){
        string dato = s[i];
        //string num = ("%d",dato);
        //printf("El carcter %c equivale a %d en codigo ASCII",dato,dato);
        cout<<num<<"-"<<endl;
    }
*/
    return a.exec();
}
