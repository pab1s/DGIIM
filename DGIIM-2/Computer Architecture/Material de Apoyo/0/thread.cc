#include <omp.h>
#include <iostream>
#include <sstream>
#include <thread>

int main(void)
{
	#pragma omp parallel
	{
		std::stringstream oss;
		oss << "pthread:" << std::this_thread::get_id() 
		    << " openmp:" << omp_get_thread_num()
		    << " hello world!\n";
		std::cout << oss.str();
	}
}
