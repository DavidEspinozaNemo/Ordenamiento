
#include "claseextra.cpp"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <fstream>
//#include "listasimple.h"

using namespace std;

bool mayor(int inicio,int final){
    if(inicio>final){
        return true;
    }else{
        return false;
    }
}
bool mayor(char inicio,char final){
    //cout<<"char";
    int num1= ("d%",inicio);
    int num2= ("d%",final);
    if(num1>num2){
        return true;
    }else{
        return false;
    }
}

bool mayor(string inicio,string final){
    int cantidad1 = inicio.size();
    int cantidad2 = final.size();
    int contador1=0;
    int contador2=0;
    if(cantidad1<cantidad2){
        for(contador1=0;contador1<cantidad1;contador1++){
            char primera1 = inicio[contador1];
            char primera2 = final[contador1];
            int num1 = ("d%",primera1);
            int num2 = ("d%",primera2);
            if(num1>num2){
                return true;
            }else{
                return false;
            }
        }


    }else{
        for(contador2=0;contador2<cantidad2;contador2++){
            char primera1 = inicio[contador2];
            char primera2 = final[contador2];
            int num1 = ("d%",primera1);
            int num2 = ("d%",primera2);
            if(num1>num2){
                return true;
            }else{
                return false;
            }
        }
    }



}


bool mayor(persona* inicio,persona* final){
    int primera1 = inicio->getCedula();
    int primera2 = final->getCedula();
    int num1 = ("d%",primera1);
    int num2 = ("d%",primera2);
    if(num1>num2){
        return true;
    }else{
        return false;
    }
}

bool menor(int inicio,int final){

    if(inicio<final){
        return true;
    }else{
        return false;
    }
}
bool menor(char inicio,char final){
    int num1= ("d%",inicio);
    int num2= ("d%",final);
    if(num1<num2){
        return true;
    }else{
        return false;
    }
}

bool menor(string inicio,string final){
    char primera1 = inicio[0];
    char primera2 = final[0];
    int num1 = ("d%",primera1);
    int num2 = ("d%",primera2);
    if(num1<num2){
        return true;
    }else{
        return false;
    }
}



void tri_insertion(int* t) //YOSUA BLANCO DIAZ
{
    std::cout<<"Tri insertion: ";
    int en_cours, j;
    for(int i = 1; i < 20; i++)
    {
        en_cours = t[i];
        for(j = i; j > 0 && t[j-1] > en_cours;j--) t[j] = t[j-1];
        t[j] = en_cours;
    }
}

template <class T>
void tri_bulle(T tableau)  //YOSUA BLANCO DIAZ // LISTO CON :INT,CHAR
{
    //std::cout<<"Ordenando "<<endl;
    int passage = 0;
    bool permutation = true;
    int en_cours;
    while(permutation)
    {
        permutation = false;
        passage++;

        for(en_cours=0; en_cours<(tableau->cantDatos()+1)-passage; en_cours++)
        {
            if(mayor(tableau->sacarDatos(en_cours),tableau->sacarDatos(en_cours+1)))
            {
                permutation = true;
                tableau->cambio(en_cours,en_cours+1);
            }
        }
    }
    //cout<<"ordenado";
}

void bulle(int* tableau, int p) {  // YOSUA BLANCO DIAZ //LISTO
    int i_b = p;
    while ((i_b>0) && (tableau[i_b]<tableau[i_b - 1])) {
        int t = tableau[i_b -1];
        tableau[i_b - 1]= tableau[i_b];
        tableau[i_b ] = t;
        i_b --;
    }
}

void tri_gnome (int* tableau) {     //YOSUA BLANCO DIAZ PARTE DEL BULLE
    std::cout<<"Tri gnome: ";
    for (int i_i=0;i_i<20;i_i++) bulle(tableau,i_i);
}

template <class T>
void tri_selection(T tableau, int taille) // YOSUA BLANCO DIAZ
{
    std::cout<<"Tri Selection: ";
     int en_cours, plus_petit, j;
     for (en_cours = 0; en_cours < taille-1 ; en_cours++)
     {
         plus_petit = en_cours;
         for (j = en_cours; j < taille; j++)
             if (menor(tableau->sacarDatos(j),tableau->sacarDatos(plus_petit)))
                 plus_petit = j;
         tableau->cambio(en_cours,plus_petit);

     }
}


