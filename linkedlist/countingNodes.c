#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

void countNode(struct Node* head){
    int count=0;
    if(head==NULL){
        printf("Linkedlist is empty\n");
    }
    struct Node* ptr;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    printf("%d",count);
}

int main(){
    struct Node* head=NULL;
    head=malloc(sizeof(struct Node));
    head->data=46;
    head->link=NULL;

    struct Node* current=NULL;
    current=malloc(sizeof(struct Node));
    current->data=56;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct Node));
    current->data=12;
    current->link=NULL;
    head->link->link=current;

    countNode(head);

    return 0;
}