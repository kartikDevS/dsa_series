#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* addEmpty(int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=temp;
    return temp;
}

int main(){
    struct Node*tail;
    tail=addEmpty(14);
    printf("%d",tail->data);
}