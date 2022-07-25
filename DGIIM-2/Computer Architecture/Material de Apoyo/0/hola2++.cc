#include <omp.h>
#include <iostream>

int main()
{
	#pragma omp parallel
	{
		std::cout << omp_get_thread_num() << ": ¡hola!" << std::endl;
		std::cout << omp_get_thread_num() << ": ¡mundo!" << std::endl;
	}
}