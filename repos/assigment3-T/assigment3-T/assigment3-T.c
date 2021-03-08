#include <stdio.h>
#define SIZE 1000

int main()
{
	int Tri[SIZE] = {0,};

	for (int i = 1; i < SIZE; i++)
	{
		Tri[i - 1] = i * (i + 1) / 2;
		printf("%d", Tri[i - 1]);
	}

}