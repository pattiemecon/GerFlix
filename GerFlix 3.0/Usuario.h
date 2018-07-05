
typedef struct
{
    int idUsuario;
    char nombre[50];
    int estado;
}eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarListaUsuarios(eUsuario[], int);
void imprimirDivisorUsuarios(char, int, int);
void imprimirEncabezadoUsuarios(char, int, int);
void imprimirDetalleUsuarios(char, eUsuario, int, int);
int buscarPosicionLibreUsuarios(eUsuario[], int);
int obtenerIdUsuarios(eUsuario[], int);
eUsuario ingresarNuevoUsuario(int);
int existeUsuario(eUsuario[], int, int);
