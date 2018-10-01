#include "listadoblecircular.h"
#include <iostream>
using namespace std;




template <class T>
void listaDobleCircular<T>::cambio(int inicio,int final){
    T dato1;
    NodoListaDobleCircular* nodo_inicio;
    NodoListaDobleCircular* aux = primero;
    NodoListaDobleCircular* nodo_final;
    int contador = 0; //1 para la primera pos
    do{
        if(contador == inicio){
            nodo_inicio = aux; //coloca inicio
        }else if(contador == final){
            nodo_final = aux;  //coloca final
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=primero);
    if(nodo_final!=NULL && nodo_inicio!=NULL){
        dato1 = nodo_final->elemento;
        nodo_final->elemento=nodo_inicio->elemento;
        nodo_inicio->elemento=dato1;
    }else{
        cout<<"error en los indices";
    }

}

template <class T>
void listaDobleCircular<T>::insertarPos(T elemento,int pos){
    NodoListaDobleCircular* nuevo= new NodoListaDobleCircular(elemento);
    if (ListaVacia())
       {
         primero = nuevo;
         nuevo->siguiente=primero;
       }
       else
       {
         if(pos <=1)
         {
             nuevo->siguiente = primero;
             primero->atras=nuevo;
             primero = nuevo;
         }
         else
         {
           NodoListaDobleCircular* aux= primero;
           int i =2;
           while((i != pos )&&(aux->siguiente!= primero))
           {
              i++;
              aux=aux->siguiente;
           }
           NodoListaDobleCircular* nuevo= new NodoListaDobleCircular(elemento);
           nuevo->siguiente=aux->siguiente;
           aux->siguiente=nuevo;
          }
     }
}
template <class T>
void listaDobleCircular<T>::insertar(T elemento,int str,int obj)
{
    NodoListaDobleCircular* nuevo;
    nuevo = new NodoListaDobleCircular(elemento,str,obj);
    if(ListaVacia()){
        primero = nuevo;
        primero->siguiente=primero;
        primero->atras=primero;

    }else {
        NodoListaDobleCircular* aux = primero;
        do{
            if(aux->siguiente == primero){
                aux->siguiente = nuevo;
                nuevo->atras = aux;
                nuevo->siguiente=primero;
                primero->atras=nuevo;
            }
            aux=aux->siguiente;
        }while(aux!=primero);
    }
}


template <class T>
void listaDobleCircular<T>::mostrarLista(){
    cout<<"Lista Doble Circular: \n";
    NodoListaDobleCircular* n;
    n = primero;
    do{
        cout<<n->elemento<<endl;
        n=n->siguiente;
    }while(n!=primero);
}
