#include <iostream>

using namespace std;

class TresEnRaya{
	
	private:
		int tablero[3][3];

	public:
		
		bool hay_tres(){
			bool si = false;
			
			for(int i=0; i < 3; i++)
				for ( int j=0; j<3; j++)
					if ( tablero[i][j] == 1)
						si = true;
					else
						si = false;
						
			for(int j=0; j < 3; j++)
				for ( int i=0; i<3; i++)
					if ( tablero[i][j] == 1)
						si = true;
					else
						si = false;
						
			return si;
		}		
		
	void Jugar(){
		int tablero[3][3] = {0};
		int contador = 0;
	
		
		for ( int i = 0; i < 3; i++){
			for (int j=0; j < 3; j++){
				cout << tablero[i][j];
			}
		cout << "\n";
		}
		
		while ( contador != 9 && !hay_tres()){
			cout << "\nJugador 1: ";
			int filas, columnas;
			cin >> filas >> columnas;
			
			for ( int i = 0; i < 3; i++)
				for (int j=0; j < 3; j++)
					if ( i == filas && columnas == j )
					tablero[i][j] = 1;
			
			for ( int i = 0; i < 3; i++){
				for (int j=0; j < 3; j++){
					cout << tablero[i][j];
				}
				cout << "\n";
			}
	
			cout << "\nJugador 2: ";
			cin >> filas >> columnas;
				
			for ( int i = 0; i < 3; i++)
				for (int j=0; j < 3; j++)
					if ( i == filas && columnas == j )
						tablero[i][j] = 2;
				
			for ( int i = 0; i < 3; i++){
				for (int j=0; j < 3; j++){
					cout << tablero[i][j];
				}
				cout << "\n";
			}
			
			contador++;
		}
	}
};
		
int main(){
	
	TresEnRaya tres;

	tres.Jugar();			
}
