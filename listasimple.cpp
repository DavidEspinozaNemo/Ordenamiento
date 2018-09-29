#include "listasimple.h"
#include <iostream>
#include <sstream>
using namespace std;



template <class T>
bool listaSimple<T>::mayor(int inicio,int final){
    T dato1;
    NodoListaSimple* nodo_inicio;
    NodoListaSimple* aux = primero;
    NodoListaSimple* nodo_final;
    int contador = 0; //0 para la primera pos
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
            int num1 = ("%d",nodo_inicio->elemento);
            int num2 = ("%d",nodo_final->elemento);
            if(num1 > num2){
                cout<<"si";
                return true;
            }else{
                cout<<"no";
                return false;
            }
    }else{
        cout<<"error en los indices";
    }

}
template <class T>
bool listaSimple<T>::menor(int inicio,int final){
    T dato1;
    NodoListaSimple* nodo_inicio;
    NodoListaSimple* aux = primero;
    NodoListaSimple* nodo_final;
    int contador = 0; //0 para la primera pos
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
        int num1 = ("%d",nodo_inicio->elemento);
        int num2 = ("%d",nodo_final->elemento);
        if( num1 < num2){
            cout<<"si";
            return true;
        }else{
            cout<<"no";
            return false;
        }
    }else{
        cout<<"error en los indices";
    }

}

template <class T>
void listaSimple<T>::cambio(int inicio,int final){
    T dato1;
    NodoListaSimple* nodo_inicio;
    NodoListaSimple* aux = primero;
    NodoListaSimple* nodo_final;
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
void listaSimple<T>::insertar(T elemento,int str,int obj)
{

    NodoListaSimple* nuevo;
    nuevo = new NodoListaSimple(elemento,str,obj);
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
        cout<<n->elemento<<endl;
        n=n->siguiente;
    }while(n!=NULL);
}
