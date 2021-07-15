#include <omp.h>
#include <iostream>

int main()
{
	#pragma omp parallel
	std::cout << omp_get_thread_num() << ": ¡hola mundo!" << std::endl;
}
