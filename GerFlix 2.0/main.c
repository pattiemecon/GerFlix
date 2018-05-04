#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include "Usuario.h"
#include "UsuarioSerie.h"
#define TAMSERIE 20
#define TAMUSUARIO 100
#define TAMUSUARIO_SERIE 30

int main()
{
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];
    eUsuarioSerie listaDeUsuarioSerie[TAMUSUARIO_SERIE];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    inicializarUsuarioSerieEstado(listaDeUsuarioSerie,TAMUSUARIO_SERIE);
    inicializarUsuarioSerieHardCode(listaDeUsuarioSerie);

    int opcion;
    int posicionDeIngreso;
    int nuevoId;
//    int serieExistente;

    do
    {
        printf("\n1. Mostrar el listado de series");
        printf("\n2. Mostrar el listado de usuarios");
        printf("\n3. Mostrar por cada usuario, el nombre de las series que ve");
        printf("\n4. Mostrar por cada serie, el nombre de los usuarios que la ven");
        printf("\n5. ABM Usuario");
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
            //mostrarUsuariosConSeries(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
            break;
        case 4:
            //mostrarSeriesConUsuarios(listaDeSeries, TAMSERIE, listaDeUsuarios, TAMUSUARIO);
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
