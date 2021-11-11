#ifndef OBLIG_H
#define OBLIG_H

#include "linea.h"
#include "palabra.h"
#include "diccionario.h"
#include <stdlib.h>
#include <stdio.h>

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

//Pre: Na.
//Pos: Imprime todas las palabras de la posicion de linea dada.
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea);
//Pre: Na.
//Pos: Imprime todas las lineas y palabras del texto.
TipoRetorno ImprimirTexto(Texto a);//Temporal

//Pre: Na.
//Post: Comprime el texto para que no queden líneas vacías ni líneas sin completar con excepción de la última línea del texto
TipoRetorno ComprimirTexto(Texto &a);
//Pre: Na.
//Post: Imprime las ultimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas en el texto t
TipoRetorno ImprimirUltimasPalabras(UltPalabras p);

//      DESTRUCTORAS

//Pre: Na.
//Pos: Borra la linea dada del texto a.
TipoRetorno BorrarLinea(Texto &a, Posicion posicionLinea);

//Pre: Na.
//Pos: Borra todas las lineas del texto.
TipoRetorno BorrarTodo(Texto &a);

//Pre: Na.
//Pos: Borra todas las ocurrencias de la palabraABorrar del texto a
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);

//Pre: Na.
//Pos: Borra tolas las ocurrencias de la palabraABorrar de la línea posicionLinea del texto a
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);
//Pre: Na.
//Pos: Borra la palabra de la posición posicionPalabra de la línea posicionLinea
TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);

//Pre: Na.
//Pos: Agrega la palabraAIngresar al diccionario d
TipoRetorno IngresarPalabraDiccionario(Diccionario &d, Cadena palabraAIngresar);

//Pre: Na.
//Pos: Borra la palabraABorrar del diccionario d
TipoRetorno BorrarPalabraDiccionario(Diccionario &d, Cadena palabraABorrar);

//Pre: Na.
//Pos: Imprime el diccionario d
TipoRetorno ImprimirDiccionario(Diccionario d);

//Pre: Na.
//Pos: Impirme las palabras del texto t que no están en el diccionario d
TipoRetorno ImprimirTextoIncorrecto(Texto t, Diccionario d);

#endif // OBLIG_H
