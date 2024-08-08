#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//string �Լ� ����, ���Ǵ� main �Ʒ��� ���� �� ����
int my_strlen(char* arr1);
int my_strcmp(char* arr1, char* arr2);
void my_strcpy(char* arr1, char* arr2);
void my_strcat(char* arr1, char* arr2);

int main() {
	char arr1[50], arr2[50];

	scanf("%s", arr1);
	scanf("%s", arr2);

	printf("arr1�� ���� : %d, arr2�� ���� : %d\n", my_strlen(arr1), my_strlen(arr2));
	printf("���ڿ� �� : %d\n", my_strcmp(arr1, arr2));
	printf("���ڿ� ���� -> ���� ���ڿ� : %s, �ٲ� ���ڿ� : ", arr1);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	printf("���ڿ� ���� -> ���� ���ڿ� : %s, �ٲ� ���ڿ� : ", arr1);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

int my_strlen(char* arr1) {
	int len = 0;
	for (int i = 0; arr1[i] != '\0'; i++) { // �ι��ڸ� ������ ������ �ݺ� (�������� ���ڿ��� ����)
		len++;
	}
	return len;
}

int my_strcmp(char* arr1, char* arr2) {
	int len1 = my_strlen(arr1);
	int len2 = my_strlen(arr2);
	if (len1 > len2) { // ������ ���̰� �� ��� ũ�Ⱑ �� ũ�Ƿ� 1�� ��ȯ
		return 1;
	}
	else if (len1 < len2) { // �ݴ�� -1�� ��ȯ
		return -1;
	}
	else { // ���̰� ������ �� ���ڿ��� ���ڸ� �ϳ��ϳ� ���ؼ� �ٸ��� 1 or -1�� ��ȯ
		for (int i = 0; i < len1; i++) {
			if (arr1[i] != arr2[i]) {
				if (arr1[i] > arr2[i]) {
					return 1;
				}
				if (arr1[i] < arr2[i]) {
					return -1;
				}
			}
		}
	}
	return 0; // �ƹ��͵� �ش����� ������ �� ���ڿ��� ���ٴ� 0�� ��ȯ
}

void my_strcpy(char* arr1, char* arr2) {
	int len2 = my_strlen(arr2);
	int i;
	for (i = 0; i < len2; i++) { // arr1�� ���̿ʹ� ��������Ƿ�(ũ��� ������) len2�� ���ڸ� �ϳ��ϳ� ������
		arr1[i] = arr2[i];
	}
	arr1[i] = '\0';
}

void my_strcat(char* arr1, char* arr2) {
	int len1 = my_strlen(arr1);
	int len2 = my_strlen(arr2);
	int i;
	for (i = 0; i < len2; i++) {
		arr1[len1 + i] = arr2[i]; // arr1�� ���� �ڿ� arr2�� ���ڸ� �ϳ��ϳ� ������
	}
	arr1[len1 + i] = '\0';
}