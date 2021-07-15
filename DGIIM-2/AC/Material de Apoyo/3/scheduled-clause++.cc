#include <omp.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	int n = 200, a[n], chunk = 1, suma = 0;

	if (argc != 3)
		throw std::invalid_argument("necesito iteraciones y chunck");

	std::istringstream iss1(argv[1]);
	iss1 >> n;
	if(!iss1) 
		throw std::invalid_argument("número de iteraciones no válido");
	n = std::min(std::max(n , 1), 200); // [1, 200]

	std::istringstream iss2(argv[2]);
	iss2 >> chunk;
	if(!iss2 || chunk < 1) 
		throw std::invalid_argument("chunk no válido");

	std::iota(a, a + n, 0);

	#pragma omp parallel for schedule(dynamic,chunk) \
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
