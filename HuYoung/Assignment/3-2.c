#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//string 함수 선언, 정의는 main 아래에 정의 후 구현
int my_strlen(char* arr1);
int my_strcmp(char* arr1, char* arr2);
void my_strcpy(char* arr1, char* arr2);
void my_strcat(char* arr1, char* arr2);

int main() {
	char arr1[50], arr2[50];

	scanf("%s", arr1);
	scanf("%s", arr2);

	printf("arr1의 길이 : %d, arr2의 길이 : %d\n", my_strlen(arr1), my_strlen(arr2));
	printf("문자열 비교 : %d\n", my_strcmp(arr1, arr2));
	printf("문자열 연결 -> 원래 문자열 : %s, 바뀐 문자열 : ", arr1);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	printf("문자열 복사 -> 원래 문자열 : %s, 바뀐 문자열 : ", arr1);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

int my_strlen(char* arr1) {
	int len = 0;
	for (int i = 0; arr1[i] != '\0'; i++) { // 널문자를 만나기 전까지 반복 (실질적인 문자열의 길이)
		len++;
	}
	return len;
}

int my_strcmp(char* arr1, char* arr2) {
	int len1 = my_strlen(arr1);
	int len2 = my_strlen(arr2);
	if (len1 > len2) { // 문장의 길이가 더 길면 크기가 더 크므로 1을 반환
		return 1;
	}
	else if (len1 < len2) { // 반대로 -1을 반환
		return -1;
	}
	else { // 갈이가 같으면 각 문자열의 문자를 하나하나 비교해서 다를때 1 or -1을 반환
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
	return 0; // 아무것도 해당하지 않으면 두 문자열이 같다는 0을 반환
}

void my_strcpy(char* arr1, char* arr2) {
	int len2 = my_strlen(arr2);
	int i;
	for (i = 0; i < len2; i++) { // arr1의 길이와는 상관없으므로(크기는 같을때) len2의 문자를 하나하나 복사함
		arr1[i] = arr2[i];
	}
	arr1[i] = '\0';
}

void my_strcat(char* arr1, char* arr2) {
	int len1 = my_strlen(arr1);
	int len2 = my_strlen(arr2);
	int i;
	for (i = 0; i < len2; i++) {
		arr1[len1 + i] = arr2[i]; // arr1의 길이 뒤에 arr2의 문자를 하나하나 복사함
	}
	arr1[len1 + i] = '\0';
}