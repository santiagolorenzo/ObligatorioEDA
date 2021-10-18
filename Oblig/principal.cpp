#include "menu.h"
#include <stdio.h>
#include <string.h>
int main(){
  int opcion = 0;
  Texto t=crearTextoVacio();
  TipoRetorno texto;
  while(opcion != -1){
    desplegarMenu();
    int posicionLinea, posicionPalabra;
    Cadena palabra;
    scanf("%d", &opcion);
    printf("\n");
    if(opcion != -1)
    switch(opcion){
      case 1:
        // Insertar una nueva línea                    
        texto = InsertarLinea(t);
        verificacion(texto);
        break;
      case 2:
        // Insertar nueva líena en una posición dada
        printf("Ingrese la posicion en la que agregar la nueva linea: ");
        scanf("%d", &posicionLinea);
        texto = InsertarLineaEnPosicion(t, posicionLinea);
        verificacion(texto);
        break;
      case 3:
        // Borrar una línea en una posición dada
        printf("Ingrese la posicion que quiere borrar: ");
        scanf("%d", &posicionLinea);
        texto = BorrarLinea(t, posicionLinea);
        verificacion(texto);
        break;
      case 4:
        // Borrar todas las lineas del texto
        texto = BorrarTodo(t);
        verificacion(texto);
        break;          
      case 5:
        // Borrar una palabra del texto
        printf("Ingrese la palabra a borrar: ");
        scanf("%s", palabra);
        texto = BorrarOcurrenciasPalabraEnTexto(t, palabra);
        verificacion(texto);
        break;
      case 6:
        // Imprimir el texto
        texto = ImprimirTexto(t);
        verificacion(texto);
        break;
      case 7:
        // Comprimir el texto
        texto = ComprimirTexto(t);
        verificacion(texto);
        texto = ImprimirTexto(t);
        break;        
      case 8: 
        // Insertar una palabra en una línea
        printf("Ingrese la palabra a agregar: ");
        scanf("%s", palabra);
        printf("Ingrese la linea en la que se agregara: ");
        scanf("%d", &posicionLinea);
        printf("Ingrese la posicion de palabra en la que se agregara: ");
        scanf("%d", &posicionPalabra);
        texto = InsertarPalabra(t, posicionLinea, posicionPalabra, palabra);
         verificacion(texto);
        break;
      case 9:
        // Borrar palabra en posición dada
        printf("Ingrese la linea en la que se borrara: ");
        scanf("%d", &posicionLinea);
        printf("Ingrese la posicion de la palabra a borrar: ");
        scanf("%d", &posicionPalabra);
        texto = BorrarPalabra(t, posicionLinea, posicionPalabra);
        verificacion(texto);
        break;
      case 10:
        //Borrar ocurrencias de palabra de una línea dada
        printf("Ingrese la palabra a borrar: ");
        scanf("%s", palabra);
        printf("Ingrese la linea en la que se borrara: ");
        scanf("%d", &posicionLinea);
        texto = BorrarOcurrenciasPalabraEnLinea(t, posicionLinea, palabra);  
        verificacion(texto);
        break;
      case 11:
        // Imprimir línea dada
        printf("Ingrese la linea a imprimir: ");
        scanf("%d", &posicionLinea);
        texto = ImprimirLinea(t, posicionLinea);
        verificacion(texto);
        break;
      default:
        printf("Error de opcion, ingrese una opcion valida: ");
        scanf("%d", &opcion);
      break;
    }
  }
}
  /*
  	Texto t;
    TipoRetorno tr = CrearTexto(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    tr = InsertarLinea(t);
    printf("la cantidad de lineas es %d\n", cantLineas(t));
    printf("la cantidad de palabras es %d\n", cantPalabras(t, 1));
    Cadena x, y;
    int p, h;
    printf("Ingresa una palabra: ");
    scanf("%s", x);
    printf("Ingresa la posicion: ");
    scanf("%d", &p);
    tr= InsertarPalabra(t, 1, p, x);
    verificacion(tr); 
    tr= InsertarPalabra(t, 1, p+1, x);
    verificacion(tr);    
    tr= InsertarPalabra(t, 1, 3, x);
    verificacion(tr);  
    tr= InsertarPalabra(t, 1, 3, x);
    verificacion(tr);

    // Agregar palabras en segunda linea

    printf("Ingresa una nueva palabra: ");
    scanf("%s", x);
    printf("Ingresa una nueva posicion: ");
    scanf("%d", &p);
    tr= InsertarPalabra(t, 2, p, x);
    tr= InsertarPalabra(t, 2, p+1, x);
    tr = ImprimirTexto(t);
    
    printf("\n\n");
    tr= ImprimirTexto(t);
    printf("la cantidad de lineas es %d\n", cantLineas(t));
    printf("la cantidad de palabras es %d\n", cantPalabras(t, 1));
    */
	
	
	/*
	
	Texto t;
    TipoRetorno tr = CrearTexto(t);
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
    scanf("%s", x);
    printf("Ingresa la posicion: ");
    scanf("%d", &p);
    tr= InsertarPalabra(t, 1, p, x);
    tr= InsertarPalabra(t, 1, p+1, x);
    verificacion(tr);    
    tr= InsertarPalabra(t, 4, 1, x);
    verificacion(tr);
    tr = ImprimirTexto(t);
    verificacion(tr);

    printf("Ingresa una nueva palabra: ");
    scanf("%s", x);
    tr= InsertarPalabra(t, 1, p+1, x);
    tr= InsertarPalabra(t, 1, p+1, x);
    tr = ImprimirTexto(t);
    printf("Ingresa una palabra a borrar: ");    
    scanf("%s", y);
    //printf("%s\n", y);
    //tr = BorrarOcurrenciasPalabraEnLinea(t, 1, y);
    tr = BorrarOcurrenciasPalabraEnTexto(t, y);
    verificacion(tr);
    tr = ImprimirTexto(t);
    verificacion(tr);


    tr = ImprimirLinea(t, 1);
	
	
    tr = ComprimirTexto(t);
    verificacion(tr);

    printf("TEXTO COMPRIMIDO: \n");
    tr = ImprimirTexto(t);
	

    //tr = BorrarLinea(t, 2);
	//verificacion(tr);
    //tr = ImprimirTexto(t);
	/*
	tr= InsertarPalabra(t, 1, 3, x);
    verificacion(tr);  
    tr= InsertarPalabra(t, 1, 3, x);
    verificacion(tr);
    tr = ImprimirTexto(t);
    verificacion(tr);

		Agregar palabras en segunda linea

    printf("Ingresa una nueva palabra: ");
    scanf("%s", x);
    printf("Ingresa una nueva posicion: ");
    scanf("%d", &p);
    tr= InsertarPalabra(t, 2, p, x);
    tr= InsertarPalabra(t, 2, p+1, x);
    tr = ImprimirTexto(t);
    
    printf("\n\n");
    tr= ImprimirTexto(t);
    printf("la cantidad de lineas es %d\n", cantLineas(t));
    printf("la cantidad de palabras es %d\n", cantPalabras(t, 1));
	
	*/