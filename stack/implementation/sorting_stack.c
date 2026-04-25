#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
	stack[++top] = val;
}

int pop() {
	return stack[top--];
}

int isEmpty() {
	return top == -1;
}

void printStack() {
	for (int i = top; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void sortStack() {
	int temp[MAX];
	int tempTop = -1;

	while (!isEmpty()) {
		int curr = pop();

		// Move larger elements back to original stack
		while (tempTop != -1 && temp[tempTop] > curr) {
			push(temp[tempTop--]);
		}

		// Place current element in temp
		temp[++tempTop] = curr;
	}

	// Move sorted elements back to original stack
	while (tempTop != -1) {
		push(temp[tempTop--]);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		push(val);
	}

	printf("Original: ");
	printStack();

	sortStack();

	printf("After sorting: ");
	printStack();

	return 0;
}
