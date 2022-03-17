/* 
 * File:   Ventas.h
 * Author: Pablo Olivares Martínez
 *
 * Created on 11 de junio de 2020, 20:58
 */

#ifndef VENTAS_H
#define VENTAS_H

#include "Venta.h"

class Ventas {
public:
    Ventas();
    Ventas(Ventas& orig);
    Ventas(std::string fichero);
    ~Ventas();
    Ventas& operator=(const Ventas& orig);
    Ventas& operator+=(const Venta& orig);
    bool operator>(const Ventas& orig);
    bool operator==(const Ventas& orig);
    void read(const std::string fichero);
    double ventaMedia() const;
    inline int getnumVentas() { return numVentas;}
    
private:
    int numVentas;
    Venta *lasVentas;
    
    void allocate(int n);
    void deallocate();
    void copy(const Ventas& orig);
};

std::istream& operator>>(std::istream& is, Ventas& orig);

#endif /* VENTAS_H */

