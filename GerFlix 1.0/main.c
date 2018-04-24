#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

void mostrarUsuariosConSeries(eUsuario[], int, eSerie[], int);
void mostrarSeriesConUsuarios(eSerie[], int, eUsuario[], int);

int main()
{
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];
    inicializarSeriesEstado(listaDeSeries, TAMSERIE);

    inicializarSeriesHardCode(listaDeSeries);
    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    /*

    1. Mostrar el listado de series
    2. Mostrar el listado de usuarios
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.



    */


printf("\n1. Mostrar el listado de series\n");
mostrarListaSeries(listaDeSeries, TAMSERIE);
printf("\n\n2. Mostrar el listado de usuarios\n");
mostrarListaUsuarios(listaDeUsuarios, TAMUSUARIO);
printf("\n\n3. Mostrar el listado de Usuarios con el nombre de la serie que ve\n");
mostrarUsuariosConSeries(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
printf("\n\n4. Mostrar por cada serie, el nombre de los usuarios que la ven\n");
mostrarSeriesConUsuarios(listaDeSeries, TAMSERIE, listaDeUsuarios, TAMUSUARIO);
printf("\n");

    return 0;
}

void mostrarUsuariosConSeries(eUsuario listaUsuarios[], int cantidadUsuarios, eSerie listaSeries[], int cantidadSeries)
{
    int i;
    int j;
    int imprimioUsuarios = 0;
    int halloSerie = 0;

    printf("\n---------------------------------------------------------------------\n");
    printf("|   ID|NOMBRE                        |SERIE                         |\n");
    printf("|-----|------------------------------|------------------------------|");

    for(i = 0; i < cantidadUsuarios; i++)
    {
        if(listaUsuarios[i].estado == 1)
        {
            imprimioUsuarios = 1;
            halloSerie = 0;
            printf("\n");
            printf("|%5d|", listaUsuarios[i].idUsuario);
            printf("%-30s|", listaUsuarios[i].nombre);

            for(j = 0; j < cantidadSeries; j++)
            {
                if(listaSeries[j].estado == 1 && listaUsuarios[i].idSerie == listaSeries[j].idSerie)
                {
                    halloSerie = 1;
                    printf("%-30s|", listaSeries[j].nombre);
                    break;
                }
            }

            if(halloSerie == 0)
            {
                printf("                              |");
            }
        }
    }
    if(imprimioUsuarios == 0)
    {
        printf("\nNO HAY USUARIOS INGRESADOS");
    }
    printf("\n---------------------------------------------------------------------\n");
}

void mostrarSeriesConUsuarios(eSerie listaSeries[], int cantidadSeries, eUsuario listaUsuarios[], int cantidadUsuarios)
{
    int i;
    int j;
    int imprimioSeries = 0;
    int halloUsuarios = 0;

    printf("\n------------------------------------------\n");
    printf("|   ID|SERIE                             |\n");
    printf("|     |    USUARIO                       |\n");
    printf("|-----|----------------------------------|");

    for(i = 0; i < cantidadSeries; i++)
    {
        if(listaSeries[i].estado == 1)
        {
            imprimioSeries = 1;
            halloUsuarios = 0;
            printf("\n");
            printf("|%5d|", listaSeries[i].idSerie);
            printf("%-30s    |", listaSeries[i].nombre);

            for(j = 0; j < cantidadUsuarios; j++)
            {
                if(listaUsuarios[j].estado == 1 && listaUsuarios[j].idSerie == listaSeries[i].idSerie)
                {
                    printf("\n");
                    halloUsuarios = 1;
                    printf("|     |    %-30s|", listaUsuarios[j].nombre);
                }
            }

            if(halloUsuarios == 0)
            {
                printf("\n|     |     ** NO HAY USUARIOS VIENDO ** |");
            }
        }
    }
    if(imprimioSeries == 0)
    {
        printf("\nNO HAY SERIES INGRESADAS");
    }
    printf("\n------------------------------------------\n");
}
