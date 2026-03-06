#include <stdio.h>
#include <stdlib.h>

//this is the optimal version i.e it has time complexity O(1) as we made the code in
//a way that it always points to the last node whenever the add_at_end function is called

struct Node{
    int data;
    struct Node*link;
};

struct Node* add_at_end(struct Node*ptr,int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}

int main(){
    struct Node*head;
    head=malloc(sizeof(struct Node));
    head->data=69;
    head->link=NULL;

    struct Node*ptr;
    ptr=head;

    ptr=add_at_end(ptr,65);
    ptr=add_at_end(ptr,89);
    ptr=add_at_end(ptr,99);

    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}