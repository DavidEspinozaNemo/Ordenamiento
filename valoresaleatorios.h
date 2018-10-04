#ifndef VALORESALEATORIOS_H
#define VALORESALEATORIOS_H

#include "listadoble.h"
#include "lectorarchivo.h"
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;


//Generar una lista de numeros aleatorios.
listaDoble<int>* generarNumeros(int rango){
    int num;
    srand(time(NULL));
    listaDoble<int> *lista = new listaDoble<int>();
    for(int i = 0; i<rango; i++){
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        num = 1 + rand()%1000000;
        lista->insertarPos(num,0);
    }
    return lista;
}
//Generar una lista de letras aleatorias.
listaDoble<char>* generarChars(int rango){
    int num;
    char letr;
    srand(time(NULL));
    listaDoble<char> *lista = new listaDoble<char>();
    for(int i = 0; i<rango; i++){
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        num = 97 + rand()% (123-97) ;
        letr = (char)num;
        if(letr != '}' && letr != '{' && letr != ']' && letr != '[')lista->insertarPos(letr,0);
        else i--;
    }
    return lista;
}

//Generar una lista de palabras aleatorias.
listaDoble<string>* generarPalabras(int rango){
    listaDoble<string> *biblioteca = leerPalabras();
    int rangoDeBibliot =biblioteca->cantDatos(), num;
    listaDoble<string> *lista = new listaDoble<string>();
    for(int i = 0; i<rango; i++){
        num = rand()%(rangoDeBibliot-1);
        lista->insertarPos(biblioteca->getDato(num),0);
    }
    return lista;
}

#endif // VALORESALEATORIOS_H
