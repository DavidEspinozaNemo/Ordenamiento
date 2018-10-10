#ifndef LISTADOBLECIRCULAR_CPP
#define LISTADOBLECIRCULAR_CPP

#include "listadoblecircular.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "claseextra.cpp"
using namespace std;



template  <class T>
void listaDobleCircular<T>::sustituirValor(int elemento,int pos){

    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    NodoListaDoble* nuevo = new NodoListaDoble(elemento);
    NodoListaDoble* aux1;
    NodoListaDoble* aux2;
    NodoListaDoble* ultimo;
    int contador=0;
    do{
        if(contador == pos){
            nodo=aux;

        }else if(contador == pos+1 && pos!=cantDatos()){
            aux2=aux;

        }else if(contador == pos-1 && pos!=0){
            aux1=aux;

        }else if(contador == cantDatos()){
            ultimo=aux;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=primero);
    if(pos==0){
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        delete(nodo);
        primero=nuevo;
        ultimo->siguiente=nuevo;
        nuevo->atras=ultimo;
    }else if(pos==cantDatos()){
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
        ultimo=nuevo;
        ultimo->siguiente=primero;
        primero->atras=ultimo;
    }else{
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }
    //cout<<"hhh";

}
template  <class T>
void listaDobleCircular<T>::sustituirValor(char elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=primero);

}
template  <class T>
void listaDobleCircular<T>::sustituirValor(string elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=primero);
}

template  <class T>
void listaDobleCircular<T>::sustituirValor(persona *elemento,int pos){
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == pos){
            aux->elemento = elemento;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=primero);
}


template <class T>
int listaDobleCircular<T>::cantDatos(){
    NodoListaDoble* n;
    n = primero;
    int cant = 0;
    while(n->siguiente != primero){
        cant++;
        n = n->siguiente;
    }
    return cant;
}

