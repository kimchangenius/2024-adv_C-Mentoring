#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 100���� ���ڸ� �޾Ƽ� �� ���� �ܾ����(���� ����) ����

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

	// �ܾ� ���� �� ���� ���� �ľ�
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			word_cnt++;
		}
		str_len++;
	}
	word_cnt++; // ������ �ܾ�
	words = (char**)malloc(sizeof(char*) * word_cnt);
	ans = (char*)malloc(sizeof(char) * (str_len + 1)); // �ι���

	printf("\n=================================\n");
	printf("���� ���� : %d, �ܾ� �� : %d\n", str_len, word_cnt);

	// �ܾ�� words�� ����
	for (int i = 0; i < word_cnt; i++) {
		word_len = 0;
		if (i == word_cnt - 1) {
			for (int j = 0 + curr_idx; str[j] != '\0'; j++) { // ������ �ܾ�
				word_len++;
			}
		}
		else {
			for (int j = 0 + curr_idx; str[j] != ' '; j++) { // �߰� �ܾ��
				word_len++;
			}
		}
		printf("�ܾ� ���� : %d\n", word_len);
		*(words + i) = (char*)malloc(sizeof(char) * (word_len + 1)); // �ι���
		int k;
		for (k = 0; k < word_len; k++) {
			words[i][k] = str[curr_idx + k];
		}
		words[i][k] = '\0';
		curr_idx += word_len + 1; // ����
		printf("%s\n", words[i]);
	}
	printf("=================================\n");

	// �и��� �ܾ���� �������� ans�� ���� �� ���
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

	// �����Ҵ� ����
	for (int i = 0; i < word_cnt; i++) {
		free(words[i]);
	}
	free(words);
	free(ans);
	return 0;
}