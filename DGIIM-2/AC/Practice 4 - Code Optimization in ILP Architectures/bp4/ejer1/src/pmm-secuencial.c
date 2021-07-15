#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#endif

//Sólo puede estar definida una de las tres constantes VECTOR_ (sólo uno de los ...
//dos defines siguientes puede estar descomentado):
//#define VECTOR_GLOBAL // descomentar para que los vectores sean variables ...
// globales (su longitud no estará limitada por el ...
// tamaño de la pila del programa)
#define VECTOR_DYNAMIC  // descomentar para que los vectores sean variables ... \
                        // dinámicas (memoria reutilizable durante la ejecución)

#ifdef VECTOR_GLOBAL
#define MAX 1024  //=2^15
double M2[MAX][MAX], MF[MAX][MAX], M1[MAX][MAX];
#endif

int main(int argc, char **argv) {
    int i, j;
    double ncgt;
    struct timespec cgt1, cgt2;

    if (argc < 2) {
        printf("Falta tamaño de las matrices\n");
        exit(-1);
    }

    unsigned int N = atoi(argv[1]);

#ifdef VECTOR_GLOBAL
    if (N > MAX) N = MAX;
#endif

#ifdef VECTOR_DYNAMIC
    double **M2, **MF, **M1;
    M2 = (double **)malloc(N * sizeof(double *));
    MF = (double **)malloc(N * sizeof(double *));
    M1 = (double **)malloc(N * sizeof(double *));

    // Reservamos memoria ahora para las componentes de la matriz
    for (i = 0; i < N; i++) {
        M1[i] = (double *)malloc(N * sizeof(double));
        M2[i] = (double *)malloc(N * sizeof(double));
        MF[i] = (double *)malloc(N * sizeof(double));
    }
    if ((M2 == NULL) || (MF == NULL) || (M1 == NULL)) {
        printf("No hay suficiente espacio para los vectores \n");
        exit(-2);
    }
#endif

    // Inicializamos la matriz y los vectores
    srand48(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            M1[i][j] = drand48();
            M2[i][j] = drand48();
            MF[i][j] = 0;
        }
    }

    // Inicializamos la primera variable de tiempo
    clock_gettime(CLOCK_REALTIME,&cgt1);

    // Calculamos el producto
    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++)
            MF[i][j] += M1[i][j] * M2[j][i];

    clock_gettime(CLOCK_REALTIME,&cgt2);
    ncgt = (double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

    // Para tamaños pequeños (hasta N=10), imprimimos todas las componentes del vector resultante
    // y el tiempo de ejecución
    if (N <= 10) {
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n", N, ncgt);

        for (i = 0; i < N; i++) {
            for ( j = 0; j < N; j++) {
                printf("MF[%i][%i] = %f\n", i, j, MF[i][j]);
            }
        }
    }

    // Para tamaños superiores, imprimimos el tiempo de ejecución y la primera y última componente del vector
    else {
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n Primera componente: %f\n Última componente: %f\n", N, ncgt,
               MF[0][0], MF[N - 1][N - 1]);
    }

#ifdef VECTOR_DYNAMIC
    for (i = 0; i < N; i++) {
        free(M1[i]);
        free(M2[i]);
        free(MF[i]);
    }
    free(M1);
    free(M2);
    free(MF);
#endif

    return 0;
}
