#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N; // �迭�� ũ��(����)
	int Q; // ������ ����
	int L, R; // arr�� L��° ���Һ��� R��° ���ұ����� ���� ���ϴ� ����
	int sum; // ���� �����ϱ� ���� ����
	
	// �迭 �Է�
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);  // N���� ������ �����ϱ� ���� ���� �迭
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	// ���� �Է�
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		sum = 0;
		scanf("%d %d", &L, &R);
		for (int j = L - 1; j < R; j++) { // �迭�� �ε����� 0���� �����ϹǷ� L-1���� R���� ���� ������ ����
			sum += arr[j];
		}
		printf("%d\n", sum);
	}
	free(arr); // ���� �Ҵ� ����
	return 0;
}