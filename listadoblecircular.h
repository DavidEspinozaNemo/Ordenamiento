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

        NodoListaDobleCircular(T x)
        {
        elemento = x;
        siguiente = NULL;
        atras = NULL;

        }
    };
    NodoListaDobleCircular* primero;
    public:
        listaDobleCircular ()
        {
            primero = NULL;

        }
        int cantDatos();
        T sacarDatos(int);
        void insertar(T elemento);
        void insertarPos(T,int);
        T quitar();
        void cambio(int,int);                      
        bool ListaVacia() { return primero == NULL; }
        void limpiarLista();
        void mostrarLista();
};

#endif // LISTADOBLECIRCULAR_H
