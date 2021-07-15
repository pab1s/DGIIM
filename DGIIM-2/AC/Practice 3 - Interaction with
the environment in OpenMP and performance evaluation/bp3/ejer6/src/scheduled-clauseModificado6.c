#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
  #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) { 
  int i, n=200,chunk,chunk_b,a[n],suma=0;
  omp_sched_t kind, STATIC = 1;
  
  if(argc < 3)     {
      fprintf(stderr,"\nFalta iteraciones o chunk \n");
      exit(-1);
     }
   n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]); 

   for (i=0; i<n; i++)       a[i] = i; 
 
   #pragma omp parallel for firstprivate(suma) \
            lastprivate(suma) schedule(dynamic,chunk)
   for (i=0; i<n; i++)
   {   suma = suma + a[i];
       printf(" thread %d suma a[%d]=%d suma=%d \n",
             omp_get_thread_num(),i,a[i],suma);
       
       if (i == 1) {
         omp_set_dynamic(0);
         omp_set_num_threads(2);
         omp_set_schedule(STATIC, 2);
         omp_get_schedule(&kind, &chunk_b);

         printf("MODIFICADO:\n");
         printf("DENTRO: dyn-var -- %d | nthreads-var -- %d | threads-limit-var -- %d | run-sched-var -- (kind %d | chunk %d) \n",
         omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(), kind, chunk_b);
       } else if (i == 0) {
         omp_get_schedule(&kind, &chunk_b);

         printf("SIN MODIFICAR:\n");
         printf("DENTRO: dyn-var -- %d | nthreads-var -- %d | threads-limit-var -- %d | run-sched-var -- (kind %d | chunk %d) \n",
         omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(), kind, chunk_b);
       }
   }
  
   printf("Fuera de 'parallel for' suma=%d\n",suma); 
   printf("FUERA: dyn-var -- %d | nthreads-var -- %d | threads-limit-var -- %d | run-sched-var -- (kind %d | chunk %d) \n",
         omp_get_dynamic(), omp_get_max_threads(), omp_get_thread_limit(), kind, chunk_b);
   
   return(0);
}
