#include <omp.h>

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <random>

const size_t N = 1 << 23;

std::array<int, N> a, b, c;
int r;

void f1()
{
	for (size_t i = 0; i < N; ++i)
		r += a[i] * b[i] - c[i];
}

void f2()
{
	#pragma omp parallel for
	for (size_t i = 0; i < N; ++i)
		#pragma omp critical
		r += a[i] * b[i] - c[i];
}

void f3()
{
	#pragma omp parallel for
	for (size_t i = 0; i < N; ++i)
		#pragma omp atomic
		r += a[i] * b[i] - c[i];
}

void f4()
{
	#pragma omp parallel
	{
		int rp = 0;
		#pragma omp for
		for (size_t i = 0; i < N; ++i)
			rp += a[i] * b[i] - c[i];
		#pragma omp atomic
		r += rp;
	}
}

void f5()
{
	#pragma omp parallel for reduction(+:r)
	for (size_t i = 0; i < N; ++i)
		r += a[i] * b[i] - c[i];
}

template<class F> void test(F &f)
{
	std::default_random_engine engine(0);
	std::uniform_int_distribution<int> distribution;
	auto rng = std::bind(distribution, engine);
	
	std::generate(a.begin(), a.end(), rng);
	std::generate(b.begin(), b.end(), rng);
	std::generate(c.begin(), c.end(), rng);	
	r = 0;
	
	f();
	std::cout << "r = " << r << std::endl;
}

int main()
{
	test(f1);
	test(f2);
	test(f3);
	test(f4);
	test(f5);
}
