#ifndef COMMONOBJECT_H
#define COMMONOBJECT_H

#include<iostream>
#include<cstdlib>
#include<string>
#define MaxObjects 3

struct ComObject
{
public:
    virtual int getIdentidad() = 0;
};

//------------------------------------------------------

class Numero : public ComObject
{
    int Dato;
public:
    Numero(int d){ this->Dato = d;}
    int getIdentidad() {return Dato;}
};

class Letra : public ComObject
{
    char Dato;
public:
    Letra(char d){ this->Dato = d;}
    int getIdentidad() {return (int)Dato;}
};

//sigue sin funcionar
class Palabra : public ComObject
{
    std::string Dato;
public:
    Palabra(std::string d){ this->Dato = d;}
    int getIdentidad(){
        int size = Dato.size(), total = 0;
        for(int a = 0; a<size; a++) total += (int)Dato[a];
        return total;
    }
};
//-----------------Objetos---Manipulables------------------------------

template<class T>
ComObject* GetObject(int type, T dato){
    switch(type)
    {
        case 0: return new Numero(dato);
        case 1: return new Letra(dato);
        //case 2: return new Palabra(dato);
        default:
            return nullptr;
    };
}


#endif // COMMONOBJECT_H
