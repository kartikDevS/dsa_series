#include <stdio.h>
#include <stdlib.h>


struct queue {
	int data;
	struct queue *next;
};

typedef struct queue *Q;
Q front = NULL, rear = NULL;

void enqueue(int element) {
	Q newNode=malloc(sizeof(struct queue));
	newNode->data=element;
	newNode->next=NULL;
	if(front==NULL){
		front=rear=newNode;
		printf("Successfully inserted.\n");
		return;
	}
	rear->next=newNode;
	rear=newNode;
	printf("Successfully inserted.\n");
}

void dequeue() {
	if(front==NULL){
		printf("Queue is underflow.\n");
		return;
	}
	Q temp=front;
	front=front->next;
	printf("Deleted value = %d\n",temp->data);
	free(temp);
	temp=NULL;
}

void size() {
	if(front==NULL){
		printf("Queue size : 0\n");
		return;
	}
	Q ptr=front;
	int size=1;
	while(ptr!=rear){
		size++;
		ptr=ptr->next;
	}
	printf("Queue size : %d\n",size);
}

void isEmpty() {
	if(front==NULL){
		printf("Queue is empty.\n");
	}
	else{
		printf("Queue is not empty.\n");
	}
}

void display() {
	if(front == NULL) {
		printf("Queue is empty.\n");
	} else {
		Q temp = front;
		printf("Elements in the queue : ");
		while(temp  != NULL) {
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}

