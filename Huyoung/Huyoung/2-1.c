#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_values();

int main() {
	int num1 = 10;
	int num2 = 20;
	int* ptr1 = &num1; // num1 -> ptr1 -> p1
	int* ptr2 = &num2; // num2 -> ptr2 -> p2
	printf("��ȯ ����: num1 = %d, num2 = %d\n", num1, num2);
	swap_values(&ptr1, &ptr2);
	printf("��ȯ ����: num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}

void swap_values(int **p1, int **p2) {
	int* temp = **p1; // temp = &num1 -> 2�� �������� ������ num1�� �ּҸ� ����Ŵ -> num1,num2�� �ּҸ� ���� �ٲ�� ������ ���� ��������� ���������� �ٲ�
	**p1 = **p2; // &num1 = &num2;
	**p2 = temp; // &num2 = temp;
}