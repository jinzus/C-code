#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define MAX_LEN 10

struct Record {
	int id;
	char name[MAX_LEN + 1];
	Record* next;
};

Record* list = NULL;

void init() {
	Record* r = new Record();
	r->next = NULL;
	list = r;
}

void printer(const Record* record) {
	printf("Code: %3d, Name: %s, Pointer: %p\n", record->id, record->name, record->next);
}

void printAll() {
	Record* curr = list;
	curr = curr->next;
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
	Record* curr = list;
	while (curr->next) {
		curr = curr->next;
	}
	return curr;
}

void add(Record* record) {
	Record* curr = last();
	insert_after(curr, record);
}

void add_after(const int id, Record* record) {

	Record* curr = list;
	while (curr->id != id) {
		curr = curr->next;
	}
	if (!curr->next) {
		curr = last();
		insert_after(curr, record);
	}
	else {
		record->next = curr->next;
		curr->next = record;
	}
}

Record* get(const int id) {
	Record* curr = list;
	curr = curr->next;
	while (curr->id != id) {
		curr = curr->next;
	}
	return curr;
}

void remove(const int id) {
	Record* curr = list;
	Record* prev = NULL;
	prev = curr;
	curr = curr->next;
	while (curr->id != id) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
	curr = NULL;
}

int main() {
	init();
	Record* r1;
	r1 = new Record({ 0,"Andrea",NULL });
	Record* r2;
	r2 = new Record({ 1,"Marco",NULL });
	Record* r3;
	r3 = new Record({ 2,"Pasto",NULL });
	Record* r4;
	r4 = new Record({ 3,"Jhon",NULL });
	Record* r5;
	r5 = new Record({ 4,"Marta",NULL });
	Record* r6;
	r6 = new Record({ 5,"Giova",NULL });
	add(r1);
	add(r2);
	add(r3);
	add(r4);
	add(r5);
	add_after(4, r6);
	remove(5);
	printAll();
	remove(0);
	printf("\n\n\n");
	printAll();
	printf("\n\n\n");
	for (int i = 1; i < 5; ++i) {
		printer(get(i));
	}
	return 0;
}