#ifndef MYBINSORT_H
#define MYBINSORT_H

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

#endif
