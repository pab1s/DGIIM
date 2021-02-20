#include "../include/ruta.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

 


int main(int argc, char * argv[]){
  if (argc!=2){
    cout<<"Introduce el nombre del fichero de entrada"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No se pudo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  
  Ruta R;
  f >> R; //leemos las rutas y los puntos de interes
  
  cout << "La ruta introducida es: " << endl;
  cout << R;
  
  
}
  