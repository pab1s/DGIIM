#include <iostream>

using namespace std;

class Traccion {
	
	private:
		
		int estrella = 1;
		int pinion = 1;
		
	public:
		
		bool RoturaCadena (int star, int pin) {
			
			bool rotura = true;
			
			if (star == 1 && pin >= 5)
				rotura = false;
			if (star == 2 && (pin == 1 || pin == 7))
				rotura = false;
			if (star == 3 && pin <= 3)
				rotura = false;	
				
			return rotura;		
		}
		
		void CambioMarchas (char e, char p) {
			
				if (e == 'E') {
					
					if (p == 'S' && estrella < 7 && RoturaCadena((estrella+1), pinion))
						estrella++;
					if (p == 'B' && estrella > 1 && RoturaCadena((estrella-1), pinion))
						estrella--;	
				}
						
				if (e == 'P') {
					
					if (p == 'S' && pinion < 7 && RoturaCadena(estrella, (pinion+1)))
						pinion++;
					if (p == 'B' && pinion > 1 && RoturaCadena(estrella, (pinion-1)))
						pinion--;
					if (p == 'T' && pinion < 6 && RoturaCadena(estrella, (pinion+2)))
						pinion = pinion + 2;
					if (p == 'C' && pinion > 2 && RoturaCadena(estrella, (pinion-2)))
						pinion = pinion - 2;
				}
		}
		
		void SalidaDatos () {
			cout << "ESTRELLA: " << estrella << " PINION: " << pinion;
		}
};

int main () {
	
	Traccion TraccionBici;
	char engranaje, posicion;
	
	do {
		
		cin >> engranaje;
		
		if (engranaje != '#') {
			
			cin >> posicion;			
			
			TraccionBici.CambioMarchas(engranaje, posicion);
		}
		
	} while (engranaje != '#');
	
	TraccionBici.SalidaDatos ();
}
