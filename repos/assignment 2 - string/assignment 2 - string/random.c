#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#define SIZE 6

void random_count(int freq[SIZE]) //�ּ� 50���� 100���� ���� ���� ��, �� string �� ���� �ϰ� �� ���� �ο��ϴ� �Լ�
{
	int i;
	
	srand((unsigned)time(NULL));
	int num = rand() % (51) + 50;

	for (i = 0; i < num; i++)
	{
		++freq[rand() % SIZE];
	}
}