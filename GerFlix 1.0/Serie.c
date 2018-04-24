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

    printf("\n------------------------------------------------------------------------------\n");
    printf("|   ID|NOMBRE                                |GENERO              |TEMPORADAS|\n");
    printf("|-----|--------------------------------------|--------------------|----------|");

    for(i = 0; i < cantidadSeries; i++)
    {
        if(listaSeries[i].estado == 1)
        {
            imprimioSeries = 1;
            printf("\n");
            printf("|%5d|", listaSeries[i].idSerie);
            printf("%-38s|", listaSeries[i].nombre);
            printf("%-20s|", listaSeries[i].genero);
            printf("%10d|", listaSeries[i].cantidadTemporadas);
        }
    }
    if(imprimioSeries == 0)
    {
        printf("\nNO HAY SERIES INGRESADAS");
    }
    printf("\n------------------------------------------------------------------------------\n");
}
