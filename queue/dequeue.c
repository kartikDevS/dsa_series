struct queue {
	int data;
	struct queue *next;
};
typedef struct queue *DeQueue;
DeQueue front = NULL, rear = NULL;

void push(int ele) {
	DeQueue temp = NULL;
	temp = (DeQueue)malloc(sizeof(struct queue));
	if(temp == NULL) {
		printf("Dequeue is overflow.\n");
	} else {
		temp->data = ele;
		temp->next = front;   // new node points to current front
		front = temp;         // update front
		if(rear == NULL) {    // if queue was empty
			rear = temp;
		}
		printf("Successfully inserted at front side.\n");
	}
}

void pop() {
	DeQueue temp = NULL;
	if(front == NULL) {
		printf("Dequeue is underflow.\n");
	} else {
		temp = front;
		front = front->next;   // move front forward
		if(front == NULL) {    // if queue became empty
			rear = NULL;
		}
		printf("Deleted element %d from the front side.\n", temp->data);
		free(temp);
	}
}


void inject(int ele) {
	DeQueue temp = NULL;
	temp = (DeQueue)malloc(sizeof(struct queue));
	if(temp == NULL) {
		printf("Dequeue is overflow.\n");
	} else {
		temp -> data = ele;
		temp -> next = NULL;
		if(front == NULL) {
			front = temp;
		} else {
			rear -> next = temp;
		}
		rear = temp;
		printf("Successfully inserted at rear side.\n");
	}
}

void eject() {
	DeQueue temp = NULL;
	if(rear == NULL) {
		printf("Dequeue is underflow.\n");
	} else {
		temp = front;
		if (front == rear) {
			front = rear = NULL;
		} else {
			while(temp -> next != rear) { 
				temp = temp -> next;
			}
			rear=temp;
			temp = rear -> next;
			rear->next = NULL;
		}
		printf("Deleted element %d from the rear side.\n", temp -> data);
		free(temp);
	}
}

void display() {
	if(front == NULL) {
		printf("Double ended queue is empty.\n");
	} else {
		DeQueue temp = front;
		printf("Elements in the double ended queue : \n");
		while(temp != NULL) { 
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}