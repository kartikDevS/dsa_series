#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int stack[MAX];
int top = -1;

int main() {
	int opsSize;
	scanf("%d", &opsSize);

	char op[20];  // buffer for each operation
	int sum = 0;

	for (int i = 0; i < opsSize; i++) {
		scanf("%s", op);

		if (isdigit(op[0]) || (op[0] == '-' && isdigit(op[1]))) {
			// integer score (handles negatives too)
			int val = atoi(op);
			stack[++top] = val;
		} 
		else if (strcmp(op, "+") == 0) {
			if (top >= 1) {
				int val = stack[top] + stack[top - 1];
				stack[++top] = val;
			}
		} 
		else if (strcmp(op, "D") == 0) {
			if (top >= 0) {
				int val = 2 * stack[top];
				stack[++top] = val;
			}
		} 
		else if (strcmp(op, "C") == 0) {
			if (top >= 0) {
				top--;  // invalidate last score
			}
		}
	}

	// calculate total sum
	for (int i = 0; i <= top; i++) {
		sum += stack[i];
	}

	printf("%d\n", sum);
	return 0;
}

