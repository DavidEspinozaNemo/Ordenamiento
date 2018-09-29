#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class T>
void quicksort(T *a, int primero, int ultimo)
{
    int i, j, central;
    T pivote;

    central = (primero + ultimo) / 2;
    pivote = a[central];
    i = primero;
    j = ultimo;

    do {
        while (a[i] < pivote) i++;
        while (a[j] > pivote) j--;
        if (i <= j)
        {
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        quicksort(a, primero, j); // mismo proceso con sublista izqda
    if (i < ultimo)
        quicksort(a, i, ultimo); // mismo proceso con sublista drcha
}

#endif
