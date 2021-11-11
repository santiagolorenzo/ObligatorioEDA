#ifndef PALABRA_H
#define PALABRA_H
#define MAX_CANT_PALABRAS_X_LINEA 3
#define MAX_CANT_ULTIMAS_PALABRAS 3
#include <stdio.h>
#include <stdlib.h>

typedef char * Cadena;
struct str_pal{
    Cadena palabra;
    struct str_pal * sig;
};
typedef struct str_pal * Palabra;


// VER SI VA
struct str_nodo_doble{
    Cadena palabra;
    struct str_nodo_doble * ant;
    struct str_nodo_doble * sig;
};
typedef struct str_nodo_doble * NodoD;

struct str_cabezal{
    NodoD primero;
    NodoD ultimo;
    int cantidad;
};
typedef struct str_cabezal * UltPalabras;

///// HASTA ACÁ

//      CONSTRUCTORAS

//Pre: na.
//Pos: Crea una palabra vacia.
Palabra crearPalabrasVacia();

//Pre: 
//Pos: 
void crearPalabra(Palabra &p, Cadena palabra);

//Pre: na.
//Pos: Agrega una Cadeba palabra, en la posicion x de la Palabra p.
void insertarPalabra(Palabra &p, int x, Cadena palabra);

//Pre: Na.
//Pos: Crea la lista doblemente encadenada ultPalabras.
UltPalabras crearUltPalabras();

//Pre: Na.
//Pos: Agrega palabra en la lista DE ultPalabras.
void agregarUltPalabra(UltPalabras ultPalabras, Cadena palabra);


//      PREDICADO

//Pre: na.
//Pos: Devuelve true si la linea de palabras esta vacia, false en caso contrario.
bool isEmpty(Palabra p);

//Pre: na.
//Pos: Devuelve la cantidad de palabras en un str_pal.
int cantPalabras(Palabra p);

//Pre: Recibe una palabra no vacia.
//Pos: Devuelve la siguiente palabra.
Palabra tail(Palabra p);

//Pre: Na.
//Pos: Imprime la palabra p
void imprimirPalabras(Palabra p);

//Pre: Na.
//Pos: Imprime la palabra p que está en la posición xp
void imprimirPalabraPosicion(Palabra p, int xp);


//Pre: Na.
//Pos: Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
void imprimirUltPalabras(UltPalabras ultPalabras);


//      DESTRUCTORAS
//Pre: Na.
//Pos: Borra la palabra que está en la posición xp
void borrarPalabra(Palabra &p, int xp);


#endif // PALABRA_H
