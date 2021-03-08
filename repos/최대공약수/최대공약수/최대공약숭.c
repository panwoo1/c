#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�ִ������� ���ϴ� �Լ�
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
		printf("( %d, %d )�� �ִ������� %d �̴�.\n", x, y, result);
	}
	return 0;
}