#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Intestazione.h"

void first(){
	FILE* fp;
	fp = fopen("testo.txt", "w");
	fprintf(fp, "Hello world!\n");
	fclose(fp);
}

void second() {
	int k;
	FILE* fp;
	fp = fopen("Random Ns.txt", "w");
	for (int i = 0; i < 10; ++i) {
		k = ((float)rand() / RAND_MAX) * 100;
		fprintf(fp,"%02d\n",k);
	}
	fclose(fp);
}

void third() {
	int k;
	FILE* fp;
	fp = fopen("Random Ns.txt", "r");
	do{
		fscanf(fp, "%2d\n", &k);
		printf("%2d\n", k);
	} while (!feof(fp));
	fclose(fp);
}

void forth() {
	int k;
	FILE* fp;
	fp = fopen("Ciao.txt", "r");
	do {
		k = fgetc(fp);
		printf("%c", (char)k);
		break;
	} while (!feof(fp));
	fclose(fp);
}

int main() {
	first();
	second();
	third();
	forth();
	fileReader_Writer();
	return 0;
}