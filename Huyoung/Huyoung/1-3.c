#include <stdio.h>
#include <string.h>

int main() {
	char input[1001]; // 널문자(\0) 생각해서 문자열 길이 + 1
	char str[1001];
	int cnt, answer = 0; // cnt는 문자열 길이 확인용, answer는 부분 문자열 개수(답) 저장용

	scanf_s("%s", str, sizeof(str));
	scanf_s("%s", input, sizeof(input));

	int str_len = strlen(str);
	int input_len = strlen(input);

	for (int i = 0; i < str_len; i++) { // str의 길이만큼 반복
		cnt = 0;
		for (int j = 0; j < input_len; j++) { // input의 길이만큼 반복
			if (str[i + j] != input[j]) { // str의 [i+j]번째 문자가 input의 [j]번째 문자열과 같은지 확인
				break; // 다르면 str의 다음 문자열로 나가기 위해 break
			}
			else {
				cnt++; // 같으면 input 문자열의 끝까지 확인하기 위한 변수 cnt+ 1
			}
		}
		if (cnt == input_len) { // 같은 문자열이 input 문자열의 길이만큼 같으면 답 변수 answer + 1
			answer++;
		}
	}
	printf("%d", answer);
	return 0;
}