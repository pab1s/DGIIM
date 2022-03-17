#include <omp.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	double intervalos, suma = 0;

	if (argc != 2)
		throw std::invalid_argument("necesito el número de intervalos");

	std::istringstream iss(argv[1]);
	iss >> intervalos;
	if(!iss) 
		throw std::invalid_argument("número de intervalos no válido");
	intervalos = std::max(1.0, intervalos);

	auto start = std::chrono::high_resolution_clock::now();
	double anchura = 1.0 / intervalos;
	for (double i = 0.5; i < intervalos; ++i)
	{
		double x = i * anchura;
		suma += 4.0 / (1.0 + x * x);
	}
	suma *= anchura;
	auto stop = std::chrono::high_resolution_clock::now();

	std::cout << "iteraciones: " << intervalos << std::endl
	          << "M_PIl: " << std::setprecision(99) << M_PIl << std::endl
	          << "pi   : " << std::setprecision(99) <<  suma << std::endl
	          << "tiempo: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;
}

