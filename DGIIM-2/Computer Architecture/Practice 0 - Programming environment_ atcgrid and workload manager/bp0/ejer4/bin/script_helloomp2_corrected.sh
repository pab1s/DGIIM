#!/bin/bash
#Órdenes para el Gestor de carga de trabajo:
#1. Asigna al trabajo un nombre
#SBATCH --job-name=helloOMP2_corrected
#2. Asignar el trabajo a una partición (cola) 
#SBATCH --partition=ac#2. Asignar el trabajo a un account
#SBATCH --account=ac

#Obtener información de las variables del entorno del Gestor de carga de trabajo:
echo "Id. usuario del trabajo: $SLURM_JOB_USER"
echo "Id. del trabajo: $SLURM_JOBID"
echo "Nombre del trabajo especificado por usuario: $SLURM_JOB_NAME"
echo "Directorio de trabajo (en el que se ejecuta el script): $SLURM_SUBMIT_DIR"
echo "Cola: $SLURM_JOB_PARTITION"
echo "Nodo que ejecuta este trabajo:$SLURM_SUBMIT_HOST"
echo "Nº de nodos asignadosal trabajo: $SLURM_JOB_NUM_NODES"
echo "Nodos asignados al trabajo: $SLURM_JOB_NODELIST"
echo "CPUspor nodo: $SLURM_JOB_CPUS_PER_NODE"

#Instrucciones del script para ejecutar código:
echo -e "\n 1. Ejecución helloOMPuna vez sin cambiar nº de threads(valor por defecto):\n"
srun ./HelloOMP
echo -e "\n 2. Ejecución helloOMPvarias veces con distinto nº de threads:\n"
for((P=12;P>0;P=P/2))
do
	export OMP_NUM_THREADS=$P
	echo -e "\n  -Para $P threads:"
	srun ./HelloOMP2_corrected
done
