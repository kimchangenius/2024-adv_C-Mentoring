#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char** arr = malloc(sizeof(char*) * 10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = malloc(sizeof(char) * 101);
	}
	printf("입력 문자열 : \n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%s", arr[i]);
	}
	for (int h = 0; h < 9; h++)
	{
		for (int i = h + 1; i < 10; i++)
		{
			if (arr[h][0] > arr[i][0])
			{
				char* temp = arr[h];
				arr[h] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		int len = strlen(arr[i]);
		arr[i] = realloc(arr[i], sizeof(char) * (len + 1));
	}
	printf("\n정렬 후 : \n");
	for (int h = 0; h < 10; h++)
	{
		printf("%s\n", arr[h]);
	}

	for (int i = 0; i < 10; i++)
	{
		free(arr[i]);
	}
	free(arr);

	return 0;
}