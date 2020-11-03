
#include <iostream>
#include <cmath>

using namespace std;

int main () {
   
   char operacion;      //Declara un car�cter para ser detectado
   double solucion;     //Variable que va a dar la solucion de la operacion que realicemos
   
   cout << "Elija la operacion que desea realizar (a, b o c): ";
   cin >> operacion;
   
   //Pide que se introduzca un car�cter que nos mandar� a la operaci�n deseada mediante la funci�n 'if'
   //En cada apartado de 'if' est�n las variables que se usan espec�ficamente en esa operaci�n
   
   if (operacion == 'a') {       //Operaci�n 'a'
      
      double x,y;
      
      cout << "Introduzca el valor de x: ";     //Entrada de variables
      cin >> x;
      cout << "Introduzca el valor en y: ";
      cin >> y;
      
      solucion = (1 + pow(x, 2) / y) / (pow(x, 3) / (1 + y));        //C�lculo
      
      cout << "La solucion de la operacion 'a' es: " << solucion;    //Salida de variables (la soluci�n)
      return 0;
   }
   
   if (operacion == 'b') {       //Operaci�n 'b'
      
      double h;
      
      cout << "Introduzca el valor de h: ";     //Entrada de variables
      cin >> h;
      
      solucion = (1 + 1.0 / 3.0 * sin(h) - 1.0 / 7.0 * cos(h)) / (2 * h);        //C�lculo
      
      cout << "La solucion de la operacion 'b' es: " << solucion;    //Salida de variables (la soluci�n)
      return 0;
   }
   
   if (operacion == 'c') {       //Operaci�n 'c'
   
      double x;
       
      cout << "Introduzca el valor de x: ";     //Entrada de variables
      cin >> x;
      
      solucion = sqrt(1 + pow((exp(x) / pow(x, 2)), 2));        //C�lculo
      
      cout << "La solucion de la operacion 'c' es: " << solucion;    //Salida de variables (la soluci�n)
      return 0;
   }
   
   else {       //En caso de que el car�cter introducida no sea ni a, ni b, ni c, nos aparecer� este mensaje;
      
      cout << "No ha introducido ninguna letra asociada a ninguna operacion.";    //Mensaje que comunica el error
      return 0;
   }
}
