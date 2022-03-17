#include <cmath>
#include <iomanip>
#include <iostream>
#include <benchmark/benchmark.h>
#include <omp.h>

const int N = 25;
const int intervalos = 1 << N;
const double precision = 1.0 / std::pow(10.0, N / 3);

void check(double pi)
{
	if (std::abs(pi - M_PI) > precision)
	{
		std::cout << "intervalos: " << intervalos << std::endl
		          << "pi        : " << std::setprecision(99) << pi << std::endl
		          << "M_PIl     : " << std::setprecision(99) << M_PIl << std::endl
		          << "diferencia: " << std::abs(pi - M_PIl) << std::endl;
		exit(1);
	}
}

static void pi(benchmark::State& state)
{
	double suma = 0;
	for (auto _ : state)
	{
		double anchura = 1.0 / intervalos;
		suma = 0;
		for (double i = 0.5; i < intervalos; ++i)
		{
			double x = i * anchura;
			suma += 4.0 / (1.0 + x * x);
		}
		suma *= anchura;
	}
	check(suma);
}

static void opi(benchmark::State& state)
{
	double suma = 0;
	for (auto _ : state)
	{
		double anchura = 1.0 / intervalos;
		suma = 0;
		#pragma omp parallel for reduction(+:suma)
		for (int i = 0; i < intervalos; ++i)
		{
			double x = (i + 0.5) * anchura;
			suma += 4.0 / (1.0 + x * x);
		}
		suma *= anchura;
	}
	check(suma);
}

BENCHMARK(pi);
BENCHMARK(opi);
BENCHMARK_MAIN();

