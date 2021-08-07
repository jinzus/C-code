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
	Record* pre;
};

Record* list = NULL;

void init(Record *r) {
	Record* firstL = new Record();
	Record* lastL=new Record();
	firstL->pre = NULL;
	firstL->next = r;
	r->pre = firstL;
	r->next = lastL;
	lastL->pre = r;
	lastL->next = NULL;
	list = firstL;
}

void printer(const Record* record) {
	printf("Code: %3d, Name: %s, Pointer backward: %p, Pointer forward: %p\n", record->id, record->name,record->pre, record->next);
}

void printAll() {
	Record* curr = list;
	curr = curr->next;
	do{
		printer(curr);
		if(curr->next) curr = curr->next;
	} while (curr->next);
}

void insert_after(Record *n, Record* r) {
	n->next = r->next;
	r->next = n;
	n->pre = r;
	n->next->pre = n;
	return;
}

void insert_before(Record* n, Record* r) {
	n->pre = r->pre;
	r->pre = n;
	n->next = r;
	n->pre->next = n;
	return;
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
	Record* r = get(id);
	r->pre->next = r->next;
	r->next->pre = r->pre;
	delete r;
	r=nullptr;
}

int main() {
	Record* r1 = new Record({0,"Maria",NULL,NULL});
	Record* r2 = new Record({ 1,"Maria",NULL,NULL });
	Record* r3 = new Record({ 2,"Giovanni",NULL,NULL });
	Record* r4 = new Record({ 3,"Andrea",NULL,NULL });
	Record* r5 = new Record({ 4,"Luca",NULL,NULL });
	init(r1);
	insert_after(r2,r1);
	insert_before(r3, r1);
	insert_before(r4, r1);
	remove(0);
	insert_before(r5, r3);
	remove(1);
	printAll();
	return 0;
}