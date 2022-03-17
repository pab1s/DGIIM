
#include <iostream>
#include <cmath>

using namespace std;

int main () {
   
   double area, lado1, lado2, angulo;     //Declaración de variables
   const double PI = 3.14159265359;       //Declaración de constantes
   
   cout << "Introduzca la longitud de un lado del triangulo en centimetros: ";      //Introducción de variables
   cin >> lado1;
   cout << "Introduzca la longitud de otro de sus lados tambien en centimetros: ";
   cin >> lado2;
   cout << "Introduzca el angulo que forman los dos lados en grados: ";
   cin >> angulo;
   
   angulo = angulo * PI / 180;                     //Cálculos
   area = 0.5 * lado1 * lado2 * sin(angulo);
   
   cout << "El area del triangulo es de " << area << " cm2.";     //Salida del resultado
}
