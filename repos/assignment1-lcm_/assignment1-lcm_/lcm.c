#include <stdio.h>
#define SIZE 50

long long get_gcd(long long x, long long y);
long long get_lcm(long long x, long long y);

int main()
{
	int num;
	int count = 0;
	long long arr[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &num);

		if (num < 0)
			break;
		else
		{
			arr[i] = num;
			count++;
		}
	}
	long long lcm = arr[0];
	for (int i = 1; i < count; i++)
	{
		lcm = get_lcm(lcm, arr[i]);
	}
	printf("%lld", lcm);

	return 0;
}
long long get_gcd(long long x, long long y)
{
	long long temp, n;

	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	while (x%y != 0)
	{
		n = x % y;
		x = y;
		y = n;
	}
	return y;
}
long long get_lcm(long long x, long long y)
{
	return x*y / get_gcd(x, y);
}