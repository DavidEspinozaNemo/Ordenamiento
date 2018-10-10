#ifndef LISTADOBLE_CPP
#define LISTADOBLE_CPP

#include "listadoble.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "claseextra.cpp"
using namespace std;

template <class T>
cola<T>* listaDoble<T>::llenarLista(cola<T>& q){
    NodoListaDoble *aux=primero;
    do{
        q.insertar(aux->elemento);
        aux=aux->siguiente;
    }while(aux!=NULL);
    return &q;
}

template  <class T>
void listaDoble<T>::sustituirValor(int elemento,int pos){
    //cout<<"Sustiruir:"<<pos<<":"<<cantDatos()<<endl;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    NodoListaDoble* nuevo = new NodoListaDoble(elemento);
    NodoListaDoble* aux1;
    NodoListaDoble* aux2;
    int contador=0;
    do{
        if(contador == pos){
            nodo=aux;
            //cout<<"nodo:"<<nodo->elemento<<endl;
        }else if(contador == pos+1 && pos!=cantDatos()){
            aux2=aux;
            //cout<<"aux2:"<<aux2->elemento<<endl;
        }else if(contador == pos-1 && pos!=0){
            aux1=aux;
            //cout<<"aux1:"<<aux1->elemento<<endl;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
    if(pos==0){
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        delete(nodo);
        primero=nuevo;
    }else if(pos==cantDatos()){
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }else{
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }
}
template  <class T>
void listaDoble<T>::sustituirValor(char elemento,int pos){
    //cout<<"Sustiruir:"<<pos<<":"<<cantDatos()<<endl;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    NodoListaDoble* nuevo = new NodoListaDoble(elemento);
    NodoListaDoble* aux1;
    NodoListaDoble* aux2;
    int contador=0;
    do{
        if(contador == pos){
            nodo=aux;
            //cout<<"nodo:"<<nodo->elemento<<endl;
        }else if(contador == pos+1 && pos!=cantDatos()){
            aux2=aux;
            //cout<<"aux2:"<<aux2->elemento<<endl;
        }else if(contador == pos-1 && pos!=0){
            aux1=aux;
            //cout<<"aux1:"<<aux1->elemento<<endl;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
    if(pos==0){
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        delete(nodo);
        primero=nuevo;
    }else if(pos==cantDatos()){
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }else{
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }
}

template  <class T>
void listaDoble<T>::sustituirValor(string elemento,int pos){
    //cout<<"Sustiruir:"<<pos<<":"<<cantDatos()<<endl;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    NodoListaDoble* nuevo = new NodoListaDoble(elemento);
    NodoListaDoble* aux1;
    NodoListaDoble* aux2;
    int contador=0;
    do{
        if(contador == pos){
            nodo=aux;
            //cout<<"nodo:"<<nodo->elemento<<endl;
        }else if(contador == pos+1 && pos!=cantDatos()){
            aux2=aux;
            //cout<<"aux2:"<<aux2->elemento<<endl;
        }else if(contador == pos-1 && pos!=0){
            aux1=aux;
            //cout<<"aux1:"<<aux1->elemento<<endl;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
    if(pos==0){
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        delete(nodo);
        primero=nuevo;
    }else if(pos==cantDatos()){
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }else{
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }
}


template  <class T>
void listaDoble<T>::sustituirValor(persona* elemento,int pos){
    //cout<<"Sustiruir:"<<pos<<":"<<cantDatos()<<endl;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo;
    NodoListaDoble* nuevo = new NodoListaDoble(elemento);
    NodoListaDoble* aux1;
    NodoListaDoble* aux2;
    int contador=0;
    do{
        if(contador == pos){
            nodo=aux;
            //cout<<"nodo:"<<nodo->elemento<<endl;
        }else if(contador == pos+1 && pos!=cantDatos()){
            aux2=aux;
            //cout<<"aux2:"<<aux2->elemento<<endl;
        }else if(contador == pos-1 && pos!=0){
            aux1=aux;
            //cout<<"aux1:"<<aux1->elemento<<endl;
        }
        aux=aux->siguiente;
        contador++;
    }while(aux!=NULL);
    if(pos==0){
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        delete(nodo);
        primero=nuevo;
    }else if(pos==cantDatos()){
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }else{
        nuevo->siguiente=aux2;
        aux2->atras=nuevo;
        aux1->siguiente=nuevo;
        nuevo->atras=aux1;
        delete(nodo);
    }
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
    //cout<<"cambio"<<endl;
    T dato1;
    NodoListaDoble* nodo_inicio;
    NodoListaDoble* aux = primero;
    NodoListaDoble* nodo_final;
    NodoListaDoble* aux1=NULL,*aux2=NULL,*aux3=NULL,*aux4=NULL;
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

                }else if(contador == final+1){
                    aux4=aux;

                }
                aux=aux->siguiente;
                contador++;
            }while(aux!=NULL);


            if(nodo_final!=NULL && nodo_inicio!=NULL){

                if(casoEspecial!=1 && casoEspecial!=2){

                    NodoListaDoble* temp=new NodoListaDoble(aux4->elemento);
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
                    delete(temp);
                    /*dato1 = nodo_final->elemento;
                    nodo_final->elemento=nodo_inicio->elemento;
                    nodo_inicio->elemento=dato1;*/
                }else if(casoEspecial==1){
                    NodoListaDoble* temp=new NodoListaDoble(aux4->elemento);
                    temp->siguiente=aux4;
                    aux4->atras=temp;
                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    nodo_inicio->siguiente=temp->siguiente;
                    aux4->atras=nodo_inicio;
                    delete(temp);
                }else{
                    NodoListaDoble* temp=new NodoListaDoble(aux4->elemento);
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

                }else if(contador == final+1){
                    aux4=aux;

                }
                aux=aux->siguiente;
                contador++;
            }while(aux!=NULL);
            if(nodo_final!=NULL && nodo_inicio!=NULL){
                if(casoEspecial!=1 && casoEspecial!=2){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    nodo_inicio->siguiente=aux4;
                    aux4->atras=nodo_inicio;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    primero=nodo_final;
                }else if(casoEspecial==1){
                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    nodo_inicio->siguiente=aux4;
                    aux4->atras=nodo_inicio;

                    primero=nodo_final;
                }else{
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    nodo_inicio->siguiente=aux4;
                    aux4->atras=nodo_inicio;
                    aux2->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux2;
                    primero=nodo_final;

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
            }while(aux!=NULL);
            if(nodo_final!=NULL && nodo_inicio!=NULL){
                if(casoEspecial !=1 && casoEspecial !=2){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux3->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux3;
                    nodo_inicio->siguiente=NULL;
                }else if(casoEspecial==2){
                    nodo_final->siguiente=aux2;
                    aux2->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    aux2->siguiente=nodo_inicio;
                    nodo_inicio->atras=aux2;
                    nodo_inicio->siguiente=NULL;
                }else{
                    nodo_final->siguiente=nodo_inicio;
                    nodo_inicio->atras=nodo_final;
                    aux1->siguiente=nodo_final;
                    nodo_final->atras=aux1;
                    nodo_inicio->siguiente=NULL;
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
            }while(aux!=NULL);
            if(nodo_final!=NULL && nodo_inicio!=NULL){
                nodo_final->siguiente=aux2;
                aux2->atras=nodo_final;
                aux3->siguiente=nodo_inicio;
                nodo_inicio->atras=aux3;
                primero=nodo_final;


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

template <class T>
void listaDoble<T>::mostrarLista(string t){
    t=t+"Lista Doble: \n";
    NodoListaDoble* n;
    n = primero;
    do{
        t=t+n->elemento+"\n";
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

template <>
void listaDoble<persona*>::mostrarLista(){
    cout<<"Lista Doble: \n";
    NodoListaDoble* n;
    n = primero;
    do{
        cout << n->elemento->getNombre() << " : " << n->elemento->getCedula() <<" : "<< n->elemento->getEdad()<<endl;
        n=n->siguiente;
    }while(n!=NULL);
}

template <>
void listaDoble<persona*>::mostrarLista(){
    t=t+"Lista Doble: \n";
    NodoListaDoble* n;
    n = primero;
    do{
        t=t+n->elemento->getNombre() + " : " + n->elemento->getCedula() +" : "+ n->elemento->getEdad()+"\n";
        n=n->siguiente;
    }while(n!=NULL);
}

#endif
