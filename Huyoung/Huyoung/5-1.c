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
	float total_sum = 0; // ��ü ����� �հ�
	int n;
	scanf("%d", &n);
	STD* arr = (STD*)malloc(sizeof(STD) * n);
	FILE* fp = fopen("average_student.txt", "w");

	for (int i = 0; i < n; i++) {
		char tmp[20]; // �Ź� �迭�� �ʱ�ȭ�ϱ� ���� �ݺ��� �ȿ� ������
		scanf("%s", tmp);
		(arr + i)->name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1)); // �ι���
		strcpy((arr + i)->name, tmp);
		scanf("%d %d", &(arr + i)->kor, &(arr + i)->eng);
	}

	for (int i = 0; i < n; i++) { // �� �л����� ��� ���� ���
		int sum = (arr + i)->kor + (arr + i)->eng;
		fprintf(fp, "%s�� ��� ����: %.2f\n", (arr + i)->name, (float)sum / 2);
	}

	// ���� ��� ���� ���
	float subject_sum = 0;
	for (int i = 0; i < n; i++) {
		subject_sum += (arr + i)->kor; // �Ǽ� + ���� = �Ǽ�
	}
	fprintf(fp, "���� ������ ��� ����: %.2f\n", subject_sum / n);
	total_sum += subject_sum / n;

	// ���� ��� ���� ���
	subject_sum = 0;
	for (int i = 0; i < n; i++) {
		subject_sum += (arr + i)->eng;
	}
	fprintf(fp, "���� ������ ��� ����: %.2f\n", subject_sum / n);
	total_sum += subject_sum / n;

	// �� ��� ���� ���
	fprintf(fp, "�� ��� ����: %.2f", total_sum / 2); // ��� 2���� ������ ������ �����Ƿ� (�� ������ ����� ��)/2 �� �ϸ� ��ü ��հ� ����
	return 0;
}