#include <iostream>
using namespace std;

class Complejo{
	private:
		double real;
		double imaginario;
	public:
		void Mostrar(string nombre){
			cout << "\n" << nombre << ": " << real << " + " << imaginario << "i";			
		}
		
		//Constructor
		Complejo (double a, double b){
			real = a;
			imaginario = b;
		}
		
		Complejo(){
			real = 1;
			imaginario = 1;
		}
		
		//Suma
		Complejo operator + (Complejo complejo2){
			Complejo resultado;
			
			resultado.real = real + complejo2.real;
			resultado.imaginario = imaginario + complejo2.imaginario;
			
			return resultado;
		}
		
		//Resta
		Complejo operator - (Complejo complejo2){
			Complejo resultado;
			
			resultado.real = real - complejo2.real;
			resultado.imaginario = imaginario - complejo2.imaginario;
			
			return resultado;
		}
		
		//Producto
		Complejo operator * (Complejo complejo2){
			Complejo resultado;
			
			resultado.real = (real * complejo2.real) - (imaginario*complejo2.imaginario);
			resultado.imaginario = (real*complejo2.imaginario) + (imaginario*complejo2.real) ;
			
			return resultado;
		}
		
		//Datos
		void SetComplejo(){
			cout << "\nIntroduce un nuevo valor para la parte real del complejo: ";
			cin >> real;
			cout << "\nIntroduce un nuevo valor para la parte real del complejo: ";
			cin >> imaginario;
			cout << "\n";
		}
		
		double GetReal(){
			return real;
		}
		
		double GetImaginario(){
			return imaginario;
		}
};

//Pregunta si desea cambiar el primer complejo
bool CambiarDatos(){
	char respuesta;
	bool decision = true;	
	
	do{
		cout << "\nDeseas cambiar el complejo 1? (s/n): ";
		cin >> respuesta;
	}while(respuesta != 's' && respuesta != 'n');
	
	
	if (respuesta == 'n'){
		decision = false;
	}
	
	return decision;	
}

//Pregunta cual es el numero que quiere cambiar
int PedirNumero(){
	int resultado;
	
	do{
		cout << "\nQue numero deseas cambiar? (1/2): ";
		cin >> resultado;
	}while(resultado != 1 && resultado != 2);
	
	return resultado;	
}

int main(){
	Complejo complejo1{1,1};
	Complejo complejo2{2,2};
	Complejo suma, resta, producto;
	double real, imaginario;
	bool decision;
	int numeroCambiar;
	
	complejo1.Mostrar("Complejo 1");
	complejo2.Mostrar("Complejo 2");
	
	cout << "\n--------------------";
	
	decision = CambiarDatos();
	
	//Si quiere cambiar algun numero, pide datos, lo cambia y muestra los datos actualizados
	if (decision){
		numeroCambiar = PedirNumero();
		if(numeroCambiar == 1){
			complejo1.SetComplejo();
		}
		else{
			complejo2.SetComplejo();
		}
		
		complejo1.Mostrar("Complejo 1");
		complejo2.Mostrar("Complejo 2");
	}
	
	//Hago operaciones
	suma = complejo1+complejo2;
	resta = complejo1-complejo2;
	producto = complejo1*complejo2;
	
	//Muestro resultados
	suma.Mostrar("Suma");
	resta.Mostrar("Resta");
	producto.Mostrar("Producto");
	
	cout << "\nLa partes reales son: " << complejo1.GetReal() << " y " << complejo2.GetReal();
	cout << "\nLa partes imaginarias son: " << complejo1.GetImaginario() << " y " << complejo2.GetImaginario();	
}

