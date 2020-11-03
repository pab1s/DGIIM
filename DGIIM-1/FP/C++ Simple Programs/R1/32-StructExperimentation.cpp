
#include<iostream> // inclusion de la libreria de E/S
#include<string> // inclusion de la libreria para tratamiento de cadenas de car.

using namespace std; // espacio de nombres estandar

// definicion de la estructura
struct CuentaCD {
   double saldo;
   double tasa_de_interes;
   int plazo;
   char inicial1;
   char inicial2;
};

CuentaCD cuenta;

int main () {
   
   //APARTADO A: se trata de un valor real definida en la estructura CuentaCD
   
   cuenta.saldo;
   
   //APARTADO B: se trata de otro valor de tipo real tambi�n definido en la estructura CuentaCD
   
   cuenta.tasa_de_interes;
   
   //APARTADO C: en este caso, CuentaCD es una estructura a la que no se le ha asignado un nombre, por lo que no est� declarada
   
   //CuentaCD.plazo;
   
   //APARTADO D: cuenta_ahorros no es una estructura declarada, por lo que no se puede emplear
   
   //cuenta_ahorros.inicial1;
   
   //APARTADO E: se trata de un caracter declarado en la estructura, por lo que no da ning�n error
   
   cuenta.inicial2;
   
   //APARTADO F: es una estructura que est� siendo declarada en el programa
   
   cuenta;
}
