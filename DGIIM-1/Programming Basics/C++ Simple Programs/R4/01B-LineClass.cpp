#include <iostream>

using namespace std;

class Recta {
    
    private:
    
    double A, B, C;
    
    public:
    
    //Asignación de valores
    void Asignar(double a, double b, double c) {
    	
    	A = a;
    	B = b;
    	C = c;
	}

    //Cálculo de la pendiente
    double Pendiente ()   {
       
       double pendiente = -A / B;
       return pendiente;  
    }
    
    //Cálculo de la abscisa
    double Abscisa (double y) {
       
       double abscisa = (-C -y*B) / A;
       return abscisa;
    }
    
    //Cálculo de la ordenada
    double Ordenada (double x) {
       
       double ordenada = (-C -x*A) / B;
       return ordenada;
    }
    
}recta1, recta2;

int main () {
   
   const string SEPARADOR = "\n*****************\n";
   double a1, b1, c1, a2, b2, c2, x1, y1;
   
   cout << "Introduza los valores de la recta segun su ecuacion general (Ax + By + C = 0): " << endl << endl;
   
   cout << "Recta 1: " << endl;
   cout << "Introduzca el valor de A: ";
   cin >> a1;
   cout << "Introduzca el valor de B: ";
   cin >> b1;
   cout << "Introduzca el valor de C: ";
   cin >> c1;
   
   cout << "\nRecta 2: " << endl;
   cout << "Introduzca el valor de A: ";
   cin >> a2;
   cout << "Introduzca el valor de B: ";
   cin >> b2;
   cout << "Introduzca el valor de C: ";
   cin >> c2;
   
   recta1.Asignar(a1, b1, c1);
   recta2.Asignar(a2, b2, c2);
   
   cout << SEPARADOR;
   cout << "PENDIENTES:";
   cout << SEPARADOR;
   cout << "La pendiente de la recta 1 es: " << recta1.Pendiente ();
   cout << "\nLa pendiente de la recta 2 es: " << recta2.Pendiente () << endl;
   
   cout << SEPARADOR;
   cout << "OBTENER ORDENADA:";
   cout << SEPARADOR;
   cout << "Introduzca un valor para la coordenada x de la recta 1: ";
   cin >> x1;
   cout << "El valor de la coordenada y en la recta 1 segun el x aportado es: " << recta1.Ordenada(x1) << endl;
   
   cout << SEPARADOR;
   cout << "OBTENER ABSCISA:";
   cout << SEPARADOR;
   cout << "Introduzca un valor para la coordenada y de la recta 1: ";
   cin >> y1;
   cout << "El valor de la coordenada x en la recta 1 segun el y aportado es: " << recta1.Abscisa(y1);  
}
