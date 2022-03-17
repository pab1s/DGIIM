#include <omp.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[])
{
	if (argc != 2)
		throw std::invalid_argument("necesito el número de iteraciones");

	int n;
	std::istringstream iss(argv[1]);
	iss >> n;
	if(!iss) 
		throw std::invalid_argument("número de iteraciones no válido");

	n = std::min(std::max(n, 1), 20); // [1, 20]

	int a[n], suma = 0;

	std::iota(a, a + n, 0);

	#pragma omp parallel for reduction(+:suma)
	for (int i = 0; i < n; ++i)
		suma += a[i];

	std::cout << "tras \"parallel for reduction(+:suma)\" suma = " 
	          << suma << std::endl;
}
