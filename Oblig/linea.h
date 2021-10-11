#ifndef LINEA_H
#define LINEA_H
#include "palabra.h"
struct str_linea{
    Palabra palabras;
    str_linea * sig;
};
typedef struct str_linea * Texto;


//CONSTRUCTORAS

//Pre: na.
//Pos: Crea un texto vacío.
Texto crearTextoVacio();

//Pre: na.
//Pos: Crea una línea en el texto t.
void crearLinea(Texto &t);

//Pre: na.
//Pos: Crea una linea nueva en la posicion de x del texto a.
void crearLineaPosicion(Texto &a, int x);

//Pre: na.
//Post: Imprime una línea del texto
void imprimirLinea(Texto a);

//Pre: na.
//Pos: Devuelve true si t es un texto vacio, o false en caso contrario.
bool isEmpty(Texto t);

//Pre: na.
//Pos: Devuelve la cantidad de palabras que tiene el texto t.
int cantLineas(Texto t);

//Pre: n/a
//Post: devuelve el valor del primer elemento de la lista
Texto head(Texto t);

//Pre: na.
//Pos: Devuelve la linea siguiente del texto.
Texto tail(Texto l);

//Pre: na.
//Pos: Elimina la linea x del texto t.
void borrarLineaPosicion(Texto &t, int x);

#endif // LINEA_H
