#include <stdio.h>
#include <string.h>

int main() {
	char input[1001]; // �ι���(\0) �����ؼ� ���ڿ� ���� + 1
	char str[1001];
	int cnt, answer = 0; // cnt�� ���ڿ� ���� Ȯ�ο�, answer�� �κ� ���ڿ� ����(��) �����

	scanf_s("%s", str, sizeof(str));
	scanf_s("%s", input, sizeof(input));

	int str_len = strlen(str);
	int input_len = strlen(input);

	for (int i = 0; i < str_len; i++) { // str�� ���̸�ŭ �ݺ�
		cnt = 0;
		for (int j = 0; j < input_len; j++) { // input�� ���̸�ŭ �ݺ�
			if (str[i + j] != input[j]) { // str�� [i+j]��° ���ڰ� input�� [j]��° ���ڿ��� ������ Ȯ��
				break; // �ٸ��� str�� ���� ���ڿ��� ������ ���� break
			}
			else {
				cnt++; // ������ input ���ڿ��� ������ Ȯ���ϱ� ���� ���� cnt+ 1
			}
		}
		if (cnt == input_len) { // ���� ���ڿ��� input ���ڿ��� ���̸�ŭ ������ �� ���� answer + 1
			answer++;
		}
	}
	printf("%d", answer);
	return 0;
}