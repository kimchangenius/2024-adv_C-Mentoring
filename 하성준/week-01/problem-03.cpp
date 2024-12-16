#include<stdio.h>
#include<string.h>

int main() {
	char str1[1000], str2[1000];
	int len1, len2, cnt=0, f = 0;
	scanf("%s%s", &str1, &str2);

	len1 = strlen(str1);
	len2 = strlen(str2);
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[j + i] != str2[j])f = 1;
		}
		if (f == 0) cnt++;
		else f = 0;
	}
	printf("%d", cnt);
}
