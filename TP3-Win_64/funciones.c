#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void pedirCadena(char mensaje[], char cadena[],int tam)
{
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validarTamCadena(mensaje,cadena,tam);
}

void validarTamCadena(char mensajeError[], char cadena[], int tam)
{
    while(strlen(cadena)>tam)
    {
        printf("Reingrese %s", mensajeError);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}

void primerLetraMayuscula(char palabra[])
{
    int i=0;

    strlwr(palabra);
    palabra[0]=toupper(palabra[0]);

    for(i=0; i<strlen(palabra); i++)
    {
        if(palabra[i]==' ')
        {
            palabra[i+1]=toupper(palabra[i+1]);
        }
    }
}


void pedirFlotante(char mensaje[],float flotante)
{
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%f", &flotante);
    //validarFlotante(mensaje,flotante);
}

int pedirEntero(char mensaje[], int menorValor, int mayorValor)
{
int entero;

printf("Ingrese%s",mensaje);
scanf("%d",&entero);
while(entero>mayorValor||entero<menorValor)
    {
        printf("Error. Reingrese%s",mensaje);
        scanf("%d",&entero);
    }
return entero;
}


/*void validarEntero(char mensaje[],int entero)
{

    while(auxiliar==0)
    {
        printf("Reingrese %s", mensaje);
        fflush(stdin);
        scanf("%d", &entero);
    }

}*/


/*void validarFlotante(char mensaje[],float flotante)
{
    int auxiliar;

    printf("%f",flotante);

    while(!(auxiliar==1))
    {
        printf("Reingrese %s", mensaje);
        fflush(stdin);
        scanf("%f", &flotante);
    }

}*/
