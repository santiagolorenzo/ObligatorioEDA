#include "menu.h"
#include <stdio.h>
#include <string.h>
int main(){
  int opcion = 0;
  Texto t=crearTextoVacio();
  UltPalabras ultPalabras = crearUltPalabras();
  Diccionario d = crearDiccVacio(); 
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
        agregarUltPalabra(ultPalabras, palabra);
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
      case 12:
        // Agregar palabra a diccionario
        printf("Ingrese la palabra a agregar: ");
        scanf("%s", palabra);
        texto = IngresarPalabraDiccionario(d, palabra);
        verificacion(texto);
        break; 
      case 13:
        // Borrar palabra del diccionario
        printf("Ingrese la palabra a borrar: ");
        scanf("%s", palabra);
        texto = BorrarPalabraDiccionario(d, palabra);
        verificacion(texto);
        break; 
      case 14:
        // Imprimir diccionario
        texto = ImprimirDiccionario(d);
        verificacion(texto);
        break; 
      case 15:
        // Imprimir errores del texto
        texto = ImprimirTextoIncorrecto(t, d);
        verificacion(texto);
        break;
      case 16:
        // Imprimir ultimas palabras
        texto = ImprimirUltimasPalabras(ultPalabras);
        verificacion(texto);
        break;   
      default:
        printf("Error de opcion, ingrese una opcion valida: ");
        scanf("%d", &opcion);
      break;
    }
  }
}