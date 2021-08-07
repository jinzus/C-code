#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

struct Record {
	int num;
	char name[MAX_LEN + 1];
	Record* next;
};

Record* list = NULL;

void printer(const Record* record) {
	printf("Code: %3d, Name: %s, Pointer: %p\n", record->num, record->name, record->next);
}

void printAll() {
	Record* curr = list;
	while (curr) {
		printer(curr);
		curr = curr->next;
	}
}

void insert_after(Record* r, Record* n) {
	n->next = r->next;
	r->next = n;
}

Record* last() {
	Record* curr;
	curr = list;
	while (true) {
		if (!curr->next) break;
		curr = curr->next;
	}
	return curr;
}

void add(Record* r) {
	Record* curr;
	curr = last();
	insert_after(curr, r);
}

Record* remover(Record* r) {
	Record* curr = list;
	Record* prev = NULL;
	while (curr != r) {
		prev = curr;
		curr = curr->next;
	}
	if (curr == r) {
		prev->next = curr->next;
	}
	return curr;
}

int main() {
	Record r1;
	r1.num = 10;
	strcpy(r1.name, "Andrea");
	r1.next = NULL;
	list = &r1;
	Record r2;
	r2.num = 20;
	strcpy(r2.name, "Marco");
	r2.next = NULL;
	add(&r2);
	Record r3;
	r3.num = 30;
	strcpy(r3.name, "Maria");
	r3.next = NULL;
	add(&r3);
	printAll();
	remover(&r3);
	printf("\n\n\n");
	printAll();
	add(&r3);
	printf("\n\n\n");
	printAll();
	return 0;
}