// archivo PilaGenerica.h

#ifndef PILAGENERICA_H
#define PILAGENERICA_H
#include <iostream>
#include <sstream>
#include <stdio.h>

template <class T>
class PilaGenerica
{
 	class NodoPila
 	{
 	public:
 		NodoPila* siguiente;
 		T elemento;
        NodoPila(T x)
 		{
        elemento = x;
 		siguiente = NULL;
 		}
 	};
 	
 	NodoPila* cima;
 	public:
 		PilaGenerica ()
 		{
 			cima = NULL;
 		}
 		
        void insertar(T elemento);
 		T quitar();
 		
        T cimaPila();

 		bool pilaVacia() { return cima == NULL; }
 		void limpiarPila();
        void mostrarPila();
        void mostrarPila(std::string);

		
};

#endif
