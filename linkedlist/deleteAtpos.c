#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};


void delete_at_pos(struct Node**head,int pos){
    struct Node*current=*head;
    struct Node*previous=*head;

    if(*head==NULL){
        printf("Linkedlist is empty\n");
    }
    else if(pos==1){
        *head=current->link;
        free(current);
        current=NULL;
    }
    else{
        while(pos!=1){
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
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

    int pos=3;
    delete_at_pos(&head,pos);

    ptr=head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}