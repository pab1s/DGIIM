#include <iostream>
#include <vector>

using namespace std;

const int MAX_LONG = 100;

class Liga{
    private:
        vector<vector<char>> partidos;
    public:
        Liga();
        Liga(int num_equipos);
        void NuevoResultado(int equipo1, int equipo2, char resultado);
        vector<int> CalcularPuntuaciones();
};

class GeneradorLiga{
    public:
        Liga Lee();
};

void ImprimeResultados(vector<int> v);

int main(){
	GeneradorLiga generador;
    Liga liga = generador.Lee();
    
    vector<int> puntuaciones = liga.CalcularPuntuaciones();
    ImprimeResultados(puntuaciones);
    
	return 0;
}

// Vectores
Liga::Liga(){}

Liga::Liga(int num_equipos){
    partidos.resize(num_equipos);
    for (int i = 0; i < partidos.size(); i++){
        partidos[i].resize(num_equipos);
    } 
}

void Liga::NuevoResultado(int equipo1, int equipo2, char resultado){
    if (equipo1 < partidos.size() && equipo2 < partidos.size()){
        partidos[equipo1][equipo2] = resultado;
    }
}

vector<int> Liga::CalcularPuntuaciones(){
    vector<int> puntos(partidos.size(), 0);
    
    for (int i = 0; i < partidos.size(); i++){
        for (int j = 0; j < partidos[i].size(); j++){
            if (i != j){
                if (partidos[i][j] == '1'){
                    puntos[i] += 3;
                } else if (partidos[i][j] == '2'){
                    puntos[j] += 3;
                } else {
                    puntos[i] += 1;
                    puntos[j] += 1;
                }
            }
        }
    }
    
    return puntos;
}


Liga GeneradorLiga::Lee(){
    int num_equipos, equipo1, equipo2;
    char result;
    cin >> num_equipos;
    Liga liga(num_equipos);
    
    int partidos = num_equipos * (num_equipos - 1);
    
    for (int i = 0; i < partidos; i++){
        cin >> equipo1;
        cin >> equipo2;
        cin >> result;
        liga.NuevoResultado(equipo1, equipo2, result);
    }
    
    return liga;
}

void ImprimeResultados(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << "El equipo " << i+1 << " tiene " << v[i] << " puntos." << endl;
    }
}
