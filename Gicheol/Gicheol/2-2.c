#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	int query_number;
	scanf("%d", &size);
	int* arr = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &query_number);
	int** arr2 = malloc(sizeof(int*) * query_number);
	for (int i = 0; i < query_number; i++)
	{
		arr2[i] = malloc(sizeof(int) * 2);
	}
	for (int h = 0; h < query_number; h++)
	{
		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &arr2[h][i]);
		}
	}

	for (int h = 0; h < query_number; h++)
	{
		int hap = 0;
		for (int i = arr2[h][0]; i <= arr2[h][1]; i++)
		{
			hap += i;
		}
		printf("%d\n", hap);
	}
	for (int i = 0; i < query_number; i++)
	{
		free(arr2[i]);
	}
	free(arr);
	return 0;
}