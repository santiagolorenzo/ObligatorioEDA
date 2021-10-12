#ifndef OBLIG_H
#define OBLIG_H

#include "linea.h"
#include "palabra.h"

#define MAX_CANT_PALABRAS_X_LINEA 10

typedef char* Cadena;
enum _retorno{
    OK, ERROR, NO_IMPLEMENTADA
};
typedef enum _retorno TipoRetorno;
typedef unsigned int Posicion;

//      CONSTRUCTORAS

//Pre: Na.
//Pos: Crea un texto vacio.
TipoRetorno CrearTexto(Texto &a);

//Pre: Na.
//Pos: Crea e inserta una línea vacía al final del texto.
TipoRetorno InsertarLinea(Texto &a);

//Pre: Na.
//Pos: Agrega una linea nueva en la posicion dada en el texto a.
TipoRetorno InsertarLineaEnPosicion(Texto &a, Posicion posicionLinea);

//Pre: Na.
//Pos: Agrega una palabra al texto a, en la posicion de linea y de palabra dada. 
TipoRetorno InsertarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);

//      PREDICADO

TipoRetorno ImprimirTexto(Texto a);//Temporal

//Pre: Na.
//Pos: Agrega una linea nueva en la posicion dada en el texto a.
TipoRetorno InsertarLineaEnPosicion(Texto &a, Posicion posicionLinea);

//      DESTRUCTORAS
//Pre: Na.
//Pos: Borra la linea dada del texto a.
TipoRetorno BorrarLinea(Texto &a, Posicion posicionLinea);

//Pre: Na.
//Pos: Borra todas las lineas del texto.
TipoRetorno BorrarTodo(Texto &a);

//Pre: Na.
//Post: Borra todas las ocurrencias de la palabraABorrar del texto a
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);

//Pre: Na.
//Post: Borra tolas las ocurrencias de la palabraABorrar de la línea posicionLinea del texto a
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);

/*


TipoRetorno ComprimirTexto(Texto &a);
TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea);
*/


void verificacion(TipoRetorno r);
int menu();


#endif // OBLIG_H
