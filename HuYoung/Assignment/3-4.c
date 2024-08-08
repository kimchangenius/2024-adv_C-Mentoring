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
	char *input; // �ӽ� �����ϴ� ���ڿ��� �����Ҵ��ϸ�(input[101] ó��) arr�� ����Ǵ� ���ڿ��� �� �������� ������ ����
	char** arr = (char**)malloc(sizeof(char*) * 1);
	int arr_idx = 0;

	while (1) {
		input = (char*)malloc(sizeof(char) * 101); // �����Ҵ��� �� �ڿ� �Է��� �ް� arr ������ �迭�� �����ϸ� ���� �߻� X
		gets(input); // �Է�
		*(arr + arr_idx) = (char*)malloc(sizeof(char) * strlen(input));
		*(arr + arr_idx) = input;

		if (input[0] == NULL) { // ����
			break;
		}

		// �ܾ� �߰�
		arr_idx++;
		arr = (char**)realloc(arr, sizeof(char*) * (arr_idx + 1));

	}

	// ���� ����
	int least;
	for (int i = 0; i < arr_idx - 1; i++) {
		least = i;
		for (int j = i + 1; j < arr_idx; j++) {
			if (strcmp(*(arr + least), *(arr + j)) > 0) { // strcmp�� �� ���ھ� ���ϱ� ������ ���ĺ� ��(������ ��)���� ���ĵ�
				least = j;
			}
		}
		if (least != i) {
			str_swap(*(arr + least), *(arr + i));
		}
	}

	printf("===== ���� �� =====\n");
	for (int i = 0; i < arr_idx; i++) {
		printf("%s\n", *(arr + i));
	}

	// �����Ҵ� ����
	free(arr);
	return 0;
}