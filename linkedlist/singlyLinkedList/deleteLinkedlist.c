#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* del_list(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
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

    ptr=malloc(sizeof(struct Node));
    ptr->data=16;
    ptr->link=NULL;
    head->link->link=ptr;

    ptr=malloc(sizeof(struct Node));
    ptr->data=17;
    ptr->link=NULL;
    head->link->link->link=ptr;

    head=del_list(head);

    if(head==NULL){
        printf("Linkedlist is empty");
    }
    return 0;
}