#ifndef CLASEEXTRA_CPP
#define CLASEEXTRA_CPP

#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;



class persona
{
    private:
        string nombre;
        int edad;
        int cedula;
    public:
        persona(string nom,int eda,int ced)
        {
            this->nombre=nom;
            this->edad=eda;
            this->cedula=ced;
        }

};

#endif // LISTADOBLE_H
