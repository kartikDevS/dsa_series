// In the given singly linked list program we have two files, one file contains the main program and the other file contains the functions, to be implemented by the user.



// Here the user has to implement the code for two functions addNodes() and traverseList(). The addNodes() function creates a new list and adds elements to the list until delimiter -1 is occurred.



// Fill in the missing code in the below functions addNodes(NODE first, int x) and traverseList(NODE first) in the file CreateAndAddNodes.c.



#include<stdio.h>
#include<stdlib.h>

// #include "CreateAndAddNodes.c"

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE createNode(int x) {
    NODE temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

NODE addNodes(NODE first, int x) {
    NODE temp,ptr;
    temp=createNode(x);
    if(first==NULL){
        first=temp;
    }
    else{
        ptr=first;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return first;
}

void traverseList(NODE first) {
    NODE ptr=first;
    while(ptr!=NULL){
        printf("%d --> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

void main() {
	NODE first = NULL;
	int x;
	printf("Enter elements up to -1 : ");
	scanf("%d", &x);
	while (x != -1) {
		first = addNodes(first, x);
		scanf("%d", &x);
	}
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		printf("The elements in SLL are : ");
		traverseList(first);
	}
}



