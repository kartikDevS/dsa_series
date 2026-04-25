struct stack {
	int data;
	struct stack *next;
};
typedef struct stack *stk;
struct queue{
	stk stack1;
	stk stack2;
};
typedef struct queue* Q;
Q que;
void push(stk* stack, int x) {
	stk temp;
	temp = (stk)malloc(sizeof(struct stack));
	if(temp == NULL) {
		printf("Stack is overflow.\n");
		return ;
	} else {
		temp -> data = x;
		temp -> next = *stack;
		*stack = temp;
	}
}
int pop(stk* stack) {
	stk temp;
	if(stack == NULL) {
		printf("Stack is underflow.\n");
		return -1;
	} else {
		temp = *stack;
		*stack = temp -> next;
		return temp->data;
	}
}
void enqueue(int ele) {
	push(&que->stack1,ele);
	printf("Successfully inserted.\n");
}
void dequeue() {
	if(que->stack2==NULL && que->stack1==NULL){
		printf("Queue is underflow.\n");
		return;
	}
	if(que->stack2==NULL){
		while(que->stack1!=NULL){
			push(&que->stack2,pop(&que->stack1));
		}
	}
	int val=pop(&que->stack2);
	printf("Deleted value = %d\n",val);
}
void display() {
	if(que->stack1==NULL && que->stack2==NULL){
		printf("Queue is empty.\n");
		return;
	}
	stk ptr1=que->stack1 ,ptr2=que->stack2;
	while(ptr1!=NULL){
		printf("%d ",ptr1->data);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL){
		printf("%d ",ptr2->data);
		ptr2=ptr2->next;
	}
	printf("\n");
}