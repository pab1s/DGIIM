#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

int resultado = 0;

#ifndef TEST
#define TEST 0
#endif
/* -------------------------------------------------------------------- */
#if TEST == 0
/* -------------------------------------------------------------------- */
    #define SIZE (1<<16)
    int lista[SIZE];

/* -------------------------------------------------------------------- */
#elif TEST == 1
/* -------------------------------------------------------------------- */
#define SIZE 4
unsigned lista[SIZE] = {0x80000000, 0x00400000, 0x00000200, 0x00000001};
#define RESULT 4
/* -------------------------------------------------------------------- */
#elif TEST == 2
/* -------------------------------------------------------------------- */
#define SIZE 8
unsigned lista[] = {0x7fffffff, 0xffbfffff, 0xfffffdff, 0xfffffffe,
                    0x01000023, 0x00456700, 0x8900ab00, 0x00cd00ef};
#define RESULT 156
/* -------------------------------------------------------------------- */
#elif TEST == 3
/* -------------------------------------------------------------------- */
#define SIZE 8
unsigned lista[] = {0x0, 0x01020408, 0x35906a0c, 0x70b0d0e0,
                    0xffffffff, 0x12345678, 0x9abcdef0, 0xdeadbeef};
#define RESULT 116
/* -------------------------------------------------------------------- */
#elif TEST == 4
/* -------------------------------------------------------------------- */
#define NBITS 20
#define SIZE 1 << NBITS
unsigned lista[SIZE];
#define RESULT (NBITS * (1 << NBITS - 1))
/* -------------------------------------------------------------------- */
#else
/* -------------------------------------------------------------------- */
#pragma GCC error "Error: Definir TEST entre 0..4"
#endif

void crono(int (*func)(), char *msg)
{
    struct timeval tv1, tv2;
    long tv_usecs;

    gettimeofday(&tv1, NULL);
    resultado = func(lista, SIZE);
    gettimeofday(&tv2, NULL);

    tv_usecs = (tv2.tv_sec - tv1.tv_sec) * 1E6 +
               (tv2.tv_usec - tv1.tv_usec);


#if TEST == 0
    printf("%ld\n", tv_usecs);
#else
    printf("resultado = %d\t", resultado);
    printf("%s:%9ld us\n", msg, tv_usecs);
#endif
}

#define WSIZE 8*sizeof(long)

//popcount recorrido con bucle for
int popcount01(unsigned * array, size_t len)
{
    size_t j;
    long result = 0;
    long x = 0;
    for (size_t i = 0; i < len; i++){
        x = array[i];
        for (j = 0; j < WSIZE; j++){
            result += x & 0x1;
            x >>= 1;
        }
    }
    return result;
}

//popcount recorrido con bucle while
int popcount02(unsigned *array, size_t len)
{
    long result = 0;
    unsigned long x = 0;
    for (size_t j = 0; j < len; j++){
        x = array[j];
        while (x){
            result += x & 0x1;
            x >>= 1;
        }
    }
    return result;
}

//popcount while traducido a asm con test
int popcount03(unsigned *array, size_t len)
{
    size_t i;
    unsigned long x;
    long result = 0;
    for (i = 0; i < len; i++){
        x = array[i];
        asm("\n"
        "ini3:                  \n\t"
            "shr %[x]           \n\t"
            "adc $0, %[r]       \n\t"
            "test %[x], %[x]    \n\t"
            "jne ini3           \n\t"
            
            : [r] "+r" (result)
            : [x] "r" (x)
            );
    }
    return result;
}

//popcount while traducido a asm sin test
int popcount04(unsigned *array, size_t len)
{
    size_t i;
    unsigned long x;
    long result = 0;
    for (i = 0; i < len; i++){
        x = array[i];
        asm("\n"
            "clc                \n\t"
        "ini4:                  \n\t"
            "adc $0, %[r]       \n\t"
            "shr %[x]           \n\t"
            "jnz ini4           \n\t"
            "adc $0, %[r]       \n\t"
            : [r] "+r" (result)
            : [x] "r" (x)
            );
    }
    return result;  
}

//popcount libro O'Hallaron
int popcount05(unsigned *array, size_t len)
{
    unsigned long x;
    long result = 0;
    for (size_t j = 0; j < len; j++){
        x = array[j];
        long val = 0;
        int i;
        for (i = 0; i < sizeof(x); i++){
            val += x & 0x01010101;
            x >>= 1;
        }
        val += (val >> 32);
        val += (val >> 16);
        val += (val >> 8);
        result += val & 0xFF;        
    }
    return result;
}

//popcount naive Wikipedia
int popcount06(unsigned *array, size_t len)
{
    const uint64_t m1  = 0x5555555555555555; //binary: 0101...
    const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
    const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
    const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
    const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
    const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
    const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
    
    unsigned long x;
    long result = 0;
    for (size_t j = 0; j < len; j++){
        x = array[j];
        x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
        x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
        x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
        x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
        x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits 
        x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits 
        result += x;        
    }
    return result;

}

