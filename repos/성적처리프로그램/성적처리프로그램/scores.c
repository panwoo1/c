#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����ó�����α׷�
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
				printf("����� ������ ��� %d���̸� ����� A �Դϴ�.\n\n", avg);
			}
			else if (avg >= 80)
			{
				printf("����� ������ ��� %d���̸� ����� B �Դϴ�.\n\n", avg);
			}
			else if (avg >= 70)
			{
				printf("����� ������ ��� %d���̸� ����� C �Դϴ�.\n\n", avg);
			}
			else if (avg >= 60)
			{
				printf("����� ������ ��� %d���̸� ����� D �Դϴ�.\n\n", avg);
			}
			else
			{
				printf("����� ������ ��� %d���̸� ����� F �Դϴ�.\n\n", avg);
			}
		
	}
	return 0;
}

