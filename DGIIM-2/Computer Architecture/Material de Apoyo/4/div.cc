#include <array>
#include <iterator>
#include <numeric>

template<class I, class T> 
void div(I begin, I end, T constant)
{
	while (begin != end)
		*begin++ /= constant;
}

int main(int argc, char **argv)
{
	const int N = 1000;
	
	std::array<int, N> a;
	
	for (int i = 0; i < N; ++i)
	{
		std::iota(a.begin(), a.end(), 0);
		div(a.begin(), a.end(), i + 1);
	}
	
	for (int i = 0; i < N; ++i)
	{
		std::iota(a.begin(), a.end(), 0);
		div(a.begin(), a.end(), i + 1.0);
	}
	
	return a[argc % a.size()];
}

