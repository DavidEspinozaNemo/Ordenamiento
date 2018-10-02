#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

template <class T>
class listaSimple
{
    class NodoListaSimple
    {
    public:
        NodoListaSimple* siguiente;
        T elemento;

        NodoListaSimple(T x)
        {
        elemento = x;
        siguiente = NULL;


        }
    };
    NodoListaSimple* primero;
    public:
        listaSimple ()
        {
            primero = NULL;
        }
        void insertar(T elemento);
        void insertarPos(T elemento,int);
        void cambio(int,int);
        bool menor(int,int);

        bool mayor(int,int);//(indice inicial,indice fianl,si es string, si es obj)
        bool mayor(char,char);
        bool mayor(string,string);

        //bool mayor(persona,persona);
        T sacarDatos(int);
        int cantDatos();
        bool ListaVacia() { return primero == NULL; }


        void mostrarLista();
};

#endif // LISTASIMPLE_H
