//cal.c ��Ģ ����, �޴�, �л� ���� �ҽ�
#include <stdio.h>
#include "cal.h"

int add(int x, int y) //���� �Լ�
{
	return x + y;
}
int sub(int x, int y) //���� �Լ�
{
	return x - y;
}
int mul(int x, int y) //���� �Լ�
{
	return x * y;
}
int div(int x, int y) //������ �Լ�
{
	return x / y;
}
void menu() //�޴�
{
	printf("=====================\n");
	printf("0. ����\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ������\n");
	printf("4. ����\n");
	printf("=====================\n");
}
void intro() //�л� ����
{
	printf("��ǻ�����α׷��� �� ���� �����մϴ�\n");
	printf("�а�: ��ǻ�� ���ڽý��۰��к�\n");
	printf("�г�: 1�г�\n");
	printf("�й�: 202002952\n");
	printf("�̸�: ������\n");
}