void tri_insertion(int* t, int gap, int debut) // PARTE DEL SHELL  // YOSUA BLANCO DIAZ
{
    int j,en_cours;
    for (int i = gap + debut; i < 20; i+=gap) {
        en_cours = t[i];
        for (j = i; j >= gap && t[j - gap] > en_cours; j-=gap) {
            t[j] = t[j - gap];
        }
        t[j] = en_cours;
    }
}

void tri_shell(int* t) {  // YOSUA BLANCO DIAZ
    std::cout<<"Tri Shell: ";
    int intervalles[5]={6,4,3,2,1};
    for (int ngap=0;ngap<5;ngap++) {
        for (int i=0;i<intervalles[ngap];i++)
            tri_insertion(t,intervalles[ngap],i);
    }
}

//-----------  ALGORITMOS DE DAVID --------------------------------------

//------------------------ radixsort ----------------------------
//https://www.geeksforgeeks.org/radix-sort/
// A utility function to get maximum value in arr[]
template <class T>
T getMax(T arr[], int n)
{
    T mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
template < class T>
void countSort(T arr[], int n, int exp)
{
    T output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ ( ((int)arr[i])/exp )%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
template <class T>
void radixsort(T arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
template <class T>
void print(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}


//----------------- quickSort ------------------

template <class T>
void quicksort(T *tabla, int primero, int ultimo)
{
    int i, j, central;
    //int pivote;

    central = (primero + ultimo) / 2;
    //pivote = tabla[central];
    i = primero;
    j = ultimo;

    do {
        while (menor(tabla->sacarDatos(i),tabla->sacarDatos(central))) i++; //tabla[i] < pivote
        while (mayor(tabla->sacarDatos(j),tabla->sacarDatos(central))) j--; //tabla[j] > pivote
        if (i <= j)
        {
            //T temp = tabla[i];
            //tabla[i] = tabla[j];

            //tabla[j] = temp;
            tabla->cambio(i,j);
            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        quicksort(tabla, primero, j); // mismo proceso con sublista izqda
    if (i < ultimo)
        quicksort(tabla, i, ultimo); // mismo proceso con sublista drcha
}

//------------------ Binsort -----------------------------

template <class T>
void Mybinsort(T lista[], int cantidadElementos){
    cantidadElementos++;
    int largoUrna = (int)(cantidadElementos * 0.4);
    int anchoUrna = (int)(cantidadElementos * 0.6);

    int filasOcupadas[anchoUrna];
    T Urna[anchoUrna][largoUrna];

    for(int a = 0; a<anchoUrna; a++){
        filasOcupadas[a] = 0;
        for(int b = 0; b<largoUrna; b++) Urna[a][b] = 0;
    }

    for(int a = 0; a<cantidadElementos; a++){
        T Dato = lista[a];
        int UbicacionDato = ((int)Dato)%cantidadElementos; //Para que elementos que pasen del rango, entren.
        int ejeX = (int)(UbicacionDato/largoUrna);
        int ejeY = ((int)UbicacionDato%largoUrna) -1;
        if(Urna[ejeX][ejeY] == 0){
            Urna[ejeX][ejeY] = Dato;
            filasOcupadas[ejeX] = 1;
        }
        else{
            //Aun no se que hacer
        }
    }

    int c = 0;
    for(int a = 0; a<anchoUrna; a++){
        if(c>=cantidadElementos) break;
        if(filasOcupadas[a] == 1){
            for(int b = 0; b<largoUrna; b++) if(Urna[a][b] != 0) lista[c++] = Urna[a][b];
        }
    }
}

//----------------- mergesorth ---------------------


//https://www.geeksforgeeks.org/merge-sort/
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
template < class T>
void merge(T arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    T L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
template < class T>
void mergeSort(T arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
template< class T>
void printArray2(T A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout << A[i]<<" ";
    std::cout<<"\n";
}


//------------------------  heapsprt --------------------


//https://www.geeksforgeeks.org/heap-sort/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template <class T>
void heapify(T arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        T temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        //swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
template <class T>
void heapSort(T arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        T temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        //swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
template < class T>
void printArray(T arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
