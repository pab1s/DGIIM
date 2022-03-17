/*
 * Nucleo original
 */
#include "nucleo.h"

extern my_struct_t s[];
extern int R[];

inline void core ()
{
    int i, j, x1, x2;

    for (i=0 ; i<M ; i++)
    {
        x1 = x2 = 0;

        for(j=0; j<N ; j++)
            x1 += 2*s[j].a+i;

        for(j=0; j<N ; j++)
            x2 += 3*s[j].b-i;

        if (x1<x2)
            R[i]=x1;
        else
            R[i]=x2;
    }
}
