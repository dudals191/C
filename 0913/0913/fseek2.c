#include <stdio.h>

main() {
	FILE *fp = NULL;
	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("data.txt 파일을 열 수 없습니다.");
		exit(1);
	}
	fputs("This is an house.", fp);
	fseek(fp, 11, SEEK_SET);
	fputs("apple", fp);
	fclose(fp);
}