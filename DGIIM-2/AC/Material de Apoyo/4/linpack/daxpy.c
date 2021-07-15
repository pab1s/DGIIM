/*
 * Nucleo original
 */
extern double *x, *y, a;
extern unsigned int N;

/* Función a optimizar */
inline void daxpy ()
{
    int i;

    // hacemos la multiplicacion
    for (i=0; i<N; i++)
    {
        y[i] = a*x[i] + y[i];
    }
}

