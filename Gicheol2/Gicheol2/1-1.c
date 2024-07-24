#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[10][10];
	int number;
	int count = 1;

	scanf("%d", &number);

	for (int h = 0; h < number; h++)
	{
		for (int i = 0; i < number; i++)
		{
			scanf("%d", &*(*(arr + i) + h));
		}
	}

	for (int i = 0; i < number; i++)
	{
		for (int h = number - 1; h >= 0; h--)
		{
			printf("%d ", *(*(arr + i) + h));
		}
		printf("\n");
	}
	return 0;
}