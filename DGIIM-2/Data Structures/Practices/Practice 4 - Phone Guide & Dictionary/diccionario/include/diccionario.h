#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

/**
 * @brief Tipo elemento que define el diccionario. T es el tipo de dato asociado a una
 * clave que no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej)
 * asociados a la clave de tipo T. El diccionario está ordenado de menor a mayor
 * clave.
 * @tparam T parametro de la clave.
 * @tparam U parametro de la lista.
 */
template <class T, class U>
struct data {
    T clave;
    list<U> info_asoci;
};

/**
 * @brief Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede
 * usarse como un funtor.
 * @tparam T parametro de la clave.
 * @tparam U parametro de la lista.
 * @param d1 dato 1 a comparar.
 * @param d2 dato 2 a comparar.
 * @return true si d1 es menor que d2.
 * @return false si d1 es mayor que d2.
 */
template <class T, class U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2) {
    if (d1.clave < d2.clave) return true;
    return false;
}

/**
 * @brief Un diccionario es una lista de datos de los definidos anteriormente. Cuidado
 * porque se manejan listas de listas. Se añaden 2 funciones privadas que hacen más
 * facil la implementación de algunos operadores o funciones de la parte pública.
 * Copiar copia un diccioario en otro y borrar elimina todos los elementos de un
 * diccionario. La implementación de copiar puede hacerse usando iteradores o
 * directamente usando la función assign.
 * @tparam T parametro de la clave.
 * @tparam U parametro de la lista.
 */
template <class T, class U>
class Diccionario {
   private:
   /**
    * @param datos Lista de datos almacenados.
    */
    list<data<T, U>> datos;

	/**
	 * @brief Copia un diccionario.
	 * @param D Diccionario a copiar.
	 */
    void Copiar(const Diccionario<T, U> &D);

	/**
	 * @brief Función que borra el diccionario.
	 */
	void Borrar();

   public:
    /**
     * @brief Constructor por defecto.
     */
    Diccionario() : datos(list<data<T, U>>()){};

    /**
     * @brief Constructor de copias.
     * @param D Diccionario a copiar.
     */
    Diccionario(const Diccionario &D);

    /**
     * @brief Destructor
     */
    ~Diccionario() {}

    /**
     * @brief Operador de asignación. 
     * @param D Diccionario a copiar.
     * @return Diccionario<T, U>& Diccionario copiado.
     */
    Diccionario<T, U> &operator=(const Diccionario<T, U> &D);

    /**
     * @brief Busca la clave p en el diccionario. Si está devuelve un iterador a
     * dónde está clave. Si no está, devuelve end() y deja el iterador de salida
	 * apuntando al sitio dónde debería estar la clave.
     * @param p Clave a buscar.
     * @param it_out Iterador con la posición de la clave.
     * @return true Si existe la clave.
     * @return false Si no existe.
     */
    bool Esta_Clave(const T &p, typename list<data<T, U>>::iterator &it_out);

    /**
     * @brief Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
	 * e inserta la lista con toda la información asociada a esa clave. Si el
     * diccionario no estuviera ordenado habría que usar la función sort().
     * @param clave Clave a insertar.
     * @param info Información a insertar.
     */
    void Insertar(const T &clave, const list<U> &info);

    /**
     * @brief Añade una nueva informacion asocida a una clave que está en el
	 * diccionario. la nueva información se inserta al final de la lista de
     * información. Si no esta la clave la inserta y añade la informacion asociada.
     * @param s Clave a la que se le añade la información.
     * @param p Información a añadir.
     */
    void AddSignificado_Palabra(const U &s, const T &p);

    /**
     * @brief Devuelve la información (una lista) asociada a una clave p. Podrían
	 * haberse definido operator[] como
	 * data<T,U> & operator[](int pos){ return datos.at(pos);}
	 * const data<T,U> & operator[](int pos)const { return datos.at(pos);}
     * @param p Clave a buscar la información.
     * @return list<U> Información asociada a p.
     */
    list<U> getInfo_Asoc(const T &p);

    /**
     * @brief Devuelve el tamaño del diccionario.
     * @return int Numero de entradas del diccionario.
     */
    int size() const;

