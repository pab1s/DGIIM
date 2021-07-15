#include <chrono>
#include <iomanip>
#include <iostream>

int suma_prod(int a, int b, int n)
{
	return a * b + n;
}

int main(int argc, char **argv)
{
	int A = argc, B = 2, N = 6000;
	int C = 0;
	
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 1; i <= 10000; ++i)
		C += suma_prod(A, B, N);

	auto stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::nano> t = (stop - start);

	std::cout << "tiempo: " 
	          << std::fixed << std::setprecision(2) << t.count()
	          << "ns" << std::endl;

	return C;
}
