#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow(int a, int n) { // 10의 제곱수를 반환하는 함수
	int num = 1;
	for (int i = 0; i < n; i++) {
		num *= a;
	}
	return num;
}

int digit(int num) { // 입력된 수(1000 이하)의 자릿수를 반환하는 함수
	int cnt = 0;
	if (num >= 10000) {
		return 0;
	}
	else {
		for (int i = 1; i <= 10000; i *= 10) {
			if (num % i == num) {
				return cnt;
			}
			cnt++;
		}
	}
}

char* rome_num_transform(int num) { // 입력된 수(1000 이하)를 로마 숫자로 변환하는 함수
	int rome_i[6] = { 500, 100, 50, 10, 5, 1 };
	char *rome_c[6] = {"D", "C", "L", "X", "V", "I"};
	int expt_i[6] = { 900, 400, 90, 40, 9, 4 };
	char* expt_c[6] = { "CM", "CD", "XC", "XL", "IX", "IV" };

	char rome_num[5];
	int div, remain;
	if (num == 1000) {
		return "M";
	}
	for (int k = 0; k < 6; k++) {
		if (num == expt_i[k]) { // 9나 4가 들어간 수 예외 처리
			return expt_c[k];
		}
	}
	for (int i = 0; i < 6; i++) {
		div = num / rome_i[i];
		remain = num % rome_i[i];
		if (i == 0 || i == 2 || i == 4) { // V, L, D 일때
			if (div > 1 || div < 1) {
				continue;
			}
			else {
				strcpy(rome_num, rome_c[i]);
			}
		}
		else { // I, X, C 일때
			if (div > 3 || div < 1) {
				continue;
			}
			else {
				for (int j = 0; j < div; j++) {
					if (j == 0) {
						strcpy(rome_num, rome_c[i]);
					}
					else {
						strcat(rome_num, rome_c[i]);
					}
				}
					
			}
		}
		if (remain > 0) {
			strcat(rome_num, rome_num_transform(remain));
		}
		return rome_num;
	}
	return "";
}

int main() {
	int num, num_digit, array_len = 0;
	int* dec; // 10 단위의 수를 저장하는 배열
	char* array = (char *)malloc(sizeof(char) * 1);
	char temp[5]; // 변환된 자리수의 로마숫자 문자열을 임시 저장하는 배열

	scanf("%d", &num);
	num_digit = digit(num); // 입력된 숫자의 자리수를 파악
	dec = (int*)malloc(sizeof(int) * num_digit);
	for (int i = 0; i < num_digit; i++) {
		dec[i] = num % pow(10, num_digit - i);
		if (i >= 1) {
			dec[i - 1] -= dec[i];
		}
	}
	printf("%d = ", num);
	for (int i = 0; i < num_digit; i++) {
		if (i == num_digit - 1) {
			printf("%d = ", dec[i]);
		}
		else {
			printf("%d + ", dec[i]);
		}
		strcpy(temp, rome_num_transform(dec[i]));
		array_len += strlen(temp);
		array = (char*)realloc(array, sizeof(char) * (array_len + 1)); // 널문자
		if (i == 0) {
			strcpy(array, temp);
		}
		else {
			strcat(array, temp);
		}
	}
	printf("%s, %d\n", array, array_len);

	free(array); // 동적할당 해제
	return 0;
}