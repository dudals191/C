#include <stdio.h>

void swap(int *px, int *py);

main() {
	int a = 100, b = 200;

	printf("swap() 호출 전 a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("swap() 호출 후 a = %d b = %d\n", a, b);
}

void swap(int *px, int *py) {
	int tmp;

	tmp = *px;
	*px = *py;
	*py = tmp;
}