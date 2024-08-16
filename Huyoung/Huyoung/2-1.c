#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_values();

int main() {
	int num1 = 10;
	int num2 = 20;
	int* ptr1 = &num1; // num1 -> ptr1 -> p1
	int* ptr2 = &num2; // num2 -> ptr2 -> p2
	printf("교환 이전: num1 = %d, num2 = %d\n", num1, num2);
	swap_values(&ptr1, &ptr2);
	printf("교환 이후: num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}

void swap_values(int **p1, int **p2) {
	int* temp = **p1; // temp = &num1 -> 2번 역참조를 했으니 num1의 주소를 가리킴 -> num1,num2의 주소를 직접 바꿔야 각각의 값을 출력했을때 정상적으로 바뀜
	**p1 = **p2; // &num1 = &num2;
	**p2 = temp; // &num2 = temp;
}