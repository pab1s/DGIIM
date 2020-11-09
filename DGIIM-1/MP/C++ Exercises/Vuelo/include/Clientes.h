/* 
 * File:   Clientes.h
 * Author: Pablo Olivares Martínez
 *
 * Created on 11 de junio de 2020, 19:20
 */

#ifndef CLIENTES_H
#define CLIENTES_H

#include "Cliente.h"

class Clientes {
public:
    /**
     * Versión de devolución por referencia del operador de acceso a un elemento 
     * de la colección de clientes
     * @param n el número de elemento al que se quiere acceder
     * @return el elemento que hay en la posición n (comienza desde la posición 0)
     */
    Cliente& operator[](int n);
    
    /**
     * Versión de devolución por referencia constante del operador de acceso 
     * a un elemento de la colección de clientes
     * @param n el número de elemento al que se quiere acceder
     * @return el elemento que hay en la posición n (comienza desde la posición 0)
     */
    const Cliente& operator[](int n) const;
    
    /**
     * Devuelve el número de clientes en la colección
     * @return el número de clientes en la colección
     */
    int getNumeroClientes() const;
    
    Clientes();
    Clientes(Clientes& orig);
    ~Clientes();
    Clientes& operator=(const Clientes& orig);
    Clientes& operator+=(const Cliente& orig);
    Clientes operator+(const Clientes &otro);
    void escribirClientes(const std::string nombre) const;
    
private:
    int numClientes;
    Cliente *losClientes;
    
    void allocate(int n);
    void deallocate();
    void copy(const Clientes& orig);
};
std::ostream& operator<<(std::ostream& os, const Clientes& orig);
#endif /* CLIENTES_H */

