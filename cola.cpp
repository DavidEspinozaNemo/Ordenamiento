
#include "cola.h"
#include <iostream>
using namespace std;

template <class T>
void cola<T> :: insertar(T elemento)
{
    NodoCola* nuevo;
    nuevo = new NodoCola (elemento);
    if (colaVacia())
    {
        frente = nuevo;
    }
    else
    {
        final -> siguiente = nuevo;
    }
    final = nuevo;
}

template <class T>
T cola<T> :: quitar()
{
    if (colaVacia())
    throw "Cola vacÃ­a, no se puede extraer.";
    T aux = frente -> elemento;
    NodoCola* a = frente;
    frente = frente -> siguiente;
    delete a;
    return aux;
}

template <class T>
T cola<T> :: frenteCola()const
{
    if (colaVacia())
    throw "Cola vacÃ­a";
    return frente -> elemento;
}

template <class T>
void cola<T> :: borrarCola()
{
    for (;frente != nullptr;)
    {
        NodoCola* a;
        a = frente;
        frente = frente -> siguiente;
        delete a;
    }
    final = nullptr;
}

template <class T>
bool cola<T> :: colaVacia() const
{
    return frente == NULL;
}

template <class T>
void cola<T>::mostrarCola(cola<T>& q)
{
    cout<<"COLA: \n";
    while (! q.colaVacia())
    {
        T v;
        v = q.quitar();
        //cout<<v<<endl;
    }
    std::cout << std::endl;
}
