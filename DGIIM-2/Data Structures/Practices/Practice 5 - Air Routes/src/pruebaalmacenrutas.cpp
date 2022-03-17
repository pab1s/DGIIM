#include "../include/almacenrutas.h"
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
  
  AlmacenRutas AR;
  f >> AR; //leemos las rutas y los puntos de interes
  cout << "Almacen de rutas leido correctamente" << endl;

  list<Ruta> aux = AR.getLista();

  Ruta r;
  string id;

  cout << "Introduce el identificador de una ruta: " << endl;
  cin >> id;

  r = AR.GetRuta(id);
  cout << "La ruta " << id << " es: " << endl << r << endl;
 
  
  cout << "El almacen de rutas introducido es: " << endl;
  cout << AR << endl;
  
  
}
  