#include <stdio.h>
#include <stdlib.h>

typedef struct Point { //�������� 1
	int x;
	int y;
}Point;

int ccw(Point P1, Point P2, Point P3); //�������� 2

int main()
{
	int n;
	int count = 0, count_1 = 0, count_2 = 0;

	scanf("%d", &n);

	Point* arr = (Point*)malloc(sizeof(int) * n * n); //�������� 3 ����ü ���� �迭
	int* result = (int*)malloc(sizeof(int) * n); //ccw�� ���� ������ ���� �迭

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	for (int i = 0; i < n; i++) {
		if (i + 2 == n) {				//���� ��� n�� 5�� ��� i = 3 �϶�, i+2 = 5 �� �ǹǷ�, �ʱ����� ����Ű����  �Ѵ�
			arr[i + 2].x = arr[i + 2 - n].x;
			arr[i + 2].y = arr[i + 2 - n].y;
		}
		if (i + 1 == n) {            //���������� i�� 4�� ��� i+1 = 5 �̹Ƿ�, �ʱ����� ����Ű���� �Ѵ�
			arr[i + 1].x = arr[i + 1 - n].x;
			arr[i + 1].y = arr[i + 1 - n].y;

			if (i + 2 == n + 1) { //i�� 4�� ��� i+2 = 6 ����, 2��° ���� ����Ű���� �Ѵ�
				arr[i + 2].x = arr[i + 2 - n].x;
				arr[i + 2].y = arr[i + 2 - n].y;
			}
		}
		result[i] = ccw(arr[i], arr[i + 1], arr[i + 2]);
	}
	for (int i = 0; i < n; i++) { //�� �� 1�� -1 ���� ���� ���� ���� ���� �������� ����� ����
		if (result[i] == 1) {
			count_1++;
		}
		else if (result[i] == -1){
			count_2++;
	    }
		else {
			for (int i = 0; i < n - 1; i++) { //���� 1�� -1���� ������ ������ ���� ����
				if (result[i] == 1 && result[i + 1] == -1) {
					count++;
				}
				if (i == n - 2 && result[i] == -1 && result[i + 1] == 1) { // -1-1-1-1 1 �� ���
					count++;
				}
			}
		}
	}
	if (count_1 < count_2) {
		count = count_1;
	}
	else if (count_1 > count_2) {
		count = count_2;
	}
	printf("%d\n", count);

	free(arr);
	free(result);

	return 0;
}

int ccw(Point P1, Point P2, Point P3)
{
	int S;

	S = (P2.x - P1.x) * (P3.y - P1.y) - (P2.y - P1.y) * (P3.x - P1.x);

	if (S > 0)
		return 1;
	else if (S < 0)
		return -1;
	else
		return 0;
}