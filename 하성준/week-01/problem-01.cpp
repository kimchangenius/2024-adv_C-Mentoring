#include<stdio.h>
#include<stdlib.h>

void curl(int** m, int** curlm, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(curlm + j) + i) = *(*(m + i) + n - 1 - j);
		}
	}
}

int main() {
	int n;
	printf("n:");
	scanf("%d", &n);
	int** matrix = (int**)malloc(sizeof(int*) * n);
	int** curlm = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		*(matrix + i) = (int*)malloc(sizeof(int) * n);
		*(curlm + i) = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", (*(matrix + j) + i));
		}
	}

	printf("\n");
	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		curl(matrix, curlm, n);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d ", *(*(curlm + k) + j));
				*(*(matrix + k) + j) = *(*(curlm + k) + j);
			}
			printf("\n");
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		free(*(matrix + i));
		free(*(curlm + i));
	}
	free(*(matrix));
	free(*(curlm));
}
