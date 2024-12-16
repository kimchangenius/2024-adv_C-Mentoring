#include<stdio.h>
#include<math.h>
int main() {
	int num[1000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		num[i] = i + 1;
	}
	for (int i = 1; i < sqrt(n); i++)
	{
		for (int j = (i + 1)*2-1; j < 1000; j+=i+1)
		{
			num[j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] != 0)printf("%d ", num[i]);
	}
}