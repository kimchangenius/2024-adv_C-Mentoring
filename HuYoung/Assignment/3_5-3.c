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

	// 각 행렬 동적할당
	A = (int**)malloc(sizeof(int*) * row_A); // m * k 행렬
	for (int i = 0; i < row_A; i++) {
		*(A + i) = (int*)malloc(sizeof(int) * col_A);
	}

	B = (int**)malloc(sizeof(int*) * row_B); // k * n 행렬
	for (int i = 0; i < row_B; i++) {
		*(B + i) = (int*)malloc(sizeof(int) * col_B);
	}

	C = (int**)malloc(sizeof(int*) * row_A); // m * n 행렬
	for (int i = 0; i < row_A; i++) {
		*(C + i) = (int*)malloc(sizeof(int) * col_B);
	}

	/*
	setup_matrix(A, row_A, col_A); // m * k 행렬
	setup_matrix(B, col_A, col_B); // k * n 행렬
	setup_matrix(C, row_A, col_B); // m * n 행렬
	*/

	// 각 행렬 입력 및 초기화
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
	for (int i = 0; i < row_A; i++) { // 0으로 초기화
		for (int j = 0; j < col_B; j++) {
			C[i][j] = 0;
		}
	}

	// 행렬 곱셈 계산 및 출력
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

	// 동적할당 해제
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