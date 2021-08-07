#ifndef _INTESTAZIONE_H
	#define _INTESTAZIONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESCR_SIZE 100

struct Linea {
	char line[DESCR_SIZE + 1];
	Linea* next;
};

Linea* lista = NULL;

void init() {
	Linea* r = new Linea();
	r->next = NULL;
	lista = r;
}

Linea* last(){
	Linea *curr;
	curr = lista;
	while (curr->next) {
		curr = curr->next;
	}
	return curr;
}

void add(const char *s) {
	Linea* r = new Linea({"\0",NULL});
	Linea *curr = lista;
	strcpy(r->line, s);
	if (!curr->next) {
		r->next = curr->next;
		curr->next = r;
	}
	else {
		while (curr->next) {
			if (strcmp(curr->next->line, s) > 0) break;
			curr = curr->next;
		}
		r->next = curr->next;
		curr->next = r;
	}
}

void getline(FILE *fp) {
	char buffer[DESCR_SIZE + 1];
	char c;
	int i;
	while (!feof(fp)) {
		i = 0;
		while (1){
			c = fgetc(fp);
			if (feof(fp) || c == '\n' || c == EOF) break;
			buffer[i++] = c;
		}
		buffer[i] = '\0';
		add(buffer);
	}
}

void fileReader_Writer() {
	FILE* FR;
	FR=fopen("Lista testo.txt","r");
	init();
	getline(FR);
	fclose(FR);
	FILE* FW;
	FW=fopen("Lista testo ordinata.txt", "w");
	Linea* curr = lista;
	while (curr->next) {
		curr = curr->next;
		fprintf(FW,"%s\n",curr->line);
	}
	fclose(FW);
}

#endif