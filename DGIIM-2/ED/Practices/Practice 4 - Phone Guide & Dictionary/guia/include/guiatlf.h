#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

istream &operator>>(istream &is, pair<string, string> &d);

class Guia_Tlf {
   private:
    map<string, string> datos;  // si admites que haya nombres repetidos
                                // tendr�as que usar un multimap

   public:
    // Guia_Tlf(){}
    // Guia_Tlf(const Guia_Tlf & gt);
    //~Guia_Tlf(){}
    // Guia_Tlf & operator=(const Guia_Tlf & gt);
    /**
    * @brief Acceso a un elemento
    * @param nombre: nombre del elemento  elemento acceder
    * @return devuelve el valor asociado a un nombre, es decir el teléfono
    */
    string &operator[](const string &nombre);

    /**
     * @brief Devuelve el tlf asociado al nombre.
     * @param nombre nombre asociado al tlf.
     * @return string Numero de telefono.
     */
    string gettelefono(const string &nombre);

    /**
     @brief Insert un nuevo telefono
     @param nombre: nombre clave del nuevo telefono
     @param tlf: numero de telefono
     @return : un pair donde first apunta al nuevo elemento insertado y bool es
     true si se ha insertado el nuevo tlf o false en caso contrario
    */
    pair<map<string, string>::iterator, bool> insert(string nombre, string tlf);

    /**
     @brief Insert un nuevo telefono
     @param p: pair con el nombre y el telefono asociado

     @return : un pair donde first apunta al nuevo elemento insertado y bool es
     true si se ha insertado el nuevo tlf o false en caso contrario
    */
    pair<map<string, string>::iterator, bool> insert(pair<string, string> p);

    /**
      @brief Borrar un telefono
      @param nombre: nombre que se quiere borrar
      @note: en caso de que fuese un multimap borraria todos con ese nombre
    */
    void borrar(const string &nombre);

    /**
      @brief Borrar un telefono
      @param nombre: nombre que se quiere borrar y telefono asociado
      @note: esta funcion nos permite borrar solamente aquel que coincida en
      nombre y tlf
    */
    // con map siempre hay uno con multimap puede existir mas de uno
    void borrar(const string &nombre, const string &tlf);

    /**
      @brief  Numero de telefonos
      @return el numero de telefonos asociados
     */
    int size() const;

    /**
      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
      @param nombre: nombre sobre el que queremos consultar
      @return numero de telefonos asociados a un nombre
     */
    // al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas
    // de uno
    unsigned int contabiliza(const string &nombre);

    /**
      @brief Limpia la guia
     */
    void clear();

    /**
     * @brief Nos dice si la guia es vacia o no.
     * @return true es vacia.
     * @return false no es vacia.
     */
    bool esVacia();

     /**
      * @brief Busca un nombre dado un telefono.
      * @param tlf telefono a buscar.
      * @return: devuelve una pareja con el iterador que apunta a
      * la posicion del nombre de la persona asociada al numero y 
      * true si existe ese nombre y false si no.
      */
    pair<map<string, string>::iterator, bool> buscarNombre(const string &tlf);

    /**
     * @brief Funcion que dado un telefono, cambia su nombre asociado
     * por uno nuevo.
     * @param tlf telefono asociado.
     * @param nuevo_nombre nombre nuevo.
     */
    void cambiarNombre(const string &tlf, const string &nuevo_nombre);

    /**
     * @brief Funcion para cambiar de telefono dado un nombre y un
     * nuevo numero de telefono.
     * @param nombre nombre asociado al telefono a cambiar.
     * @param tlf telefono nuevo.
     */
    void cambiarTlf(const string &nombre, const string &tlf);


    /**
      @brief Union de guias de telefonos
      @param g: guia que se une
      @return: una nueva guia resultado de unir el objeto al que apunta this y g
    */
    Guia_Tlf operator+(const Guia_Tlf &g);

    /**
      @brief Diferencia de guias de telefonos
      @param g: guia que se une
      @return: una nueva guia resultado de la diferencia del objeto al que
      apunta this y g
    */
    Guia_Tlf operator-(const Guia_Tlf &g);

    /**
      @brief Escritura de la guia de telefonos
      @param os: flujo de salida. Es MODIFICADO
      @param g: guia de telefonos que se escribe
      @return el flujo de salida
     */
    friend ostream &operator<<(ostream &os, Guia_Tlf &g);

    /**
      @brief Lectura de  la guia de telefonos
      @param is: flujo de entrada. ES MODIFICADO
      @param g: guia de telefonos. ES MODIFICADO
      @return el flujo de entrada
    */
    friend istream &operator>>(istream &is, Guia_Tlf &g);

    /**
     * @brief Clase iteradora de la clase Guia de Telefonos.
     */
    class iterator {
       private:
        map<string, string>::iterator mit;
        iterator(typename map<string, string>::iterator it);
        friend class Guia_Tlf;

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
        pair<const string, string> &operator*();

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
        map<string, string>::const_iterator mit;
        const_iterator(typename map<string, string>::const_iterator it);
        friend class Guia_Tlf;

       public:
        const_iterator();
        const_iterator(const const_iterator &it);
        const_iterator &operator=(const const_iterator &it);
        const_iterator &operator++();
        const_iterator &operator--();
        pair<const string, string> operator*() const;
        bool operator!=(const const_iterator &it) const;
        bool operator==(const const_iterator &it) const;
    };

    /**
     * @brief Devuelve un iterador al principio de la guía.
     * @return iterador al principio de la guía.
     */
    iterator begin();

    /**
     * @brief Devuelve un iterador al final de la guía.
     * @return iterador al final de la guía.
     */
    iterator end();

    /**
     * @brief Devuelve un iterador constante al principio de la guía.
     * @return iterador constante al principio de la guía.
     */
    const_iterator cbegin() const;

    /**
     * @brief Devuelve un iterador constante al final de la guía.
     * @return iterador constante al final de la guía.
     */
    const_iterator cend() const;
};

#endif //GUIA_GUIATLF_H
