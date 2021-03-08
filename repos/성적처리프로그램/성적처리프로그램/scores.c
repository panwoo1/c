#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//성적처리프로그램
int main(void)
{
	int i, j;
	int scores[10][5];



	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scores[i][j] = rand() % 100 + 1;
			printf("%d ", scores[i][j]);
		}
		printf("\n");
			int avg = (scores[i][0] + scores[i][1] + scores[i][2] + scores[i][3] + scores[i][4]) / 5;

			if (avg >= 90)
			{
				printf("당신의 성적은 평균 %d점이며 등급은 A 입니다.\n\n", avg);
			}
			else if (avg >= 80)
			{
				printf("당신의 성적은 평균 %d점이며 등급은 B 입니다.\n\n", avg);
			}
			else if (avg >= 70)
			{
				printf("당신의 성적은 평균 %d점이며 등급은 C 입니다.\n\n", avg);
			}
			else if (avg >= 60)
			{
				printf("당신의 성적은 평균 %d점이며 등급은 D 입니다.\n\n", avg);
			}
			else
			{
				printf("당신의 성적은 평균 %d점이며 등급은 F 입니다.\n\n", avg);
			}
		
	}
	return 0;
}

