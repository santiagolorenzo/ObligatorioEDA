#include "linea.h"
#include <stdlib.h>
#include <stdio.h>
Texto crearTextoVacio(){
    return NULL;
}
void crearLinea(Texto &t){
    Texto aux = new str_linea;
    aux->palabras = crearPalabrasVacia();
    aux->sig = t;
    t = aux;
}

void imprimirLinea(Texto a){        // <---Hay que modificar 
    if (a == NULL){
        printf(" NULL \n");
    }else{
        imprimirLinea(a->sig);
        printf("%d : \n", (cantLineas(a)+ 1) - 1);
    }
}
Texto tail(Texto t){
    return t->sig;
}
bool isEmpty(Texto t){
    if(t==NULL){
        return true;
    }else{
        return false;
    }
}
int cantLineas(Texto t){
    if(isEmpty(t)){
        return 0;
    }else{
        return 1+cantLineas(tail(t));
    }
}
void crearLineaPosicion(Texto &t, int x){
    if(!isEmpty(t)){
        if(x==1){
            crearLinea(t);
            printf("Creo linea arriba\n");
        }else{
            crearLineaPosicion(t->sig, x-1);    //el tail da error ._.
        }
    }
}
void borrarLineaPosicion(Texto &t, int x){      //Ver si funciona cuando hayan palabras
    if(t!=NULL){
        if(x==1){
            Texto aux=t;
            t=t->sig;
            delete aux;
        }
        borrarLineaPosicion(t->sig,x-1);
    }
}

