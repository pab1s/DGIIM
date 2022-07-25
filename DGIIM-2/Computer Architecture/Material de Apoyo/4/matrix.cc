//-----------------------------------------------------------------------------
// matrix.cc
//-----------------------------------------------------------------------------

#include "matrix.h"

//-----------------------------------------------------------------------------

const size_t N = 10000;

//-----------------------------------------------------------------------------

std::array<int, N> v1, v2;
matrix<int, N, 1> m0;
matrix<int, N, N> m1, m2;
matrix<int, 1, N> m3;

//-----------------------------------------------------------------------------

int f1()
{
	return v1 * m1 * m2 * v2;
}

//-----------------------------------------------------------------------------

int f2()
{
	return v1 * m1 * m0 * m3 * m2 * v2;
}

//-----------------------------------------------------------------------------

int main()
{
	return f1() + f2();
}

//-----------------------------------------------------------------------------
