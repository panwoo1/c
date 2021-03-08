#include <stdio.h>
#include <stdlib.h>

typedef struct Point { //제약조건 1
	int x;
	int y;
}Point;

int ccw(Point P1, Point P2, Point P3); //제약조건 2

int main()
{
	int n;
	int count = 0, count_1 = 0, count_2 = 0;

	scanf("%d", &n);

	Point* arr = (Point*)malloc(sizeof(int) * n * n); //제약조건 3 구조체 동적 배열
	int* result = (int*)malloc(sizeof(int) * n); //ccw의 값을 저장할 동적 배열

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	for (int i = 0; i < n; i++) {
		if (i + 2 == n) {				//예를 들어 n이 5일 경우 i = 3 일때, i+2 = 5 가 되므로, 초기점을 가리키도록  한다
			arr[i + 2].x = arr[i + 2 - n].x;
			arr[i + 2].y = arr[i + 2 - n].y;
		}
		if (i + 1 == n) {            //마찬가지로 i가 4일 경우 i+1 = 5 이므로, 초기점을 가리키도록 한다
			arr[i + 1].x = arr[i + 1 - n].x;
			arr[i + 1].y = arr[i + 1 - n].y;

			if (i + 2 == n + 1) { //i가 4일 경우 i+2 = 6 따라서, 2번째 점을 가리키도록 한다
				arr[i + 2].x = arr[i + 2 - n].x;
				arr[i + 2].y = arr[i + 2 - n].y;
			}
		}
		result[i] = ccw(arr[i], arr[i + 1], arr[i + 2]);
	}
	for (int i = 0; i < n; i++) { //각 각 1과 -1 값을 따로 세어 적은 값이 오목점의 결과와 같다
		if (result[i] == 1) {
			count_1++;
		}
		else if (result[i] == -1){
			count_2++;
	    }
		else {
			for (int i = 0; i < n - 1; i++) { //만약 1과 -1값이 같으면 다음과 같이 센다
				if (result[i] == 1 && result[i + 1] == -1) {
					count++;
				}
				if (i == n - 2 && result[i] == -1 && result[i + 1] == 1) { // -1-1-1-1 1 인 경우
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