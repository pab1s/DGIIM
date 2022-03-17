#include <omp.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>

int main()
{
	const int N = 7;
	int a[N];

	std::iota(a, a + N, 0);

	#pragma omp parallel
	{
		int suma = 0;

		#pragma omp for
		for (int i = 0; i < N; ++i)
		{
			suma += a[i];
			
			std::ostringstream oss;
			oss << "\thebra " << omp_get_thread_num() 
			    << ": suma += (a[" << i << "] == " << a[i] << ")" << std::endl;
			std::cout << oss.str();
		}

		std::ostringstream oss;
		oss << "* hebra " << omp_get_thread_num() 
		    << " suma = " << suma << std::endl;
		std::cout <<  oss.str();
	}
}
