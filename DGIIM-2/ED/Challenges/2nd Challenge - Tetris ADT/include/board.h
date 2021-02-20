/**
 * @file board.h
 * @author Juan Andrés Mauricio Martín y Pablo Olivares Martínez
 * @note A implementar
 */

#include "piece.h"
#include "matrix.h"

/**
 * @brief Clase Tablero que se encargará de almacenar las distintas piezas 
 * que se han colocado y de permitir los distintos movimientos de la pieza en juego.
 */
class Board {
private:
    Matrix board;
    
public:
    /**
     * @brief Mueve la pieza hacia los lados en caso de ser posible
     * @param is_right true -> comprueba a la derecha // false -> izquierda
     */
    void moveSide(bool is_right);

    /**
     * @brief Mueve la pieza hacia abajo en caso de ser posible
     */
    void goDown();

    /**
     * @brief Insertamos una nueva pieza en las coordenadas del pivote
     * @pre i >=0, i < height
     * @param i coordenada x del pivote
     * @pre j >=0, j < width
     * @param j coordenada y del pivote
     * @param p pieza a insertar en el tablero
     */
    void insert(int i, int j, const Piece& p);

    /**
     * @brief Elimina la línea i-ésima en caso de que todos los pixeles sean fijos
     * @pre i >= 0, i < width
     * @param i línea a estudiar
     */
    void eraseLine(int i);
    
    /**
     * @brief Borrar la pieza en caso de ser necesario (ej: al rotar una pieza estamos
     * insertando una nueva y eliminamos la anterior)
     */
    void replacePiece();

    /**
     * @brief Estudia si un movimiento es posible o no
     * @pre movement = 0,1,2
     * @param movement -> indica el tipo de movimiento:
     *                    0. Movimiento hacia la derecha
     *                    1. Movimiento hacia la izquierda
     *                    2. Movimiento hacia abajo
     * 
     * @return true  -> en caso de SÍ ser posible
     * @return false -> en caso de NO ser posible
     */
    bool isValidMove(int movement);
    
    /**
     * @brief Comprueba si la rotación a realizar es posible
     * @param right_rotation indica el sentido de la rotación
     * @return true -> en caso de SÍ ser posible
     * @return false -> en caso de NO ser posible
     */
    bool isValidRotation(bool right_rotation);
    
    /**
     * @brief Mira si todos los pixeles de la línea i-ésima son fijos
     * @pre i >= 0, i < width
     * @param i línea a estudiar
     * @return true  -> en caso de que la línea solo tenga pixeles fijos
     * @return false -> en caso de que la línea tiene pixeles no fijos
     */
    bool isValidErase(int i);
};      