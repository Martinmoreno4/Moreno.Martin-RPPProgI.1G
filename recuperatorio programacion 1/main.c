#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct{
    int id;
    char procesador[50];
    char marca[50];
    float precio;
}Notebook;

/*1. Crear una función llamada calcularIVA que reciba como parámetro el
    precio bruto de un producto y devuelva el valor del impuesto (el IVA es 21%).
    Realizar la llamada desde main. */

float calcularIVA(float precioBruto);

/*2. Crear una función que se llame reemplazarCaracter que reciba una cadena de
    caracteres como primer parámetro, como segundo parámetro el carácter a
    reemplazar y como tercero el nuevo carácter y devuelva la cantidad de veces
    que se reemplazo el carácter. int reemplazarCaracter(char [], char, char); *
*/
int reemplazarCaracter(char cadena[], char caracterR, char caracterN);

/*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función
    que permita ordenar un array de dicha estructura por marca. Ante igualdad de marca
    deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
*/
void ordenarPorMarcaYPrecio(Notebook array[], int tam);




int main()
{


    Notebook array[TAM]=
    {
        {1,"pentium","pcero",5000.0},
        {1,"kentium","pcero",6000.0},
        {1,"hp","pcUno",4000.0},
        {1,"hb","pcDos",5030.0},
        {1,"hnose","pcUno",7000.0},
    };

    char palabra[10]="diegoooooo";

    int cantidadDeLetrasCambiadas=0;

    cantidadDeLetrasCambiadas=reemplazarCaracter(palabra,'o','a');

    printf("la cantidad de letras cambias fue %d\n",cantidadDeLetrasCambiadas);

    ordenarPorMarcaYPrecio(array, TAM);
    float precioAux=35;
    float valorIva=0;
    valorIva=calcularIVA(precioAux);

    printf("el valor del impuesto es %f\n",valorIva);


    return 0;
}


float calcularIVA(float precioBruto)
{
    float rta=0;
    rta = (precioBruto*.21);
    return rta;
}

int reemplazarCaracter(char cadena[], char caracterR, char caracterN)
{
    int rta=0;
    int tam=strlen(cadena);
    for(int i=0; i<tam; i++)
    {
        if(cadena[i]==caracterR)
        {
            cadena[i]=caracterN;
            rta++;
        }
    }
    return rta;
}

void ordenarPorMarcaYPrecio(Notebook array[], int tam)
{
    Notebook aux;
    for(int i=0; i < tam-1; i++)
    {
        for(int j=i+1; j < tam; j++)
        {
            if(strcmp(array[j].marca,array[i].marca)>0)
            {
                aux = array[i];
                array[i]=array[j];
                array[j]=aux;
            }
            else if(strcmp(array[j].marca,array[i].marca)==0)
            {
                if(array[i].precio>array[j].precio)
                {
                    aux = array[i];
                    array[i]=array[j];
                    array[j]=aux;
                }
            }
        }
    }
}
