#ifndef LECTORARCHIVO_H
#define LECTORARCHIVO_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "listadoble.h"
using namespace std;

listaDoble<string>* leerPalabras(){
    //Esto es para crear el archivo, se elimina despues de usarlo una vez.
    //ofstream fichero;
    //fichero.open("biblioteca", ios::out);
    //for(int i = 0; i < 10; i++) fichero.put('h');
    //fichero.close();

    listaDoble<string> *Biblioteca = new listaDoble<string>();
    string LaPalabra = "";
    char c;
    ifstream fichero1("biblioteca", ios::in);
    while(fichero1.get(c)){
        if(c == ',') {
            Biblioteca->insertarPos(LaPalabra, 1);
            LaPalabra = "";
        }
        else {
            LaPalabra = LaPalabra + c;
        }
    }
    return Biblioteca;
}

listaDoble<char>* tranformarString(string dato){
    listaDoble<char> *LaPalabra = new listaDoble<char>();
    int size = dato.size();
    char letra;
    for(int i = 0; i<size; i++) {
        letra = (char)(dato[i]);
        LaPalabra->insertarPos(letra, i);
    }
    for(int i = size-1; i>0; i--) {
        LaPalabra->cambio(i,i-1);
    }
    return LaPalabra;
}

#endif // LECTORARCHIVO_H
