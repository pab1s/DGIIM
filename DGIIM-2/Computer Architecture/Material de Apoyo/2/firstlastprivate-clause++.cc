#include <omp.h>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
	const int N = 7;

	int a[N], suma = 0;

	std::iota(a, a + N, 0);

	#pragma omp parallel for firstprivate(suma) lastprivate(suma)
	for (int i = 0; i < N; ++i)
	{
		int viejo = suma;
		suma = suma + a[i];
		#pragma omp critical
		std::cout << "\thebra " << omp_get_thread_num()
		          << ": suma += a[" << i << "] = " << viejo 
		          << " --> " << suma << std::endl;
	}

	std::cout << "fuera de \"parallel for firstprivate(suma)\" suma = " 
	          << suma << std::endl;
}
