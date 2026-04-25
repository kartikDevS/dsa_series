#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initializeStack(Stack *stack) {
    // Write your code here...
    stack->top=NULL;
    
}

int isEmpty(Stack *stack) {
    // Write your code here...
    return stack->top==NULL;
    
}

void push( Stack *stack,int x    ) {
    // Write your code here...
    Node *new=malloc(sizeof(Node));
	new->data=x;
	new->next=NULL;
	new->next=stack->top;
	stack->top=new;
    printf("Pushed %d\n",x);
}

int pop(Stack*stack) {
    // Write your code here...
	if(isEmpty(stack)){printf("Stack is empty\n"); return -1;}
	Node*temp=stack->top;
	int val=temp->data;
	stack->top=temp->next;
	free(temp);
	printf("Popped %d\n",val);
	return val;
}

int peek(Stack*stack) {
	// Write your code here...
	if(isEmpty(stack)){printf("Stack is empty\n"); return -1;}
	printf("Top Element: %d\n",stack->top->data);
	return stack->top->data;
}

int main() {
    Stack stack;
    initializeStack(&stack);
    int numOperations, choice, value;
    printf("No of operations: ");
    scanf("%d", &numOperations);
    for (int i = 0; i < numOperations; i++) {
        printf("Choose an operation:\n1. Push\n2. Pop\n3. Peek\n4. Check if stack is empty\n5. Exit\nchoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Exiting program!");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
