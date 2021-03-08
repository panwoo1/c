#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#define SIZE 6
#define DEBUG

int main(void)
{
	FILE* fp;
	int i, count = 0;
	int freq[SIZE] = { 0 };
	char buffer[256] = { 0 };
	char fname[100] = "fruit.txt";
	char* fruit[SIZE] = { "banana", "mango", "apple", "blueberry", "orange", "melon" };
#ifdef DEBUG
	random_count(freq);
#endif
	if ((fp = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "파일을 열 수 없습니다.");
		exit(1);
	}

	printf("file name: %s\n", fname);
#ifdef DEBUG
	for (i = 0; i < SIZE; i++)
	{
		fprintf(fp, "%s %d개\n", fruit[i], freq[i]);
	}
#endif
	fclose(fp);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "파일을 열 수 없습니다.");
		exit(1);
	}
	while (!feof(fp))
	{
		fread(buffer, sizeof(buffer), 1, fp);
		fputs(buffer, stdout);
		fscanf(fp, "%d", &freq[i]);
		for (i = 0; i < SIZE; i++)
		{
			count += freq[i];
		}
	}

	printf("\n전체 과일 개수는 %d이다.\n", count);
	
	fclose(fp);
	printf("\n");
	intro();

	return 0;
}