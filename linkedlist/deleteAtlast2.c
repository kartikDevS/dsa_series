#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

void delete_last(struct Node**head){
    if(*head==NULL){
        printf("Linkedlist is empty\n");
        return;
    }
    else if((*head)->link==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        struct Node*temp=*head;

        while(temp->link->link!=NULL){
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
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

    // ptr=malloc(sizeof(struct Node));
    // ptr->data=16;
    // ptr->link=NULL;
    // head->link->link=ptr;

    // ptr=malloc(sizeof(struct Node));
    // ptr->data=17;
    // ptr->link=NULL;
    // head->link->link->link=ptr;


    delete_last(&head);

    ptr=head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}