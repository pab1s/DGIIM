#!/bin/bash

#Declaración de variables
X0=1
XN=16

#Función auxiliar
execute_bin()
{
	VALUE_1=7500
	VALUE_2=10500
	
	export OMP_NUM_THREADS=$1

	echo "PMV SECUENCIAL"
	./pmv-secuencial-dynamic $VALUE_1 #srun ./pmv-secuencial-dynamic $VALUE_1
	./pmv-secuencial-dynamic $VALUE_2 #srun ./pmv-secuencial-dynamic $VALUE_2
	echo

	echo "PMV OPENMP-A"
	./pmv-OpenMP-a $VALUE_1 #srun ./pmv-OpenMP-a $VALUE_1
	./pmv-OpenMP-a $VALUE_2 #srun ./pmv-OpenMP-a $VALUE_2
	echo

	echo "PMV OPENMP-B"
	./pmv-OpenMP-b $VALUE_1	#srun ./pmv-OpenMP-b $VALUE_1
	./pmv-OpenMP-b $VALUE_2	#srun ./pmv-OpenMP-b $VALUE_2
	echo

	echo "PMV OPENMP-REDUCTION"
	./pmv-OpenMP-reduction $VALUE_1	#srun ./pmv-OpenMP-reduction $VALUE_1
	./pmv-OpenMP-reduction $VALUE_2	#srun ./pmv-OpenMP-reduction $VALUE_2
	echo
}

#Instrucciones del script para ejecutar código:

for((P=$X0;P<=$XN;P=P+1))
do	
	echo -e "NÚMERO DE HEBRAS: $P \n" 
	execute_bin $P
done

echo -e "NÚMERO DE HEBRAS: 32 \n" 
execute_bin 32

