#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "claseextra.cpp"
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
        void sustituirValor(int,int);
        void sustituirValor(char,int);
        void sustituirValor(string,int);
        void sustituirValor(persona*,int);
        void cambio(int,int);
        bool menor(int,int);
        bool mayor(int,int);

		T getDato(int); //Cambio David
        int cantDatos(); //Cambio David
};

#endif // LISTADOBLE_H
