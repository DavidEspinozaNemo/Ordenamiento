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
            NodoCola (T x)
            {
                elemento = x;
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
            T frenteCola();
            void borrarCola();
            void insertar(T elemento);
            void mostrarCola(cola<T>& q);
            bool colaVacia() const;


};

#endif // COLA_H
