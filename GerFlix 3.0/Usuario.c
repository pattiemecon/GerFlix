#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

/*
    int idUsuario;
    char nombre[50];
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
    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void mostrarListaUsuarios(eUsuario listaUsuarios[], int cantidadUsuarios)
{
    int i;
    int imprimioUsuarios = 0;

    printf("\n");
    imprimirDivisorUsuarios('-', 1, 1);
    printf("\n");
    imprimirEncabezadoUsuarios('|', 1, 1);
    printf("\n");
    imprimirDivisorUsuarios('|', 1, 1);

    for(i = 0; i < cantidadUsuarios; i++)
    {
        if(listaUsuarios[i].estado == 1)
        {
            imprimioUsuarios = 1;
            printf("\n");
            imprimirDetalleUsuarios('|', listaUsuarios[i], 1, 1);
        }
    }
    if(imprimioUsuarios == 0)
    {
        printf("\nNO HAY USUARIOS INGRESADOS");
    }
    printf("\n");
    imprimirDivisorUsuarios('-', 1, 1);
}

void imprimirDivisorUsuarios(char separador, int imprimeId, int imprimeNombre)
{
    if(imprimeId == 1 || imprimeNombre == 1)
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
    }
}

void imprimirEncabezadoUsuarios(char separador, int imprimeId, int imprimeNombre)
{
    if(imprimeId == 1 || imprimeNombre == 1)
    {
        printf("%c", separador);
        if(imprimeId == 1)
        {
            printf("%5s%c", "ID", separador);
        }
        if(imprimeNombre == 1)
        {
            printf("%-30s%c", "USUARIO", separador);
        }
    }
}

void imprimirDetalleUsuarios(char separador, eUsuario listaUsuarios, int imprimeId, int imprimeNombre)
{
    if(imprimeId == 1 || imprimeNombre == 1)
    {
        printf("%c", separador);
        if(imprimeId == 1)
        {
            printf("%5d%c", listaUsuarios.idUsuario, separador);
        }
        if(imprimeNombre == 1)
        {
            printf("%-30s%c", listaUsuarios.nombre, separador);
        }
    }
}

int buscarPosicionLibreUsuarios(eUsuario listaUsuarios[], int cantidadElementos)
{
    int posicionLibre = -1;
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaUsuarios[i].estado == 0)
        {
            posicionLibre = i;
            break;
        }
    }

    return posicionLibre;
}

int obtenerIdUsuarios(eUsuario listaUsuarios[], int cantidadElementos)
{
    int nuevoId;
    int i;
    int maximo;
    int primerElemento = 1;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaUsuarios[i].estado != 0)
        {
            if(listaUsuarios[i].idUsuario > maximo || primerElemento == 1)
            {
                maximo = listaUsuarios[i].idUsuario;
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

eUsuario ingresarNuevoUsuario(int id)
{
    eUsuario retorno;

    retorno.idUsuario = id;
    do
    {
        printf("\nIngrese nombre del usuario: ");
        fflush(stdin);
        gets(retorno.nombre);
        if(strcmp(retorno.nombre, "") == 0)
        {
            printf("\nDebe ingresar el nombre del usuario");
        }
    } while(strcmp(retorno.nombre, "") == 0);
    retorno.estado = 1;

    return retorno;
}

int existeUsuario(eUsuario listaUsuarios[], int elementoBuscado, int cantidadElementos)
{
    int existeElemento = 0;
    int i;

    for(i = 0; i < cantidadElementos; i++)
    {
        if(listaUsuarios[i].idUsuario == elementoBuscado)
        {
            existeElemento = 1;
            break;
        }
    }

    return existeElemento;
}
