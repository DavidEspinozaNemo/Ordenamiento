#include "listadoble.h"
#include <iostream>
using namespace std;

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
        cout<<n<<endl;
        n=n->siguiente;
    }while(n!=NULL);
}
