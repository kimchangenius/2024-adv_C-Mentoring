#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char ss1[1001];
	char ss2[1001];
	int count = 0;

	scanf("%s", ss1);
	scanf("%s", ss2);

	char* ptr = strstr(ss1, ss2);

	while (ptr != NULL)
	{
		count++;
		ptr = strstr(ptr + 1, ss2);
	}
	printf("%d", count);

	return 0;
}