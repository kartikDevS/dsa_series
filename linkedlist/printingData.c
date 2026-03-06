#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

void print(struct Node*head){
    if(head==NULL){
        printf("Linkedlist is empty");
    }
    struct Node*ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

int main(){

    struct Node*head=NULL;
    head=malloc(sizeof(struct Node));
    head->data=34;
    head->link=NULL;

    struct Node*current=NULL;
    current=malloc(sizeof(struct Node));
    current->data=57;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct Node));
    current->data=23;
    current->link=NULL;
    head->link->link=current;

    print(head);

    return 0;
}