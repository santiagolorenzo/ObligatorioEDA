#include "oblig.h"
#include <stdio.h>

/*
void verificacion(TipoRetorno r){
    if(r == OK){
        printf("OK\n");
    }else{
        printf("ERROR\n");
    }
}

*/

int main(){
    //Texto t;
    //TipoRetorno tr = CrearTexto(t); // un texto vacio
    //-------------------------
    
    // Llamar al menú principal
    int opcion = 0;
    while(opcion != -1){
        opcion = menu();
    

        TipoRetorno tr;
        Texto t;

        if (opcion != 0){
            switch (opcion)
            {
            case 1:
                // Crear texto vacío
                tr = CrearTexto(t); // un texto vacio
                verificacion(tr);
                break;
            case 2:
                // Insertar una nueva línea
                tr = InsertarLinea(t);
                verificacion(tr);
                break;

            case 3:
                // Insertar nueva líena en una posición dada
                break;
            case 4:
                // Borrar una línea en una posición dada
                break;
            case 5:
                // Borrar todas las lineas del texto
                break;
            case 6:
                // Borrar una palabra del texto
                break;
            case 7:
                // Imprimir el texto
                break;
            case 8: 
                // Comprimir el texto
                break;
            case 9:
                // Insertar una palabra en una línea
                break;
            case 10:
                // Borrar palabra en posición dada
                break;
            case 11:
                //Borrar una palabra de una línea dada
                break;
            case 12:
                // Imprimir línea dada
                break;

            default:
                break;
            }
        }
    }

	/*

     tr = InsertarLinea(t);
    verificacion(tr);
    tr = InsertarLinea(t);
    verificacion(tr);
    tr = InsertarLinea(t);
    verificacion(tr);
    tr = InsertarLinea(t);
    verificacion(tr);
    tr = InsertarLinea(t);
    verificacion(tr);
    tr = InsertarLineaEnPosicion(t, 10);
    verificacion(tr);
    tr = BorrarLinea(t, 0);
    verificacion(tr);
    tr = ImprimirTexto(t);
    verificacion(tr);
    //tr = BorrarTodo(t);
    //verificacion(tr);
    printf("la cantidad de lineas es %d\n", cantLineas(t));
    printf("la cantidad de palabras es %d\n", cantPalabras(t, 1));
	
	*/
	
}
