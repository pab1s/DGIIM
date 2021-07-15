#include <omp.h>
#include <sched.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <thread>

int main(void)
{
	#pragma omp parallel
	{
		std::stringstream oss;
		oss << "cpu:" << sched_getcpu()
		    << " pid:" << getpid()
		    << " pthread:" << std::this_thread::get_id() 
		    << " openmp:" << omp_get_thread_num()
		    << " hello world!\n";
		std::cout << oss.str();
	}
}