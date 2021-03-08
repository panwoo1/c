#include <stdio.h>
int get_prime(int n);

#define SIZE 2000

int main()
{
	int i,j, num;
	int arr[SIZE] = { 0, };

	scanf("%d", &num);


	for (i = 2; i <SIZE; i++)
	{
		arr[i] = get_prime(i);
	}

	for (j = num/2; j > 0; j--)
	{
		if (arr[j] == 1 && arr[num - j] == 1)
		{
			printf("%d %d\n", j, num - j);
				break;
		}
	}
	return 0;
}
int get_prime(int n)
{
	int count = 0, i;

	for (i = 1; i <= n; i++) {
		if (n % i == 0) count++;
	}
	if (count == 2)   
		return 1;    
	return 0;            
}