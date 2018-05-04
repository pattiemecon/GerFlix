
typedef struct
{
    int idUsuario;
    int idSerie;
    int estado;
}eUsuarioSerie;

void inicializarUsuarioSerieEstado(eUsuarioSerie[], int);
void inicializarUsuarioSerieHardCode(eUsuarioSerie[]);
int buscarPosicionLibreUsuarioSerie(eUsuarioSerie[], int);
eUsuarioSerie ingresarNuevoUsuarioSerie(int, int);
void mostrarUsuariosConSeries(eUsuarioSerie[], int);
void mostrarSeriesConUsuarios(eUsuarioSerie[], int);
