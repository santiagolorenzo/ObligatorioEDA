#ifndef PALABRA_H
#define PALABRA_H
typedef char * Cadena;
struct str_pal{
    Cadena palabra;
    struct str_pal * sig;
};
typedef struct str_pal * Palabra;

//      CONSTRUCTORAS

//Pre: na.
//Pos: Crea una palabra vacia.
Palabra crearPalabrasVacia();
//Pre: na.
//Pos: Agrega una Cadeba palabra, en la posicion x de la Palabra p.
void insertarPalabra(Palabra p, int x, Cadena palabra);

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

#endif // PALABRA_H
