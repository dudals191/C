#include <stdio.h>

void main() {
	int number;

	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &number);

	if (number >= 0 && number <= 100)
		printf("�Է��� ������ 0���� 100 ���̿� �ֽ��ϴ�. \n");
	else
		printf("�Է��� ������ 0���� 100 ���̰� �ƴմϴ�. \n");
}