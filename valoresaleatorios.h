#ifndef VALORESALEATORIOS_H
#define VALORESALEATORIOS_H

#include "listadoble.h"
#include "lectorarchivo.h"
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include <cstdlib>
#include "cola.h"
using namespace std;

template <class T>
void crearNombresAleatorios(T est);

template <class T>
T llenarlista(T lista,cola<char>& q){
    q.mostrarCola(q);
    return lista;
}
template <class T>
T llenarlista(T lista,cola<string>& q){
    q.mostrarCola(q);
    return lista;
}
template <class T>
T llenarlista(T lista,cola<persona>& q){
    q.mostrarCola(q);
    return lista;
}
//Generar una lista de numeros aleatorios.
template <class T>
void generarNumeros(T est, int rango){
    int num;
    srand(time(NULL));
    //listaDoble<int> *lista = new listaDoble<int>();
    for(int i = 0; i<rango; i++){
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        num = 1 + rand()%1000000;
        est->insertar(num);
    }
}
//Generar una lista de letras aleatorias.
template <class T>
void generarChars(T est, int rango){
    int num;
    char letr;
    srand(time(NULL));
    for(int i = 0; i<rango; i++){
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        num = 97 + rand()% (123-97) ;
        letr = (char)num;
        if(letr != '}' && letr != '{' && letr != ']' && letr != '[') est->insertar(letr);
        else i--;
    }
}

//Generar una lista de palabras aleatorias.
template <class T>
void generarPalabras(T est, int rango){
    listaDoble<string> *biblioteca = leerPalabras();
    int rangoDeBibliot =biblioteca->cantDatos(), num;
    for(int i = 0; i<rango; i++){
        num = rand()%(rangoDeBibliot-1);
        est->insertar(biblioteca->getDato(num));
    }
}

//Generar un lista de objetos Personas aleatorias
template <class T>
void generarPersonas(T est, int rango){
    listaDoble<string> *NombreAleatorios = new listaDoble<string>();
    crearNombresAleatorios(NombreAleatorios);
    int rangoEdad, rangoCedula, rangoNombre;
    for(int i = 0; i<rango; i++){
        rangoEdad = 15 + rand()%(85);
        rangoCedula = 1000000 + rand()%(100000);
        rangoNombre = rand()%(NombreAleatorios->cantDatos()-1);
        est->insertar(new persona(NombreAleatorios->getDato(rangoNombre),rangoEdad,rangoCedula));
    }
}

//Defino nombres aleatorios
template <class T>
void crearNombresAleatorios(T est){
    est->insertar("Sebastian");
    est->insertar("Rodrigo");
    est->insertar("David");
    est->insertar("Ismael");
    est->insertar("Maria");
    est->insertar("Fabiana");
    est->insertar("Fabian");
    est->insertar("Martinez");
    est->insertar("Alexander");
    est->insertar("Felipe");
    est->insertar("Juana");
    est->insertar("Rose");
    est->insertar("Emilia");
    est->insertar("Esperanza");
    est->insertar("Toto");
}

#endif // VALORESALEATORIOS_H
