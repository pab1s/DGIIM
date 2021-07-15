#!/bin/bash
#Órdenes para el Gestor de carga de un trabajo:
#1. Asigna al trabajo un nombre
#SBATCH --job-name=tiempos_pmv_ac
#2. Asignar el trabajo a una partición (cola)
#SBATCH --partition=ac
#3. Asignar el trabajo a un account
#SBATCH --account=ac

#Obtener información de las variables del entorno del Gestor de carga de trabajo:
echo "Id. usuario del trabajo: $SLURM_JOB_USER"
echo "Id. del trabajo: $SLURM_JOBID"
echo "Nombre del trabajo especificado por usuario: $SLURM_JOB_NAME"
echo "Directorio de trbajo (en el que se ejecuta el script): $SLURM_SUBMIT_DIR"
echo "Cola: $SLURM_JOB_PARTITION"
echo "Nodo que ejecuta este trabajo: $SLURM_SUBMIT_HOST"
echo "Nº de nodos asignados al trabajo: $SLURM_JOB_NUM_NODES"
echo "Nodos asignados al trabajo: $SLURM_JOB_NODELIST"
echo "CPUs por nodo: $SLURM_JOB_CPUS_PER_NODE"

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
	srun ./pmv-secuencial-dynamic $VALUE_1
	srun ./pmv-secuencial-dynamic $VALUE_2
	echo

	echo "PMV OPENMP-A"
	srun ./pmv-OpenMP-a $VALUE_1
	srun ./pmv-OpenMP-a $VALUE_2
	echo

	echo "PMV OPENMP-B"
	srun ./pmv-OpenMP-b $VALUE_1
	srun ./pmv-OpenMP-b $VALUE_2
	echo

	echo "PMV OPENMP-REDUCTION"
	srun ./pmv-OpenMP-reduction $VALUE_1
	srun ./pmv-OpenMP-reduction $VALUE_2
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

