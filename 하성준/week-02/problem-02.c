#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	int q;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int L, R;
		int result = 0;
		printf("---------------------------------------------------\n");
		scanf("%d%d", &L, &R);
		for (int i = L-1; i < R; i++)
		{
			result += arr[i];
		}
		printf("%d\n", result);
		result = 0;
	}
	free(arr);
}
