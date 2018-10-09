#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <claseextra.cpp>

using namespace std;

template <class T>
class listaSimple
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

    public:
        listaSimple ()
        {
            primero = NULL;
        }
        void insertar(T elemento);
        void insertarPos(T elemento,int);
        void cambio(int,int);
        bool menor(int,int);
        void sustituirValor(int,int);
        void sustituirValor(char,int);
        void sustituirValor(string,int);
        void sustituirValor(persona*,int);
        bool mayor(int,int);//(indice inicial,indice fianl,si es string, si es obj)
        bool mayor(char,char);
        bool mayor(string,string);

        //bool mayor(persona,persona);
        T sacarDatos(int);

        int cantDatos();
        bool ListaVacia() { return primero == NULL; }
        NodoListaDoble* primero;

        void mostrarLista();
};

#endif // LISTASIMPLE_H
