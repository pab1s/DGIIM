#include <omp.h>
#include <iostream>
#include <iterator>

int main()
{
	const int N = 9;
	int b[N];

	std::fill(b, b + N, -1);

	#pragma omp parallel
	{
		int a;

		#pragma omp single copyprivate(a)
		{
			std::cout << "introduce a: ";
			std::cin >> a;
			std::cout << "\"single\" ejecutado por la hebra " 
			          << omp_get_thread_num() << std::endl;
		}

		#pragma omp for
		for (int i = 0; i < N; ++i)
			b[i] = a;
	}

	std::cout << "después de \"parallel\" b = ";
	std::copy(b, b + N, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
