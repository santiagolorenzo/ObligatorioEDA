#ifndef DICCIONARIO_H
#define DICCIONARIO_H

//#include "palabra.h"
#include "linea.h"
//typedef char * Cadena;

struct str_dicc{
    Cadena palabraDicc;
    struct str_dicc * hizq;
    struct str_dicc * hder;
};
typedef struct str_dicc * Diccionario;


// CONSTRUCTORAS

//Pre: Na.
//Pos: Devuelve un diccionario vacío
Diccionario crearDiccVacio();

//Pre: Na.
//Pos: Agrega palabra al diccionario
void agregarPalabraDicc(Diccionario &d, Cadena palabra);


// PREDICADO

//Pre: Na.
//Pos: Devuelve true si el diccionario está vacío, false en caso contrario
bool isEmptyDicc(Diccionario d);

//Pre: El diccionario no es vacío
//Pos: Devuelve true si d es hoja
bool esHoja(Diccionario d);

//Pre: El diccionario no puede ser vacío
//Pos: Devuelve la palabra que contiene el primer elemento del diccionario d
Cadena raiz(Diccionario d);

//Pre: El diccionario no puede ser vacío
//Pos: Devuelve el subdiccionario izquierdo del diccionario d
Diccionario subDiccIzq(Diccionario d);

//Pre: El diccionario no puede ser vacío
//Pos: Devuelve el subdiccionario derecho del diccionario d
Diccionario subDiccDer(Diccionario d);

//Pre: Na.
//Pos: Imprime el diccionario en orden
void imprimirDicc(Diccionario d);
//Pre: Na.
//Pos: Imprime el texto t, sin las palabras que contenga el diccionario d
void imprimirErroresTexto(Texto t, Diccionario d);
//Pre: Na.
//Pos: Devuelve true si palabra pertenece a d, false en caso contrario.
bool buscarPalabraDicc(Diccionario d, Cadena palabra);
// DESTRUCTORAS

//Pre: El diccionario no está vacío
//Pos: Borra palabra del diccionario d
void borrarPalabraDicc(Diccionario &d, Cadena palabra);

#endif