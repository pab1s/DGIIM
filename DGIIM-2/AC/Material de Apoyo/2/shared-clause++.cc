#include <omp.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

int main()
{
	const int N = 7;

	int a[N];
	std::iota(a, a + N, 1);

	#pragma omp parallel for shared(a)
	for (int i = 0; i < N; ++i)
		a[i] += i; 

	std::cout << "después de \"#pragma omp parallel for shared(a)\" a = ";
	std::copy(a, a + N, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
