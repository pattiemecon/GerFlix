#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UsuarioSerie.h"

void inicializarUsuarioSerieEstado(eUsuarioSerie usuarioSerie[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarioSerie[i].estado = 0;
    }
}

void inicializarUsuarioSerieHardCode(eUsuarioSerie usuarioSerie[])
{
    int idUsuario[15] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014};
    int idSerie[15] = {100,100,101,101,102,100,100,103,101,102,103,105,105,100,103};
    int i;

    for(i=0; i<15; i++)
    {
        usuarioSerie[i].idUsuario=idUsuario[i];
        usuarioSerie[i].idSerie=idSerie[i];
        usuarioSerie[i].estado = 1;
    }
}

int buscarPosicionLibreUsuarioSerie(eUsuarioSerie listaUsuarioSerie[], int cantidadElementos)
{
    int posicionLibre = -1;
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaUsuarioSerie[i].estado == 0)
        {
            posicionLibre = i;
            break;
        }
    }

    return posicionLibre;
}

eUsuarioSerie ingresarNuevoUsuarioSerie(int idUsuario, int idSerie)
{
    eUsuarioSerie retorno;

    retorno.idUsuario = idUsuario;
    retorno.idSerie = idSerie;
    retorno.estado = 1;

    return retorno;
}

void mostrarUsuariosConSeries(eUsuarioSerie listaUsuarioSerie[], int cantidadUsuarioSerie)
{
    int i;
    int j;
    int imprimioUsuarioSerie = 0;
    int halloSerie = 0;

    printf("\n");
    imprimirDivisorUsuarios('-', 1, 1);
    imprimirDivisorSeries('-', 0, 1, 0, 0);
    printf("\n");
    imprimirEncabezadoUsuarios('|', 1, 1);
    imprimirEncabezadoSeries(' ', 0, 1, 0, 0);
    printf("|");
    printf("\n");
    imprimirDivisorUsuarios('|', 1, 1);
    imprimirDivisorSeries('-', 0, 1, 0, 0);

    for(i = 0; i < cantidadUsuarioSerie; i++)
    {
        if(listaUsuarioSerie[i].estado == 1)
        {
            imprimioUsuarioSerie = 1;
            halloSerie = 0;
            printf("\n");
            imprimirDetalleUsuarios('|', listaUsuarioSerie[i], 1, 1);

            for(j = 0; j < cantidadSeries; j++)
            {
                if(listaSeries[j].estado == 1 && listaUsuarios[i].idSerie == listaSeries[j].idSerie)
                {
                    halloSerie = 1;
                    imprimirDetalleSeries(' ', listaSeries[j], 0, 1, 0, 0);
                    printf("|");
                    break;
                }
            }

            if(halloSerie == 0)
            {
                printf("                                |");
            }
        }
    }
    if(imprimioUsuarios == 0)
    {
        printf("\nNO HAY USUARIOS INGRESADOS");
    }
    printf("\n");
    imprimirDivisorUsuarios('-', 1, 1);
    imprimirDivisorSeries('-', 0, 1, 0, 0);
}

void mostrarSeriesConUsuarios(eUsuarioSerie listaUsuarioSerie[], int cantidadUsuarioSerie)
{
    int i;
    int j;
    int imprimioSeries = 0;
    int halloUsuarios = 0;

    printf("\n");
    imprimirDivisorSeries('-', 1, 1, 0, 0);
    printf("\n");
    imprimirEncabezadoSeries('|', 1, 1, 0, 0);
    printf("\n");
    printf("%-6s", "|");
    printf("%-5s", "|");
    imprimirEncabezadoUsuarios(' ', 0, 1);
    printf("\b\b\b\b\b\b|");
    printf("\n");
    imprimirDivisorSeries('|', 1, 1, 0, 0);

    for(i = 0; i < cantidadUsuarioSerie; i++)
    {
        if(listaUsuarioSerie[i].estado == 1)
        {
            imprimioSeries = 1;
            halloUsuarios = 0;
            printf("\n");
            imprimirDetalleSeries('|', listaSeries[i], 1, 1, 0, 0);

            for(j = 0; j < cantidadUsuarios; j++)
            {
                if(listaUsuarios[j].estado == 1 && listaUsuarios[j].idSerie == listaSeries[i].idSerie)
                {
                    printf("\n");
                    halloUsuarios = 1;
                    printf("%-6s", "|");
                    printf("%-5s", "|");
                    imprimirDetalleUsuarios(' ', listaUsuarios[j], 0, 1);
                    printf("\b\b\b\b\b\b|");
                }
            }

            if(halloUsuarios == 0)
            {
                printf("\n");
                printf("%-6s", "|");
                printf("%-5s", "|");
                printf("** SIN USUARIOS **        |");
            }
        }
    }
    if(imprimioSeries == 0)
    {
        printf("\nNO HAY SERIES INGRESADAS");
    }
    printf("\n");
    imprimirDivisorSeries('-', 1, 1, 0, 0);
}
