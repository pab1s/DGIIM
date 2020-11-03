
#include <iostream>
#include <cmath>

using namespace std;

int main () {
   
   char operacion;      //Declara un carácter para ser detectado
   double solucion;     //Variable que va a dar la solucion de la operacion que realicemos
   
   cout << "Elija la operacion que desea realizar (a, b o c): ";
   cin >> operacion;
   
   //Pide que se introduzca un carácter que nos mandará a la operación deseada mediante la función 'if'
   //En cada apartado de 'if' están las variables que se usan específicamente en esa operación
   
   if (operacion == 'a') {       //Operación 'a'
      
      double x,y;
      
      cout << "Introduzca el valor de x: ";     //Entrada de variables
      cin >> x;
      cout << "Introduzca el valor en y: ";
      cin >> y;
      
      solucion = (1 + pow(x, 2) / y) / (pow(x, 3) / (1 + y));        //Cálculo
      
      cout << "La solucion de la operacion 'a' es: " << solucion;    //Salida de variables (la solución)
      return 0;
   }
   
   if (operacion == 'b') {       //Operación 'b'
      
      double h;
      
      cout << "Introduzca el valor de h: ";     //Entrada de variables
      cin >> h;
      
      solucion = (1 + 1.0 / 3.0 * sin(h) - 1.0 / 7.0 * cos(h)) / (2 * h);        //Cálculo
      
      cout << "La solucion de la operacion 'b' es: " << solucion;    //Salida de variables (la solución)
      return 0;
   }
   
   if (operacion == 'c') {       //Operación 'c'
   
      double x;
       
      cout << "Introduzca el valor de x: ";     //Entrada de variables
      cin >> x;
      
      solucion = sqrt(1 + pow((exp(x) / pow(x, 2)), 2));        //Cálculo
      
      cout << "La solucion de la operacion 'c' es: " << solucion;    //Salida de variables (la solución)
      return 0;
   }
   
   else {       //En caso de que el carácter introducida no sea ni a, ni b, ni c, nos aparecerá este mensaje;
      
      cout << "No ha introducido ninguna letra asociada a ninguna operacion.";    //Mensaje que comunica el error
      return 0;
   }
}
