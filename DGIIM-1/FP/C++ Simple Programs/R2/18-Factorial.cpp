#include <iostream>

using namespace std;

int main ()	{
	
	int n, nfinal, exp, contador = 1;
	double x, xfinal;
	
	cout << "Introduzca un numero real: ";
	cin >> x;
	cout << "Introduzca un exponente para ese numero: ";
	cin >> exp;
	cout << "Ahora introduzca un numero del que quiera obtener su factorial: ";
	cin >> n;
	
	// Asigna los valores de x y n a otras variables para que los bucles nos den al final el resultado deseado
	xfinal = x;
	nfinal = n;
	
	// Realiza la potencia
	while (exp > contador) {
		xfinal = xfinal * x;
		contador++;
	}
	
	// En caso de que n sea 0, el factorial es 0
	if (n == 0)
		nfinal = 1;
	
	// Realiza el factorial
	else	{	
		while (n > 1)	{
			n--;
			nfinal = nfinal * n;
		}
	}
	
	cout << "El resultado de la potencia es: " << xfinal << endl;
	cout << "El factorial de n es: " << nfinal;
}
