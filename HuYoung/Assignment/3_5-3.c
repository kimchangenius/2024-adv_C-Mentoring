#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
void setup_matrix(int** matrix, int row, int col) {
	matrix = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int*)malloc(sizeof(int) * col);
	}
}
*/

int main() {
	int **A, **B, **C;
	int row_A, col_A, row_B, col_B;

	scanf("%d %d %d", &row_A, &col_A, &col_B);
	row_B = col_A;

	// �� ��� �����Ҵ�
	A = (int**)malloc(sizeof(int*) * row_A); // m * k ���
	for (int i = 0; i < row_A; i++) {
		*(A + i) = (int*)malloc(sizeof(int) * col_A);
	}

	B = (int**)malloc(sizeof(int*) * row_B); // k * n ���
	for (int i = 0; i < row_B; i++) {
		*(B + i) = (int*)malloc(sizeof(int) * col_B);
	}

	C = (int**)malloc(sizeof(int*) * row_A); // m * n ���
	for (int i = 0; i < row_A; i++) {
		*(C + i) = (int*)malloc(sizeof(int) * col_B);
	}

	/*
	setup_matrix(A, row_A, col_A); // m * k ���
	setup_matrix(B, col_A, col_B); // k * n ���
	setup_matrix(C, row_A, col_B); // m * n ���
	*/

	// �� ��� �Է� �� �ʱ�ȭ
	for (int i = 0; i < row_A; i++) {
		for (int j = 0; j < col_A; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < row_B; i++) {
		for (int j = 0; j < col_B; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	for (int i = 0; i < row_A; i++) { // 0���� �ʱ�ȭ
		for (int j = 0; j < col_B; j++) {
			C[i][j] = 0;
		}
	}

	// ��� ���� ��� �� ���
	printf("\n");
	for (int i = 0; i < row_A; i++) { // 0 ~ 2
		for (int j = 0; j < col_B; j++) {  // 0 ~ 2
			for (int k = 0; k < col_A; k++) { // 0 ~ 3
				C[i][j] += A[i][k] * B[k][j];
			}
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	// �����Ҵ� ����
	for (int i = 0; i < row_A; i++) {
		free(*(A + i));
	}
	free(A);
	for (int i = 0; i < col_A; i++) {
		free(*(B + i));
	}
	free(B);
	for (int i = 0; i < col_B; i++) {
		free(*(C + i));
	}
	free(C);
	return 0;
}