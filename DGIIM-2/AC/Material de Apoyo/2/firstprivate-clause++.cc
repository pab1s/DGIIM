#include <omp.h>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
	const int N = 7;
	int suma = 0, a[N] = {0, 1, 2, 3, 4, 5, 6};

	#pragma omp parallel firstprivate(suma)
	{
		int viejo = suma;
		
		#pragma omp for
		for (unsigned i = 0; i < N; ++i)
		{
			suma = suma + a[i];
			#pragma omp critical
			std::cout << "\thebra " << omp_get_thread_num()
			          << ": suma += a[" << i << "] = " << viejo 
			          << " --> " << suma << std::endl;
		}
	}

	std::cout << "fuera de \"parallel for firstprivate(suma)\" suma = " 
	          << suma << std::endl;
}
