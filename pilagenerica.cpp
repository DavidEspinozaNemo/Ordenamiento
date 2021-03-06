#ifndef PILAGENERICA_CPP
#define PILAGENERICA_CPP
#include "PilaGenerica.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "claseextra.cpp"
using namespace std;

template <class T>
void PilaGenerica<T>::insertar(T elemento)
{
    NodoPila* nuevo;
    nuevo = new NodoPila(elemento);
    nuevo -> siguiente = cima;
    cima = nuevo;
}

template <class T>
T PilaGenerica<T>::quitar()
{
    if (pilaVacia())
    throw "Pila vacía, no se puede extraer.";

    T aux = cima -> elemento;
    cima = cima -> siguiente;
    return aux;
}

template <class T>
T PilaGenerica<T>::cimaPila()
{
    if (pilaVacia())
    throw "Pila vacía";
    return cima -> elemento;
}

template <class T>
void PilaGenerica<T>:: limpiarPila()
{
    NodoPila* n;
    while(!pilaVacia())
    {
        n = cima;
        cima = cima -> siguiente;
        delete n;
    }
}

template <class T>
void PilaGenerica<T>::mostrarPila(){
    cout<<"PILA: \n";
    NodoPila* n;
    while(!pilaVacia())
    {
        n = cima;
        cima = cima->siguiente;
        cout<<n->elemento<<endl;
    }
}

/*
template <>
void PilaGenerica<persona*>::mostrarPila(){
    cout<<"PILA: \n";
    NodoPila* n;
    while(!pilaVacia())
    {
        n = cima;
        cima = cima->siguiente;
        cout << n->elemento->getNombre() << " : " << n->elemento->getCedula() <<" : "<< n->elemento->getEdad()<<endl;
    }
}*/

#endif
