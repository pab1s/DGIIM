/**
 * @file pixel.h
 * @author Juan Andrés Mauricio Martín y Pablo Olivares Martínez
 * @note A implementar
 */

/**
 * @note Define los tipos de piezas que hay
 */
#define L_BLUE 0
#define BLUE 1
#define RED 2
#define ORANGE 3
#define YELLOW 4
#define GREEN 5
#define PURPLE 6

#include <fstream>

/**
 * @brief Clase pixel
 * @param color cada pixel tendrá un color que también tomaremos como referencia para colorear cada pixel y formar figuras
 * @param state definimos el estado de cada pixel. Habrá tres opciones:
 *                  1.-1 -> pixel vacío 
 *                  2. 0 -> pieza fija (ya puesta)
 *                  3. 1 -> pieza en movimiento (jugándose)
 *                  4. 2 -> pivote de la pieza que se está jugando (esencial para distintos métodos)
 */
class Pixel
{
private:
    int color;
    int state;

public:
    /**
     * @brief Constructor por defecto de la clase Pixel
     */
    Pixel();

    /**
     * @brief Devuelve el color asociado al pixel
     * @return int color
     */
    int getColor() const;

    /**
     * @brief Devuelve el estado asociado al pixel
     * @return int estado
     */
    int getState() const;

    /**
     * @brief Establece el color del pixel
     * @param c color
     */
    void setColor(int c);

    /**
     * @brief Establece el estado del pixel
     * @param e estado
     */
    void setState(int e);

    /**
     * @brief Devuelve si el pixel es pivote o no
     * @return true -> en caso de SÍ ser pivote
     * @return false -> en caso de NO ser pivote
     */
    bool isPivot();
    
    /**
     * @brief Entrada de un Pixel desde istream
     * @param is stream de entrada
     * @param Pixel a leer
     */
    friend std::istream& operator>> (std::istream& is, Pixel& p);
    
    /**
     * @brief Salida de un pixel a ostream
     * @param os stream de salida
     * @param p Pixel a escribir
     */
    friend std::ostream &operator<<(std::ostream &os, const Pixel &p);
};


