#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct std {
	char* name;
	int kor;
	int eng;
}STD;

int main() {
	float total_sum = 0; // 전체 평균의 합계
	int n;
	scanf("%d", &n);
	STD* arr = (STD*)malloc(sizeof(STD) * n);
	FILE* fp = fopen("average_student.txt", "w");

	for (int i = 0; i < n; i++) {
		char tmp[20]; // 매번 배열을 초기화하기 위해 반복문 안에 선언함
		scanf("%s", tmp);
		(arr + i)->name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1)); // 널문자
		strcpy((arr + i)->name, tmp);
		scanf("%d %d", &(arr + i)->kor, &(arr + i)->eng);
	}

	for (int i = 0; i < n; i++) { // 각 학생들의 평균 점수 출력
		int sum = (arr + i)->kor + (arr + i)->eng;
		fprintf(fp, "%s의 평균 점수: %.2f\n", (arr + i)->name, (float)sum / 2);
	}

	// 국어 평균 점수 출력
	float subject_sum = 0;
	for (int i = 0; i < n; i++) {
		subject_sum += (arr + i)->kor; // 실수 + 정수 = 실수
	}
	fprintf(fp, "국어 과목의 평균 점수: %.2f\n", subject_sum / n);
	total_sum += subject_sum / n;

	// 영어 평균 점수 출력
	subject_sum = 0;
	for (int i = 0; i < n; i++) {
		subject_sum += (arr + i)->eng;
	}
	fprintf(fp, "영어 과목의 평균 점수: %.2f\n", subject_sum / n);
	total_sum += subject_sum / n;

	// 총 평균 점수 출력
	fprintf(fp, "총 평균 점수: %.2f", total_sum / 2); // 모두 2개의 과목을 가지고 있으므로 (각 과목의 평균의 합)/2 를 하면 전체 평균과 같음
	return 0;
}