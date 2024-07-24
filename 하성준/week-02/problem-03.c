#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char* str[10];
	for (int i = 0; i < 10; i++)
	{
		char tmp[100];
		scanf("%s", tmp);
		str[i] = (char*)malloc(sizeof(char) * strlen(tmp));
		strcpy(str[i], tmp);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (*(str[i]) > *(str[j]))
			{
				char* tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	printf("\n-------------------------------------------------------------------\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", str[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		free(str[i]);
	}
}
