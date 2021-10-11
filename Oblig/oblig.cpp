#include "oblig.h"
#include <stdio.h>

TipoRetorno CrearTexto(Texto &a){
    a = crearTextoVacio();
    return OK;
}
TipoRetorno InsertarLinea(Texto &a){
    crearLinea(a);
    return OK;
}
TipoRetorno ImprimirTexto(Texto a){
    imprimirLinea(a);
    return OK;
}
TipoRetorno InsertarLineaEnPosicion(Texto &a, Posicion posicionLinea){
    if(posicionLinea== 0){
        return ERROR;
    }else if(posicionLinea<= cantLineas(a)){
        crearLineaPosicion(a, posicionLinea);
        return OK;
    }else{
        return NO_IMPLEMENTADA;
    }
}
TipoRetorno BorrarLinea(Texto &a, Posicion posicionLinea){
    if(posicionLinea>cantLineas(a) || posicionLinea == 0){
        return ERROR;
    }else{
        borrarLineaPosicion(a, posicionLinea);
        return OK;
    }

}


void verificacion(TipoRetorno r){
    if(r == OK){
        printf("OK\n");
    }else{
        printf("ERROR\n");
    }
}


int menu(){
    int opcion = 0;
    
    printf("Por favor digite una opción de las siguientes\n");
    printf("1 - Crear un nuevo texto vacío\n");
    printf("2 - Insertar una nueva línea\n");
    printf("3 - Insertar nueva línea en una posición dada\n");
    printf("4 - Borrar una línea en una posición dada\n");
    printf("5 - Borrar todas las líneas del texto\n");
    printf("6 - Borrar una palabra del texto\n");
    printf("7 - Imprimir el texto\n");
    printf("8 - Comprimir el texto\n");
    printf("9 - Insertar una palabra en una línea\n");
    printf("10 - Borrar palabra en posición dada\n");
    printf("11 - Borrar una palabra de una línea dada\n");
    printf("12 - Imprimir línea dada\n");
    printf("Para salir ingrese -1\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    return opcion;
}   


/*


TipoRetorno BorrarTodo(Texto &a);
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);
TipoRetorno ImprimirTexto(Texto a);
TipoRetorno ComprimirTexto(Texto &a);

TipoRetorno InsertarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea);
*/
