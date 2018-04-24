#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

/*
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
*/

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
     int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]={"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,105,105,100,103};



    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void mostrarListaUsuarios(eUsuario listaUsuarios[], int cantidadUsuarios)
{
    int i;
    int imprimioUsuarios = 0;

    printf("\n----------------------------------------------------------\n");
    printf("|   ID|NOMBRE                                            |\n");
    printf("|-----|--------------------------------------------------|");

    for(i = 0; i < cantidadUsuarios; i++)
    {
        if(listaUsuarios[i].estado == 1)
        {
            imprimioUsuarios = 1;
            printf("\n");
            printf("|%5d|", listaUsuarios[i].idUsuario);
            printf("%-50s|", listaUsuarios[i].nombre);
        }
    }
    if(imprimioUsuarios == 0)
    {
        printf("\nNO HAY USUARIOS INGRESADOS");
    }
    printf("\n----------------------------------------------------------\n");
}
