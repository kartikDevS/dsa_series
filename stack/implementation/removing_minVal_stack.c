// Write the code.....
#include <stdio.h>
#define MAX 100

struct Stack {
int arr[MAX];
int top;
};

void initStack(struct Stack* stack){
	stack->top=-1;
}


void push(struct Stack* stack,int element){
	if(stack->top==MAX-1)return;
	stack->arr[++stack->top]=element;
}

int pop(struct Stack* stack){
	if(stack->top==-1)return -1;
	return stack->arr[stack->top--];
}

int main(){
	int n;
	scanf("%d",&n);
	int x;
	
	struct Stack stack1;
	initStack(&stack1);
	
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		push(&stack1,x);
	}
int min = stack1.arr[0];
	for (int i = 1; i <= stack1.top; i++) {
		if (stack1.arr[i] < min) {
			min = stack1.arr[i];
		}
	}

	for (int i = 0; i <= stack1.top; i++) {
		if (stack1.arr[i] != min) {
			printf("%d ", stack1.arr[i]);
		}
	}
	printf("\n");

	return 0;
}
