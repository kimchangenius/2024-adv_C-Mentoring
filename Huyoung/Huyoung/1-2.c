#include <stdio.h>

// �����佺�׳׽��� ü (Seive of Eratosthenes)
void SoE() {
	int N;
	int nums[1001]; // �迭�� �ε��� 0 ~ 1000, ���� ����� �� 2 ~ 1000 -> 1001�� �迭 ũ�⸦ ������ ��

	scanf_s("%d", &N);

	for (int i = 2; i <= N; i++) { // 2 ~ N �ε����� ���� 2 ~ N�� ����
		nums[i] = i;
	}
	
	for (int i = 2; i <= N; i++) {
		if (nums[i] == 0) { // �迭�� ���� 0�̸� ���� ���� �Ѿ
			continue;
		}
		else { // �迭�� ���� 0�� �ƴ� ��
			for (int j = i + i; j <= N; j+=i) { // i�� ���(i�� ����)�� ��� 0���� ����
				nums[j] = 0;
			}
		}
	}

	for (int i = 2; i <= N; i++) { // 0�� �ƴ� ��, �� �Ҽ��� ���
		if (nums[i] != 0) {
			printf("%d ", nums[i]);
		}
	}
}

int main() {
	SoE();
	return 0;
}