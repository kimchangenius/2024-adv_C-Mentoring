#include <stdio.h> 

int main() {
	int N, k; // �� kȸ ȸ���ϴ� ������� ���� �ٲپ� �ý��ϴ� ��
	int arr[10][10]; // �Էµ� �迭�� �����ϱ� ���� �迭
	int tmp[10][10]; // ����� �迭�� �ӽ������ϰ�, ȸ���� �迭�� ����� �迭

	// 2���� �迭 �Է�
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &arr[i][j]);
			tmp[i][j] = arr[i][j]; // 0ȸ ȸ������ ������ ���� ���� ����
		}
	}

	// �ݽð� ���� kȸ ȸ��
	printf("�� ȸ ȸ��? ");
	scanf_s("%d", &k);
	if (k >= 4) { // 4ȸ�� �Ѿ ȸ���� �ǹ̰� �����Ƿ� 4�� ���� �������� ȸ���ϵ��� ��
		k %= 4;
	}
	for (int r = 0; r < k; r++) { // kȸ ȸ���ϱ� ���� �ݺ���
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(tmp + j) + N - i - 1) = *(*(arr + i) + j); // tmp�� [j][N-i-1]�� arr�� [i][j]��° ���� ������ ���� ȸ�� ����
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				*(*(arr + i) + j) = *(*(tmp + i) + j); // arr �迭�� ����� tmp �迭�� �����ؼ� ���� ȸ���� �غ�
			}
		}
	}

	// ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", *(*(tmp+i)+j));
		}
		printf("\n");
	}

	return 0;
}