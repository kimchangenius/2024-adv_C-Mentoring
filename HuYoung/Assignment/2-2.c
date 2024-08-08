#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N; // 배열의 크기(길이)
	int Q; // 쿼리의 개수
	int L, R; // arr의 L번째 원소부터 R번째 원소까지의 합을 구하는 쿼리
	int sum; // 합을 저장하기 위한 변수
	
	// 배열 입력
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);  // N개의 정수를 저장하기 위한 동적 배열
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	// 쿼리 입력
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		sum = 0;
		scanf("%d %d", &L, &R);
		for (int j = L - 1; j < R; j++) { // 배열의 인덱스는 0부터 시작하므로 L-1부터 R보다 작을 때까지 합함
			sum += arr[j];
		}
		printf("%d\n", sum);
	}
	free(arr); // 동적 할당 해제
	return 0;
}