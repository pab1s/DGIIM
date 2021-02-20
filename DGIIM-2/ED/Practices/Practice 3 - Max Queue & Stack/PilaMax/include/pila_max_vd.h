#pragma once

/* 
 * @file  pila_max_vd.h
 * @brief Archivo que contiene las cabeceras de los métodos de nuestra clase pila con maximo hecho con VD
 * @author Alvaro Luna y Pablo Olivares
 * @date 2020-12-04
 */

#ifndef PILA_MAX_VD_H
#define PILA_MAX_VD_H

#include <iostream>
#include <vector>

/**
 * @brief struct utilizado como objeto de la pila. Contiene el propio numero
 * que queremos almacenar en nuestra pila y el maximo valos que tiene la pila 
 * por debajo.
 */

struct elemento{
    int maximo; ///<el máximo
    int ele; ///<elemento a almacenar
};


/**
 * @brief Clase utilizada para la practica de pilas con maximo en
 *  la de la asignatura de ED. Se utilizan vectores dinamicos de la STL 
 */
class pila_max_vd {

public:
    /**
      * @brief Constructor basico sin parametros
      */
    pila_max_vd() =  default;

    /**
     * @brief Destructor basico
    */
    ~pila_max_vd() =  default;;

    /**
     * @brief Constructor de copia
     * @param orig Pila a copiar
     */
    pila_max_vd(const pila_max_vd &orig);

    /**
     * @brief Operador de asignacion
     * @param orig Pila a asignar
     */
    pila_max_vd & operator= (const pila_max_vd &orig);

    /**
     * @brief Añade un nuevo elemento a la pila con maximo
     * @param numero numero que queremos añadir encima del tope
     */
    void poner(int numero);

    /**
     * @brief Elimina el elemento qeu estuviese en el tope de la pila con maximo
     */
    void quitar();

    /**
     * @brief Consulta si la pila no tiene ningun elemento
     * @return true si la pila esta vacia
     * @return false si la pila no esta vacia
     */
    bool vacia() const;

    /**
     * @brief Consulta el elemento tope de nuestra pila con maximo
     * @return Copia del tope
     */
    const elemento &tope() const;

private:
    std::vector<elemento> elementopila;
};

#endif /* PILA_MAX_VD_H */