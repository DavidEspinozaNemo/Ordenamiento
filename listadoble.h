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
        T sacarDatos(int);
        void insertar(T elemento);
        void insertarPos(T,int);
        bool ListaVacia() { return primero == NULL; }
        void mostrarLista();
        void cambio(int,int);
        bool menor(int,int);
        bool mayor(int,int);
		T getDato(int); //Cambio David
        int cantDatos(); //Cambio David
};

#endif // LISTADOBLE_H
