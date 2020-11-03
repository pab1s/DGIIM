
#include <iostream>						//Inclusi�n de librer�a de recursos I/O.
#include <cmath>							//Inclusi�n de librer�a de recursos matem�ticos.

using namespace std;

int main()	{
	
	char autonomo, pensionista, civil;																	// Declaraci�n de variables
	double RentaBruta, RentaNeta, Retencion;
	bool trabajador_normal, es_autonomo, es_pensionista;
	bool es_soltero, rentabaja, rentaalta;
	
	cout << "Introduzca su renta bruta en euros: ";														//Entrada de datos
	cin >> RentaBruta;
	cout << "Introduzca su antigua retencion (en %): ";
	cin >> Retencion;
	cout << "\nEs usted autonomo? (S [si] o N [no]): ";
	cin >> autonomo;
	cout << "Es usted pensionista? (S [si] o N [no]): ";
	cin >> pensionista;
	cout << "Cual es su estado civil? (C [casado] o S [soltero u otros]): ";
	cin >> civil;
	
	trabajador_normal = (autonomo == 'N') && (pensionista == 'N');										// Declara las condiciones de los booleans
	rentabaja = (RentaBruta < 20000);
	rentaalta = (RentaBruta >= 20000);
	es_autonomo = (autonomo == 'S');
	es_pensionista = (pensionista == 'S');
	es_soltero = (civil == 'S');
	
	Retencion = (Retencion / 100.0);																	//Pide la retencion inicial
	
	if(trabajador_normal)	{																			//En caso de ser un trabajador normal, aplicar� su subida de retenci�n

		Retencion = Retencion + Retencion * 0.02;
		
		if(rentabaja)																					// La retenci�n subir� dependiendo de las condiciones establecidas
			Retencion = Retencion + Retencion * 0.06;
		
		if(rentaalta && (es_soltero == 0))
			Retencion = Retencion + Retencion * 0.10;
		
		if(rentaalta && es_soltero)
			Retencion = Retencion + Retencion * 0.08;
	}
	
	else	{
		if(es_autonomo)																					// Si es autonomo, aplica su correspondiente bajada
			Retencion = Retencion - Retencion * 0.03;
		
		else
		{
			if(es_pensionista)																			// Si es pensionista, aplica su correspondiente bajada
				Retencion = Retencion + Retencion * 0.01;
		}
	}
	
	RentaNeta = RentaBruta - RentaBruta * Retencion;													// C�lculo
	
	cout << "\nSu renta neta es de " << RentaNeta << " euros.";											//Salida de datos
	cout << "\nLa renta bruta introducida es de " << RentaBruta << " euros.";
	cout << "\nLa retencion total aplicada es del " << (Retencion * 100) << " %."; 	
}
