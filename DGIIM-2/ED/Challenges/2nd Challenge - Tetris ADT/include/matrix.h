/**
 * @file matrix.h
 * @author Juan Andrés Mauricio Martín y Pablo Olivares Martínez
 * @note A implementar
 */

#include "pixel.h"
#include <fstream>

/**
 * @brief Clase Matrix, será la encargada de gestionar cada uno de los píxeles,
 * tanto del tablero, como de las piezas.
 */
class Matrix {
private:
    Pixel** matrix;
    int width, height;

    /**
     * @brief Reserva memoria para la matriz dinámica
     * @pre @p w, @p h > 0
     * @param w ancho
     * @param h largo
     */
    void allocate(int w, int h);

    /**
     * @brief Destruye la memoria de la matriz
     */
    void deallocate();

    /**
     * @brief Copia una matriz
     * @param m matriz a copiar
     */
    void copy(const Matrix& m);

public:
    /**
     * @brief Constructor de la clase Matrix
     */
    Matrix();

    /**
     * @brief Constructor de copia de la clase Matrix
     * @param m matriz a copiar
     */
    Matrix(const Matrix& m);

    /**
     * @brief Constructor de copia de la clase Matrix
     * 
     * @pre @p w > 0
     * @param w ancho
     * 
     * @pre @p h > 0
     * @param h largo
     * 
     * @pre @p c >= 0, @p c < 7
     * @param c color de cada pixel
     */
    Matrix(int w, int h, int c);

    /**
     * @brief Operador igual de la clase Matrix
     * @param m matriz a igualar
     * @return Matrix 
     */
    Matrix operator=(const Matrix& m);

    /**
     * @brief Destructor de la clase Matrix
     */
    ~Matrix();

    /**
     * @brief Establece el ancho de la matriz
     * @pre @p w > 0
     * @param w ancho
     */
    void setWidth(int w);

    /**
     * @brief Establece el largo de la matriz
     * @pre @p h > 0
     * @param h largo
     */
    void setHeight(int h);

    /**
     * @brief Establece el pixel de la posición (i,j)
     * 
     * @pre @p i >= 0, @p i < height
     * @param i fila
     *  
     * @pre j>=0, j< width
     * @param j columna
     * 
     * @param p pixel a introducir
     */
    void setPixel(int i, int j, const Pixel& p);

    /**
     * @brief Devuelve el ancho de la matriz
     * @return int width
     */
    int getWidth() const;

    /**
     * @brief Devuelve el largo de la matriz
     * @return int height
     */
    int getHeight() const;
    
    /**
     * @brief Devuelve el pixel (i,j) de la matriz
     * 
     * @pre i >= 0, i < height
     * @param i fila
     * 
     * @pre j>=0, j<width
     * @param j columna
     * 
     * @return Pixel 
     */
    Pixel getPixel(int i, int j) const;

    /**
     * @brief Obtiene la fila del pivote
     * @return int 
     */
    int getXPivot() const;

    /**
     * @brief Obtiene la columna del pivote 
     * @return int 
     */
    int getYPivot() const;

    /**
     * @brief Entrada de un Racional desde istream
     * @param is stream de entrada
     * @param m Matriz que recibe
     * @pre La entrada tiene el formato establecido para la matriz
     */
    friend std::istream& operator>> (std::istream& is, Matrix& m);
    /**
     * @brief Salida de una matriz a ostream
     * @param os stream de salida
     * @param m Matriz a escribir
     */
    friend std::ostream& operator<<(std::ostream &os, const Matrix &m);
};