#include <stdio.h>

int main() {
	int number = 10; 
	int *p;			//* : 주소 -> 값
	p = &number;	//& : 값 -> 주소

	printf("%d\n", *p);
}