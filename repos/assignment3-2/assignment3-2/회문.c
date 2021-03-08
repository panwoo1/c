#include<stdio.h>
#include<string.h>
#include<ctype.h>

void change_alpha(char str[]); //문자열에서 대문자를 소문자로 바꾸는 함수
void longest_Pal(char str[]); //가장 긴 회문을 판별해 출력하는 함수
void print_substring(char str[], int start, int max); //문자열 출력 함수
void sort(int arr[], int size); //배열 정렬(오름차순)

int main()
{
	char substr[100];

	scanf("%s", substr);
	change_alpha(substr);
	longest_Pal(substr);

	return 0;
}
void change_alpha(char str[]) //문자열에서 대문자를 소문자로 바꾸는 함수
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

			for (int x = 0; x < (j - i + 1) / 2; x++) //회문인지 아닌지를 판별
				if (str[i + x] != str[j - x])
					result = 0;

			if (result == 1 && (j - i + 1) >= maxlength) { //회문인지를 판별하여 만약 최대값이 크면 회문의 초기값과 끝 값을 변경
				start = i;
				maxlength = j - i + 1;
				str_num1[i] = start;
				str_num2[i] = maxlength;
			}
		}
	}
	sort(str_num1, 100); //가장 긴 회문이 여러개일 경우를 위해 초기값을 따로 저장한 배열과 최대값을 저장한 배열 정렬
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