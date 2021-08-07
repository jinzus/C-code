#include <stdio.h>
#define len 10

void show(int arr[]) {
	for (int i = 0; i < len; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

int ascending(int ARR[]) {
	int END = 1;
	for (int i = 0; i < len - 1; i++) {
		if (ARR[i + 1] < ARR[i]) {
			END = 0;
			break;
		}
	}
	if (END) {
		return END;
	}else{
		int temp = 0;
		for (int i = 0; i < len - 1; i++) {
			if (ARR[i + 1] < ARR[i]) {
				temp = ARR[i];
				ARR[i] = ARR[i + 1];
				ARR[i + 1] = temp;
			}
		}
	}
	return	END;
}

int descending(int ARR[]) {
	int END = 1;
	for (int i = 0; i < len - 1; i++) {
		if (ARR[i + 1] > ARR[i]) {
			END = 0;
			break;
		}
	}
	if (END) {
		return END;
	}else{
		int temp = 0;
		for (int i = 0; i < len - 1; i++) {
			if (ARR[i + 1] > ARR[i]) {
				temp = ARR[i];
				ARR[i] = ARR[i + 1];
				ARR[i + 1] = temp;
			}
		}
	}
	return	END;
}

void sort(int arr[],int (*funPtr)(int ARR[])) {
	int end;
	do {
		end = (*funPtr)(arr);
		if (end) break;
		show(arr);
	} while (!end);
}

int main() {
	int A[len] = { 23,17,13,29,5,3,11,2,7,19 };
	show(A);
	sort(A,ascending);
	printf("\n\n\n");
	show(A);
	sort(A, descending);
	return 0;
}