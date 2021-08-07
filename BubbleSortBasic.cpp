#include <stdio.h>
#define len 10

void show(int arr[]) {
	for (int i = 0; i < len; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void sort(int arr[]) {
	int end;
	do {
		end = 1;
		for (int i = 0; i < len - 1; i++) {
			if (arr[i + 1] < arr[i]) {
				end = 0;
				break;
			}
		}
		if (end) {
			break;
		}else{
			int temp = 0;
			for (int i = 0; i < len - 1; i++) {
				if (arr[i + 1] < arr[i]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
		show(arr);
	} while (!end);
}

int main() {
	int A[len] = { 23,17,13,29,5,3,11,2,7,19 };
	show(A);
	sort(A);
	return 0;
}