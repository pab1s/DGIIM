#include <iostream>
#include <cmath>
using namespace std;

struct TipoPunto{
	double abscisa;
	double ordenada;
};

struct TipoPoligono{
	TipoPunto puntos[100];
	int num_puntos;
};

//Calcula distancia entre 2 puntos
double DistanciaPuntos(TipoPunto punto1, TipoPunto punto2){
	double difX, difY;
	double distancia;
	
	difX = abs((punto1.abscisa - punto2.abscisa));
	difY = abs((punto1.ordenada - punto2.ordenada));

	distancia = sqrt(pow(difX, 2) + pow(difY, 2));
	
	return distancia;
}

//Calcula el area de un triángulo dados sus puntos
double AreaTriangulo( TipoPunto punto1, TipoPunto punto2, TipoPunto punto3){
	double s1, s2, s3;
	double f;
	double area;
	
	s1 = DistanciaPuntos(punto1, punto2);
	s2 = DistanciaPuntos(punto2, punto3);
	s3 = DistanciaPuntos(punto3, punto1);
	f = (s1+s2+s3)/2;
	
	area = sqrt(f*(f-s1)*(f-s2)*(f-s3));
	
	return area;
}

//Calcula el area de cualquier polígono
double AreaPoligono(TipoPoligono poligono){
 	
    double resultado;
    
 	// Calcula el area de cada parte del polígono
    if (poligono.num_puntos == 3){
        resultado = AreaTriangulo(poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]);
    } 
	
	else {	
        TipoPoligono T1 = {{poligono.puntos[0], poligono.puntos[1], poligono.puntos[2]}, 3};
        TipoPoligono B;
        
        int j = 0;
        
        for (int i = 0; i < poligono.num_puntos; i++){
            if (i != 1){
                B.puntos[j] = poligono.puntos[i];
                j++;
            }
        }
        
        B.num_puntos = j;
        
        resultado = AreaPoligono(T1) + AreaPoligono(B);
    }
    
    return resultado;
}


int main(){

	TipoPoligono poligono;
	double area;

	do{
		cout << "Introduce el numero de lados del poligono: ";
		cin >> poligono.num_puntos;
	}while(poligono.num_puntos<3);

	for (int i=0; i<poligono.num_puntos; i++){
		cout << "Introduce las coordenadas del vertice numero " << i+1 << ": ";
		cin >> poligono.puntos[i].abscisa >> poligono.puntos[i].ordenada;
	}

	area = AreaPoligono(poligono);

	cout << "El area es " << area;
}

