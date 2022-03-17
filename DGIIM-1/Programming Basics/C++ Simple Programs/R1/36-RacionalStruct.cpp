#include <iostream>
#include <algorithm>

using namespace std;

int main () {
   
   //Apartado A: Introducir un racional
   int x1, x2, x3, y1, y2, y3, mcd1, mcd2;
   double resultadodecimal;
   
   cout << "Introduzca el numerador: ";
   cin >> x1;
   cout << "Introduzca el denominador: ";
   cin >> y1;
   
   cout << "El numero racional introducido es: " << x1 << "/" << y1;
   
   //Apartado B: Simplificar el racional
   
	mcd1 = __gcd (x1, y1);
	x1 = x1 / mcd1;
	y1 = y1 / mcd1;
	
   cout << "\nEl numero racional simplificado es: " << x1 << "/" << y1;  
   
   //Apartado C: Suma de dos racionales
   
   cout << "\nIntroduzca el numerador del segundo racional: ";
   cin >> x2;
   cout << "Introduzca el denominador del segundo racional: ";
   cin >> y2;
   
   cout << "El segundo numero racional introducido es: " << x2 << "/" << y2 << endl;
   
   x3 = x1 * y2 + y1 * x2;
   y3 = y1 * y2;
   
   	mcd2 = __gcd (x3, y3);
	x3 = x3 / mcd2;
	y3 = y3 / mcd2;
    
   cout << "La suma de ambos numeros racionales es: " << x3 << "/" << y3 << endl;
   
   //Apartado D: Producto de dos racionales
   
   x3 = x1 * x2;
   y3 = y1 * y2;
   
	mcd2 = __gcd (x3, y3);
	x3 = x3 / mcd2;
	y3 = y3 / mcd2;
    
   cout << "El producto de ambos numeros racionales es: " << x3 << "/" << y3 << endl;
   
   //Apartado E: Evaluar un número racional
   
   resultadodecimal = (double) x1 / (double) y1;
   
      cout << "El primer numero racional introducido es: " << resultadodecimal;
}
