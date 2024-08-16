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
	char* sentence = (char *)malloc(sizeof(char) * 1); // realloc�� �ϱ� ���� �ӽ� ���� �Ҵ�

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%s", input);
		for (int j = 0; input[j] != '\0'; j++) {
			str_len++; // ������ ���ڿ� ����
		}
		str_len += 2; // ���� + �ι���
		sentence = (char*)realloc(sentence, sizeof(char) * str_len);
		if (i == 0) {
			my_strcpy(sentence, input); // ó�� ���ڿ��� strcat�� �ϸ� �ʱ�ȭ�� �Ǿ����� �ʱ� ������ �����Ⱚ�� �߰��ǹǷ� strcpy�� ���� �ʱ�ȭ�ϰ� ���� ������
		}
		else {
			my_strcat(sentence, input);
		}
		my_strcat(sentence, " "); // ������ ' ' �̷��� �� �ƴ϶� " " ���� �ؾ��� -> strcat�� ���ڿ��� �����Ƿ�
	}
	printf("%s\n", sentence);
	free(sentence);
	return 0;
}