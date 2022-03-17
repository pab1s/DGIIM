#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int i, j;
    double t1, total;

    if (argc < 2) {
        fprintf(stderr, "Falta tamaño de la matriz (debe de ser cuadrada)\n");
        exit(-1);
    }

    // Tamaño de la matriz pasado por parámetro
    unsigned int tam = atoi(argv[1]);

    if (tam < 2) {
        fprintf(stderr, "El tamaño no puede ser menor a 2");
        exit(-1);
    }

    // Declaramos con memoria dinámica
    double *v1, *v2, **M;

    v1 = (double *)malloc(tam * sizeof(double));
    v2 = (double *)malloc(tam * sizeof(double));
    M = (double **)malloc(tam * sizeof(double *));

// Reservamos memoria ahora para las componentes de la matriz e inicializamos
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (i = 0; i < tam; i++)
                M[i] = (double *)malloc(tam * sizeof(double));

            srand48(time(NULL));

            for (i = 0; i < tam; i++) {
                v1[i] = drand48();
                v2[i] = 0;
            }

            for (i = 0; i < tam; i++) {
                for (j = 0; j < tam; j++) {
                    if (j <= i)
                        M[i][j] = drand48();
                    else
                        M[i][j] = 0;
                }
            }
        }

        // Inicializamos la primera variable de tiempo
        #pragma omp single
        t1 = omp_get_wtime();
        
        // Calculamos el producto
        #pragma omp parallel for private(j) schedule(runtime) // Para paralelizar el for de dentro
        for (i = 0; i < tam; i++) {
            for (j = 0; j <= i; j++) {
                v2[i] += M[i][j] * v1[j];
            }
        }
        
        // Obtenemos el tiempo total transcurrido
        #pragma omp single
        total = omp_get_wtime() - t1;

    }

    // Para tamaños pequeños (hasta tam=11), imprimimos todas las componentes del vector resultante
    // y el tiempo de ejecución
    if (tam <= 11) {
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n", tam, total);

        for (i = 0; i < tam; i++) {
            printf("v2[%i] = %f\n", i, v2[i]);
        }
    }

    // Para tamaños superiores, imprimimos el tiempo de ejecución y la primera y última componente del vector
    else {
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n Primera componente: %f\n Última componente: %f\n", tam, total, v2[0], v2[tam - 1]);
    }

    // Liberamos memoria
    free(v1);
    free(v2);

    for (i = 0; i < tam; i++) {
        free(M[i]);
    }

    free(M);

    return 0;
}