template <class T>
T listaDobleCircular<T>::sacarDatos(int indice){
    //cout<<"error";
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    int contador=0;
    do{
        if(contador == indice){
            nodo = aux;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=primero);
    //cout<<"error";
    return nodo->elemento;
}


template <class T>
void listaDobleCircular<T>::cambio(int inicio,int final){

    T dato1;
    NodoListaDoble* nodo_inicio;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo_final;
    NodoListaDoble* aux1=NULL,*aux2=NULL,*aux3=NULL,*aux4=NULL;
    NodoListaDoble* ultimo;
    int casoEspecial=0;
    casoEspecial = abs(final-inicio);

    int contador = 0; //1 para la primera pos
    if(inicio!=final){
        if(inicio!=0 && final!=cantDatos()){


            do{
                if(contador == inicio){
                    nodo_inicio = aux; //coloca inicio

                }else if(contador == final){
                    nodo_final = aux;  //coloca final

                }else if(contador == inicio-1){
                    aux1=aux;

                }else if(contador == inicio+1 && casoEspecial!=1){
                    aux2=aux;

                }else if(contador == final-1 && casoEspecial!=1 && casoEspecial!=2){
                    aux3=aux;

                }else if(contador == final+1 && final+1!=cantDatos()){
                    aux4=aux;

                }else if(contador == cantDatos()){
                    ultimo=aux;
                }
                aux=aux->siguiente;
                contador++;
            }while(aux!=primero);


            if(nodo_final!=NULL && nodo_inicio!=NULL){

                if(casoEspecial!=1 && casoEspecial!=2 && final+1!=cantDatos()){

                    NodoListaDoble* temp=new NodoListaDoble(primero->elemento);
                    temp->siguiente=aux4;
                    aux4->atras=temp;
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    nodo_inicio->siguiente=temp->siguiente;
                    aux4->atras=nodo_inicio;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                    delete(temp);
                    /*dato1 = nodo_final->elemento;
                    nodo_final->elemento=nodo_inicio->elemento;
                    nodo_inicio->elemento=dato1;*/
                }else if(casoEspecial==1 && final+1!=cantDatos()){
                    NodoListaDoble* temp=new NodoListaDoble(primero->elemento);
                    temp->siguiente=aux4;
                    aux4->atras=temp;
                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    nodo_inicio->siguiente=temp->siguiente;
                    aux4->atras=nodo_inicio;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                    delete(temp);
                }else if(casoEspecial==2 && final+1!=cantDatos()){
                    NodoListaDoble* temp=new NodoListaDoble(primero->elemento);
                    temp->siguiente=aux4;
                    aux4->atras=temp;
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux2->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux2;
                    nodo_inicio->siguiente=temp->siguiente;
                    aux4->atras=nodo_inicio;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                    delete(temp);
                }else if(casoEspecial!=1 && casoEspecial!=2 && final+1==cantDatos()){
                    NodoListaDoble* temp=new NodoListaDoble(primero->elemento);
                    temp->siguiente=ultimo;
                    ultimo->atras=temp;
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    nodo_inicio->siguiente=temp->siguiente;
                    ultimo->atras=nodo_inicio;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                    delete(temp);
                }else if(casoEspecial==1 && final+1==cantDatos()){
                    NodoListaDoble* temp=new NodoListaDoble(primero->elemento);
                    temp->siguiente=ultimo;
                    ultimo->atras=temp;
                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    nodo_inicio->siguiente=temp->siguiente;
                    ultimo->atras=nodo_inicio;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                    delete(temp);
                }else if(casoEspecial==2 && final+1==cantDatos()){
                    NodoListaDoble* temp=new NodoListaDoble(primero->elemento);
                    temp->siguiente=ultimo;
                    ultimo->atras=temp;
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux2->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux2;
                    nodo_inicio->siguiente=temp->siguiente;
                    ultimo->atras=nodo_inicio;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                    delete(temp);
                }



            }else{
                cout<<"error en los indices";
            }
        }else if(inicio==0 && final!=cantDatos()){

            //int cont=0;
            do{
                if(contador == inicio){
                    nodo_inicio = aux; //coloca inicio

                }else if(contador == final){
                    nodo_final = aux;  //coloca final

                }else if(contador == inicio+1 && casoEspecial!=1){
                    aux2=aux;

                }else if(contador == final-1 && casoEspecial!=1 && casoEspecial!=2){
                    aux3=aux;

                }else if(contador == final+1 && final+1!=cantDatos()){
                    aux4=aux;

                }else if(contador == cantDatos() ) {
                    ultimo=aux;

                }
                aux=aux->siguiente;
                contador++;
            }while(aux!=primero);
            if(nodo_final!=NULL && nodo_inicio!=NULL){
                if(casoEspecial!=1 && casoEspecial!=2 && final+1==cantDatos()){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    nodo_inicio->siguiente=ultimo;
                    ultimo->atras=nodo_inicio;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    primero=nodo_final;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                }else if(casoEspecial!=1 && casoEspecial!=2 && final+1!=cantDatos()){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    nodo_inicio->siguiente=aux4;
                    aux4->atras=nodo_inicio;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    primero=nodo_final;
                    ultimo->siguiente=primero;
                    primero->atras=ultimo;
                }
                else if(casoEspecial==1){

                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    nodo_inicio->siguiente=aux4;
                    aux4->atras=nodo_inicio;
                    primero=nodo_final;
                    primero->atras=ultimo;
                    ultimo->siguiente=primero;

                }else{
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    nodo_inicio->siguiente=aux4;
                    aux4->atras=nodo_inicio;
                    aux2->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux2;
                    primero=nodo_final;
                    primero->atras=ultimo;
                    ultimo->siguiente=ultimo;
                }


            }else{
                cout<<"error en los indices";
            }
        }else if(inicio!=0 && final==cantDatos()){

            do{
                if(contador == inicio){
                    nodo_inicio = aux; //coloca inicio

                }else if(contador == final){
                    nodo_final = aux;  //coloca final

                }else if(contador == inicio-1){
                    aux1=aux;

                }else if(contador == inicio+1 && casoEspecial!=1){
                    aux2=aux;

                }else if(contador == final-1 && casoEspecial!=1 && casoEspecial!=2 ){
                    aux3=aux;

                }
                aux=aux->siguiente;
                contador++;
            }while(aux!=primero);
            if(nodo_final!=NULL && nodo_inicio!=NULL){
                if(casoEspecial !=1 && casoEspecial !=2){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    nodo_inicio->siguiente=primero;
                    primero->atras=nodo_inicio;
                }else if(casoEspecial==2){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux2->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux2;
                    nodo_inicio->siguiente=primero;
                    primero->atras=nodo_inicio;
                }else{
                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    nodo_inicio->siguiente=primero;
                    primero->atras=nodo_inicio;
                }



                /*dato1 = nodo_final->elemento;
                nodo_final->elemento=nodo_inicio->elemento;
                nodo_inicio->elemento=dato1;*/
            }else{
                cout<<"error en los indices";
            }
        }else if(inicio==0 && final==cantDatos()){

            do{
                if(contador == inicio){
                    nodo_inicio = aux; //coloca inicio

                }else if(contador == final){
                    nodo_final = aux;  //coloca final

                }else if(contador == inicio+1){
                    aux2=aux;

                }else if(contador == final-1){
                    aux3=aux;

                }
                aux=aux->siguiente;
                contador++;
            }while(aux!=primero);
            if(nodo_final!=NULL && nodo_inicio!=NULL){
                nodo_final->siguiente=aux2;
                aux2->atras=nodo_final;
                aux3->siguiente=nodo_inicio;
                nodo_inicio->atras=aux3;
                primero=nodo_final;
                nodo_inicio->siguiente=primero;
                primero->atras=primero;
                /*dato1 = nodo_final->elemento;
                nodo_final->elemento=nodo_inicio->elemento;
                nodo_inicio->elemento=dato1;*/
            }else{
                cout<<"error en los indices";
            }

        }
    }
}
template <class T>
void listaDobleCircular<T>::insertarPos(T elemento,int pos){

    NodoListaDoble* nuevo = new NodoListaDoble(elemento);
    NodoListaDoble* ultimo;

    int contador=0;


    if (ListaVacia())
       {
         primero = nuevo;
         nuevo->siguiente=primero;

       }
       else
       {
         if(pos==0)
         {
             NodoListaDoble* aux=primero;
             do{


                 if(contador == cantDatos()){
                     ultimo=aux;
                 }
                 contador++;
                 aux=aux->siguiente;
             }while(aux!=primero);
             nuevo->siguiente = primero;
             primero->atras=nuevo;
             primero = nuevo;
             ultimo->siguiente=primero;
             primero->atras=ultimo;

         }
         else
         {
           NodoListaDoble* aux= primero;
           int i =2;
           while((i != pos )&&(aux->siguiente!= primero))
           {
              i++;
              aux=aux->siguiente;
              break;
           }
           NodoListaDoble* nuevo= new NodoListaDoble(elemento);
           nuevo->siguiente=aux->siguiente;
           aux->siguiente=nuevo;
          }
     }

}
template <class T>
void listaDobleCircular<T>::insertar(T elemento)
{
    NodoListaDoble* nuevo;
    nuevo = new NodoListaDoble(elemento);
    if(ListaVacia()){
        primero = nuevo;
        primero->siguiente=primero;
        primero->atras=primero;

    }else {
        NodoListaDoble* aux = primero;
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
    NodoListaDoble* n;
    n = primero;
    do{
        cout<<n->elemento<<endl;
        n=n->siguiente;
    }while(n!=primero);
}

template <>
void listaDobleCircular<persona*>::mostrarLista(){
    cout<<"Lista Doble Circular: \n";
    NodoListaDoble* n;
    n = primero;
    do{
        cout << n->elemento->getNombre() << " : " << n->elemento->getCedula() <<" : "<< n->elemento->getEdad()<<endl;
        n=n->siguiente;
    }while(n!=primero);
}
#endif