	/**
	 * @brief Obtiene todas las claves.
	 * @return list<U> Lista que almacena las claves.
	 */
	list<U> getClaves();

    /**
     * @brief Obtiene los datos asociados a una clave. 
     * @param p Clave de los datos.
     * @return data<T,U> Datos resultantes.
     */
    data<T,U> getDato(const T &p);

	/**
	 * @brief Comprueba si el diccionario está vacio. 
	 * @return true Si esta vacio.
	 * @return false Si no esta vacio.
	 */
	bool esVacia();

	/**
	 * @brief Ordena los datos del diccionario. 
	 */
	void Ordenar();

	/**
	 * @brief Elimina una entrada dada una clave. 
	 * @param clave Clave a eliminar.
	 */
	void Eliminar(const T &clave);

    /**
     * @brief Funciones begin asociada al diccionario.
     * @return list<data<T,U> >::iterator& Iterador inicial.
     */
    typename list<data<T,U> >::iterator &begin();

    /**
     * @brief Funciones end asociada al diccionario.
     * @return list<data<T,U> >::iterator& Iterador final.
     */
    typename list<data<T,U> >::iterator &end();

    /**
     * @brief Funciones cbegin constante asociada al diccionario.
     * @return list<data<T,U> >::iterator& Iterador inicial constante.
     */
    typename list<data<T,U> >::const_iterator cbegin() const;

    /**
     * @brief Funcion cend constante asociada al diccionario.
     * @return list<data<T,U> >::iterator& Iterador final constante.
     */
    typename list<data<T,U> >::const_iterator cend() const;

	/**
	 * @brief Clase iteradora para recorrer el diccionario.
	 * @param lit Iterador de list de la STL usado para nuestro
	 * diccionario. 
	 */
    class iterator {
       private:
        typename list<data<T, U>>::iterator lit;
        iterator(typename list<data<T, U>>::iterator it);
        friend class Diccionario<T, U>;

       public:
	    
		/**
		 * @brief Constructor de un nuevo objeto iterator
		 */
        iterator();

		/**
		 * @brief Constructor de un nuevo objeto iterator copiado.
		 * @param it Iterador a copiar.
		 */
        iterator(const iterator &it);

		/**
		 * @brief Operador de asignacion. 
		 * @param it Iterador a copiar.
		 * @return iterator& Iterador copiado.
		 */
        iterator &operator=(const iterator &it);

		/**
		 * @brief Operador de incremento. Establece la siguiente
		 * posicion.
		 * @return iterator& Iterador incrementado.
		 */
        iterator &operator++();

		/**
		 * @brief Operador de decremento. Establece la anterior
		 * posicion.
		 * @return iterator& Iterador decrementado.
		 */
        iterator &operator--();

		/**
		 * @brief Operador de puntero sobrecargado.
		 * Devuelve el valor a la que apunta el iterador.
		 * @return data<T, U>& Valor al que apunta el iterador.
		 */
        data<T, U> &operator*();

		/**
		 * @brief Operador distintos. Comprueba que dos iteradores
		 * son distintos.
		 * @param it Iterador a comparar.
		 * @return true Son distintos.
		 * @return false Son iguales.
		 */
        bool operator!=(const iterator &it) const;

		/**
		 * @brief Operador iguales. Comprueba que dos iteradores
		 * son iguales.
		 * @param it Iterador a comparar.
		 * @return true Son iguales.
		 * @return false Son distintos.
		 */
        bool operator==(const iterator &it) const;
    };

	/**
	 * @brief Bis de la clase iterator pero constante.
	 */
	class const_iterator {
       private:
        typename list<data<T, U>>::const_iterator lit;
        const_iterator(typename list<data<T, U>>::const_iterator it);
        friend class Diccionario<T, U>;

       public:
        const_iterator();
        const_iterator(const const_iterator &it);
        const_iterator &operator=(const const_iterator &it);
        const_iterator &operator++();
        const_iterator &operator--();
        data<T, U> operator*() const;
        bool operator!=(const const_iterator &it) const;
        bool operator==(const const_iterator &it) const;
    };
};

#include "../src/diccionario.cpp"
#endif
