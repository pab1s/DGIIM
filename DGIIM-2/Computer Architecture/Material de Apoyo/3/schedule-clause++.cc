#include <omp.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	const int n = 7;
	int a[n], chunk, suma = 0;

	if (argc != 2)
		throw std::invalid_argument("necesito el chunck");

	std::istringstream iss(argv[1]);
	iss >> chunk;
	if(!iss || chunk < 1) 
		throw std::invalid_argument("chunk no válido");

	std::iota(a, a + n, 0);

	#pragma omp parallel for schedule(static,chunk) \
		firstprivate(suma) lastprivate(suma)
	for (int i = 0; i < n; ++i)
	{
		suma += a[i];
		std::ostringstream oss;
		oss << "\t hebra: " << omp_get_thread_num()
		    << "\t a[" << i << "] = " << a[i]
		    << "\t suma = " << suma << std::endl;
		std::cout << oss.str();
	}

	std::cout << "suma = " << suma << std::endl;
}
