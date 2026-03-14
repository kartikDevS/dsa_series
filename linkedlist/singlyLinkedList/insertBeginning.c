#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* at_the_begin(struct Node*head,int data){
    struct Node*ptr=malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->link=NULL;
    
    ptr->link=head;
    head=ptr;
    return head;
}

int main(){
    struct Node*head;
    head=malloc(sizeof(struct Node));
    head->data=13;
    head->link=NULL;

    struct Node*ptr=malloc(sizeof(struct Node));
    ptr->data=15;
    ptr->link=NULL;
    head->link=ptr;
    
    head=at_the_begin(head,19);

    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}