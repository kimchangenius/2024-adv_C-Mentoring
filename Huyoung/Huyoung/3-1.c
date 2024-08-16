#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student { // 학생 정보를 저장하기 위한 구조체
	char name[100];
	int math;
	int history;
} STD;

int pow(int num1, int num2) { // num1을 num2번 제곱해서 반환하는 함수
	int num = 1;
	for (int i = 0; i < num2; i++) {
		num *= num1;
	}
	return num;
}

int str_to_num(char *str) { // 문자열로 된 점수를 정수형으로 변환하기 위한 함수
	int num = 0, digit = strlen(str);
	for (int i = 0; i < digit; i++) {
		num += (str[i] - 48) * pow(10, digit - 1 - i);
	}
	return num;
}

int main() {
	STD student[6] = { 0, };
	char ch;
	char str[100]; // students.txt 파일의 내용을 한 줄씩 임시 저장하기 위한 배열
	char input[100]; // 문자열(이름, 과목명, 점수)을 임시 저장하기 위한 배열
	int word_len = 0, colon_cnt = 0, student_idx = 0, subject_idx, student_cnt = 0;
	FILE* fp = fopen("students.txt", "r");

	while (!feof(fp)) {
		// 한 문자씩 가져옴
		ch = fgetc(fp);

		if (ch == ':') {
			if (word_len > 0) {
				input[word_len] = '\0'; // 이름, 과목명용 널문자
			}

			if (colon_cnt == 1) { // 이름
				int i;
				for (i = 0; i < 6; i++) {
					if (strcmp(input, student[i].name) == 0) {
						student_idx = i; // 같은 이름이 있으면 그 인덱스
						break;
					}
				}
				if (i == 6) {
					strcpy(student[student_idx].name, input); // 같은 이름이 없으면
					student_cnt++;
				}

			}
			else if (colon_cnt == 2) { // 과목명
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
			input[word_len] = '\0'; // 점수용 널문자
			if (colon_cnt == 3) { // 점수
				if (subject_idx == 0) { // Math
					student[student_idx].math = str_to_num(input);
				}
				else { // History
					student[student_idx].history = str_to_num(input);
				}
				student_idx++;
			}

			colon_cnt = 0; // 다음 줄로 넘어가므로 콜론 수 초기화
		}

		else { // Colon(:) 까지의 문자열을 input에 저장
			input[word_len] = ch;
			word_len++;
		}

	} 

	int sum;
	printf("학생별 평균 점수:\n");
	for (int i = 0; i < student_cnt; i++) {
		sum = student[i].math + student[i].history;
		printf("%s: %.1f\n", student[i].name, (float)sum / 2);
	}

	printf("\n수업별 평균 점수:\n");
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