#include "palabra.h"
#include <stdlib.h>

Palabra crearPalabrasVacia(){
    return NULL;
}
void crearPalabra(Palabra &p){
    //Hacer
}
bool isEmpty(Palabra p){
    if(p==NULL){
        return true;
    }else{
        return false;
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
void insertarPalabra(Palabra p, int x, Cadena palabra){
    if(x==1){
        //Terminar
    }
}