#ifndef PILA_MAX_COLA_H
#define PILA_MAX_COLA_H
/**
 * @file pila_max_cola.h
 * @author Pablo Olivares y Álvaro Luna
 * @brief Clase pila con maximo que almacena los valores junto con
 * el mayor elemento de la pila desde el elemento mas antiguo hasta
 * el dado.
 * @date 2020-12-04
 */
#include "cola.h"

/**
 * @brief Estructura de elementos formada por el elemento añadido y el
 * maximo. 
 */
struct elemento {
    int ele;
    int maximo;
};

class Pila_max_Cola {

   private:
    Cola<elemento> c;

   public:

   /**
    * @brief Construye un nuevo objeto Pila_max
    */
    Pila_max_Cola() = default;
    /**
     * @brief añade un elemento a la pila
     * @param n entero a añadir
     */
    void poner(int n);
    /**
     * @brief quita el ultimo elemento añadido en la pila
     */
    void quitar();
    /**
     * @brief da el ultimo elemento añadido en la pila
     * @return elemento 
     */
    elemento tope();
    /**
     * @brief devuelve si la pila esta vacia o no
     * 
     * @return true pila vacia
     * @return false pila no vacia
     */
    bool vacia();

};

#endif /* PILA_MAX_COLA_H */
