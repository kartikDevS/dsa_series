#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top1 = -1;        // Stack 1 grows from left
int top2;             // Stack 2 grows from right

// Push into Stack 1
void push1(int val, int size) {
	if (top1 + 1 == top2) return; // array full
	stack[++top1] = val;
}

// Push into Stack 2
void push2(int val, int size) {
	if (top2 - 1 == top1) return; // array full
	stack[--top2] = val;
}

// Pop from Stack 1
void pop1() {
	if (top1 == -1) return; // empty
	top1--;
}

// Pop from Stack 2
void pop2(int size) {
	if (top2 == size) return; // empty
	top2++;
}

int main() {
	int size, ops;
	scanf("%d", &size);
	scanf("%d", &ops);

	top2 = size; // initialize Stack 2 at right end

	for (int i = 0; i < ops; i++) {
		int type, val;
		scanf("%d", &type);
		if (type == 1) { // push stack1
			scanf("%d", &val);
			push1(val, size);
		} else if (type == 2) { // push stack2
			scanf("%d", &val);
			push2(val, size);
		} else if (type == 3) { // pop stack1
			pop1();
		} else if (type == 4) { // pop stack2
			pop2(size);
		}
	}

	// Print final state
	if (top1 == -1 && top2 == size) {
		printf("-1\n");
	} else {
		// Stack 1 bottom to top
		for (int i = 0; i <= top1; i++) {
			printf("%d ", stack[i]);
		}
		// Stack 2 bottom to top
		for (int i = size - 1; i >= top2; i--) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}

	return 0;
}
