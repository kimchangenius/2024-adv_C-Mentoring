#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// =========== 3-2.c ===========
int my_strlen(char* arr1) { 
	int len = 0;
	for (int i = 0; arr1[i] != '\0'; i++) {
		len++;
	}
	return len;
}

void my_strcpy(char* arr1, char* arr2) {
	int len2 = my_strlen(arr2);
	int i;
	for (i = 0; i < len2; i++) {
		arr1[i] = arr2[i];
	}
	arr1[i] = '\0';
}

void my_strcat(char* arr1, char* arr2) {
	int len1 = my_strlen(arr1);
	int len2 = my_strlen(arr2);
	int i;
	for (i = 0; i < len2; i++) {
		arr1[len1 + i] = arr2[i];
	}
	arr1[len1 + i] = '\0';
}
// =============================

int main() {
	int cnt, str_len = 0;
	char input[101];
	char* sentence = (char *)malloc(sizeof(char) * 1); // realloc을 하기 위한 임시 동적 할당

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%s", input);
		for (int j = 0; input[j] != '\0'; j++) {
			str_len++; // 각각의 문자열 길이
		}
		str_len += 2; // 띄어쓰기 + 널문자
		sentence = (char*)realloc(sentence, sizeof(char) * str_len);
		if (i == 0) {
			my_strcpy(sentence, input); // 처음 문자열은 strcat을 하면 초기화가 되어있지 않기 때문에 쓰레기값이 추가되므로 strcpy를 통해 초기화하고 값을 저장함
		}
		else {
			my_strcat(sentence, input);
		}
		my_strcat(sentence, " "); // 공백을 ' ' 이렇게 가 아니라 " " 으로 해야함 -> strcat은 문자열을 받으므로
	}
	printf("%s\n", sentence);
	free(sentence);
	return 0;
}