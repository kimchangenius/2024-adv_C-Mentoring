#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_values(int** ptr3, int** ptr4);

int main()
{
	int num1 = 10;
	int num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	printf("��ȯ ����: num1 = %d, num2 = %d\n", num1, num2);
	swap_values(&ptr1, &ptr2);
	printf("��ȯ ����: num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}
void swap_values(int** ptr3, int** ptr4)
{
	int* temp = **ptr3;
	**ptr3 = **ptr4;
	**ptr4 = temp;
}