#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//최대공약수를 구하는 함수
int get_gcd(int x, int y)
{
	if (y == 0)
		return x;
	return get_gcd(y, x % y);
}
int main(void)
{
	int x, y, i, j, result;
	
	srand((unsigned)time(NULL));

	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
		}
		result = get_gcd(x, y);
		printf("( %d, %d )의 최대공약수는 %d 이다.\n", x, y, result);
	}
	return 0;
}