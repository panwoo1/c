#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#define SIZE 6

void random_count(int freq[SIZE]) //최소 50부터 100까지 숫자 생성 후, 각 string 에 랜덤 하게 빈도 수를 부여하는 함수
{
	int i;
	
	srand((unsigned)time(NULL));
	int num = rand() % (51) + 50;

	for (i = 0; i < num; i++)
	{
		++freq[rand() % SIZE];
	}
}