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

    int opcion;
    int posicionDeIngreso;
    int nuevoId;
    int serieExistente;

    do
    {
        printf("\n1. Mostrar el listado de series");
        printf("\n2. Mostrar el listado de usuarios");
        printf("\n3. Mostrar el listado de Usuarios con el nombre de la serie que ve");
        printf("\n4. Mostrar por cada serie, el nombre de los usuarios que la ven");
        printf("\n5. ABM Usuario (pide Serie para asociar)");
        printf("\n6. ABM Serie");
        printf("\n7. Salir");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            mostrarListaSeries(listaDeSeries, TAMSERIE);
            break;
        case 2:
            mostrarListaUsuarios(listaDeUsuarios, TAMUSUARIO);
            break;
        case 3:
            mostrarUsuariosConSeries(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
            break;
        case 4:
            mostrarSeriesConUsuarios(listaDeSeries, TAMSERIE, listaDeUsuarios, TAMUSUARIO);
            break;
        case 5:
            posicionDeIngreso = buscarPosicionLibreUsuarios(listaDeUsuarios, TAMUSUARIO);
            if(posicionDeIngreso == -1)
            {
                printf("\nNo hay espacio para ingresar un nuevo usuario");
            }
            else
            {
                nuevoId = obtenerIdUsuarios(listaDeUsuarios, TAMUSUARIO);
                listaDeUsuarios[posicionDeIngreso] = ingresarNuevoUsuario(nuevoId);
                do
                {
                    mostrarListaSeries(listaDeSeries, TAMSERIE);
                    printf("\nIngrese ID de la serie que ve el Usuario: ");
                    scanf("%d", &listaDeUsuarios[posicionDeIngreso].idSerie);
                    serieExistente = existeSerie(listaDeSeries, listaDeUsuarios[posicionDeIngreso].idSerie, TAMSERIE);
                    if(serieExistente == 0)
                    {
                        printf("\nEl ID ingresado no existe. Por favor vuelva a ingresar el dato");
                    }
                } while(serieExistente == 0);
            }
            break;
        case 6:
            posicionDeIngreso = buscarPosicionLibreSeries(listaDeSeries, TAMSERIE);
            if(posicionDeIngreso == -1)
            {
                printf("\nNo hay espacio para ingresar una nueva serie");
            }
            else
            {
                nuevoId = obtenerIdSeries(listaDeSeries, TAMSERIE);
                listaDeSeries[posicionDeIngreso] = ingresarNuevaSerie(nuevoId);
            }
            break;
        case 7:
            break;
        default:
            printf("\nDebe ingresar una opcion del 1 al 7");
            break;
        }

        if(opcion != 7)
        {
            printf("\n");
            system("pause");
            system("cls");
        }
    } while(opcion != 7);

    return 0;
}

void mostrarUsuariosConSeries(eUsuario listaUsuarios[], int cantidadUsuarios, eSerie listaSeries[], int cantidadSeries)
{
    int i;
    int j;
    int imprimioUsuarios = 0;
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

    for(i = 0; i < cantidadUsuarios; i++)
    {
        if(listaUsuarios[i].estado == 1)
        {
            imprimioUsuarios = 1;
            halloSerie = 0;
            printf("\n");
            imprimirDetalleUsuarios('|', listaUsuarios[i], 1, 1);

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

void mostrarSeriesConUsuarios(eSerie listaSeries[], int cantidadSeries, eUsuario listaUsuarios[], int cantidadUsuarios)
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

    for(i = 0; i < cantidadSeries; i++)
    {
        if(listaSeries[i].estado == 1)
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
