#include <stdio.h>
#include <stdlib.h>

struct Node*ptr;

struct Node{
    int data;
    struct Node*link;
};

void add_at_end(struct Node**head,int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;

    if(*head==NULL){
        *head=temp;
        return;
    }
    ptr=*head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void add_at_pos(struct Node*head,int data,int pos){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;

    ptr=head;

    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
}

int main(){
    struct Node*head=malloc(sizeof(struct Node));
    head->data=13;
    head->link=NULL;

    add_at_end(&head,15);
    add_at_end(&head,17);
    add_at_end(&head,19);

    int pos=3; int data=30;
    add_at_pos(head,21,3);
    add_at_pos(head,23,5);


    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}