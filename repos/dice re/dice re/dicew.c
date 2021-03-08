#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(void)
{
	int com, user, i=1;

	while (i <= 10)
	{
		user = (rand() % 3 + 1);
		com = (rand() % 3 + 1);

		if (com == 1)
		{
			if (user == 1)
			{
				printf("%d번째 게임은 비겼음\n", i);
				printf("컴퓨터 = 가위, 홍길동 = 가위\n\n");
				i++;
			}
			else if (user == 2)
			{
				printf("%d번째 게임은 홍길동이 이겼음\n", i);
				printf("컴퓨터 = 가위, 홍길동 = 바위\n\n");
				i++;
			}
			else
			{
				printf("%d번째 게임은 컴퓨터가 이겼음\n", i);
				printf("컴퓨터 = 가위, 홍길동 = 보\n\n");
				i++;
			}
		}
		else if (com == 2)
		{
			if (user == 1)
			{
				printf("%d번째 게임은 컴퓨터가 이겼음\n", i);
				printf("컴퓨터 = 바위, 홍길동 = 가위\n\n");
				i++;
			}
			else if (user == 2)
			{
				printf("%d번째 게임은 비겼음\n", i);
				printf("컴퓨터 = 바위, 홍길동 = 바위\n\n");
				i++;
			}
			else
			{
				printf("%d번째 게임은 홍길동이 이겼음\n", i);
				printf("컴퓨터 = 바위, 홍길동 = 보\n\n");
				i++;
			}
		}
		else
		{
			if (user == 1)
			{
				printf("%d번째 게임은 홍길동이 이겼음\n", i);
				printf("컴퓨터 = 보, 홍길동 = 가위\n\n");
				i++;
			}
			else if (user == 2)
			{
				printf("%d번째 게임은 컴퓨터가 이겼음\n", i);
				printf("컴퓨터 = 보, 홍길동 = 바위\n\n");
				i++;
			}
			else
			{
				printf("%d번째 게임은 비겼음\n", i);
				printf("컴퓨터 = 보, 홍길동 = 보\n\n");
				i++;
			}
		}
	}
}
int main(void)
{
	game();

	return 0;
}

