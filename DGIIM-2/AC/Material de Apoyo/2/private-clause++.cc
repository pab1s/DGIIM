#include <omp.h>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
	const int N = 7;
	int a[N], suma;

	std::iota(a, a + N, 0);

	#pragma omp parallel private(suma)
	{
		suma = 0;

		#pragma omp for
		for (int i = 0; i < N; ++i)
		{
			suma += a[i];
			#pragma omp critical
			std::cout << "\thebra " << omp_get_thread_num() 
			          << ": suma += a[" << i << "] = " << a[i] << std::endl;
		}

		#pragma omp critical
		std::cout << "* hebra " << omp_get_thread_num() 
		          << " suma = " << suma << std::endl;
	}
}
