#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define MAX_LEN 10
#define TRI int 
#define FALSE 0
#define TRUE !FALSE

struct Record {
	int id;
	char name[MAX_LEN + 1];
	Record* next;
};

TRI str_compare(char str1[], char str2[]) {
	char* char1 = str1;
	char* char2 = str2;
	while (1) {
		if (*char1 && *char2) {
			if (*char1 > *char2) {
				return 1;
			}
			else if (*char1 == *char2) {
				++char1;
				++char2;
			}
			else {
				return 0;
			}
		}
		else if (!*char1 && *char2) {
			return 0;
		}
		else if (*char1 && !*char2) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

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
		if (str_compare(curr->name,record->name)) {
			pre->next = record;
			record->next = curr;
			return;
		}
		while (curr->next) {
			pre = curr;
			curr = curr->next;
			if(str_compare(record->name,pre->name)&& str_compare(curr->name, record->name)){
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
	Record* r1 = new Record({ 1,"Erika",NULL });
	Record* r2 = new Record({ 112,"Mario",NULL });
	Record* r3 = new Record({ 45,"Alberto",NULL });
	Record* r4 = new Record({ 97,"Sara",NULL });
	Record* r5 = new Record({ 19,"Andrea",NULL });
	add(r1);
	add(r2);
	add(r3);
	add(r4);
	add(r5);
	printAll();
	return 0;
}