#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void print_array(int* list, int size)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i]);
	}printf("\n");
}
int selection_sort(int* list, int size)
{
	int i, j, temp, least;

	print_array(list, SIZE);
	for (i = 0; i < SIZE - 1; i++)
	{
		least = i;
		for (j = i + 1; j < SIZE; j++)
			if (list[j] < list[least])
				least = j;
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
	printf("---------------------------------\n");
	print_array(list, SIZE);
}
int binary_search(int list[], int n, int key)
{
	int low, high, middle;

	low = 0;
	high = n - 1;

	printf("이진 탐색 : ");
	while (low <= high)
	{
		printf("[%d %d] ", low, high);
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
}
int main(void)
{
	int i, j, key;
	int list[10];
	srand((unsigned)time(NULL));
	
	for (i = 1; i <= SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			list[j] = rand() % 99;
			key = rand() % 99;
		}
		printf("%d 번째 선택정렬입니다.\n", i);
		selection_sort(list, SIZE);
		printf("\n");
		printf("\n찾는 값 %d의 탐색 결과 = %d\n\n", key, binary_search(list, SIZE, key));
	}
	return 0;
}