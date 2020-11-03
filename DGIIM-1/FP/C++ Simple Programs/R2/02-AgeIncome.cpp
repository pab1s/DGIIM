
#include <iostream>

using namespace std;

int main ()	{									//Función principal
	
	int edad;									//Variables a usar
	double ingresos;
	char opcion;
	
	cout << "Introduzca su edad: ";				//Entrada de datos
	cin >> edad;
	cout << "Introduzca sus ingresos: ";
	cin >> ingresos;
	cout << "Introduzca el metodo que desee emplear (a, b o c): ";
	cin >> opcion;
	
	if(opcion == 'a')	{							//Opción A
		cout << "\nMetodo A:\n";
		
		if((edad >= 65) && (ingresos < 300))	{			//Condicional que comprueba si se cumplen las condiciones
			ingresos = ingresos + (ingresos * 0.05);		//Cálculos
			
			cout << "El ingreso por ser jubilado ahora es de " << ingresos << " euros.";		//Salida de datos

			return 0;
		}
		
		else	{													//En caso de que no pueda realizarse, manda este mensaje
			cout << "No es aplicable una subida de ingresos.";		//Salida de datos
			
			return 0;
		}
	}
	
	if(opcion == 'b')	{							//Opción B
		cout << "\nMetodo B:\n";
		
		if(edad >= 65)	{			//Condicional que comprueba si se cumplen las condiciones
			if(ingresos < 300)	{
				ingresos = ingresos + (ingresos * 0.05);		//Cálculos
				
				cout << "Su nuevo ingreso por ser jubilado ahora es de " << ingresos << " euros.";		//Salida de datos
				
				return 0;
			}	
			
			else	{																								//En caso de que no pueda realizarse, manda este mensaje
				cout << "No es aplicable una subida de ingresos debido a que superan el maximo establecido.";		//Salida de datos
				
				return 0;
			}
		}
		
		else	{																			//En caso de que no pueda realizarse, manda este mensaje
			cout << "No es aplicable una subida de ingresos ya que no esta jubilado.";		//Salida de datos
			
			return 0;
		}
	}
	
	if(opcion == 'c')	{							//Opción C
		cout << "\nMetodo C:\n";
		
		if((edad >= 65) || (edad <= 35))	{			//Condicional que comprueba si se cumplen las condiciones
			if(ingresos < 300)	{
				ingresos = ingresos + (ingresos * 0.07);		//Cálculos
				
				cout << "Los ingresos son de " << ingresos << " euros.";		//Salida de datos
				
				return 0;
			}
			
			else	{															//En caso de ser jubilado o joven pero superar los 300€, hace esto
				ingresos = ingresos + (ingresos * 0.04);						//Cálculos
				
				cout << "Los ingresos son de " << ingresos << " euros.";		//Salida de datos
				
				return 0;
			}
		}
		
		else	{													//En caso de que no pueda realizarse, manda este mensaje
			cout << "No es aplicable una subida de ingresos.";		//Salida de datos
			
			return 0;
		}
	}
	
}
