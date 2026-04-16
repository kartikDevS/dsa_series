#include <stdlib.h>
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x){
	// write your code here to enqueue an element
	if(rear==MAX-1){
		printf("Queue is overflow.\n");
		return;
	}
	if(front==-1)front=0;
	queue[++rear]=x;
	printf("Successfully inserted.\n");
}
void dequeue() {
	// write your code here to dequeue an element
	if(front==-1 || front>rear){
		printf("Queue is underflow.\n");
		return;
	}
	printf("Deleted element = %d\n",queue[front++]);
	if(front>rear){
		front=rear=-1;
	}
}
void display() {
	// write your code here to display the queue
	if(rear==-1){
		printf("Queue is empty.\n");
		return;
	}
	printf("Elements in the queue : ");
	for(int i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}
void size() {
	// write your code here to get the size of the queue
	if(rear==-1){
		printf("Queue size : 0\n");
		return;
	}
	printf("Queue size : %d\n",rear-front+1);
}
void isEmpty() {
	// write your code here to check whether the queue is empty not
	if(rear==-1){
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue is not empty.\n");
}


int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}