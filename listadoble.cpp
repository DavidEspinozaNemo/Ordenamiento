#ifndef LISTADOBLE_CPP
#define LISTADOBLE_CPP

#include "listadoble.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "claseextra.cpp"
using namespace std;

template  <class T>
void listaDoble<T>::sustituirValor(int elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
}
template  <class T>
void listaDoble<T>::sustituirValor(char elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
}
template  <class T>
void listaDoble<T>::sustituirValor(string elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
}

template  <class T>
void listaDoble<T>::sustituirValor(persona *elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
}

template <class T>
int listaDoble<T>::cantDatos(){
    NodoListaDoble* n;
    n = primero;
    int cant = 0;
    while(n->siguiente != NULL){
        cant++;
        n = n->siguiente;
    }
    return cant;
}

template <class T>
T listaDoble<T>::sacarDatos(int indice){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == indice){
            nodo = aux;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
    return nodo->elemento;
}

template <class T>
void listaDoble<T>::cambio(int inicio,int final){

    T dato1;
    NodoListaDoble* nodo_inicio;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo_final;
    int contador = 0; //1 para la primera pos
    do{
        if(contador == inicio){
            nodo_inicio = aux; //coloca inicio
        }else if(contador == final){
            nodo_final = aux;  //coloca final
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
    if(nodo_final!=NULL && nodo_inicio!=NULL){
        dato1 = nodo_final->elemento;
        nodo_final->elemento=nodo_inicio->elemento;
        nodo_inicio->elemento=dato1;
    }else{
        cout<<"error en los indices";
    }

}

template <class T>
void listaDoble<T>::insertarPos(T elemento,int pos)
{
    NodoListaDoble* nuevo= new NodoListaDoble(elemento);
    if (ListaVacia())
         primero = nuevo;
       else{
            if(pos <=1){
                nuevo->siguiente = primero;
                primero->atras=nuevo;
                primero = nuevo;
            }else
            {
                 NodoListaDoble* aux= primero;
                 int i =2;
                 while((i != pos )&&(aux->siguiente!= NULL)){

                       i++;
                       aux=aux->siguiente;

                 }

                 nuevo->siguiente=aux->siguiente;
                 aux->siguiente=nuevo;
                 aux->siguiente->atras=aux;
                 nuevo->siguiente->atras=nuevo;
            }
    }
}
template <class T>
void listaDoble<T>::insertar(T elemento)
{
    NodoListaDoble* nuevo;
    nuevo = new NodoListaDoble(elemento);
    if(ListaVacia()){
        primero = nuevo;
    }else {
        NodoListaDoble* aux = primero;
        do{
            if(aux->siguiente == NULL){
                aux->siguiente = nuevo;
                nuevo->atras = aux;
                break;
            }
            aux=aux->siguiente;
        }while(aux!=NULL);
    }
}


template <class T>
void listaDoble<T>::mostrarLista(){
    cout<<"Lista Doble: \n";
    NodoListaDoble* n;
    n = primero;
    do{
        cout<<n->elemento<<endl;
        n=n->siguiente;
    }while(n!=NULL);
}

//Cambio David
template <class T>
T listaDoble<T>::getDato(int pos){
    NodoListaDoble* n;
    n = primero;
    for(int i = 0; i<pos; i++) n = n->siguiente;
    return n->elemento;
}

#endif
