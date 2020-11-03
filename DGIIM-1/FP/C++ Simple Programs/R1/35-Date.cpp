
#include <iostream> // inclusion de la libreria de E/S
#include <string>	// inclusion de la libreria string

using namespace std; // espacio de nombres estandar

struct TipoFecha{	// Declaramos la estructura fecha
    int dia;
    int mes;
    int ano;
};

TipoFecha fecha;		// Declaramos las distintas estructuras fecha que vamos a usar
TipoFecha sigfecha;
TipoFecha prevfecha;
TipoFecha copiafecha;

int main () {			// Función principal
	
	string frasebis = "";							// Lo usaremos para decir si es bisiesto o no en la salida de texto
	
	cout << "Introduzca el dia de la fecha: ";		// Entrada de variables
   	cin >> fecha.dia;
   	cout << "Introduzca el mes de la fecha: ";
   	cin >> fecha.mes;
   	cout << "Introduzca el año de la fecha: ";	   
	cin >> fecha.ano;

	sigfecha.dia = fecha.dia + 1;					// Operaciones para sumar y restar un dia
	sigfecha.mes = fecha.mes;
	sigfecha.ano = fecha.ano;
   
	prevfecha.dia = fecha.dia - 1;
	prevfecha.mes = fecha.mes;
	prevfecha.ano = fecha.ano;

	copiafecha = fecha;								// Copia de la estructura fecha
	
	bool bisiesto = fecha.ano % 4 == 0;				// Booleanas que declaran las condiciones necesarias para realizar el cambio de mes, año  y saber si es bisiesto

	bool sigmes = (fecha.dia > 30 && fecha.mes % 2 == 1 && fecha.mes < 8 && fecha.mes != 2) ||
                 (fecha.dia > 30 && fecha.mes % 2 == 0 && fecha.mes > 8 && fecha.mes < 13) ||
                 (fecha.dia > 29 && fecha.mes % 2 == 0 && fecha.mes < 8 && fecha.mes != 2) ||
                 (fecha.dia > 29 && fecha.mes % 2 == 1 && fecha.mes > 8 && fecha.mes < 13) ||
                 (fecha.dia > 27 && fecha.mes == 2 && bisiesto == 0) ||
                 (fecha.dia > 28 && fecha.mes == 2 && bisiesto == 1);             
	bool sigano = fecha.mes == 12;
   
	bool prevmes = (fecha.dia == 1);
	bool prevmes30 = (fecha.mes == 5) ||
				 (fecha.mes == 7) ||
				 (fecha.mes == 10)||
				 (fecha.mes == 12);			 
	bool prevmes31 = (fecha.mes == 2) ||
				 (fecha.mes == 4) ||
				 (fecha.mes == 6) ||
				 (fecha.mes == 8) ||
				 (fecha.mes == 9) ||
				 (fecha.mes == 11);
	bool prevfeb29 = (fecha.mes == 3 && bisiesto == 1);
	bool prevfeb28 = (fecha.mes == 3 && bisiesto == 0);
	bool prevano = (fecha.mes == 1);
	
   if (sigmes == 1)   {										// Realizan el cambio de dia, mes y año según las condiciones de los boolean
      
      sigfecha.dia = 1;
      sigfecha.mes = fecha.mes + 1;
      sigfecha.ano = fecha.ano;
         
      if (sigano == 1)   {
      	
         sigfecha.ano = sigfecha.ano + 1;
         sigfecha.mes = 1;  
      }
   }	

	if (prevmes == 1)	{
		
		prevfecha.mes = fecha.mes - 1;
		
		if (prevmes31 == 1)
			prevfecha.dia = 31;

		if (prevmes30 == 1)
			prevfecha.dia = 30;

		if (prevfeb29 == 1)
			prevfecha.dia = 29;

		if (prevfeb28 == 1)
			prevfecha.dia = 28;

		if (prevano == 1)	{
			prevfecha.ano = fecha.ano - 1;
			prevfecha.mes = 12;
			prevfecha.dia = 31;
		}
	}
	
	if (bisiesto == 0)							// Analiza si el año no es bisiesto para cambiar el string
		frasebis = "no ";

	cout << "\nDia introducido: " << fecha.dia << "/" << fecha.mes << "/" << fecha.ano << endl;									// Salida de resultados
	cout << "Copia del dia introducido: " << copiafecha.dia << "/" << copiafecha.mes << "/" << copiafecha.ano << endl;
	cout << "El ano de la fecha introducida " << frasebis << "es bisiesto." << endl;
	cout << "Siguiente dia: " << sigfecha.dia << "/" << sigfecha.mes << "/" << sigfecha.ano << endl;
	cout << "Dia anterior: " << prevfecha.dia << "/" << prevfecha.mes << "/" << prevfecha.ano << endl;
}
