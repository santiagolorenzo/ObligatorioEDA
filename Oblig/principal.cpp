#include "oblig.h"
#include <stdio.h>
#include <string.h>
int main(){
    // Llamar al menú principal
	/*
    int opcion = 0;
    while(opcion != -1){
        opcion = menu();
    

        TipoRetorno tr;
        Texto t;
        int posicion;

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
                // Insertar nueva líena en una posición dada                                            // Revisar posición final al agregar
                printf("Ingrese la posición en la que agregar la nueva línea: ");
                scanf("%d", &posicion);
                tr = InsertarLineaEnPosicion(t, posicion);
                verificacion(tr);
                break;
            case 4:
                // Borrar una línea en una posición dada
                printf("Ingrese la posición que quiere borrar: ");
                scanf("%d", &posicion);
                tr = BorrarLinea(t, posicion);
                verificacion(tr);
                break;
            case 5:
                // Borrar todas las lineas del texto
                tr = BorrarTodo(t);
                verificacion(tr);
                break;
            case 6:
                // Borrar una palabra del texto

                break;
            case 7:
                // Imprimir el texto
                tr = ImprimirTexto(t);
                verificacion(tr);
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
                //Borrar ocurrencias de palabra de una línea dada

                Cadena x;
                printf("Ingrese la palabra a borrar: ");
                scanf("%s", x);
                tr = BorrarOcurrenciasPalabraEnLinea(t, 1, x);
                verificacion(tr);
                //printf("la palabra ingresada es %s", x);
                break;
            case 12:
                // Imprimir línea dada

                break;

            default:
                break;
            }
        }
    }
    */
	Texto t;
    TipoRetorno tr = CrearTexto(t); // un texto vacio
    //-------------------------
    
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
    printf("la cantidad de lineas es %d\n", cantLineas(t));
    printf("la cantidad de palabras es %d\n", cantPalabras(t, 1));
    Cadena x, y;
    int p, h;
    printf("Ingresa una palabra: ");
    gets(x);
    printf("Ingresa la posicion: ");
    scanf("%d", &p);
    tr= InsertarPalabra(t, 1, p, x);
    tr= InsertarPalabra(t, 1, p+1, x);
    verificacion(tr);    
    tr= InsertarPalabra(t, 4, 1, x);
    verificacion(tr);
    tr = ImprimirTexto(t);
    verificacion(tr);
    printf("Ingresa una palabra a borrar: ");    
    scanf("%s", y);
    printf("%s\n", y);
    //y = strcpy(x, y);
    tr = BorrarOcurrenciasPalabraEnLinea(t, 1, y);
    //tr = BorrarOcurrenciasPalabraEnTexto(t, y);
    verificacion(tr);
    tr = ImprimirTexto(t);
    verificacion(tr);

}
