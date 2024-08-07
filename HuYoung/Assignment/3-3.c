#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow(int a, int n) { // 10�� �������� ��ȯ�ϴ� �Լ�
	int num = 1;
	for (int i = 0; i < n; i++) {
		num *= a;
	}
	return num;
}

int digit(int num) { // �Էµ� ��(1000 ����)�� �ڸ����� ��ȯ�ϴ� �Լ�
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

char* rome_num_transform(int num) { // �Էµ� ��(1000 ����)�� �θ� ���ڷ� ��ȯ�ϴ� �Լ�
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
		if (num == expt_i[k]) { // 9�� 4�� �� �� ���� ó��
			return expt_c[k];
		}
	}
	for (int i = 0; i < 6; i++) {
		div = num / rome_i[i];
		remain = num % rome_i[i];
		if (i == 0 || i == 2 || i == 4) { // V, L, D �϶�
			if (div > 1 || div < 1) {
				continue;
			}
			else {
				strcpy(rome_num, rome_c[i]);
			}
		}
		else { // I, X, C �϶�
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
	int* dec; // 10 ������ ���� �����ϴ� �迭
	char* array = (char *)malloc(sizeof(char) * 1);
	char temp[5]; // ��ȯ�� �ڸ����� �θ����� ���ڿ��� �ӽ� �����ϴ� �迭

	scanf("%d", &num);
	num_digit = digit(num); // �Էµ� ������ �ڸ����� �ľ�
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
		array = (char*)realloc(array, sizeof(char) * (array_len + 1)); // �ι���
		if (i == 0) {
			strcpy(array, temp);
		}
		else {
			strcat(array, temp);
		}
	}
	printf("%s, %d\n", array, array_len);

	free(array); // �����Ҵ� ����
	return 0;
}