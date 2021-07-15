#!/bin/bash
#Órdenes para el Gestor de carga de un trabajo:
#1. Asigna al trabajo un nombre
#SBATCH --job-name=SumaLocal
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
#Instrucciones del script para ejecutar código:
echo "VECTORES LOCALES"
for ((P=65536;P<=67108864;P=P*2))
do
	./SumaVectoresC-local $P #srun ./SumaVectoresC-local $P
done

echo "VECTORES GLOBALES"
for ((P=65536;P<=67108864;P=P*2))
do
        ./SumaVectoresC-global $P #srun ./SumaVectoresC-global $P
done

echo "VECTORES DINAMICOS"
for ((P=65536;P<=67108864;P=P*2))
do
        ./SumaVectoresC-dynamic $P	#srun ./SumaVectoresC-dynamic $P
done



