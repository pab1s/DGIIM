#include <cassert>
#include <string>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

void zoom(Imagen& img, int x_1, int y_1, int x_2, int y_2);
/*Imagen contrast(int min, int max, std::ofstream & ofile, std::ifstream & ifile);
void morphing(ifstream bfile, ifstream efile, ofstream ifiles);*/

int main() {
    string ifile="./examples/llave.pgm", ofile="./examples/solution.pgm";

    Imagen prueba;
    prueba.read(ifile.c_str());
    
    //morphing(prueba_A, prueba_B, med);
    zoom(prueba, 5,5, 100,100);
    prueba.print(ofile.c_str());
}

/**
	 * @brief Funcion que genera una nueva imagen a partir del criterio del ejercicio 2 de la practica
	 * @return Imagen que resulta al aplicar la funcion a la imagen de entrada
     * @param img Imagen que queremos cambiar
**/
Imagen autoThreshold(Imagen & img) {
    int threshold;

}

/**
 * @brief Funcion que genera una nueva imagen aumento de una sección rectangular
 * de la imagen proporcionada.
 * @param os flujo de entrada de la imagen
 * @param is flujo de salida de la imagen
 * @param x_1 coordenada x de la matriz donde empieza la sección rectangular
 * @param y_1 coordenada y de la matriz donde empieza la sección rectangular
 * @param x_2 coordenada x de la matriz donde finaliza la sección rectangular
 * @param y_2 coordenada y de la matriz donde finaliza la sección rectangular
 */
void zoom(Imagen& img, int x_1, int y_1, int x_2, int y_2) {
    assert(x_1<=x_2 && y_1<=y_2);

    int orig_nfil = x_2-x_1 + 1,
        orig_ncol = y_2-y_1 + 1,
        nfil = 2*orig_nfil-1,
        ncol = 2*orig_ncol-1;

    Imagen aux(nfil, ncol);

    //Copia la matriz en sus nuevas posiciones
    for (int i = 0; i < orig_nfil; i++)
        for (int j = 0; j < orig_ncol; j++)
            aux.asigna_pixel(2*i,2*j,img.valor_pixel(i+x_1, j+y_1));

    //Interpola las columnas
    for (int i = 0; i < nfil; i+=2)
        for (int j = 1; j < ncol; j+=2)
           aux.asigna_pixel(i, j, 
           (aux.valor_pixel(i,j-1) + aux.valor_pixel(i,j+1)) / 2);

    //Interpola las filas
    for (int i = 1; i < nfil; i=2*i-1)
        for (int j = 0; j < ncol; j++)
           aux.asigna_pixel(i, j, 
           (aux.valor_pixel(i-1,j) + aux.valor_pixel(i+1,j)) / 2);

    img = aux;           
}

/**
	 * @brief Funcion que genera una nueva imagen contrastad a partir del criterio del ejercicio 5 de la practica
	 * @return Imagen que resulta al aplicar la funcion a la imagen de entrada
     * @param os Fichero de salida
     * @param is Fichero de entrada
     * @param min Nuevo nivel de gris minimo en la nueva escala
     * @param max Nuevo nivel de gris maximo en la nueva escala
*/
/*Imagen contrast(int min, int max, std::ostream & os, std::istream & is){
    Imagen result(img.num_filas(), img.num_columnas());
    double razon = (max - min)/(255 - 0); //suponemos que el maximo y minimo de la imagen a cambiar siempre son 255 y 0
    double aux;
    byte valornew;

    for(int i=0; i<img.num_filas(); i++){
        for (int j=0; j<img.num_columnas(); j++){
            aux = min + (razon * (img.valor_pixel(i,j) - 0));
            valornew = aux/1;
            result.asigna_pixel(i, j, valornew);
        }
    }
    
}*/

/*void morphing(const char* bfile, const char* efile, const char* ifiles) {
    Imagen img_A, img_B, aux;
    int range = 0;
    aux = img_A;

    for(int i=0; i<img_A.num_filas(); i++) {
        for (int j=0; j<img_A.num_columnas(); j++) {
            range = 
            abs(img_A.valor_pixel(i,j) - img_B.valor_pixel(i,j)) ? 
            abs(img_A.valor_pixel(i,j) - img_B.valor_pixel(i,j)) : range;
        }
    }

    for (int i=0; i<=range; i++) {
        for(int j=0; j<aux.num_filas(); j++)
            for (int k=0; k<aux.num_columnas(); k++) {
                if (aux.valor_pixel(j,k) > img_B.valor_pixel(i,j))
                    aux.asigna_pixel(j,k,aux.valor_pixel(j,k)-1);
                else if (aux.valor_pixel(j,k) < img_B.valor_pixel(i,j))
                    aux.asigna_pixel(j,k,aux.valor_pixel(j,k)+1);
            }
        aux.print("./examples/morphing/"+i+".pgm");
    }
}*/