#define CUAL_COMPILA 1

#if CUAL_COMPILA==1
    #include "../include/pila_max_vd.h"
    using Pila_max = pila_max_vd;

#elif CUAL_COMPILA==2
    #include "../include/pila_max_cola.h"
    using Pila_max = Pila_max_Cola;
#endif
