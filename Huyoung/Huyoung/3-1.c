#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student { // �л� ������ �����ϱ� ���� ����ü
	char name[100];
	int math;
	int history;
} STD;

int pow(int num1, int num2) { // num1�� num2�� �����ؼ� ��ȯ�ϴ� �Լ�
	int num = 1;
	for (int i = 0; i < num2; i++) {
		num *= num1;
	}
	return num;
}

int str_to_num(char *str) { // ���ڿ��� �� ������ ���������� ��ȯ�ϱ� ���� �Լ�
	int num = 0, digit = strlen(str);
	for (int i = 0; i < digit; i++) {
		num += (str[i] - 48) * pow(10, digit - 1 - i);
	}
	return num;
}

int main() {
	STD student[6] = { 0, };
	char ch;
	char str[100]; // students.txt ������ ������ �� �پ� �ӽ� �����ϱ� ���� �迭
	char input[100]; // ���ڿ�(�̸�, �����, ����)�� �ӽ� �����ϱ� ���� �迭
	int word_len = 0, colon_cnt = 0, student_idx = 0, subject_idx, student_cnt = 0;
	FILE* fp = fopen("students.txt", "r");

	while (!feof(fp)) {
		// �� ���ھ� ������
		ch = fgetc(fp);

		if (ch == ':') {
			if (word_len > 0) {
				input[word_len] = '\0'; // �̸�, ������ �ι���
			}

			if (colon_cnt == 1) { // �̸�
				int i;
				for (i = 0; i < 6; i++) {
					if (strcmp(input, student[i].name) == 0) {
						student_idx = i; // ���� �̸��� ������ �� �ε���
						break;
					}
				}
				if (i == 6) {
					strcpy(student[student_idx].name, input); // ���� �̸��� ������
					student_cnt++;
				}

			}
			else if (colon_cnt == 2) { // �����
				if (strcmp(input, "Math") == 0) {
					subject_idx = 0; // Math -> 0
				}
				else {
					subject_idx = 1; // History -> 1
				}
			}

			word_len = 0;
			colon_cnt++;
		}

		else if (ch == '\n' || ch == EOF) {
			input[word_len] = '\0'; // ������ �ι���
			if (colon_cnt == 3) { // ����
				if (subject_idx == 0) { // Math
					student[student_idx].math = str_to_num(input);
				}
				else { // History
					student[student_idx].history = str_to_num(input);
				}
				student_idx++;
			}

			colon_cnt = 0; // ���� �ٷ� �Ѿ�Ƿ� �ݷ� �� �ʱ�ȭ
		}

		else { // Colon(:) ������ ���ڿ��� input�� ����
			input[word_len] = ch;
			word_len++;
		}

	} 

	int sum;
	printf("�л��� ��� ����:\n");
	for (int i = 0; i < student_cnt; i++) {
		sum = student[i].math + student[i].history;
		printf("%s: %.1f\n", student[i].name, (float)sum / 2);
	}

	printf("\n������ ��� ����:\n");
	sum = 0;
	printf("Math: ");
	for (int i = 0; i < student_cnt; i++) {
		sum += student[i].math;
	}
	printf("%.2f\n", (float)sum / student_cnt);
	
	sum = 0;
	printf("History: ");
	for (int i = 0; i < student_cnt; i++) {
		sum += student[i].history;
	}
	printf("%.1f\n", (float)sum / student_cnt);

	fclose(fp);
	return 0;
}