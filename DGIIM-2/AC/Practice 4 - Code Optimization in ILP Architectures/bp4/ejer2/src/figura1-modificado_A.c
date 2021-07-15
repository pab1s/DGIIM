#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct S {
    int a;
    int b;
};

int main(int argc, char **argv) {
    int i, j, k, ii, X1, X2;

    struct timespec cgt1, cgt2;
    double ncgt;

    if (argc < 3) {
        printf("Faltan nº componentes del vector\n");
        exit(-1);
    }

    unsigned int N = atoi(argv[1]);
    unsigned int M = atoi(argv[2]);

    struct S s[N];
    int R[N];

    // Inicializar vectores
    if (N < 9) {
        for (i = 0; i < N; i++) {
            s[i].a = N * 0.1 + i * 0.1;
            s[i].b = N * 0.1 - i * 0.1;
        }
    } else {
        srand(time(NULL));
        for (i = 0; i < N; i++) {
            s[i].a = rand();
            s[i].b = rand();
        }
    }

    clock_gettime(CLOCK_REALTIME, &cgt1);

    for (ii = 0; ii < M; ii++) {
        X1 = 0; X2 = 0;
        for (i = 0; i < N-4; i+=4) { 
			X1 += 2 * s[i].a * s[i+1].a * s[i+2].a * s[i+3].a + 4*ii;
			X2 += 3 * s[i].b * s[i+1].b * s[i+2].b * s[i+3].b - 4*ii; 
		}
		for ( ; i < N; i++) {
			X1 += 2 * s[i].a * s[i+1].a * s[i+2].a * s[i+3].a + 4*ii;
			X2 += 3 * s[i].b * s[i+1].b * s[i+2].b * s[i+3].b - 4*ii; 
		}

        if (X1 < X2)
            R[ii] = X1;
        else
            R[ii] = X2;
    }

    clock_gettime(CLOCK_REALTIME, &cgt2);
    ncgt = (double)(cgt2.tv_sec - cgt1.tv_sec) +
           (double)((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

    printf("Tiempo:%11.9f\t / Tamaño Vectores:%u\t/ R[0](%d)/ / R[%d](%d)/\n / S[0].a %d S[0].b %d S[N-1].a %d S[N-1] %d\n",
           ncgt, N, R[0], M - 1, R[M - 1], s[0].a, s[0].b, s[N - 1].a, s[N - 1].b);

    return 0;
}
