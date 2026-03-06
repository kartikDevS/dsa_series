#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

int main(){
    struct Node* head=NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data=45;         // this(" -> "") is a alternative of doing it like *(head).data , so this arrow does both pointing to  data by (*) and specific value by (.) at once
    head->link=NULL;
    printf("%d",head->data);
}