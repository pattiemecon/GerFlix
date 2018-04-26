
typedef struct
{
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
}eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);
void mostrarListaSeries(eSerie[], int);
void imprimirDivisorSeries(char, int, int, int, int);
void imprimirEncabezadoSeries(char, int, int, int, int);
void imprimirDetalleSeries(char, eSerie, int, int, int, int);
