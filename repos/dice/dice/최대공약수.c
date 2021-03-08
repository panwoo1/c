#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//최대공약수를 구하는 함수
int get_lcd(int x, int y)
{
	int tmp;

	while (y != 0)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}
}
int main(void)
{
	int x, y, i;

	for (i = 0; i < 10; i++)
	{
		srand(time(NULL));
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;

		get_lcd(x, y);
		printf("( %d, %d )의 최대공약수는 %d 이다.", x);
	}

	return 0;
}