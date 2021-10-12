#include "palabra.h"
#include <stdlib.h>
#include <stdio.h>

Palabra crearPalabrasVacia(){
    return NULL;
}

void crearPalabra(Palabra &p, Cadena palabra){
    Palabra aux=new struct str_pal;
    aux->palabra= palabra;
    aux->sig= p;
    p= aux;
}

bool isEmpty(Palabra p){
    if(p==NULL){
        return true;
    }else{
        return false;
    }
}

void imprimirPalabras(Palabra p){
    if(!isEmpty(p)){
        printf("%s ", p->palabra);
        imprimirPalabras(tail(p));
    }else{
        printf("\n");
    }
}

Palabra tail(Palabra p){
    return p->sig;
}

int cantPalabras(Palabra p){
    if(isEmpty(p)){
        return 0;
    }else{
        return 1+cantPalabras(tail(p));
    }
}

void insertarPalabra(Palabra &p, int x, Cadena palabra){
    if(x==1){
        crearPalabra(p, palabra);
    }else{
        insertarPalabra(p->sig, x-1, palabra);
    }
}
