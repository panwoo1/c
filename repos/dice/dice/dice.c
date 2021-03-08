#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

// 1번 가위바위보 게임
// 1: 가위 2: 바위 3: 보
void game(void)
{
	int i, j, user, com;
	srand((unsigned)time(NULL));

	for (i = 1; i <= SIZE; i++)
	{
		for (j = 1; j < SIZE; j++)
		{
			com = rand() % 3 + 1;
			user = rand() % 3 + 1;
		}
		if (com == 1)
		{
			if (user == 1)
			{
				printf("%d번째 게임은 비겼음\n", i);
				printf("컴퓨터 = 가위, 홍길동 = 가위\n\n");
			}
			else if (user == 2)
			{
				printf("%d번째 게임은 홍길동이 이겼음\n", i);
				printf("컴퓨터 = 가위, 홍길동 = 바위\n\n");
			}
			else
			{
				printf("%d번째 게임은 컴퓨터가 이겼음\n", i);
				printf("컴퓨터 = 가위, 홍길동 = 보\n\n");
			}
		}
		else if (com == 2)
		{
			if (user == 1)
			{
				printf("%d번째 게임은 컴퓨터가 이겼음\n", i);
				printf("컴퓨터 = 바위, 홍길동 = 가위\n\n");
			}
			else if (user == 2)
			{
				printf("%d번째 게임은 비겼음\n", i);
				printf("컴퓨터 = 바위, 홍길동 = 바위\n\n");
			}
			else
			{
				printf("%d번째 게임은 홍길동이 이겼음\n", i);
				printf("컴퓨터 = 바위, 홍길동 = 보\n\n");
			}
		}
		else
		{
			if (user == 1)
			{
				printf("%d번째 게임은 홍길동이 이겼음\n", i);
				printf("컴퓨터 = 보, 홍길동 = 가위\n\n");
			}
			else if (user == 2)
			{
				printf("%d번째 게임은 컴퓨터가 이겼음\n", i);
				printf("컴퓨터 = 보, 홍길동 = 바위\n\n");
			}
			else
			{
				printf("%d번째 게임은 비겼음\n", i);
				printf("컴퓨터 = 보, 홍길동 = 보\n\n");
			}
		}

	}
	
}
int main(void)
{
	game();

	return 0;
}