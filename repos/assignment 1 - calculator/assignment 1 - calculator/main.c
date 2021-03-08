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
		printf("�޴��� �����Ͻÿ�:");
		scanf("%d", &choice);
	
		switch (choice)
		{
		case 0:
			printf("2���� ������ �Է��Ͻÿ�:");
			scanf("%d %d", &x, &y);
			pf = add; //�Լ� �����Ϳ� add �ּ� ����
			result = pf(x, y);
#ifdef DEBUG
			printf("���� ��� = %d + %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 1:
			printf("2���� ������ �Է��Ͻÿ�:");
			scanf("%d %d", &x, &y);
			pf = sub; //�Լ� �����Ϳ� sub �ּ� ����
			result = pf(x, y);
#ifdef DEBUG
			printf("���� ��� = %d - %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 2:
			printf("2���� ������ �Է��Ͻÿ�:");
			scanf("%d %d", &x, &y);
			pf = mul; //�Լ� �����Ϳ� mul �ּ� ����
			result = pf(x, y);
#ifdef DEBUG
			printf("���� ��� = %d * %d = %d\n", x, y, result);
			printf("\n");
			break;
#endif
		case 3:
			printf("2���� ������ �Է��Ͻÿ�:");
			scanf("%d %d", &x, &y);
			pf = div; //�Լ� �����Ϳ� div �ּ� ����
			if (y == 0)
			{
				printf("�߸��� �����Դϴ�.");
				continue;
			}
			result = pf(x, y);
#ifdef DEBUG
			printf("���� ��� = %d / %d = %d\n", x, y, result);
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