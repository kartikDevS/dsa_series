#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL(int x) {
	NODE temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}

NODE insertAtPositionInCLL(NODE first,int pos,int x) {
	NODE temp=createNodeInCLL(x);
	if(first==NULL){
		if(pos==1){
			first=temp;
			first->next=first;
			return first;
		}
		else{
			printf("Position not found\n");
			return first;
		}
	}
	if(pos==1){
		NODE ptr=first;
		while(ptr->next!=first){
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=first;
		first=temp;
		return first;
	}
	NODE ptr=first;
	pos--;
	while(pos>1 && ptr->next!=first){
		ptr=ptr->next;
		pos--;
	}
	if(pos>1){
		printf("Position not found\n");
		return first;
	}
	temp->next=ptr->next;
	ptr->next=temp;
	return first;
}

NODE deleteAtPositionInCLL(NODE first,int pos) {
	if(first->next==first){
		if(pos==1){
			printf("Deleted element: %d\n",first->data);
			free(first);
			return NULL;
		}
		else{
			printf("Position not found\n");
			return first;
		}
	}
	if(pos==1){
		NODE ptr=first;
		while(ptr->next!=first){
			ptr=ptr->next;
		}
		ptr->next=first->next;
		printf("Deleted element: %d\n",first->data);
		free(first);
		first=ptr->next;
		return first;
	}
	NODE ptr=first;
	NODE prev=NULL;
	while(pos>1 && ptr->next!=first){
		prev=ptr;
		ptr=ptr->next;
		pos--;
	}
	if(pos>1){
		printf("Position not found\n");
		return first;
	}
	prev->next=ptr->next;
	printf("Deleted element: %d\n",ptr->data);
	free(ptr);
	return first;

}

void traverseListInCLL( NODE first  ) {
	NODE ptr=first;
	do{
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	} while(ptr!=first);
	printf("\n");
}

void main() {
	NODE first = NULL;
	int x, pos, op;
	while(1) {
		printf("1.Insert 2.Delete 3.Display 4.Exit\n");
		printf("choice: ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Position: ");
					scanf("%d", &pos);
					if (pos <= 0) {
						printf("Position not found\n");
					} else {
						printf("Element: ");
						scanf("%d", &x);
						first = insertAtPositionInCLL(first, pos, x);
					}
					break;
	        case 2:	if (first == NULL) {
						printf("CLL is empty\n");
					} else {
						printf("Position: ");
						scanf("%d", &pos);
						first = deleteAtPositionInCLL(first, pos);
					}
					break;
			case 3:	if (first == NULL) {
						printf("CLL is empty\n");
					} else {
						printf("Elements in CLL are: ");
						traverseListInCLL(first);
					}
					break;
			case 4:	exit(0);
		}
	}
}
