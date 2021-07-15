#include <omp.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <string>

int main()
{
	const int N = 7;

	int a[N], v;

	std::iota(a, a + N, 1);

	auto zero = std::chrono::high_resolution_clock::now();

	#pragma omp parallel for lastprivate(v)
	for (int i = 0; i < N; ++i)
	{
		std::string msg = "hebra " + std::to_string(omp_get_thread_num()) +
		                  " in: " + std::to_string((std::chrono::high_resolution_clock::now() - zero).count()) +
		                  " v = " + std::to_string(v) + "\t";
		v = a[i];
		msg += " out: " + std::to_string((std::chrono::high_resolution_clock::now() - zero).count()) +
		       " v = " + std::to_string(v) + "\n";
		std::cout << msg;
	}

	std::cout << "fuera de \"parallel for lastprivate(v)\" v = " << v << std::endl;
}
