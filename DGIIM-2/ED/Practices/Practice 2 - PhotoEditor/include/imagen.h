/* 
 * File:   imagen.h
 * Author: Alvaro Luna y Pablo Olivares
 *
 * Created on 19 de octubre de 2020, 9:04
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include "imagenES.h"

typedef unsigned char byte;

/**
 * @brief Clase usada para la practica de imagenes de la asignatura de ED.
 * Usa una matriz dinámica con valores de 0 a 255 en cada celda, que representa 
 * un valor de negro
 */
 
 class Imagen {
 public:
     /**
      * @brief Constructor basico sin parametros
      */
     Imagen();
     
     /**
     * @brief Constructor basico con @f filas y @c columnas
     * @param f Numero de filas
     * @param c Numero de columnas
     */
     Imagen (int f, int c);
     
     /**
     * @brief Constructor de copia
     * @param orig Matriz a copiar
     */
     Imagen (const Imagen & orig);
     
     /**
     * @brief Destructor basico
     */
     ~Imagen();
     
     /**
     * @brief Funcion que devuelve el numero de filas que tiene la matriz
     * @return numfil
     */
     int num_filas () const;
     
     /**
     * @brief Funcion que devuelve el numero de columnas que tiene la matriz
     * @return numcol
     */
     int num_columnas () const;
     
     /**
     * @brief Funcion que asigna un valor a la posicion [fil][col]
     * @param fil Numero de fila de la posicion deseada
     * @param col Numero de columna de la posicion deseada
     * @precond 0<= @fil < num_filas (), 0 <= @col < num_columnas (), -1 < valor < 256
     */
     void asigna_pixel (int fil, int col, byte valor);
     
     /**
     * @brief Funcion que devuelve el valor de la posicion [fil][col]
     * @param fil Numero de fila de la posicion deseada
     * @param col Numero de columna de la posicion deseada
     * @precond 0<= @fil < num_filas (), 0 <= @col < num_columnas ()
     * @return valor de la posicion [fil][col]
     */
     byte valor_pixel (int fil, int col) const;

     bool print(const char* ofile);
     bool read(const char* ifile);

     /**
	 * @brief Sobrecarga el operador de asignacion
	 * @param orig Parte derecha de la asignacion
	 * @return this Parte izquierda de la asignacion
	 */
	Imagen& operator=(const Imagen& orig); 
     
 private:
     int fils;
     int cols;
     byte *img;

    /**
     * @brief Reserva memoria y si es necesario libera la reservada anteriormente
     * @param r Filas de la nueva matriz 
     * @param c Columnas de la nueva matriz 
     */

    void allocate(int r, int c);
    /**
     * @brief Libera la memoria
     */
    void deallocate();

    /**
     * @brief Copia una imagen
     * @param i Imagen a copiar
     */
    void copia(const Imagen & i);
     
 };

#endif /* IMAGEN_H */