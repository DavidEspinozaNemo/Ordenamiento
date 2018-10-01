#include "listadoble.h"
#include <iostream>
using namespace std;

template <class T>
bool listaDoble<T>::mayor(int inicio,int final){
    T dato1;
    NodoListaDoble* nodo_inicio;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo_final;
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
        if(nodo_inicio->elemento > nodo_final->elemento){
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
bool listaDoble<T>::menor(int inicio,int final){
    T dato1;
    NodoListaDoble* nodo_inicio;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo_final;
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
        if(nodo_inicio->elemento < nodo_final->elemento){
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
         primero = new NodoListaDoble(elemento);
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
void listaDoble<T>::insertar(T elemento,int str,int obj)
{
    NodoListaDoble* nuevo;
    nuevo = new NodoListaDoble(elemento,str,obj);
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
