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

void add(Record* record) {
	Record* curr = list;
	if (curr->next == NULL) {
		curr->next = record;
		return;
	}
	else {
		Record* pre = curr;
		curr = curr->next;
		if (curr->id > record->id) {
			pre->next = record;
			record->next = curr;
			return;
		}
		while (curr->next) {
			pre = curr;
			curr = curr->next;
			if ((pre->id < record->id) && (curr->id > record->id)) {
				pre->next = record;
				record->next = curr;
				return;
			}
		}
		if (!curr->next) {
			curr->next = record;
		}
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
	add(r6);
	add(r5);
	add(r4);
	add(r3);
	add(r2);
	add(r1);
	printAll();
	printf("\n\n\n");
	remove(2);
	remove(4);
	printAll();
	printf("\n\n\n");
	Record* r7;
	r7 = new Record({ 2,"Pasto",NULL });
	Record* r8;
	r8 = new Record({ 4,"Marta",NULL });
	add(r7);
	add(r8);
	printAll();
	return 0;
}