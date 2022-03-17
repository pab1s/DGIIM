#include <iomanip>
#include <iostream>
#include <chrono>
#include <random>

template<class R> void f(R r = R())
{
	typename R::result_type t = 0;
	
	for (int i = 0; i < 1000000; ++i)
		t ^= r();
	
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; ++i)
		t ^= r();
	auto stop = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double, std::milli> d = (stop - start);
	std::cout << "time = " << std::fixed << std::setprecision(2) << std::setw(6) 
	          << d.count() << "us\t value = " <<  std::setw(19) << t << std::endl;
}

int main()
{
	f<std::default_random_engine>();
	f<std::minstd_rand0         >();
	f<std::minstd_rand          >();
	f<std::mt19937              >();
	f<std::mt19937_64           >();
	f<std::ranlux24_base        >();
	f<std::ranlux48_base        >();
	f<std::ranlux24             >();
	f<std::ranlux48             >();
	f<std::knuth_b              >();
}
