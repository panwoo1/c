#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

// 1�� ���������� ����
// 1: ���� 2: ���� 3: ��
void game(void)
{
	int i, j, user, com;
	srand((unsigned)time(NULL));

	for (i = 1; i <= SIZE; i++)
	{
		for (j = 1; j < SIZE; j++)
		{
			com = rand() % 3 + 1;
			user = rand() % 3 + 1;
		}
		if (com == 1)
		{
			if (user == 1)
			{
				printf("%d��° ������ �����\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
			}
			else if (user == 2)
			{
				printf("%d��° ������ ȫ�浿�� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
			}
			else
			{
				printf("%d��° ������ ��ǻ�Ͱ� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ��\n\n");
			}
		}
		else if (com == 2)
		{
			if (user == 1)
			{
				printf("%d��° ������ ��ǻ�Ͱ� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
			}
			else if (user == 2)
			{
				printf("%d��° ������ �����\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
			}
			else
			{
				printf("%d��° ������ ȫ�浿�� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ��\n\n");
			}
		}
		else
		{
			if (user == 1)
			{
				printf("%d��° ������ ȫ�浿�� �̰���\n", i);
				printf("��ǻ�� = ��, ȫ�浿 = ����\n\n");
			}
			else if (user == 2)
			{
				printf("%d��° ������ ��ǻ�Ͱ� �̰���\n", i);
				printf("��ǻ�� = ��, ȫ�浿 = ����\n\n");
			}
			else
			{
				printf("%d��° ������ �����\n", i);
				printf("��ǻ�� = ��, ȫ�浿 = ��\n\n");
			}
		}

	}
	
}
int main(void)
{
	game();

	return 0;
}