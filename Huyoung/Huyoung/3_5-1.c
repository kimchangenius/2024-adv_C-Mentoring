#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 단어가 2개로 한정되었을 때

int main() {
	char str[101];
	char* w1;
	char* w2;
	char* ans;
	int str_len = 0, w1_len = 0, w2_len;

	gets(str);
	for (int i = 0; str[i] != '\0'; i++) {
		str_len++;

	}
	for (int i = 0; str[i] != ' '; i++) {
		w1_len++;
	}
	w2_len = str_len - w1_len - 1;
	
	//printf("%d %d %d\n", str_len, w1_len + 1, w2_len + 1);

	// 각 단어별로 동적할당 및 저장
	w1 = (char*)malloc(sizeof(char) * (w1_len + 1));
	w2 = (char*)malloc(sizeof(char) * (w2_len + 1));
	ans = (char*)malloc(sizeof(char) * (str_len + 1));

	int i;
	for (i = 0; i < w1_len; i++) {
		w1[i] = str[i];
	}
	w1[i] = '\0';

	for (i = 0; i < w2_len; i++) {
		w2[i] = str[w1_len + 1 + i];
	}
	w2[i] = '\0';

	// ans 문자열에 뒤집은 문장을 저장
	for (i = 0; i < w2_len; i++) {
		ans[i] = w2[i];
	}
	ans[i] = ' ';
	for (i = 0; i < w1_len; i++) {
		ans[w2_len + 1 + i] = w1[i];
	}
	ans[w2_len + 1 + i] = '\0';

	printf("%s", ans);
	free(w1);
	free(w2);
	free(ans);
	return 0;
}