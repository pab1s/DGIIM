#include <iostream>

using namespace std;

void Accion();

class Examen {
	
	private:
		
		static const int MAX = 100;
		int contador = 0;
		
		string asignatura;
		string pregunta[MAX];
		char solucion[MAX],
			 respuesta[MAX];
			 
	public:
		
		Examen(){}
		
		void SetAsignatura(string asign){
			asignatura = asign;
		}
		
		void SetExamen (string quest, char ans) {
			
			solucion[contador] = ans;
			pregunta[contador] = quest;
		}
		
		void NuevaPregunta () {
			
			string question;
			char answer;
			
			cout << "Introduzca la PREGUNTA " << contador+1 << ":";
			cin >> question;
			cout << "Introduzca la RESPUESTA " << contador+1 << " (a/b/c/d):";
			cin >> answer;
			
			SetExamen(question, answer);
			contador++;
			
			Accion();
		}
		
		void NumPreguntas () {
			
			cout << "El numero de preguntas actualmente es de " << contador << " preguntas." << endl;
			Accion();
		}
		
		void GetEnunciado (int num) {
			cout << "Enunciado pregunta " << num << ": " << pregunta[num-1] << endl;
			Accion();
		}
		
		void GetRespuesta (int num) {
			cout << "Solucion pregunta " << num << ": " << solucion[num-1] << endl;
			Accion();
		}
		
		void RealizarExamen () {
			
			char respuesta;
			double nota = 0;
			
			for (int i = 0; i < contador; i++) {
				
				cout << "Pregunta " << i+1 << ": " << pregunta[i] << endl;
				cout << "Respuesta (a/b/c/d o si no responde '#'): ";
				cin >> respuesta;
				
				if (respuesta == solucion[i])
					nota++;
				else if (respuesta != solucion[i] && solucion[i] != '#')
					nota--;
			}
			
			nota = nota / contador * 10;
			
			if (nota < 0)
				nota = 0;
			
			cout << "La nota que has sacado es: " << nota;
		}
}Exam;

void Menu () {
	cout << "ELIJA LA OPCION QUE DESEA REALIZAR: " << endl;
	cout << "(1) ---> Aniadir pregunta y solucion. " << endl;
	cout << "(2) ---> Ver el numero de preguntas. " << endl;
	cout << "(3) ---> Ver pregunta k-esima. " << endl;
	cout << "(4) ---> Ver respuesta k-esima. " << endl;
	cout << "(5) ---> Comenzar examen. " << endl;
}

void Accion () {
	
	int opcion;
	int numero;
	
	do {
		cout << "Elija la opcion que desea realizar: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 5);
	
    switch (opcion)  {
	
	    case 1:
	        Exam.NuevaPregunta();
	        break;
	    case 2:
	    	Exam.NumPreguntas();
			break;
	    case 3:
	    	cout << "Introduzca el numero de la pregunta: ";
	    	cin >> numero;
	        Exam.GetEnunciado(numero);
	        break;
	    case 4:
	    	cout << "Introduzca el numero de la solucion: ";
	    	cin >> numero;
	        Exam.GetRespuesta(numero);
	        break;
	    case 5:
	        Exam.RealizarExamen();
	        break;
	    }
}

int main () {
	
	string asignatura;
	
	cout << "Inserte asignatura: ";
	cin >> asignatura;
	Exam.SetAsignatura(asignatura);
	
	Menu();
	Accion();
}
