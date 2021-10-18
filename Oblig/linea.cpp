#include "linea.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Texto crearTextoVacio(){
    return NULL;
}


void crearLinea(Texto &t){
    Texto aux = new str_linea;
    aux->palabras = crearPalabrasVacia();
    aux->sig = t;
    t = aux;
}

void imprimirLinea(Texto a){
    if (isEmpty(a)){
        printf("\n");
    }else{
        printf("%d: ", cantLineas(a));
        imprimirPalabras(a->palabras);
    }
}


void imprimirTexto(Texto a){
    if (!isEmpty(a)){
        imprimirTexto(a->sig);
        imprimirLineaPosicion(a, cantLineas(a));
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
    }else if(x==cantLineas(t)){
        return cantPalabras(t->palabras);
    }else{
        return cantPalabras(tail(t), x);
    }
}

void crearLineaPosicion(Texto &t, int x){
    if(!isEmpty(t)){
        if(x==cantLineas(t)+1){
            crearLinea(t);
        }else{
            crearLineaPosicion(t->sig, x);
        }
    }else{
        crearLinea(t);
    }
}

void borrarLineaPosicion(Texto &t, int x){    
    if(x==cantLineas(t)){
        while(t->palabras != NULL){
            borrarPalabra(t->palabras, 1);
        }
        Texto aux=tail(t);
        delete t;
        t=aux;
    }else if(!isEmpty(t)){
        borrarLineaPosicion(t->sig,x);
    }
}

void borrarTodo(Texto &t){
    if(!isEmpty(t)){
        borrarLineaPosicion(t, 1);
        borrarTodo(t);
    }
}

void crearPalabraPosicion(Texto t, int plinea, int ppalabra, Cadena palabra){
    if(plinea==cantLineas(t) && !isEmpty(t)){
        insertarPalabra(t->palabras, ppalabra, palabra);
    }else{
        crearPalabraPosicion(t->sig, plinea, ppalabra, palabra);
    }
}

void verificarTamano(Texto &t){ //Es para que si se pasa de la cantidad de palabras por linea la pase para abajo
    Texto aux=t;
    int linea=1;
    while(!isEmpty(aux)){
        if(cantPalabras(aux->palabras)>MAX_CANT_PALABRAS_X_LINEA){
            int i=1;
            Palabra pSobrante=aux->palabras;
            while(i<=MAX_CANT_PALABRAS_X_LINEA){
                pSobrante=pSobrante->sig;
                i++;
            }
            crearPalabraPosicion(t, linea+1, 1, pSobrante->palabra);
            borrarPalabra(aux->palabras, MAX_CANT_PALABRAS_X_LINEA+1);
            linea++;
        }
        aux=aux->sig;
    }
}

void borrarPalabraPosicion(Texto &t, int xl, int xp){
    if(xl==cantLineas(t)){
	    borrarPalabra(t->palabras,xp);
    }
    else if(!isEmpty(t)){
	    borrarPalabraPosicion(t->sig, xl, xp);
    }
}
void borrarOcurrenciasPalabraEnLinea(Texto &t, int x, Cadena palabraABorrar){
    if (x>= 0 && x <= cantLineas(t)){
        if(x == cantLineas(t)){
            Palabra aux = t->palabras;
            Palabra ant = t->palabras;
            while (!isEmpty(aux)){ 
                if (strcasecmp(palabraABorrar, aux->palabra) == 0){
                    if (aux == t->palabras){
                        t->palabras = t->palabras->sig;
                        delete aux;
                        aux = t->palabras;
                        ant = t->palabras;
                    }else{
                        ant->sig = aux->sig;
                        delete aux;
                        aux = ant->sig;  
                    }
                } else{  
                    ant = aux;
                    aux = tail(aux);
                }
            }
        }else if(!isEmpty(t)){
            borrarOcurrenciasPalabraEnLinea(t->sig, x, palabraABorrar); 
        }      
    }
}

void borrarOcurrenciasPalabraEnTexto(Texto &t, Cadena palabraABorrar){
        int x = 1;
        while (x <= cantLineas(t)) {
            borrarOcurrenciasPalabraEnLinea(t->sig, x, palabraABorrar);
            x++;
        }    
}

void imprimirLineaPosicion(Texto t, int x){
    if (x>= 0 && x <= cantLineas(t)+1){
        if(x == cantLineas(t)){
           imprimirLinea(t);
        }else{
            imprimirLineaPosicion(t->sig, x);
        }
    }
}


//Pre: Na.
//Post: Devuelve un texto invertido
Texto invertirTexto(Texto t){
    Texto dev = NULL;
    Texto aux = t;
    Texto sig = t;
    while(aux != NULL){
        sig = aux->sig;
        aux->sig = dev;
        dev = aux;
        aux = sig;
    }
    t = dev;
    return t;
}

void comprimirTexto(Texto &t){
    Texto aux = t;
    aux = invertirTexto(aux);
    //imprimirTexto(aux);

    Palabra auxPal = NULL;
    Palabra auxPal2;
    
    while(!isEmpty(aux)){
        while(!isEmpty(aux->palabras)){
            auxPal2 = auxPal;
            auxPal = new struct str_pal;
            auxPal->palabra = new char;
            memcpy(auxPal->palabra, aux->palabras->palabra, sizeof(aux->palabras->palabra)+1);
            auxPal->sig = auxPal2;
            aux->palabras = aux->palabras->sig;
        }
        aux = aux->sig;
    }
    invertirPalabra(auxPal);
    
    int j = cantPalabras(auxPal);
    int lineasNecesarias = trunc((j / MAX_CANT_PALABRAS_X_LINEA));

    Texto auxiliar = crearTextoVacio();
    for (int i = 0; i <= lineasNecesarias; i++){
        crearLinea(auxiliar);
    }
    
    auxiliar->palabras = crearPalabrasVacia();
    int posLinea = 1;
    int contador = 0;
    while (auxPal != NULL){
        if (contador == MAX_CANT_PALABRAS_X_LINEA){
            posLinea++;
            contador = 0;
        }
        crearPalabraPosicion(auxiliar, posLinea, contador + 1  , auxPal->palabra);
        contador++;
        auxPal = auxPal->sig;
    }   
    if (cantPalabras(auxiliar->palabras) == 0){
        auxiliar = auxiliar->sig;
    }
    t = auxiliar;
}

void invertirPalabra(Palabra &a){
    Palabra dev = NULL;
    Palabra aux = a;
    Palabra sig = a;
    while(aux != NULL){
        sig = aux->sig;
        aux->sig = dev;
        dev = aux;
        aux = sig;
    }
    a = dev;
}