//popcount naive Wikipedia mejorado
int popcount07(unsigned *array, size_t len)
{
    const uint64_t m1  = 0x5555555555555555; //binary: 0101...
    const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
    const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
    const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
    const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
    const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
    const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
    
    size_t i;
    unsigned long x1,x2;
    int result = 0;
    if (len & 0x3) printf ("leyendo 128b pero len no múltiplo de 4\n");

    for (i = 0; i < len; i+=4){
        x1 = *(unsigned long*) & array[i];
        x2 = *(unsigned long*) & array[i+2];
        x1 = (x1 & m1 ) + ((x1 >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
        x1 = (x1 & m2 ) + ((x1 >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
        x1 = (x1 & m4 ) + ((x1 >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
        x1 = (x1 & m8 ) + ((x1 >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
        x1 = (x1 & m16) + ((x1 >> 16) & m16); //put count of each 32 bits into those 32 bits 
        x1 = (x1 & m32) + ((x1 >> 32) & m32); //put count of each 64 bits into those 64 bits 

        x2 = (x2 & m1 ) + ((x2 >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
        x2 = (x2 & m2 ) + ((x2 >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
        x2 = (x2 & m4 ) + ((x2 >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
        x2 = (x2 & m8 ) + ((x2 >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
        x2 = (x2 & m16) + ((x2 >> 16) & m16); //put count of each 32 bits into those 32 bits 
        x2 = (x2 & m32) + ((x2 >> 32) & m32); //put count of each 64 bits into those 64 bits 
        
        result += x1 + x2;        
    }
    return result;
}

//popcount SSE3
int popcount08(unsigned *array, size_t len)
{
    size_t i;
    int val, result = 0;
    int SSE_mask[] = {0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
    int SSE_LUTb[] = {0x02010100, 0x03020201, 0x03020201, 0x04030302};

    if (len & 0x3) printf ("leyendo 128b pero len no múltiplo de 4\n");
    for (i=0; i < len; i+=4){
    asm("movdqu     %[x], %%xmm0        \n\t"
        "movdqa     %%xmm0, %%xmm1      \n\t"
        "movdqu     %[m], %%xmm6        \n\t"
        "psrlw      $4, %%xmm1          \n\t"
        "pand       %%xmm6, %%xmm0      \n\t"
        "pand       %%xmm6, %%xmm1      \n\t"
        
        "movdqu     %[l], %%xmm2        \n\t"
        "movdqa     %%xmm2, %%xmm3      \n\t"
        "pshufb     %%xmm0, %%xmm2      \n\t"
        "pshufb     %%xmm1, %%xmm3      \n\t"
        
        "paddb      %%xmm2, %%xmm3       \n\t"
        "pxor       %%xmm0, %%xmm0       \n\t"
        "psadbw     %%xmm0, %%xmm3       \n\t"
        "movhlps    %%xmm3, %%xmm0       \n\t"
        "paddd      %%xmm3, %%xmm0       \n\t"
        "movd       %%xmm0, %[val]       \n\t"
        : [val]"=r" (val)
        : [x] "m" (array[i]),
          [m] "m" (SSE_mask[0]),
          [l] "m" (SSE_LUTb[0])
        );
        result += val;
    }
    return result;
}

//popcount SSE4.2
int popcount09(unsigned *array, size_t len)
{
    size_t i;
    unsigned x;
    int val, result = 0;

    for (i=0; i < len; i++){
        x = array[i];
        asm("popcnt %[x], %[val]"
        
            : [val] "=r" (val)
            :   [x] "r"  (x)

        );
        result += val;
    }
    return result;
}

//popcount 128bit p/mejorar prestaciones
int popcount10(unsigned *array, size_t len)
{
    size_t i;
    unsigned long x1,x2;
    long val; int result = 0;
    if (len & 0x3) printf ("leyendo 128b pero len no múltiplo de 4\n");
    for (i=0; i < len; i+=4){
        x1 = *(unsigned long*) & array[i];
        x2 = *(unsigned long*) & array[i+2];
        asm("popcnt %[x1], %[val]      \n"
            "popcnt %[x2], %%r10    \n"
            "add    %%r10, %[val]      \n"
            : [val] "=&r" (val)
            :  [x1] "r" (x1),
               [x2] "r" (x2)
            : "r10"
        );
        result += val;
    }
    return result;
}

int main()
{
#if TEST==0 || TEST==4
    size_t i;
    for (i = 0; i < SIZE; i++)
        lista[i] = i;
#endif
crono(popcount01 ,"popcount01 (lenguaje C - for)");
crono(popcount02 ,"popcount02 (lenguaje C - while)");
crono(popcount03 ,"popcount03 (leng.ASM-body while 4i)");
crono(popcount04 ,"popcount04 (leng.ASM-body while 3i)");
crono(popcount05 ,"popcount05 (CS:APP2e 3.49-group 8b)");
crono(popcount06 ,"popcount06 (Wikipedia- naive - 32b)");
crono(popcount07 ,"popcount07 (Wikipedia- naive -128b)");
crono(popcount08 ,"popcount08 (asm SSE3 - pshufb 128b)");
crono(popcount09 ,"popcount09 (asm SSE4- popcount 32b)");
crono(popcount10,"popcount10(asm SSE4- popcount128b)");

#if TEST != 0
    printf("calculado =  %d\n", RESULT);
#endif  
    exit(0);
}
