#ifndef COLA_H
#define COLA_H
#include <iostream>
template <class T>
class cola
{
private:
    class NodoCola
        {
        public:
            NodoCola* siguiente;
            T elemento;
            int es_string;
            int es_objto;
            NodoCola (T x,int str,int obj)
            {
                elemento = x;
                es_objto=obj;
                es_string=str;
                siguiente = nullptr;
            }
        };
        NodoCola* frente;
        NodoCola* final;
public:
        cola()
            {
                frente = final = nullptr;
            }

            T quitar();
            T frenteCola()const;
            void borrarCola();
            void insertar(T elemento,int,int);
            void mostrarCola(cola<T>& q);
            bool colaVacia() const;

};

#endif // COLA_H
