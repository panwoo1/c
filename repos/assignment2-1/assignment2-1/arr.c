#include <stdio.h>

void sort(int arr[], int size);

int main()
{
	int answers[100];
	int points[100];
	int st_answer[100];
	int st_points[100] = { 0 };
	int question_count, students;

	scanf("%d", &question_count);

	for (int i = 0; i < question_count; i++){
		scanf("%d", &answers[i]);
	}

	for (int i = 0; i < question_count; i++){
		scanf("%d", &points[i]);
	}

	scanf("%d", &students);

	for (int i = 0; i < students; i++) {
		int sum = 0;
		for (int j = 0; j < question_count; j++) {
			scanf("%d", &st_answer[j]);
			if (st_answer[j] == answers[j])
			{
				sum += points[j];
			}
		}
		st_points[i] = sum;
	}
	sort(st_points, 100);

	printf("%d", st_points[0]);

	return 0;
}
void sort(int arr[], int size)
{
	int i, j, temp, least;

	for (i = 0; i < size - 1; i++)
	{
		least = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[least])
				least = j;
		}
		temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;
	}
}