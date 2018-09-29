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
        int es_string=0;
        int es_objeto=0;
        NodoListaSimple(T x,int str,int obj)
        {
        elemento = x;
        siguiente = NULL;
        es_string= str;
        es_objeto=obj;
        }
    };
    NodoListaSimple* primero;
    public:
        listaSimple ()
        {
            primero = NULL;
        }
        void insertar(T elemento,int,int);
        void insertarPos(T elemento,int);
        void cambio(int,int);
        bool menor(int,int);
        bool mayor(int,int);
        bool ListaVacia() { return primero == NULL; }


        void mostrarLista();
};

#endif // LISTASIMPLE_H
