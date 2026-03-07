#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* delete_last(struct Node*head){
    if(head==NULL){
        printf("Linkedlist is empty\n");
        return NULL;
    }
    if(head->link==NULL){
        free(head);
        return NULL;
    }
    struct Node*temp1;
    struct Node*temp2;

    temp1=head;
    while(temp1->link->link!=NULL){
        temp1=temp1->link;
    }
    temp2=temp1->link;
    temp1->link=NULL;
    free(temp2);
    return head;
}

int main(){
    struct Node*head=malloc(sizeof(struct Node));
    head->data=13;
    head->link=NULL;

    struct Node*ptr=malloc(sizeof(struct Node));
    ptr->data=15;
    ptr->link=NULL;
    head->link=ptr;

    // ptr=malloc(sizeof(struct Node));
    // ptr->data=16;
    // ptr->link=NULL;
    // head->link->link=ptr;

    // ptr=malloc(sizeof(struct Node));
    // ptr->data=17;
    // ptr->link=NULL;
    // head->link->link->link=ptr;


    head=delete_last(head);

    ptr=head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}