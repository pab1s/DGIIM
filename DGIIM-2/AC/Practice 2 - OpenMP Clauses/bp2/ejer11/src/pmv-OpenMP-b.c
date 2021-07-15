#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv)  {
   int i, j;
   double t1, total;

   if(argc < 2){
      fprintf(stderr,"Falta tamaño de la matriz (debe de ser cuadrada)\n");
      exit(-1);
    }

    // Tamaño de la matriz pasado por parámetro
    unsigned int tam = atoi(argv[1]);

    if(tam < 2){
        fprintf(stderr, "El tamaño no puede ser menor a 2");
        exit(-1);
    }

    // Declaramos con memoria dinámica
    double *v1, *v2, **m;

    v1 = (double*) malloc(tam*sizeof(double));
    v2 = (double*) malloc(tam*sizeof(double));
    m = (double**) malloc(tam*sizeof(double*));


    // Reservamos memoria ahora para las componentes de la matriz
    #pragma omp parallel for
    for(i=0; i<tam; i++)
        m[i] = (double*) malloc(tam*sizeof(double));

#pragma omp parallel private(i)
{
    // Inicializamos la matriz y los vectores
    #pragma omp for
    for(i=0; i<tam; i++)
        v1[i] = 1;
        v2[i] = 0;

    #pragma omp for private(j) // Para paralelizar el for de dentro
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            m[i][j] = 2;
        }
    }

    // Inicializamos la primera variable de tiempo
    #pragma omp single
    {
        t1 = omp_get_wtime();
    }
    
    // Calculamos el producto
    for(i=0; i<tam; i++){
        double producto_local = 0;

        #pragma omp for
        for(j=0; j<tam; j++){
            producto_local = producto_local + (m[i][j]*v1[j]);
        }

        #pragma omp critical
        v2[i] += producto_local;
    }
}

    // Obtenemos el tiempo total transcurrido
    #pragma omp single
    {
        total = omp_get_wtime() - t1;
    }

    // Para tamaños pequeños (hasta tam=11), imprimimos todas las componentes del vector resultante
    // y el tiempo de ejecución
    if(tam <= 11){
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n", tam, total);

        for(i=0; i<tam; i++){
            printf("v2[%i] = %f\n", i, v2[i]);
        }
    }

    // Para tamaños superiores, imprimimos el tiempo de ejecución y la primera y última componente del vector
    else{
        printf("Tamaño vectores: %i\n Tiempo de ejecución: %f\n Primera componente: %f\n Última componente: %f\n", tam, total, v2[0], v2[tam-1]);
    }

    // Liberamos memoria
    free(v1);
    free(v2);

    for(i=0; i<tam; i++){
        free(m[i]);
    }

    free(m);

    return 0;
}
