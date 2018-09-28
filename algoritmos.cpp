
//#include "algoritmos.h"

#include<iostream>
//#include <stdio.h>
//#include <stdlib.h>

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
void tri_bulle(T tableau)  //YOSUA BLANCO DIAZ
{
    std::cout<<"Tri Bulle: ";
    int passage = 0;
    bool permutation = true;
    int en_cours;
    while(permutation)
    {
        permutation = false;
        passage++;
        for(en_cours=0; en_cours<20-passage; en_cours++)
        {
            if(tableau->mayor(en_cours,en_cours+1)) // tableau.mayor(en_cours,en_cours+1,tipo de dato)
            {
                permutation = true;
                //on echange les deux elements
                //int temp = tableau[en_cours];
                //tableau[en_cours] = tableau[en_cours+1];
                //tableau[en_cours+1] = temp;
                tableau->cambio(en_cours,en_cours+1);
            }
        }
    }
}

void bulle(int* tableau, int p) {
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


void tri_selection(int *tableau, int taille) // YOSUA BLANCO DIAZ
{
    std::cout<<"Tri Selection: ";
     int en_cours, plus_petit, j, temp;

     for (en_cours = 0; en_cours < taille - 1; en_cours++)
     {
         plus_petit = en_cours;
         for (j = en_cours; j < taille; j++) if (tableau[j] < tableau[plus_petit]) plus_petit = j;
          temp = tableau[en_cours];
          tableau[en_cours] = tableau[plus_petit];
          tableau[plus_petit] = temp;
     }
}



void tri_insertion(int* t, int gap, int debut) // PARTE DEL SHELL
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
