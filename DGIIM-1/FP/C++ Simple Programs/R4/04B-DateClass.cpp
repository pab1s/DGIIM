//Programa que permite implementar una fecha
#include <iostream>
using namespace std;

//Clase que permite implementar una fecha
class Fecha {
	public:
		
		//Variables de la clase
		int dia;
		int mes;
		int year;
		
		
		
		//Metodo que verifica si la fecha es valida o no
		bool EsValida(){
	  		bool bisiesto;
	  		bisiesto = Bisiesto();
		  
		  //Comprobamos que la fecha es correcta
		  if(mes > 12 || mes < 1 || year < 1 || dia < 1 || dia > 31)
		    return false;
		  else if(!bisiesto && mes == 2 && dia > 28)
		    return false;
		  else if (!(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia == 31)
		    return false;
		  else if (mes == 2 && bisiesto && dia > 29)
		  	  return false;
		  else
		    return true;
		}
		
		//Funcion que suma un dia
		void DiaSiguiente() {
			
			//Comprobamos si el año es bisiesto
			bool bisiesto;
			bisiesto = Bisiesto();
			
			//Sumamos un dia
			dia++;
			
			//Arreglamos la fecha en caso de que no sea valida
			if((dia > 29 && mes == 2 && bisiesto) || (dia > 28 && mes == 2 && !bisiesto)){
				dia = 1;
				mes++;
			} 
			else if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31){
				mes++;
				dia = 1;
			}
			if(!(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 30){
				mes++;
				dia = 1;
			}
			if(mes == 13){
				year++;
				mes = 1;
			}	
		}
	
	//Funcion que calcula la fecha de antes	
		void DiaAnterior () {
			
			//Comprobamos si el año es bisiesto
			bool bisiesto;
			bisiesto = Bisiesto();
			
			//Restamos un dia
			dia--;
			
			//Arreglamos la fecha en caso de que no sea valida
			if(dia == 0){
				mes--;
				if(mes == 2 && bisiesto)
					dia = 29;
				else if(mes == 2 && !bisiesto)
					dia = 28;
				else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
					dia = 31;
				else if(!(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
					dia = 30;
				if(mes == 0){
					year--;
					mes = 12;
					dia = 31;
				}
			}
		}
	
	private:
		bool Bisiesto() {
	  
		  //Comprobamos si el año es bisiesto
		  if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		    return true;
		  else
		    return false;
		}
	
};

//Funcion que permite la entrada de una fecha
Fecha Entrada() {
	
	//Variable
	Fecha fecha;
	
	//Introducimos los datos
	cout << "Introduce un dia: ";
	cin >> fecha.dia;
	cout << "\nIntroduce un mes: ";
	cin >> fecha.mes;
	cout << "\nIntroduce un año: ";
	cin >> fecha.year;
	
	//Devolvemos
	return fecha;
}

//Probamos la clase y los metodos
int main() {
	Fecha fecha;
	Fecha aux;
	fecha = Entrada();
	aux = fecha;
	
		
	if(fecha.EsValida()){
		cout << endl << "La fecha es valida" << endl;
		fecha.DiaSiguiente();
		cout << "Dia siguiente: " << fecha.dia << "/" << fecha.mes << "/" << fecha.year;
		aux.DiaAnterior();
			cout << endl << "Dia anterior: " << aux.dia << "/" << aux.mes << "/" << aux.year;
	}
	
	else
		cout << endl << "Fecha no valida";
}
