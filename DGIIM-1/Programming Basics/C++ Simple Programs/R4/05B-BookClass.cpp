#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Libro{
	private:
		string autor, libro, editorial, ano;
	public:
		Libro(){
			autor="Autor desconocido";
			libro="Libro desconocido";
			editorial="Editorial desconocida";
			ano="Ano desconocido";
		}
		
		void SetAutor(string autor_value){
			autor=autor_value;
		}
		void SetLibro(string libro_value){
			libro=libro_value;
		}
		void SetEditorial(string editorial_value){
			editorial=editorial_value;
		}
		void SetAno(string ano_value){
			ano=ano_value;
		}
		
		void MostrarDatos(){
			cout << "\nTITULO: " << libro;
			cout << "\nAUTOR: " << autor;
			cout << "\nEDITORIAL: " << editorial;
			cout << "\nANIO: " << ano;
		}
		
		void CompareLibros(Libro libro2){
			bool mismo_libro, mismo_autor, mismo_edit, mismo_ano;
			
			mismo_libro = libro == libro2.libro;
			mismo_autor = autor == libro2.autor;
			mismo_edit = editorial == libro2.editorial;
			mismo_ano = ano == libro2.ano;
			
			if(mismo_libro && mismo_autor && mismo_edit && mismo_ano){
				cout << "\n\nLOS LIBROS SON IGUALES";
			}
			else{
				cout << "\n\nLOS LIBROS NO SON IGUALES";
			}
		}
		
		void EncontrarCampo(){
			char campo;
			cout << "\nInserte campo a mostrar de " << libro << "\n";
			cout << "A. Autor\n E. Editorial\n Y. Anio\n >>> ";
			cin >> campo;
			
			campo = toupper(campo);
			if(campo == 'A'){
				cout << "\nAUTOR: " << autor;
			}
			if(campo == 'E'){
				cout << "\nEDITORIAL: " << editorial;
			}
			if(campo == 'Y'){
				cout << "\nANIO: " <<ano;
			}
			if(campo != 'A' && campo != 'E' && campo != 'Y'){
				cout << "\nCaracter no encontrado";
			}	
		}
};

void LeerDatos(Libro& libro){
	string autor, titulo, editorial, ano;
	
	cout << "Inserte nombre autor: ";
	getline(cin, autor);
	libro.SetAutor(autor);
	cout << "Inserte nombre libro: ";
	getline(cin, titulo);
	libro.SetLibro(titulo);
	cout << "Inserte nombre editorial: ";
	getline(cin, editorial);
	libro.SetEditorial(editorial);
	cout << "Inserte anio publicacion: ";
	getline(cin, ano);
	libro.SetAno(ano);
}

int main(){
	Libro libro1, libro2;
	
	LeerDatos(libro1);
	libro1.MostrarDatos();
	
	cout << "\n";
	
	LeerDatos(libro2);
	libro2.MostrarDatos();
	
	libro1.CompareLibros(libro2);
	libro1.EncontrarCampo();
}

