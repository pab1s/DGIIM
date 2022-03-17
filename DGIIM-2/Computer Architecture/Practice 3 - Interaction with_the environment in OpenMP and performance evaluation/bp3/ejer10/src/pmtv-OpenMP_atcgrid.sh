#!/bin/bash

#Órdenes para el sistema de colas:
#1. Asigna al trabajo un nombre
#SBATCH --job-name=pmtv-OpenMP
#2. Asignar el trabajo a una cola (partición) 
#SBATCH --partition=ac 
#2. Asignar el trabajo a un account 
#SBATCH --account=ac

#Obtener información de las variables del entorno del sistema de colas:
echo "Id. usuario del trabajo: $SLURM_JOB_USER"
echo "Id. del trabajo: $SLURM_JOBID"
echo "Nombre del trabajo especificado por usuario: $SLURM_JOB_NAME"
echo "Directorio de trabajo (en el que se ejecuta el script): $SLURM_SUBMIT_DIR"
echo "Cola: $SLURM_JOB_PARTITION"
echo "Nodo que ejecuta este trabajo:$SLURM_SUBMIT_HOST"
echo "Nº de nodos asignados al trabajo: $SLURM_JOB_NUM_NODES"
echo "Nodos asignados al trabajo: $SLURM_JOB_NODELIST"
echo "CPUs por nodo: $SLURM_JOB_CPUS_PER_NODE"

N=15360

declare -a list=("monotonic:static" "monotonic:dynamic" "monotonic:guided")

for i in "${list[@]}"
do
	for (( j = 0; j < 3; ++j )); do
		case $j in
			0)
			echo "PLANIFICACION: $i | CHUNK: DEFAULT"
			export OMP_SCHEDULE=$i
			;;
			
			1)
			echo "PLANIFICACION: $i | CHUNK: 1"
			export OMP_SCHEDULE="$i,1"
			;;
			
			2)
			echo "PLANIFICACION: $i | CHUNK: 64"
			export OMP_SCHEDULE="$i,64"
			;;
		esac
		srun ./pmtv-OpenMP $N
	done
done
