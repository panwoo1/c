#include <stdio.h>
#include "cal.h"
#define DEBUG


int main(void)
{
	int choice, result, x, y;
	int (*pf)(int, int);

	while (1)
	{
		menu();
		printf("메뉴를 선택하시오:");
		scanf("%d", &choice);
	
		switch (choice)
		{
		case 0:
			printf("2개의 정수를 입력하시오:");
			scanf("%d %d", &x, &y);
			pf = add; //함수 포인터에 add 주소 대입
			result = pf(x, y);
#ifdef DEBUG
			printf("연산 결과 = %d + %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 1:
			printf("2개의 정수를 입력하시오:");
			scanf("%d %d", &x, &y);
			pf = sub; //함수 포인터에 sub 주소 대입
			result = pf(x, y);
#ifdef DEBUG
			printf("연산 결과 = %d - %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 2:
			printf("2개의 정수를 입력하시오:");
			scanf("%d %d", &x, &y);
			pf = mul; //함수 포인터에 mul 주소 대입
			result = pf(x, y);
#ifdef DEBUG
			printf("연산 결과 = %d * %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 3:
			printf("2개의 정수를 입력하시오:");
			scanf("%d %d", &x, &y);
			pf = div; //함수 포인터에 div 주소 대입
			if (y == 0)
			{
				printf("잘못된 연산입니다.");
				continue;
			}
			result = pf(x, y);
#ifdef DEBUG
			printf("연산 결과 = %d / %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 4:
			printf("\n");
#ifdef DEBUG
			intro();
			break;
#endif
		}
		if (choice == 4)
			break;
	}
	return 0;
}