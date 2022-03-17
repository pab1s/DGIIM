#include <string>

int f(int A, int B, int C1, int C2)
{
    if (A < B)
        return C1;
    else
        return C2;
}

int main(int argc, char **argv)
{
    int A = std::stoi(argv[1]), B = std::stoi(argv[2]), C1 = 1, C2 = 2;
    return f(A, B, C1, C2);
}
