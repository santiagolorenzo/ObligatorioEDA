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
int cantPalabras(Texto t, int x){
    if(x>cantLineas(t)){
        return -1;
    }else if(isEmpty(t)){
        return 0;
    }else if(x==1){
        return cantPalabras(t->palabras);
    }else{
        return cantPalabras(tail(t), x-1);
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
    if(x==1){
        Texto aux=tail(t);
        delete t;
        t=aux;
    }
    if(!isEmpty(t)){
        borrarLineaPosicion(t->sig,x-1);
    }
}
void borrarTodo(Texto &t){
    if(!isEmpty(t)){
        borrarLineaPosicion(t, 1);
        borrarTodo(t);
    }
}
void crearPalabraPosicion(Texto t, int plinea, int ppalabra, Cadena palabra){
    if(plinea==1 && !isEmpty(t)){
        insertarPalabra(t->palabras, ppalabra, palabra);
    }else{
        crearPalabraPosicion(t->sig, plinea-1, ppalabra, palabra);
    }
}