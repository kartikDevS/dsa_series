#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};
int main(){
    struct Node* head=NULL;
    head=malloc(sizeof(struct Node));
    head->data=45;
    head->link=NULL;

    struct Node*current=NULL;
    current=malloc(sizeof(struct Node));
    current->data=34;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct Node));
    current->data=13;
    current->link=NULL;
    head->link->link=current;


    return 0;
}