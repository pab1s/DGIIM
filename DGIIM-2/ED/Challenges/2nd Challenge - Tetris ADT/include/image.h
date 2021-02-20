#include "board.h"
#include "bag.h"

/**
 * @brief Estructura Datos que almacena la información que queremos
 * mostrar por pantalla.
 * @param level nivel de la partida
 * @param npieces número de piezas colocadas
 * @param nlines número de líneas que se han eliminado
 */
struct data{
    int level;
    int npieces;
    int nlines;
};

/**
 * @brief Clase Imagen que contiene todos los datos, métodos y clases necesarias
 * para el desarrollo del juego y de la partida, además de su guardado y carga.
 */
class Image {
private:
    data info;
    Board tablero;
    Bag bolsa;

public:
    /**
     * @brief Construye un objeto imagen inicializando a 0 los datos miembro
     */
    Image();
    
    /**
     * @brief Lee la partida de un fichero
     * @return true -> si se ha leido bien // false -> si no se lee correctamente
     */
    bool readGame(std::istream &is);
    
    /**
     * @brief Muestra la información de la partida por pantalla, además del tablero
     * @return true -> si se ha imprimido bien // false -> si no se imprime correctamente
    */
    bool printGame(std::ostream &os);
    
    /**
     * @brief Entrada de la imagen desde istream
     * @param is stream de entrada
     * @param Imagen a leer
     */
    friend std::istream& operator>> (std::istream& is, Image& i);
    
    /**
     * @brief Salida de la imagen a ostream
     * @param os stream de salida
     * @param p Imagen a mostrar
     */
    friend std::ostream &operator<<(std::ostream &os, const Image &i);
    
};