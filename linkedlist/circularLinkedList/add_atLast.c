#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* addLast(struct Node*tail,int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    if(tail==NULL){
        temp->link=temp;
        return temp;
    }
    temp->link=tail->link;
    tail->link=temp;
    tail=temp;
    return tail;
}

void print(struct Node*tail){
    if(tail==NULL){
        return;
    }
    struct Node*ptr=tail->link;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    while(ptr!=tail->link);
}

int main(){
    struct Node*tail=NULL;
    tail=addLast(tail,14);
    tail=addLast(tail,15);
    tail=addLast(tail,16);
    print(tail);
}