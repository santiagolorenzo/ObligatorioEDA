#include "oblig.h"

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

//                                                                                  7°
TipoRetorno ComprimirTexto(Texto &a){
    comprimirTexto(a);
    return OK;
}


//                                                                                  8°
TipoRetorno InsertarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
    if(a!=NULL){
        if(posicionLinea>cantLineas(a) || posicionLinea==0){ 
            //Error por cantidad de lineas
            return ERROR;
        }else if(posicionPalabra==0 || posicionPalabra>(1+cantPalabras(a, posicionLinea)) || posicionPalabra>MAX_CANT_PALABRAS_X_LINEA){ 
            //Error por cantidad de palabras
            return ERROR;
        }else{
            //Caso ok.
            crearPalabraPosicion(a, posicionLinea, posicionPalabra, palabraAIngresar);
            verificarTamano(a);
            return OK;
        }
    }else{
        return ERROR;
    }
}
//                                                                                  9°
TipoRetorno BorrarPalabra(Texto a, Posicion posicionLinea, Posicion posicionPalabra){
    if(a!=NULL){
        if(posicionLinea>cantLineas(a) || posicionLinea==0){ 
            //Error por cantidad de lineas
            return ERROR;
        }else if(posicionPalabra==0 || posicionPalabra>(1+cantPalabras(a, posicionLinea))){ 
            //Error por cantidad de palabras
            return ERROR;
        }else{
            //Caso ok.
            borrarPalabraPosicion(a, posicionLinea, posicionPalabra);
            return OK;
        }
    }else{
        return ERROR;
    }
}

//                                                                                    10°
TipoRetorno BorrarOcurrenciasPalabraEnLinea(Texto a, Posicion posicionLinea, Cadena palabraABorrar){           
    if (posicionLinea>= 0 && posicionLinea <= cantLineas(a)+1){
        borrarOcurrenciasPalabraEnLinea(a, posicionLinea, palabraABorrar);
        return OK;
    }else{
        return ERROR;
    }
}

//                                                                                    11°
TipoRetorno ImprimirLinea(Texto a, Posicion posicionLinea){
    if (posicionLinea>= 0 && posicionLinea <= cantLineas(a)+1){
        imprimirLineaPosicion(a, posicionLinea);
        return OK;
    }else{
        return ERROR;
    }
}

//                                                                                    12°
TipoRetorno IngresarPalabraDiccionario(Diccionario &d, Cadena palabraAIngresar){
    if(buscarPalabraDicc(d, palabraAIngresar)){
        return ERROR;
    }else{
        agregarPalabraDicc(d, palabraAIngresar);
        return OK;
    }
}
//                                                                                    13°
TipoRetorno BorrarPalabraDiccionario(Diccionario &d, Cadena palabraABorrar){
    if(buscarPalabraDicc(d, palabraABorrar)){
        borrarPalabraDicc(d, palabraABorrar);
        return OK;
    }else{
        return ERROR;
    }
    
}
//                                                                                    14°
TipoRetorno ImprimirDiccionario(Diccionario d){
    imprimirDicc(d);
    return OK;
}

//                                                                                    15°
TipoRetorno ImprimirTextoIncorrecto(Texto t, Diccionario d){
    imprimirErroresTexto(t, d);
    return OK;
}
//                                                                                     16°
TipoRetorno ImprimirUltimasPalabras(UltPalabras p){
    imprimirUltPalabras(p);
    return OK;
}