#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void dequeue() {
	// write your code here
	if(front==-1){
		printf("Circular queue is underflow.\n");
		return;
	}
	printf("Deleted element = %d\n",queue[front]);
	if(front==rear){
		front=rear=-1;
	}
	else{
		front=(front+1)%MAX;
	}
}

void enqueue(int x) {
	// write your code here
	if((rear==MAX-1 && front==0) || rear+1==front){
		printf("Circular queue is overflow.\n");
		return;
	}
	if(front==-1){
		front=0;
	}
	if(rear==MAX-1){
		rear=-1;//u dont have to do rear==MAX here cause dont think that this way element never gets assigned to MAX-1 cause as soon rear reaches it it becomes -1 because here we are doing ++rear=x so when rear was at 6 value was assigned at 7 .
	}
	queue[++rear]=x;
	printf("Successfully inserted.\n");
}

void display() {
	// write your code here
	if(front==-1){
		printf("Circular queue is empty.\n");
		return;
	}
	else{
		printf("Elements in the circular queue : ");
		if(front<=rear){
			for(int i=front;i<=rear;i++){
				printf("%d ",queue[i]);
			}
		}
		else{
			for(int i=front;i<=MAX-1;i++){
				printf("%d ",queue[i]);
			}
			for(int i=0;i<=rear;i++){
				printf("%d ",queue[i]);
			}
		}
		printf("\n");
	}
}

void size() {
	// write your code here
	if(front==-1){
		printf("Circular queue size : 0\n");
		return;
	}
	else{
		if(front<=rear){
			printf("Circular queue size : %d\n",rear-front+1);
		}
		else{
			printf("Circular queue size : %d\n",MAX-(front-rear-1));
		}
	}
}

void isEmpty() {
	// write your code here
	if(front==-1){
		printf("Circular queue is empty.\n");
	}
	else{
		printf("Circular queue is not empty.\n");
	}
}



int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is empty 5.Size 6.Exit\n");
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