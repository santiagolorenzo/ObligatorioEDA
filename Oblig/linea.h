#ifndef LINEA_H
#define LINEA_H
#include "palabra.h"
struct str_linea{
    Palabra palabras;
    str_linea * sig;
};
typedef struct str_linea * Texto;
//      CONSTRUCTORAS

//Pre: na.
//Pos: Crea un texto vacio.
Texto crearTextoVacio();
//Pre: na.
//Pos: Crea una linea vacia.
void crearLinea(Texto &t);
//Pre: na.
//Pos: Crea una linea nueva en la posicion de x del texto a.
void crearLineaPosicion(Texto &a, int x);
//Pre: Recibe un plinea mayor a 0, y menor a la cantidad de lineas.
//Pre: Recibe un ppalabra mayor a 0, y menor o igual a la cantidad de palabras+1.
//Pos: Crea una palabra en la posicion de linea y de palabra dada, en el texto t.
void crearPalabraPosicion(Texto t, int plinea, int ppalabra, Cadena palabra);

//      PREDICADO

void imprimirLinea(Texto a);

//Pre: na.
//Pos: Devuelve true si t es un texto vacio, o false en caso contrario.
bool isEmpty(Texto t);
//Pre: na.
//Pos: Devuelve la cantidad de palabras que tiene el texto t.
int cantLineas(Texto t);
//Pre: na.
//Pos: Devuelve la cantidad de palabras en la linea x del texto t.
int cantPalabras(Texto t, int x);
//Pre: Recibe un texto no vacio.
//Pos: Devuelve la linea siguiente del texto.
Texto tail(Texto l);

//      DESTRUCTORAS

//Pre: na.
//Pos: Elimina la linea x del texto t.
void borrarLineaPosicion(Texto &t, int x);
//Pre: na.
//Pos: Elimina todas las lineas del texto t.
void borrarTodo(Texto &t);
#endif // LINEA_H
