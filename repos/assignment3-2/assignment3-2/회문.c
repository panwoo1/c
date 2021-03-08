#include<stdio.h>
#include<string.h>
#include<ctype.h>

void change_alpha(char str[]); //���ڿ����� �빮�ڸ� �ҹ��ڷ� �ٲٴ� �Լ�
void longest_Pal(char str[]); //���� �� ȸ���� �Ǻ��� ����ϴ� �Լ�
void print_substring(char str[], int start, int max); //���ڿ� ��� �Լ�
void sort(int arr[], int size); //�迭 ����(��������)

int main()
{
	char substr[100];

	scanf("%s", substr);
	change_alpha(substr);
	longest_Pal(substr);

	return 0;
}
void change_alpha(char str[]) //���ڿ����� �빮�ڸ� �ҹ��ڷ� �ٲٴ� �Լ�
{
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (isalpha(str[i]) != 0 && islower(str[i]) == 0) {
			str[i] = tolower(str[i]);
		}
	}
}

void longest_Pal(char str[])
{
	int length = strlen(str);
	int str_num1[100] = { 0 };
	int str_num2[100] = { 0 };
	int maxlength = 1, start = 1;

	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			int result = 1;

			for (int x = 0; x < (j - i + 1) / 2; x++) //ȸ������ �ƴ����� �Ǻ�
				if (str[i + x] != str[j - x])
					result = 0;

			if (result == 1 && (j - i + 1) >= maxlength) { //ȸ�������� �Ǻ��Ͽ� ���� �ִ밪�� ũ�� ȸ���� �ʱⰪ�� �� ���� ����
				start = i;
				maxlength = j - i + 1;
				str_num1[i] = start;
				str_num2[i] = maxlength;
			}
		}
	}
	sort(str_num1, 100); //���� �� ȸ���� �������� ��츦 ���� �ʱⰪ�� ���� ������ �迭�� �ִ밪�� ������ �迭 ����
	sort(str_num2, 100);
	int max = str_num2[0];
	for (int i = 0; i < 100; i++) {
		if (str_num2[i] > max) {
			max = str_num2[i];
		}
	}
	for (int i = 0; i < 100; i++) {
		if (str_num2[i] == max) {
			if (str[str_num1[i]] < str[str_num1[i+1]]) {
				if (str_num2[i + 1] != max)
					break;
				else {
					start = str_num1[i];
				}
			}
			else if (str[str_num1[i]] > str[str_num1[i + 1]]) {
				if (str_num2[i + 1] != max)
					break;
				else {
					start = str_num1[i + 1];
				}
			}
			else {
				int start1 = str_num1[0];
				int start2 = str_num1[i];
				char s1[30];
				char s2[30];
				for (int j = 0; j < maxlength; j++) {
					s1[j] = str[start1 + j];
					s2[j] = str[start2 + j];
				}
				if (strcmp(s1, s2) < 0) {
					start = start1;
				}
				else
					start = start2;
			}
		}
	}
	printf("%d\n", maxlength);
	print_substring(str, start, start + maxlength - 1);
}
void print_substring(char str[], int start, int max)
{
	for (int i = start; i <= max; i++) {
		printf("%c", str[i]);
	}
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