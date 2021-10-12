#include "linea.h"
#include "palabra.h"
#include <string.h>

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
    if (a == NULL){
        printf(" \n");
    }else{
        printf("%d: ", cantLineas(a));
        imprimirPalabras(a->palabras);
    }
}

void imprimirTexto(Texto a){
    if(!isEmpty(a)){
        imprimirLinea(a);
        imprimirTexto(tail(a));
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

void borrarLineaPosicion(Texto &t, int x){      //Agregar borrar palabras
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

void borrarOcurrenciasPalabraEnLinea(Texto &t, int x, Cadena palabraABorrar){
    if (x>= 0 && x <= cantLineas(t)+1){
        if(x == 1){
            Palabra aux2 = t->palabras;
            while (!isEmpty(aux2)){
                aux2 = aux2->sig;
                if (strcmp(palabraABorrar, t->palabras->palabra) == 0){
                    
                    Palabra aux = tail(t->palabras);
                    delete t->palabras;
                    t->palabras = aux;
                   
                }
            }
        }else if(!isEmpty(t)){
            borrarOcurrenciasPalabraEnLinea(t->sig,x-1, palabraABorrar);
            
        }
           
    }
}

void borrarOcurrenciasPalabraEnTexto(Texto &t, Cadena palabraABorrar){
        int x = cantLineas(t);
        while (x > 0) {
            borrarOcurrenciasPalabraEnLinea(t, x-1, palabraABorrar);
            x--;
        }    
}