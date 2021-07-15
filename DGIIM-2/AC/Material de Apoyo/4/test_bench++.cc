#include <chrono>
#include <iomanip>
#include <iostream>

int suma_prod(int a, int b, int n)
{
	return a * b + n;
}

int main()
{
	const int A = 1, B = 2, N = 6000;
	
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 1; i <= 10000; ++i)
		std::cout << "suma_prod(" << A << ", " << B << ", " << N << ") = " 
		          << suma_prod(A, B, N) << std::endl;

	auto stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> t = (stop - start);

	std::cout << "tiempo: " 
	          << std::fixed << std::setprecision(2) << t.count()
	          << "ms" << std::endl;
}
