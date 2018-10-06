#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <claseextra.cpp>

using namespace std;

template <class T>
class listaDobleCircular
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
        listaDobleCircular ()
        {
            primero = NULL;

        }
        int cantDatos();
        T sacarDatos(int);
        void insertar(T elemento);
        void insertarPos(T,int);
        T quitar();
        void sustituirValor(int,int);
        void sustituirValor(char,int);
        void sustituirValor(string,int);
        void sustituirValor(persona*,int);
        void cambio(int,int);                      
        bool ListaVacia() { return primero == NULL; }
        void limpiarLista();
        void mostrarLista();
};

#endif // LISTADOBLECIRCULAR_H
