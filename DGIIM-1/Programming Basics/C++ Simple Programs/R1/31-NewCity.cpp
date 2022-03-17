
#include<iostream> // inclusion de la libreria de E/S
#include<string> // inclusion de la libreria para tratamiento de cadenas de car.

using namespace std; // espacio de nombres estandar


struct TipoPunto{		// definicion de la estructura que representa a una localización
    double abscisa;
    double ordenada;
};

struct TipoCiudad{		// definicion de la estructura que representa a una ciudad
   TipoPunto situacion;
   string nombre;
};

int main () {

   TipoCiudad ciudad1;		// Declaramos las distintas estructuras de ciudad
   TipoCiudad ciudad2;
   TipoCiudad ciudadnueva;
   
   cout << "Introduzca el nombre de la primera ciudad: ";						// Introducción de datos
   cin >> ciudad1.nombre;
   cout << "Introduzca la coordenada de abscisas de la primera ciudad: ";
   cin >> ciudad1.situacion.abscisa;
   cout << "Introduzca la coordenada de ordenadas de la primera ciudad: ";
   cin >> ciudad1.situacion.ordenada;
   
   cout << "\nIntroduzca el nombre de la segunda ciudad: ";
   cin >> ciudad2.nombre;
   cout << "Introduzca la coordenada de abscisas de la segunda ciudad: ";
   cin >> ciudad2.situacion.abscisa;
   cout << "Introduzca la coordenada de ordenadas de la segunda ciudad: ";
   cin >> ciudad2.situacion.ordenada;
   
   ciudadnueva.nombre = ciudad1.nombre + ciudad2.nombre;											// Operaciones para calcular la nueva ciudad
   ciudadnueva.situacion.abscisa = ciudad1.situacion.abscisa * ciudad2.situacion.abscisa;
   ciudadnueva.situacion.ordenada = ciudad1.situacion.ordenada * ciudad2.situacion.ordenada;
   
   cout << "\nNombre de la nueva ciudad: " << ciudadnueva.nombre << endl;																		//Salida de datos
   cout << "La localizacion de la nueva ciudad es: (" << ciudadnueva.situacion.abscisa << ", " << ciudadnueva.situacion.ordenada << ").";
}
