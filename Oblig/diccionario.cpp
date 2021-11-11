#include "diccionario.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// CONSTRUCTORAS

Diccionario crearDiccVacio(){
    return NULL;
}

void agregarPalabraDicc(Diccionario &d, Cadena palabra){
    if (isEmptyDicc(d)){
        d = new struct str_dicc;
        d->palabraDicc = new char;
        memcpy(d->palabraDicc, palabra, sizeof(palabra)+1);
        d->hizq = NULL;
        d->hder = NULL;
    }else if (strcasecmp(d->palabraDicc, palabra) > 0 ){
        agregarPalabraDicc(d->hizq, palabra);
    }else if (strcasecmp(d->palabraDicc, palabra) < 0){
        agregarPalabraDicc(d->hder, palabra);
    }
}


// PREDICADO

bool isEmptyDicc(Diccionario d){
    if (d == NULL){
        return true;
    }else{
        return false;
    }
}

bool esHoja(Diccionario d){
    return isEmptyDicc(subDiccIzq(d)) && isEmptyDicc(subDiccDer(d));
}

Cadena raiz(Diccionario d){
    return d->palabraDicc;
}

Diccionario subDiccIzq(Diccionario d){
    return d->hizq;
}

Diccionario subDiccDer(Diccionario d){
    return d->hder;
}


void imprimirDicc(Diccionario d){
    if (!isEmptyDicc(d)){
        imprimirDicc(subDiccIzq(d));
        printf("%s\n", raiz(d));
        imprimirDicc(subDiccDer(d));
    }
}

bool buscarPalabraDicc(Diccionario d, Cadena palabra){
    if (isEmptyDicc(d)){
        return false;
    }else if (strcasecmp(d->palabraDicc, palabra)  == 0){
        return true;
    }else if (strcasecmp(d->palabraDicc, palabra)  > 0){
        return buscarPalabraDicc(subDiccIzq(d), palabra);
    }else{
        return buscarPalabraDicc(subDiccDer(d), palabra);
    }
}

Cadena menor(Diccionario d){
    if (isEmptyDicc(subDiccIzq(d))){
        return raiz(d);
    }else{
        return menor(subDiccIzq(d));
    }
}

void imprimirErroresLinea(Palabra p, Diccionario d){
    if (!isEmpty(p)){
        if (!buscarPalabraDicc(d, p->palabra)){
            imprimirPalabraPosicion(p, 1);
            imprimirErroresLinea(tail(p), d);
        }else{
            imprimirErroresLinea(tail(p), d);
        }
    }
}

void imprimirErroresTexto(Texto t, Diccionario d){
    if (!isEmpty(t)){
        if (!isEmpty(t->palabras)){
            if (!buscarPalabraDicc(d, t->palabras->palabra)){
                imprimirErroresTexto(tail(t), d);
                printf("%d: ", cantLineas(t));
                imprimirErroresLinea(t->palabras, d);
                printf("\n");
            }else{
                imprimirErroresTexto(tail(t), d);
                printf("%d: ", cantLineas(t));
                printf("\n");
            }
        }else{
            imprimirErroresTexto(tail(t), d);
            printf("%d: ", cantLineas(t));
            printf("\n");
        }
    }
}


// DESTRUCTORAS

void borrarPalabraDicc(Diccionario &d, Cadena palabra){
    if (!isEmptyDicc(d)){
        if (strcasecmp(raiz(d), palabra) == 0){
            if (isEmptyDicc(subDiccIzq(d)) && isEmptyDicc(subDiccDer(d))){
                delete d;
                d = crearDiccVacio();
            }else if (!isEmptyDicc(subDiccDer(d))){
                Cadena menor_der = menor(subDiccDer(d));
                d->palabraDicc = menor_der;
                borrarPalabraDicc(d->hder, menor_der);
            }else{
                Diccionario aux = d->hizq;
                delete d;
                d = aux;
            }
        }else if (strcasecmp(raiz(d), palabra)  < 0){
            borrarPalabraDicc(d->hder, palabra);
        }else{
            borrarPalabraDicc(d->hizq, palabra);
        }
    }
}