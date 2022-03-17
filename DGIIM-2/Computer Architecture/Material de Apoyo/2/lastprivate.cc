#include <omp.h>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

int main()
{
	const int N = 7;
	
	int a[N], v;
	
	std::iota(a, a + N, 1);
	
	auto t0 = std::chrono::system_clock::now();
	
	#pragma omp parallel for lastprivate(v)
	for (int i = 0; i < N; ++i)
	{
		std::chrono::duration<float, std::milli> d = 
			std::chrono::system_clock::now() - t0;
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(3) 
		    << "hebra " << omp_get_thread_num() 
		    << "\t in:" << std::setw(4) << d.count()
		    << "ms v = " << std::setw(11) << v;
		
		v = a[i];
		
		d = std::chrono::system_clock::now() - t0;
		oss << " --> out:" << std::setw(4) << d.count() << "ms v = " << v << "\n";
		std::cout << oss.str();
	}
	
	std::cout << "fuera de \"parallel for lastprivate(v)\" v = " << v << std::endl;
}
