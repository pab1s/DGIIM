#include <omp.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	int n = 20, a[n], suma = 0;

	if (argc != 2)
		throw std::invalid_argument("necesito iteraciones");

	std::istringstream iss(argv[1]);
	iss >> n;
	if(!iss) 
		throw std::invalid_argument("número de iteraciones no válido");
	n = std::min(std::max(n , 1), 20); // [1, 20]

	std::iota(a, a + n, 0);

	#pragma omp parallel for schedule(runtime) \
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
