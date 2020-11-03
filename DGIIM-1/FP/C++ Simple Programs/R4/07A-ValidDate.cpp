#include <iostream>
using namespace std;

int Fecha(int dia, int mes, int ano){
	
	bool bisiesto = ano % 4 == 0;         
   
	bool febrero = (mes == 2);
	bool mes30 = (mes == 4) ||
				 (mes == 6) ||
				 (mes == 9)||
				 (mes == 11);			 
	bool mes31 = (mes == 1) ||
				 (mes == 3) ||
				 (mes == 5) ||
				 (mes == 7) ||
				 (mes == 8) ||
				 (mes == 10) ||
				 (mes == 12);

	bool correcto = (ano >= 0) &&
					(bisiesto && febrero && dia < 30 && dia > 0) ||
					(febrero && dia < 29 && dia > 0) ||
					(mes30 && dia < 31 && dia > 0) ||
					(mes31 && dia < 32 && dia > 0);
	
	return correcto;
}

int main ()	{
	
	int dia, mes, ano;
	bool fecha_correcta;
	
	cout << "Introduzca el dia: ";
	cin >> dia;
	cout << "Introduzca el mes: ";
	cin >> mes;
	cout << "Introduzca el ano: ";
	cin >> ano;
	
	fecha_correcta = Fecha(dia, mes, ano);
	
	cout << fecha_correcta;
}
