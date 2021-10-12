#include "oblig.h"
#include "palabra.h"
TipoRetorno CrearTexto(Texto &a){
    a = crearTextoVacio();
    return OK;
}
//                                                                                  1°
TipoRetorno InsertarLinea(Texto &a){
    crearLinea(a);
    return OK;
}
//                                                                                  2°
TipoRetorno InsertarLineaEnPosicion(Texto &a, Posicion posicionLinea){
    if(posicionLinea== 0 || posicionLinea>(cantLineas(a)+1)){
        return ERROR;
    }else if(posicionLinea<= cantLineas(a)){
        crearLineaPosicion(a, posicionLinea);
        return OK;
    }else{
        return ERROR;
    }
}
//                                                                                  3°
TipoRetorno BorrarLinea(Texto &a, Posicion posicionLinea){
    if(posicionLinea>cantLineas(a) || posicionLinea == 0){
        return ERROR;
    }else{
        borrarLineaPosicion(a, posicionLinea);
        return OK;
    }

}
//                                                                                  4°
TipoRetorno BorrarTodo(Texto &a){
    if(isEmpty(a)){
        return OK;
    }else{
        borrarTodo(a);
        return BorrarTodo(a);
    }
}
//                                                                                  5°
TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar){
        borrarOcurrenciasPalabraEnTexto(a, palabraABorrar);
        return OK;
}

//                                                                                  6°
TipoRetorno ImprimirTexto(Texto a){                                         
    imprimirTexto(a);
    return OK;
}
//                                                                                  8°
TipoRetorno InsertarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
    if(a!=NULL){
        if(posicionLinea>cantLineas(a) || posicionLinea==0){ 
            //Error por cantidad de lineas
            return ERROR;
        }else if(posicionPalabra==0 || posicionPalabra>(1+cantPalabras(a, posicionLinea))){ 
            //Error por cantidad de palabras
            return ERROR;
        }else{
            //Caso ok.
            crearPalabraPosicion(a, posicionLinea, posicionPalabra, palabraAIngresar);
            return OK;
        }
    }else{
        return ERROR;
    }
}

//                                                                                    10°
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar){            /// Probar cuando tenga palabras agregadas
    if (posicionLinea>= 0 && posicionLinea <= cantLineas(a)+1){
        borrarOcurrenciasPalabraEnLinea(a, posicionLinea, palabraABorrar);
        return OK;
    }else{
        return ERROR;
    }
}


/*

TipoRetorno BorrarOcurrenciasPalabraEnTexto(Texto a, Cadena palabraABorrar);
TipoRetorno ComprimirTexto(Texto &a);

TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra);
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar);
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea);
*/



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


