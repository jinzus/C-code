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

Record* head = NULL;

void printer(const Record* record) {
	printf("Code: %3d, Name: %s, Pointer: %p\n", record->id, record->name, record->next);
}

void printAll() {
	Record* r = head;
	while (r) {
		printer(r);
		r = r->next;
	}
}

void push(Record* r) {
	r->next = head;
	head = r;
}

Record* pop() {
	Record* r = head;
	if (head) {
		head = head->next;
	}
	return r;
}

int length() {
	Record* r = head;
	int n = 0;
	while (r) {
		n++;
		r = r->next;
	}
	return n;
}

int main() {
	Record r1 = { 0,"Andrea",NULL };
	Record r2 = { 1,"Gloria",NULL };
	Record r3 = { 2,"Mario",NULL };
	Record r4 = { 3,"Giovanni",NULL };
	Record r5 = { 4,"Luca",NULL };
	push(&r1);
	push(&r2);
	push(&r3);
	push(&r4);
	push(&r5);
	printf("%d\n",length());
	printer(pop());
	printf("%d\n", length());
	printAll();
	return 0;
}