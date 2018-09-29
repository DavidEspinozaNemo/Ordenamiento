#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include <iostream>

template <class T>
class listaDobleCircular
{
    class NodoListaDobleCircular
    {
    public:
        NodoListaDobleCircular* siguiente;
        NodoListaDobleCircular* atras;
        T elemento;
        int es_string=0;
        int es_objeto=0;
        NodoListaDobleCircular(T x,int str,int obj)
        {
        elemento = x;
        siguiente = NULL;
        atras = NULL;
        es_string= str;
        es_objeto=obj;
        }
    };
    NodoListaDobleCircular* primero;
    public:
        listaDobleCircular ()
        {
            primero = NULL;

        }
        void insertar(T elemento,int,int);
        void insertarPos(T,int);
        T quitar();
        void cambio(int,int);
        bool menor(int,int);
        bool mayor(int,int);
        T primeroLista();
        bool ListaVacia() { return primero == NULL; }
        void limpiarLista();
        void mostrarLista();
};

#endif // LISTADOBLECIRCULAR_H
