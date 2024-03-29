#include <stdlib.h>
#include <stdio.h>

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
#define VECTOR_DYNAMIC	// descomentar para que los vectores sean variables ...
			// dinámicas (memoria reutilizable durante la ejecución)

#ifdef VECTOR_GLOBAL
  #define MAX 1024	//=2^15
  double v1[MAX], v2[MAX], M[MAX][MAX];
#endif

int main(int argc, char** argv) {
	int i, j;
	double t1, t2, t3;


	if (argc<2){
		printf("Falta tamaño de matriz y vector\n");
		exit(-1);
	}

	unsigned int N = atoi(argv[1]);

	#ifdef VECTOR_GLOBAL
		if (N>MAX) N=MAX;
	#endif

	#ifdef VECTOR_DYNAMIC
		double *v1, *v2, **M;
		v1 = (double *)malloc(N * sizeof(double));
		v2 = (double *)malloc(N * sizeof(double));
		M = (double **)malloc(N * sizeof(double *));

		// Reservamos memoria ahora para las componentes de la matriz
		for (i = 0; i < N; i++) {
			M[i] = (double *)malloc(N * sizeof(double));
		}
			if ((v1 == NULL) || (v2 == NULL) || (v2 == NULL)) {
				printf("No hay suficiente espacio para los vectores \n");
				exit(-2);
			}
	#endif

	// Inicializamos la matriz y los vectores
	for (i=0; i<N;i++){
		v1[i] = i;
		v2[i] = 0;
		for(j=0;j<N;j++)
			M[i][j] = i+j;
	}

	// Inicializamos la primera variable de tiempo
	t1 = omp_get_wtime();

	// Calculamos el producto
	for (i=0; i<N;i++)
		for(j=0;j<N;j++)
				v2[i] += M[i][j] * v1[j];


	t2 = omp_get_wtime();
	t3 = t2 - t1;

    // Para tamaños pequeños (hasta N=10), imprimimos todas las componentes del vector resultante
    // y el tiempo de ejecución
    if (N <= 10) {
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n", N, t3);

        for (i = 0; i < N; i++) {
            printf("v2[%i] = %f\n", i, v2[i]);
        }
    }

    // Para tamaños superiores, imprimimos el tiempo de ejecución y la primera y última componente del vector
    else {
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n Primera componente: %f\n Última componente: %f\n", N, t3,
               v2[0], v2[N - 1]);
    }

	#ifdef VECTOR_DYNAMIC
		free(v1);
		free(v2);
		for (i = 0; i < N; i++) {
			free(M[i]);
		}
		free(M);
	#endif

	return 0;
}
