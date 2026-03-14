#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* rev_list(struct Node*head){
    struct Node*prev=NULL;
    struct Node*next=NULL;
    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
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

    head=rev_list(head);

    ptr=head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}