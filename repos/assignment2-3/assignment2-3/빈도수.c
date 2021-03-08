#include <stdio.h>

int max(int arr[], int size);

int main()
{
	int n, i, j, result, result_1 = 0;
	int result_2 = 0;
	int numbers[2][10000] = { 0, };

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &numbers[0][i]);
	}
	for (i = 0; i < n; i++) {
		result = numbers[0][i];
		int count = 1;
		for (j = i + 1; j < n; j++) {
			if (result == numbers[0][j]) {
				count++;
			}
		}
		if (count >= result_2) {
			result_1 = result;
			result_2 = numbers[1][i] = count;
		}
	}
	for (i = 0; i < n; i++) {
		if (numbers[1][i] == numbers[1][i+1]) {
			result_1 = max(numbers[0], n);
		}

		printf("%d %d", result_1, result_2);

		return 0;
	}
}
int max(int arr[], int size)
{
	int max = arr[0];
	int i;
	for (i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}