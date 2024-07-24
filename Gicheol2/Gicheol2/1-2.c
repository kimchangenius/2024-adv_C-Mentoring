#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[1000];
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		if (*(arr + i) == 0)
		{
			continue;
		}
		for (int h = i * 2; h <= N; h += i)
		{
			*(arr + h) = 0;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d ", *(arr + i));
		}
	}
	return 0;
}