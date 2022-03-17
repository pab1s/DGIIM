/**
 * @file Piece.h
 * @author Juan Andrés Mauricio Martín y Pablo Olivares Martínez
 * @note A implementar
 */
#include "pixel.h"
#include "matrix.h"

/**
 * @brief Clase Pieza encargada de gestionar la creación 
 * y rotación de cada una de las piezas.
 */
class Piece {
private:
    Matrix piece; 

public:
    /**
     * @brief Rota la pieza usando el pivote hacia la izquierda
     * @return la pieza rotada
     */
    Piece rotateLeft();

    /**
     * @brief Rota la pieza usando el pivote hacia la derecha
     * @return la pieza rotada
     */
    Piece rotateRight();

    /**
     * @brief Genera una pieza dependiendo de su color
     * @param color indica el color de la pieza a generar
     * @return pieza generada 
     */
    Piece generate(int color);

};