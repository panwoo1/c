//cal.c 사칙 연산, 메뉴, 학생 정보 소스
#include <stdio.h>
#include "cal.h"

int add(int x, int y) //덧셈 함수
{
	return x + y;
}
int sub(int x, int y) //뺄셈 함수
{
	return x - y;
}
int mul(int x, int y) //곱셈 함수
{
	return x * y;
}
int div(int x, int y) //나눗셈 함수
{
	return x / y;
}
void menu() //메뉴
{
	printf("=====================\n");
	printf("0. 덧셈\n");
	printf("1. 뺄셈\n");
	printf("2. 곱셈\n");
	printf("3. 나눗셈\n");
	printf("4. 종료\n");
	printf("=====================\n");
}
void intro() //학생 정보
{
	printf("컴퓨터프로그래밍 평가 과제 제출합니다\n");
	printf("학과: 컴퓨터 전자시스템공학부\n");
	printf("학년: 1학년\n");
	printf("학번: 202002952\n");
	printf("이름: 임찬우\n");
}
