#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(void)
{
	int com, user, i=1;

	while (i <= 10)
	{
		user = (rand() % 3 + 1);
		com = (rand() % 3 + 1);

		if (com == 1)
		{
			if (user == 1)
			{
				printf("%d��° ������ �����\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
				i++;
			}
			else if (user == 2)
			{
				printf("%d��° ������ ȫ�浿�� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
				i++;
			}
			else
			{
				printf("%d��° ������ ��ǻ�Ͱ� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ��\n\n");
				i++;
			}
		}
		else if (com == 2)
		{
			if (user == 1)
			{
				printf("%d��° ������ ��ǻ�Ͱ� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
				i++;
			}
			else if (user == 2)
			{
				printf("%d��° ������ �����\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ����\n\n");
				i++;
			}
			else
			{
				printf("%d��° ������ ȫ�浿�� �̰���\n", i);
				printf("��ǻ�� = ����, ȫ�浿 = ��\n\n");
				i++;
			}
		}
		else
		{
			if (user == 1)
			{
				printf("%d��° ������ ȫ�浿�� �̰���\n", i);
				printf("��ǻ�� = ��, ȫ�浿 = ����\n\n");
				i++;
			}
			else if (user == 2)
			{
				printf("%d��° ������ ��ǻ�Ͱ� �̰���\n", i);
				printf("��ǻ�� = ��, ȫ�浿 = ����\n\n");
				i++;
			}
			else
			{
				printf("%d��° ������ �����\n", i);
				printf("��ǻ�� = ��, ȫ�浿 = ��\n\n");
				i++;
			}
		}
	}
}
int main(void)
{
	game();

	return 0;
}

