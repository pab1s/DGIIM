#!/bin/bash
#Descripción: Ejecuta la Suma de Vectores en C desde 16384 hasta 67108864
#Uso: ./script_pc.sh

#DEFINICION DE MINIMO Y MAXIMO DE CALCULO
MIN=16384
MAX=67108864

#CONSTRUCCION DE NOMBRES DE ARCHIVO EJECUTABLES
FILENO1="SumaVectoresC-for"
FILENO2="SumaVectoresC-sections"
FILENO3="SumaVectoresC-secuencial"

#CONSTRUCCION DE ARCHIVOS DE VOLCADO DE SALIDA
OUT_FILENO1="tiempos-for-pc.txt"
OUT_FILENO2="tiempos-sections-pc.txt"
OUT_FILENO3="tiempos-secuencial-pc.txt"
OUT_DIRECTORY="tiempos"

#EJECUCION DE SCRIPT: TIEMPOS SECUENCIAL

mkdir -p $OUT_DIRECTORY

echo -e "\nPARALLEL SECUENCIAL:"
for((N=$MIN; N<=$MAX; N=N*2))
do
	echo " --> Secuencial $N de $MAX"
	./$FILENO3 $N >> $OUT_DIRECTORY/$OUT_FILENO3
	echo " " >> $OUT_DIRECTORY/$OUT_FILENO3
done

#DEFINICION DE HEBRAS A EJECUTAR EN PC
NUM_HEBRAS=4
set omp_num_threads $NUM_HEBRAS

#FOR:
mkdir -p $OUT_DIRECTORY

echo -e "\nPARALLEL FOR:"
echo -e "NUM HEBRAS DE EJECUCION: $NUM_HEBRAS\n" >> $OUT_DIRECTORY/$OUT_FILENO1
for((N=$MIN; N<=$MAX; N=N*2))
do
	echo " --> For $N de $MAX"
	./$FILENO1 $N >> $OUT_DIRECTORY/$OUT_FILENO1
	echo " " >> $OUT_DIRECTORY/$OUT_FILENO1
done

#SECTIONS:
mkdir -p $OUT_DIRECTORY

echo -e "\nPARALLEL SECTIONS:"
echo -e "NUM HEBRAS DE EJECUCION: $NUM_HEBRAS\n" >> $OUT_DIRECTORY/$OUT_FILENO2
for((N=$MIN; N<=$MAX; N=N*2))
do
	echo " --> Sections $N de $MAX"
	./$FILENO2 $N >> $OUT_DIRECTORY/$OUT_FILENO2
	echo " " >> $OUT_DIRECTORY/$OUT_FILENO2
done

