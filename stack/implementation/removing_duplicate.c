#include <stdio.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1) return;
    stack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void removeDuplicates() {
    int temp[MAX], visited[1000] = {0}, i, newTop = -1;

    for (i = 0; i <= top; i++) {
        if (!visited[stack[i]]) {
            visited[stack[i]] = 1;
	        temp[++newTop] = stack[i]; 
        }
    }

    printf("Stack after removing duplicates:\n");
    for (i = newTop; i >= 0; i--) {
        printf("%d ", temp[i]);
    }
     printf("\n");
}

int main() {
    int n, val;
   
    scanf("%d", &n);

 
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    removeDuplicates();
    return 0;
}
