#include <stdio.h>
#include <string.h>

int yun(int year);
int get_day(int yy, int mm, int dd);
void get_want_day(int n);

int main() {
	int dd, mm, yy, n_day, want_day;

	scanf("%d%d%d%d", &yy, &mm, &dd, &n_day);

	want_day = get_day(yy, mm, dd) + n_day - 1;

	get_want_day(want_day);
	return 0;
}
int yun(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int get_day(int yy, int mm, int dd)
{
	int months[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, result;
	long day = 0;

	day = (yy - 1) * 365 + (yy - 1) / 4 - (yy - 1) / 100 + (yy - 1) / 400;

	result = yun(yy);
	if (result == 1)
		months[2] = 29;
	else
		months[2] = 28;

	for (i = 1; i < mm; i++)
		day += months[i];

	day += dd;
	printf("%d\n", day);
	return day;
}
void get_want_day(int n)
{
	int months[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int yun_num = n / (365 * 4) - n / (365 * 100) + n / (365 * 400);
	int year = (n - yun_num) / 365 + 1;
	int remain = (n - yun_num) % 365;
	int month, day;
	int i, result;
		result = yun(year);
	if (result == 1)
		months[2] = 29;
	else
		months[2] = 28;


	for (i = 1; i <= 12; i++)
		if (remain >= 0)
			remain -= months[i];
		else {
			break;
		}

	month = i-1;
	day = months[i - 1] + remain + 1;

	if (yun(year) == 1) {
		day += 1;
		if (month == 1 && day == 30)
			day = 31;
	}
	if (yun(year) != 1) {
		if (month == 12) {
			day = 31;
		}
	}
	printf("%d %d %d\n", year, month, day);
}