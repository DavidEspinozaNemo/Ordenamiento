// archivo PilaGenerica.h

#ifndef PILAGENERICA_H
#define PILAGENERICA_H
#include <iostream>
template <class T>
class PilaGenerica
{
 	class NodoPila
 	{
 	public:
 		NodoPila* siguiente;
 		T elemento;
        int es_string;
        int es_objeto;
        NodoPila(T x,int str,int obj)
 		{
        es_string=str;
        es_objeto=obj;
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
 		
        void insertar(T elemento,int,int);
 		T quitar();
 		
        T cimaPila();

 		bool pilaVacia() { return cima == NULL; }
 		void limpiarPila();
        void mostrarPila();

		
};

#endif
