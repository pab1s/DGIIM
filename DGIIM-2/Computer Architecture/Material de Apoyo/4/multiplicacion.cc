#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <stdexcept>
#include <vector>

template<class _t> 
std::ostream& operator<<(std::ostream& os, const std::vector<_t>& v)
{
	os << "< ";
	for (const auto& i: v) 
		os << i << ' ';
	return os << '>';
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		throw std::invalid_argument("necesito el tamaño del vector");

	size_t n;
	std::istringstream iss(argv[1]);
	iss >> n;
	if(!iss) 
		throw std::invalid_argument("tamaño de vector no válido");

	std::vector<int> v1(n), v2(n, 0);
	std::vector<std::vector<int>> m(n, std::vector<int>(n));

	std::default_random_engine generator(n);
	std::uniform_int_distribution<int> distribution(0, 9);
	auto rng = std::bind(distribution, generator);

	for (auto& i: v1)
		i = rng();

	for (auto& i: m)
		for (auto& j: i)
			j = rng();

	if (n < 10)
		std::cerr << "v1 = " << v1 << std::endl
		          << "v2 = " << v2 << std::endl
		          << "m  = " <<  m << std::endl;

	auto start = std::chrono::high_resolution_clock::now();

	for (unsigned i = 0; i < m.size(); ++i)
		for (unsigned j = 0; j < m[i].size(); ++j)
			v2[i] += m[i][j] * v1[j];

	auto stop = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

	if (n < 10)
		std::cerr << "v2 = " << v2 << std::endl
		          << "std::accumulate(v2.begin(), v2.end(), 0) = " 
		          << std::accumulate(v2.begin(), v2.end(), 0) << std::endl;
}
