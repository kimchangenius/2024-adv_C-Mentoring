#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_swap(char* p1, char* p2) {
	char temp[101];
	strcpy(temp, p1);
	strcpy(p1, p2);
	strcpy(p2, temp);
}

int main() {
	char* input; // �Է��� ���ڿ��� ���̸� �ľ��ϱ� ���� ���ڿ� �ӽ� ����� �迭
	char** str = (char**)malloc(sizeof(char*) * 10); // ��� ���ڿ��� �����ϱ� ���� ������ �迭

	// ��� ���ڿ� �Է�
	for (int i = 0; i < 10; i++) {
		input = (char*)malloc(sizeof(char) * 101);
		scanf("%s", input);
		*(str + i) = (char*)malloc(sizeof(char) * strlen(input)); // ������ �迭�� �� �࿡ ���ڿ� ���̸�ŭ ���� �Ҵ�
		*(str + i) = input; // ������ �迭�� �� �࿡ ���ڿ� ����
	}

	printf("�Է� ���ڿ�:\n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", *(str + i));
	}

	// ���� ����
	int least;
	for (int i = 0; i < 9; i++) {
		least = i;
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(*(str + least), *(str + j)) > 0) { // least��° ���ڿ��� j��° ���ڿ��� ��, str[least] > str[j]�̸� least�� j�� ����
				least = j;
			}
		}
		if (i != least) {
			str_swap(*(str + i), *(str + least));
		}
	}

	printf("\n���� �� ���ڿ�:\n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", *(str + i));
	}

	free(str); // ���� �Ҵ� ����
	free(input); 
	return 0;
}