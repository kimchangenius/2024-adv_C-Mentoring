#include <stdio.h>

// 에라토스테네스의 체 (Seive of Eratosthenes)
void SoE() {
	int N;
	int nums[1001]; // 배열의 인덱스 0 ~ 1000, 실제 사용할 수 2 ~ 1000 -> 1001의 배열 크기를 가져야 함

	scanf_s("%d", &N);

	for (int i = 2; i <= N; i++) { // 2 ~ N 인덱스에 숫자 2 ~ N을 저장
		nums[i] = i;
	}
	
	for (int i = 2; i <= N; i++) {
		if (nums[i] == 0) { // 배열의 값이 0이면 다음 수로 넘어감
			continue;
		}
		else { // 배열의 값이 0이 아닐 때
			for (int j = i + i; j <= N; j+=i) { // i의 배수(i는 제외)를 모두 0으로 변경
				nums[j] = 0;
			}
		}
	}

	for (int i = 2; i <= N; i++) { // 0이 아닌 수, 즉 소수를 출력
		if (nums[i] != 0) {
			printf("%d ", nums[i]);
		}
	}
}

int main() {
	SoE();
	return 0;
}