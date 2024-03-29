// struct.cc

#include <functional>
#include <numeric>
#include <random>

const int N = 5000, REP = 4000;

std::default_random_engine generator(N * REP);
std::uniform_int_distribution<int> distribution(0, 9);
auto rng = std::bind(distribution, generator);

struct S 
{
	int a, b;
	S(): a(rng()), b(rng()) {}
} s[N];

int main()
{
	int R[REP];

	for (int ii = 0; ii < REP; ++ii)
	{
		int X1, X2;

		for (int i = 0; i < N; ++i)
			X1 = 2 * s[i].a + ii;

		for (int i = 0; i < N; i++)
			X2 = 3 * s[i].b - ii;

		if (X1 < X2)
			R[ii] = X1;
		else
			R[ii] = X2;
	}

	return std::accumulate(R, R + REP, 0);
}
