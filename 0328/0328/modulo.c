#include <stdio.h>
#define SEC_PER_MINUTE 60

void main() {
	int input, minute, second;

	printf("�� ������ �ð��� �Է��Ͻÿ�(21��������) : ");
	scanf_s("%d", &input);

	minute = input / SEC_PER_MINUTE;
	second = input % SEC_PER_MINUTE;

	printf("%d�ʴ� %d�� %d���Դϴ�. \n", input, minute, second);
}