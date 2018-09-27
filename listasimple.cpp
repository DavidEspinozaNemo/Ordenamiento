#include "listasimple.h"
#include <iostream>
using namespace std;
template <class T>
void listaSimple<T>::insertarPos(T elemento,int pos){
    if (ListaVacia())
        primero = new NodoListaSimple(elemento);
    else{
         if(pos <=1){
           NodoListaSimple* nuevo = new NodoListaSimple(elemento);
           nuevo->siguiente= primero;
           primero= nuevo;
         }
         else{
              NodoListaSimple* aux= primero;
              int i =2;
              while((i != pos )&&(aux->siguiente!= NULL)){
                    i++;
                    aux=aux->siguiente;
              }
              NodoListaSimple* nuevo= new NodoListaSimple(elemento);
              nuevo->siguiente=aux->siguiente;
              aux->siguiente=nuevo;
        }
    }
}
template <class T>
void listaSimple<T>::insertar(T elemento)
{

    NodoListaSimple* nuevo;
    nuevo = new NodoListaSimple(elemento);
    NodoListaSimple* aux = primero;
    if(ListaVacia()){
        primero = nuevo;

    }else {

        do{
            if(aux->siguiente == NULL){
                aux->siguiente = nuevo;
                break;
            }
            aux=aux->siguiente;
        }while(aux!=NULL);
    }
}


template <class T>
void listaSimple<T>::mostrarLista(){
    cout<<"Lista Simple: \n";
    NodoListaSimple* n;
    n = primero;
    do{
        cout<<n<<endl;
        n=n->siguiente;
    }while(n!=NULL);
}
