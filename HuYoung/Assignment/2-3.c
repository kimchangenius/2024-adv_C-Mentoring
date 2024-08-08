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
	char* input; // 입력한 문자열의 길이를 파악하기 위한 문자열 임시 저장용 배열
	char** str = (char**)malloc(sizeof(char*) * 10); // 모든 문자열을 저장하기 위한 이차원 배열

	// 모든 문자열 입력
	for (int i = 0; i < 10; i++) {
		input = (char*)malloc(sizeof(char) * 101);
		scanf("%s", input);
		*(str + i) = (char*)malloc(sizeof(char) * strlen(input)); // 이차원 배열의 각 행에 문자열 길이만큼 동적 할당
		*(str + i) = input; // 이차원 배열의 각 행에 문자열 저장
	}

	printf("입력 문자열:\n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", *(str + i));
	}

	// 선택 정렬
	int least;
	for (int i = 0; i < 9; i++) {
		least = i;
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(*(str + least), *(str + j)) > 0) { // least번째 문자열과 j번째 문자열을 비교, str[least] > str[j]이면 least를 j로 저장
				least = j;
			}
		}
		if (i != least) {
			str_swap(*(str + i), *(str + least));
		}
	}

	printf("\n정렬 후 문자열:\n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", *(str + i));
	}

	free(str); // 동적 할당 해제
	free(input); 
	return 0;
}