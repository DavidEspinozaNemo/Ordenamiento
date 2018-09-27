#include "listadoblecircular.h"
#include <iostream>
using namespace std;

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
void listaDobleCircular<T>::insertar(T elemento)
{
    NodoListaDobleCircular* nuevo;
    nuevo = new NodoListaDobleCircular(elemento);
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
        cout<<n<<endl;
        n=n->siguiente;
    }while(n!=primero);
}
