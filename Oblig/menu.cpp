#include "oblig.h"
void verificacion(TipoRetorno r){
    if(r == OK){
        printf("\nOK\n");
    }else{
        printf("\nERROR\n");
    }
}


void desplegarMenu(){
    printf("\n\nPor favor digite una opcion de las siguientes\n");
    printf("1  - Insertar una nueva linea\n");
    printf("2  - Insertar nueva linea en una posicion dada\n");
    printf("3  - Borrar una linea en una posicion dada\n");
    printf("4  - Borrar todas las lineas del texto\n");
    printf("5  - Borrar una palabra del texto\n");
    printf("6  - Imprimir el texto\n");
    printf("7  - Comprimir el texto\n");
    printf("8  - Insertar una palabra en una linea\n");
    printf("9  - Borrar palabra en posicion dada\n");
    printf("10 - Borrar una palabra de una linea dada\n");
    printf("11 - Imprimir linea dada\n");
    printf("Para salir ingrese -1\n");
    printf("Ingrese una opcion: ");
}   
