#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 100개의 문자를 받아서 그 중의 단어들을(띄어쓰기 기준) 구분

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
	int word_cnt = 0, str_len = 0, word_len, curr_idx = 0;
	char str[101];
	char** words;
	char* ans;

	gets(str);

	// 단어 개수 및 문장 길이 파악
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			word_cnt++;
		}
		str_len++;
	}
	word_cnt++; // 마지막 단어
	words = (char**)malloc(sizeof(char*) * word_cnt);
	ans = (char*)malloc(sizeof(char) * (str_len + 1)); // 널문자

	printf("\n=================================\n");
	printf("문장 길이 : %d, 단어 수 : %d\n", str_len, word_cnt);

	// 단어별로 words에 저장
	for (int i = 0; i < word_cnt; i++) {
		word_len = 0;
		if (i == word_cnt - 1) {
			for (int j = 0 + curr_idx; str[j] != '\0'; j++) { // 마지막 단어
				word_len++;
			}
		}
		else {
			for (int j = 0 + curr_idx; str[j] != ' '; j++) { // 중간 단어들
				word_len++;
			}
		}
		printf("단어 길이 : %d\n", word_len);
		*(words + i) = (char*)malloc(sizeof(char) * (word_len + 1)); // 널문자
		int k;
		for (k = 0; k < word_len; k++) {
			words[i][k] = str[curr_idx + k];
		}
		words[i][k] = '\0';
		curr_idx += word_len + 1; // 띄어쓰기
		printf("%s\n", words[i]);
	}
	printf("=================================\n");

	// 분리된 단어들을 역순으로 ans에 저장 및 출력
	for (int i = word_cnt - 1; i >= 0; i--) {
		if (i == word_cnt - 1) {
			my_strcpy(ans, words[i]);
		}
		else {
			my_strcat(ans, words[i]);
		}
		if (i > 0) {
			my_strcat(ans, " ");
		}
	}
	printf("%s\n", ans);

	// 동적할당 해제
	for (int i = 0; i < word_cnt; i++) {
		free(words[i]);
	}
	free(words);
	free(ans);
	return 0;
}