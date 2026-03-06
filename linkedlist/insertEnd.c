#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

void add_at_end(struct Node*head,int data){
    struct Node* ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link=NULL){ 
        ptr=ptr->link;
    }
    ptr->link=temp;
}

int main(){

    add_at_end(head,65);

    return 0;
}