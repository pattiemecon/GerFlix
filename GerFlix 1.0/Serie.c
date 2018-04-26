#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include <string.h>

/*
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;

*/

void inicializarSeriesEstado(eSerie series[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        series[i].estado = 0;
    }
}


void inicializarSeriesHardCode(eSerie series[])
{
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    int i;

    for(i=0; i<5; i++)
    {
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}

void mostrarListaSeries(eSerie listaSeries[], int cantidadSeries)
{
    int i;
    int imprimioSeries = 0;

    printf("\n");
    imprimirDivisorSeries('-', 1, 1, 1, 1);
    printf("\n");
    imprimirEncabezadoSeries('|', 1, 1, 1, 1);
    printf("\n");
    imprimirDivisorSeries('|', 1, 1, 1, 1);

    for(i = 0; i < cantidadSeries; i++)
    {
        if(listaSeries[i].estado == 1)
        {
            imprimioSeries = 1;
            printf("\n");
            imprimirDetalleSeries('|', listaSeries[i], 1, 1, 1, 1);
        }
    }
    if(imprimioSeries == 0)
    {
        printf("\nNO HAY SERIES INGRESADAS");
    }
    printf("\n");
    imprimirDivisorSeries('-', 1, 1, 1, 1);
}

void imprimirDivisorSeries(char separador, int imprimeId, int imprimeNombre, int imprimeGenero, int imprimeTemporadas)
{
    if(imprimeId == 1 || imprimeNombre == 1 || imprimeGenero == 1 || imprimeTemporadas == 1)
    {
        printf("%c", separador);
        if(imprimeId == 1)
        {
            printf("-----%c", separador);
        }
        if(imprimeNombre == 1)
        {
            printf("------------------------------%c", separador);
        }
        if(imprimeGenero == 1)
        {
            printf("--------------------%c", separador);
        }
        if(imprimeTemporadas == 1)
        {
            printf("----------%c", separador);
        }
    }
}

void imprimirEncabezadoSeries(char separador, int imprimeId, int imprimeNombre, int imprimeGenero, int imprimeTemporadas)
{
    if(imprimeId == 1 || imprimeNombre == 1 || imprimeGenero == 1 || imprimeTemporadas == 1)
    {
        printf("%c", separador);
        if(imprimeId == 1)
        {
            //printf("   ID%c", separador);
            printf("%5s%c", "ID", separador);
        }
        if(imprimeNombre == 1)
        {
            printf("%-30s%c", "SERIE", separador);
        }
        if(imprimeGenero == 1)
        {
            printf("%-20s%c", "GENERO", separador);
        }
        if(imprimeTemporadas == 1)
        {
            printf("%10s%c", "TEMPORADAS", separador);
        }
    }
}

void imprimirDetalleSeries(char separador, eSerie listaSeries, int imprimeId, int imprimeNombre, int imprimeGenero, int imprimeTemporadas)
{
    if(imprimeId == 1 || imprimeNombre == 1 || imprimeGenero == 1 || imprimeTemporadas == 1)
    {
        printf("%c", separador);
        if(imprimeId == 1)
        {
            printf("%5d%c", listaSeries.idSerie, separador);
        }
        if(imprimeNombre == 1)
        {
            printf("%-30s%c", listaSeries.nombre, separador);
        }
        if(imprimeGenero == 1)
        {
            printf("%-20s%c", listaSeries.genero, separador);
        }
        if(imprimeTemporadas == 1)
        {
            printf("%10d%c", listaSeries.cantidadTemporadas, separador);
        }
    }
}

int buscarPosicionLibreSeries(eSerie listaSeries[], int cantidadElementos)
{
    int posicionLibre = -1;
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaSeries[i].estado == 0)
        {
            posicionLibre = i;
            break;
        }
    }

    return posicionLibre;
}

int obtenerIdSeries(eSerie listaSeries[], int cantidadElementos)
{
    int nuevoId;
    int i;
    int maximo;
    int primerElemento = 1;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaSeries[i].estado != 0)
        {
            if(listaSeries[i].idSerie > maximo || primerElemento == 1)
            {
                maximo = listaSeries[i].idSerie;
                primerElemento = 0;
            }
        }
    }

    if(primerElemento == 0)
    {
        nuevoId = maximo + 1;
    }
    else
    {
        nuevoId = 1;
    }

    return nuevoId;
}

eSerie ingresarNuevaSerie(int id)
{
    eSerie retorno;

    retorno.idSerie = id;
    do
    {
        printf("\nIngrese nombre de la serie: ");
        fflush(stdin);
        gets(retorno.nombre);
        if(strcmp(retorno.nombre, "") == 0)
        {
            printf("\nDebe ingresar un nombre para la serie");
        }
    } while(strcmp(retorno.nombre, "") == 0);

    do
    {
        printf("\nIngrese genero de la serie: ");
        fflush(stdin);
        gets(retorno.genero);
        if(strcmp(retorno.genero, "") == 0)
        {
            printf("\nDebe ingresar un genero para la serie");
        }
    } while(strcmp(retorno.genero, "") == 0);

    do
    {
        printf("\nIngrese cantidad de temporadas de la serie: ");
        scanf("%d", &retorno.cantidadTemporadas);
        if(retorno.cantidadTemporadas < 1)
        {
            printf("\nDebe ingresar un numero positivo");
        }
    } while(retorno.cantidadTemporadas < 1);
    retorno.estado = 1;

    return retorno;
}

int existeSerie(eSerie listaSeries[], int elementoBuscado, int cantidadElementos)
{
    int existeElemento = 0;
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaSeries[i].idSerie == elementoBuscado)
        {
            existeElemento = 1;
            break;
        }
    }

    return existeElemento;
}
