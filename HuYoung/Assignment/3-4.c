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
	char *input; // 임시 저장하는 문자열을 정적할당하면(input[101] 처럼) arr에 저장되는 문자열이 다 같아지는 오류가 생김
	char** arr = (char**)malloc(sizeof(char*) * 1);
	int arr_idx = 0;

	while (1) {
		input = (char*)malloc(sizeof(char) * 101); // 동적할당을 한 뒤에 입력을 받고 arr 이차원 배열에 저장하면 오류 발생 X
		gets(input); // 입력
		*(arr + arr_idx) = (char*)malloc(sizeof(char) * strlen(input));
		*(arr + arr_idx) = input;

		if (input[0] == NULL) { // 종료
			break;
		}

		// 단어 추가
		arr_idx++;
		arr = (char**)realloc(arr, sizeof(char*) * (arr_idx + 1));

	}

	// 선택 정렬
	int least;
	for (int i = 0; i < arr_idx - 1; i++) {
		least = i;
		for (int j = i + 1; j < arr_idx; j++) {
			if (strcmp(*(arr + least), *(arr + j)) > 0) { // strcmp는 한 문자씩 비교하기 때문에 알파벳 순(사전식 순)으로 정렬됨
				least = j;
			}
		}
		if (least != i) {
			str_swap(*(arr + least), *(arr + i));
		}
	}

	printf("===== 정렬 후 =====\n");
	for (int i = 0; i < arr_idx; i++) {
		printf("%s\n", *(arr + i));
	}

	// 동적할당 해제
	free(arr);
	return 0;
}