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

struct Node* addBegin(struct Node*tail,int data){
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    if(tail==NULL){
        newNode->link=newNode;
        return newNode;
    }
    newNode->link=tail->link;
    tail->link=newNode;
    return tail;
}

struct Node* addPos(struct Node*tail,int pos,int data){
    struct Node*newP=malloc(sizeof(struct Node));
    newP->data=data;
    if(tail==NULL){
        newP->link=newP;
        return newP;
    }
    struct Node*ptr=tail->link;
    while(pos>1){
        ptr=ptr->link;
        pos--;
    }
    newP->link=ptr->link;
    ptr->link=newP;
    return tail; // well there no need to return tail in add pos and add begin cause tail remains same so u can simply make a function that return void
}

struct Node* createList(struct Node*tail){
    int i,n,data;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);
    if(n==0){
        return tail;
    }
    printf("Enter element 1: ");
    scanf("%d",&data);
    tail=addEmpty(data);
    
    for(i=1;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&data);
        tail=addLast(tail,data);
    }
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
    tail=createList(tail);
    print(tail);
}