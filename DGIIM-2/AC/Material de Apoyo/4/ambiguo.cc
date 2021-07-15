int j;

void mars1(int *v)
{
	j = 7;
	*v = 15;
	j /= 7;
}

void mars2(int v)
{
	j = 7;
	v = 15;
	j /= 7;
}

int main(int argc, char **argv)
{
	j = argc;
	mars1(&j);
	mars2(j);
	return j;
}
