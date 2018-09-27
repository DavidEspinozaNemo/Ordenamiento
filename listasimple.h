#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>

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


        bool ListaVacia() { return primero == NULL; }

        void mostrarLista();
};

#endif // LISTASIMPLE_H
