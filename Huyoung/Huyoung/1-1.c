#include <stdio.h> 

int main() {
	int N, k; // ※ k회 회전하는 방식으로 조금 바꾸어 봤습니다 ※
	int arr[10][10]; // 입력된 배열을 저장하기 위한 배열
	int tmp[10][10]; // 변경된 배열을 임시저장하고, 회전된 배열을 출력할 배열

	// 2차원 배열 입력
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &arr[i][j]);
			tmp[i][j] = arr[i][j]; // 0회 회전에서 오류를 막기 위한 저장
		}
	}

	// 반시계 방향 k회 회전
	printf("몇 회 회전? ");
	scanf_s("%d", &k);
	if (k >= 4) { // 4회를 넘어간 회전은 의미가 없으므로 4로 나눈 나머지만 회전하도록 함
		k %= 4;
	}
	for (int r = 0; r < k; r++) { // k회 회전하기 위한 반복문
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(tmp + j) + N - i - 1) = *(*(arr + i) + j); // tmp의 [j][N-i-1]에 arr의 [i][j]번째 값을 저장을 통해 회전 구현
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(arr + i) + j) = *(*(tmp + i) + j); // arr 배열에 변경된 tmp 배열을 저장해서 다음 회전을 준비
			}
		}
	}

	// 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", *(*(tmp+i)+j));
		}
		printf("\n");
	}

	return 0;
}