/**
 * @file ruta.h
 * @author Ángel Olmedo & Pablo Olivares
 * @brief Clase que almacena y modifica los valores
 * de la ruta.
 * @date 2021-01-01
 */
#ifndef __RUTAS__
#define __RUTAS__

#include <iostream>
#include <list>
#include "punto.h"

class Ruta {
   private:
    std::string Id;
    int np;
    std::list<Punto> ruta;

    /**
     * @brief Funcion privada que copia una ruta dada en
     * la actual.
     * @param P Ruta a copiar.
     */
    void copiar(const Ruta &R);

    /**
     * @brief Función que vacía una ruta por completo.
     */
    void eliminar();

   public:
    /**
     * @brief Construye a un nuevo objeto Ruta sin
     * parámetros.
     */
    Ruta();

    /**
     * @brief Construye a un nuevo objeto Ruta con
     * parámetros.
     * @param R Ruta a copiar, dada en lista de la STL.
     */
    Ruta(const std::list<Punto> &R);

    /**
     * @brief Construye a un nuevo objeto Ruta con
     * parámetros.
     * @param R Ruta a copiar, dada en lista de la STL.
     * @param etiq Etiqueta de la ruta.
     */
    Ruta(const std::list<Punto> &R, const std::string &etiq);

    /**
     * @brief Construye a un nuevo objeto Ruta con
     * parámetros.
     * @param R Ruta a copiar.
     */
    Ruta(const Ruta &R);

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param R Ruta a copiar.
     * @return Ruta& Ruta copiada.
     */
    Ruta &operator=(const Ruta &R);

    /**
     * @brief Función que inserta un punto en una ruta.
     * @param P Punto a insertar.
     */
    void insertar(const Punto &P);

    /**
     * @brief Función que elimina el primer punto de la ruta.
     */
    void borrarPunto();

    /**
     * @brief Función que dice si una ruta está vacia.
     * @return true Es vacía la ruta.
     * @return false No es vacía.
     */
    bool vacia();

    /**
     * @brief Establece el identificador de ruta.
     * @param etiq Identificador de la ruta.
     */
    void setId(const std::string &etiq);

    /**
     * @brief Establece una ruta dada una lista de puntos
     * de la STL.
     * @param r ruta dada por la lista de puntos de la STL.
     */
    void setRuta(const std::list<Punto> &r);

    /**
     * @brief Devuelve el identificador de ruta.
     * @return std::string Identificador de ruta.
     */
    std::string getId() const;

    /**
     * @brief Devuelve la en forma de lista de puntos de la
     * STL.
     * @return std::list<Punto> lista de puntos de la ruta.
     */
    std::list<Punto> getRuta() const;

    /**
     * @brief Devuelve el número de puntos de la ruta.
     * @return int Número de puntos.
     */
    int getSize() const;

    /**
     * @brief función que lee una ruta dada a través de un
     * flujo de entrada.
     * @param is Flujo de entrada.
     */
    void leerRuta(std::istream &is);

    /**
     * @brief Función que saca por el flujo dado una ruta.
     * @param os Flujo de salida.
     */
    void escribirRuta(std::ostream &os) const;

    /**
     * @brief Sobrecarga del operador de salida para una ruta.
     * @param os Flujo de salida.
     * @param R Ruta a sacar.
     * @return std::ostream& Devuelve el control del flujo.
     */
    friend std::ostream &operator<<(std::ostream &os, const Ruta &R);

    /**
     * @brief Sobrecarga del operador de entrada para una ruta.
     * @param is Flujo de entrada.
     * @param R Ruta a introducir.
     * @return std::istream& Flujo de entrada.
     */
    friend std::istream &operator>>(std::istream &is, Ruta &R);

    /**
     * @brief Sobrecarga del operador de comparación de igualdad para rutas.
     * @param R Ruta con la que se va a comparar.
     * @return true Las rutas son iguales.
     * @return false No son iguales las rutas.
     */
    bool operator==(const Ruta &R) const;

    /**
     * @brief Clase iteradora para recorrer la clase Ruta.
     */
    class iterator {
       private:
        std::list<Punto>::iterator p;

       public:
        /**
         * @brief Construye un objeto iterador.
         */
        iterator() {}

        /**
         * @brief Sobrecarga del operador de incremento
         * para el iterador.
         * @return iterator& El iterador incrementado.
         */
        iterator &operator++();

        /**
         * @brief Sobrecarga del operador de decremento
         * para el iterador.
         * @return iterator& El iterador decrementado.
         */
        iterator &operator--();

        /**
         * @brief Sobrecarga del operador de igualdad para
         * el iterador.
         * @param it Iterador a comparar.
         * @return true Apuntan al mismo punto de la ruta.
         * @return false Apuntan a distintos puntos.
         */
        bool operator==(const iterator &it);

        /**
         * @brief Sobrecarga del operador de no igualdad para
         * la clase iteradora.
         * @param it Iterador a comparar.
         * @return true Apuntan a distintos puntos.
         * @return false Apuntan al mismo punto de la ruta.
         */
        bool operator!=(const iterator &it);

        /**
         * @brief Sobrecarga del operador * para el acceso a
         * valores de la ruta.
         * @return const Punto& Punto al que apunta en la ruta.
         */
        const Punto &operator*() const;

        friend class Ruta;
        friend class const_iterator;
    };

    /**
     * @brief Bis de la clase iteradora pero de acceso constante.
     */
    class const_iterator {
       private:
        std::list<Punto>::const_iterator p;

       public:
        const_iterator() {}
        const_iterator(const iterator &it);
        const_iterator &operator=(const iterator &it);

        const_iterator &operator++();
        const_iterator &operator--();

        bool operator==(const const_iterator &it);
        bool operator!=(const const_iterator &it);
        const Punto &operator*() const;

        friend class Ruta;
    };

    /**
     * @brief Función que devuelve el iterador que apunta al
     * inicio de la ruta.
     * @return iterator Inicio de la ruta.
     */
    iterator begin();

    /**
     * @brief Función que devuelve el iterador que apunta al
     * inicio de la ruta.
     * @return iterator Final de la ruta.
     */
    const_iterator cbegin() const;

    /**
     * @brief Función que devuelve el iterador que apunta al
     * inicio de la ruta de manera const.
     * @return const_iterator Inicio de la ruta.
     */
    iterator end();

    /**
     * @brief Función que devuelve el iterador que apunta al
     * final de la ruta de manera const.
     * @return const_iterator Inicio de la final.
     */
    const_iterator cend() const;

    /**
     * @brief Función que, dado un punto, lo busca en la ruta
     * y devuelve el iterador que apunta a su posición.
     * @param p Punto a buscar.
     * @return iterator
     */
    iterator find(const Punto &p);
};

#endif /*__RUTAS__*/