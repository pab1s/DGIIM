/**
 * @file bag.h
 * @author Juan Andrés Mauricio Martín y Pablo Olivares Martínez
 * @note A implementar
 */

#include "piece.h"
#include <deque>

/**
 * @brief Clase bolsa (usa la STL) que almacena las siguientes piezas
 * a introducir durante el juego
 */
class Bag {  
private:
    /**
     * @note Creacion de una cola de piezas doblemente terminada con ayuda de la STL
     * para aprovechar sus bondades de indexación, inserción y borrado
     */
    std::deque <Piece> bag;

public:
    /**
     * @brief Devuelve la pieza en la posición n-ésima
     * @param n posición dentro de la cola
     * @return objeto de la clase Pieza
     */
    Piece getPiece(int n) const;

    /**
     * @brief Devuelve la siguiente pieza a jugar (haciendo las demás operaciones necesarias)
     * @note Además realiza el borrado de la última pieza e inserta una nueva al inicio con la STL
     * @return Pieza siguiente a jugar 
     */
    Piece nextPiece();
};