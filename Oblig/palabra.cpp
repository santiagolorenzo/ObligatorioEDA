#include "palabra.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



Palabra crearPalabrasVacia(){
    return NULL;
}

void crearPalabra(Palabra &p, Cadena palabra){
    Palabra aux = new struct str_pal;
    aux->palabra = new char;
    memcpy(aux->palabra, palabra, sizeof(palabra)+1);
    aux->sig= p;
    p = aux;
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

void imprimirPalabraPosicion(Palabra p, int xp){
	if(xp==1){
        printf("%s ", p->palabra);
	}
	else if (!isEmpty(p)){
        imprimirPalabraPosicion(p->sig, xp-1);
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


//borra palabra de la posicion xp
void borrarPalabra(Palabra &p, int xp){
	if(xp==1){
        Palabra aux = tail(p);
        delete p;
        p =aux;
	}
	else if (!isEmpty(p)){
        	borrarPalabra(p->sig, xp-1);
	}
}

UltPalabras crearUltPalabras(){
    UltPalabras ultPalabras = new struct str_cabezal;
    ultPalabras->primero = NULL;
    ultPalabras->ultimo = NULL;
    ultPalabras->cantidad = 0;
    return ultPalabras;
}

void agregarUltPalabra(UltPalabras ultPalabras, Cadena palabra){
    NodoD nd = new struct str_nodo_doble;
    nd->palabra = new char;
    memcpy(nd->palabra, palabra, sizeof(palabra)+1);
    nd->ant = NULL;
    nd->sig = ultPalabras->primero;
    ultPalabras->cantidad = ultPalabras->cantidad + 1;

    if (ultPalabras->primero == NULL){
        ultPalabras->primero = nd;
        ultPalabras->ultimo = nd;
        
    }else{
        ultPalabras->primero->ant = nd;
        ultPalabras->primero = nd;
        if (ultPalabras->cantidad > MAX_CANT_ULTIMAS_PALABRAS){
            ultPalabras->ultimo = ultPalabras->ultimo->ant;
            delete ultPalabras->ultimo->sig;
            ultPalabras->ultimo->sig = NULL;
        }      
    }
}

void imprimirUltPalabras(UltPalabras ultPalabras){
    if (ultPalabras == NULL){
        printf("No se ingresaron palabras\n");
    }else{
        NodoD aux = ultPalabras->primero;
        while (aux != NULL){
            printf("%s\n", aux->palabra);
            aux = aux->sig;
        }
    }
}