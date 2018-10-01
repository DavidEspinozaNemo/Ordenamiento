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
        int es_string=0;
        int es_objeto=0;
        NodoListaDoble(T x)
        {
            elemento = x;
            siguiente = NULL;
            atras = NULL;
            es_string= 0;
            es_objeto=0;
        }
        NodoListaDoble(T x,int str,int obj)
        {
        elemento = x;
        siguiente = NULL;
        atras = NULL;
        es_string= str;
        es_objeto=obj;
        }
    };
    NodoListaDoble* primero;
    public:
        listaDoble ()
        {
            primero = NULL;
        }
        void insertar(T elemento,int,int);
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
