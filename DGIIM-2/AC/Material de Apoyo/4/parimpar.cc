const int N = 1000000;
int v[N];

void f1()
{
    for (int i = 0; i < N; ++i)
        if (i % 2 == 1)
            v[i] = 1;
        else
            v[i] = 2;
}

void f2()
{
    for (int i = 0; i < N; i += 2)
    {
        v[i    ] = 1;
        v[i + 1] = 2;
    }
}


int main()
{
    f1();
    f2();
}