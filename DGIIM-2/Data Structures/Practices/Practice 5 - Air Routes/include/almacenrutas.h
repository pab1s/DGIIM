/**
 * @file almacenrutas.h
 * @author Ángel Olmedo & Pablo Olivares
 * @brief Clase que almacena y modifica rutas de vuelo.
 * @date 2021-01-01
 */
#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__

#include <list>
#include "ruta.h"

class AlmacenRutas {
   private:
    std::list<Ruta> AlmRuta;
    /**
     * @brief Función que copia un almacén de rutas
     * dado.
     * @param AR Almacén de rutas a copiar.
     */
    void copiar(const AlmacenRutas &AR);

    /**
     * @brief Función que elimina el almacen de rutas
     * por completo.
     */
    void eliminar();

   public:
    /**
     * @brief Construye un nuevo objeto AlmacenRutas
     * sin parámetros.
     */
    AlmacenRutas() {}

    /**
     * @brief Construye un nuevo objeto AlmacenRutas
     * con parámetros.
     * @param AR lista de rutas de la STL.
     */
    AlmacenRutas(const std::list<Ruta> &AR);

    /**
     * @brief Construye un nuevo objeto AlmacenRutas
     * con parámetros.
     * @param AR AlmacenRutas a copiar.
     */
    AlmacenRutas(const AlmacenRutas &AR);

    /**
     * @brief Sobrecarga del operador asignación para
     * AlmacenRutas.
     * @param AR AlmacenRutas a copiar.
     * @return AlmacenRutas& AlmacenRutas copiado.
     */
    AlmacenRutas &operator=(const AlmacenRutas &AR);

    /**
     * @brief Función que borra una ruta dado su identificador.
     * @param ident Identificador de la ruta.
     */
    void borrarRuta(const std::string ident);

    /**
     * @brief Inserta una ruta en el almacén de rutas.
     * @param Ruta Ruta a insertar al final de la cola.
     */
    void insertarRuta(const Ruta);

    /**
     * @brief Comprueba si un almacén está vacío.
     * @return true El almacen está vacío.
     * @return false El almacén no está vacío.
     */
    bool vacia();

    /**
     * @brief Función que devuelve una ruta dado su identificador.
     * @param ident Identificador de ruta.
     * @return Ruta& Ruta con tal identificador.
     */
    Ruta &getRuta(const std::string ident);

    /**
     * @brief Devuelve el número de rutas almacenadas.
     * @return int Número de rutas.
     */
    int getSize() const;

    /**
     * @brief Devuelve la lista de Rutas de la STL.
     * @return std::list<Ruta> Lista de rutas de la STL.
     */
    std::list<Ruta> getLista() const;

    /**
     * @brief Función que lee un almacén de rutas dado por
     * un flujo de entrada.
     * @param is Flujo de entrada.
     */
    void leerAlmacen(std::istream &is);

    /**
     * @brief Función que imprime un AlmacenRutas por el
     * flujo de salida asignado.
     * @param os Flujo de salida.
     */
    void escribirAlmacen(std::ostream &os) const;

    /**
     * @brief Sobrecarga del operador de salida para devolver
     * un AlmacenRutas a un flujo asignado.
     * @param os Flujo de salida.
     * @param AR AlmacenRutas a mostrar.
     * @return std::ostream& Devuelve el control del flujo.
     */
    friend std::ostream &operator<<(std::ostream &os, const AlmacenRutas &AR);

    /**
     * @brief Sobrecarga del operador de entrada para recibir
     * un AlmacenRutas desde un flujo asignado.
     * @param is Flujo de entrada.
     * @param AR AlmacenRutas a llenar.
     * @return std::istream& Devuelve el control del flujo.
     */
    friend std::istream &operator>>(std::istream &is, AlmacenRutas &AR);
};

#endif /*__ALMACEN_RUTAS__*/