#include <mpi.h>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
	if (argc != 2)
		throw std::invalid_argument("necesito el número de intervalos");
	
	int intervalos;
	std::istringstream iss(argv[1]);
	iss >> intervalos;
	if(!iss) 
		throw std::invalid_argument("número de intervalos no válido");
	intervalos = std::max(1, intervalos);
	
	MPI::Init(argc, argv);
	
	int procesadores = MPI::COMM_WORLD.Get_size();
	int yo = MPI::COMM_WORLD.Get_rank();
	double suma = 0, suma_parcial = 0, anchura = 1.0 / intervalos, t;
	
	t = MPI::Wtime();
	
	for (int i = yo; i < intervalos; i += procesadores)
	{
		double x = (i + 0.5) * anchura;
		suma_parcial += 4.0 / (1.0 + x * x);
	}
	
	suma_parcial *= anchura;
	
	MPI::COMM_WORLD.Reduce(&suma_parcial, &suma, 1, MPI::DOUBLE, MPI::SUM, 0);
	
	MPI::Finalize();
	
	t = MPI::Wtime() - t;
	
	if (yo == 0)
		std::cout << "iteraciones: " << intervalos << std::endl
		          << "M_PIl: " << std::setprecision(99) << M_PIl << std::endl
		          << "pi   : " << std::setprecision(99) <<  suma << std::endl
		          << "procesadores: " << procesadores << std::endl
		          << "tiempo: " << t << "s" << std::endl;
}
