#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>

template <class T>
class listaDoble
{
    class NodoListaDoble
    {
    public:
        NodoListaDoble* siguiente;
        NodoListaDoble* atras;
        T elemento;

        NodoListaDoble(T x)
        {
        elemento = x;
        siguiente = NULL;
        atras = NULL;
        }
    };
    NodoListaDoble* primero;
    public:
        listaDoble ()
        {
            primero = NULL;
        }
        void insertar(T elemento);
        void insertarPos(T,int);
        bool ListaVacia() { return primero == NULL; }
        void mostrarLista();
        void cambio(int,int);
};

#endif // LISTADOBLE_H
