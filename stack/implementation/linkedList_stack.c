#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
typedef struct stack *stk;

stk top=NULL;

void push(int x){
    stk newNode=malloc(sizeof(struct stack));
    newNode->data=x;
    newNode->next=NULL;

    newNode->next=top;
    top=newNode;
}

void pop(){
    if(top==NULL){
        printf("Stack is underflow.\n");
        return;
    }
    printf("Deleted element : %d\n",top->data);
    top=top->next;
}

void display(){
    if(top==NULL){
        printf("Stack is empty.\n");
        return;
    }
    stk ptr=top;
    printf("Elements in the stack are: ");
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("<-\n");
}

void peek(){
    if(top==NULL){
        printf("Stack is empty.\n");
        return;
    }
    printf("Element at the top: %d\n",top->data);
}

void isEmpty(){
    if(top==NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack is not empty.\n");
    }
}

int main(){
    int op,x;
    while (1) {
        printf("1.Push 2.Pop 3.Display 4.Peek 5.isEmpty 6.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&op);
        switch(op) {
            case 1:
            printf("Enter the element u want insert: ");
            scanf("%d",&x);
            push(x);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            peek();
            break;

            case 5:
            isEmpty();
            break;

            case 6:
            exit(0);
        }
    }
    return 0;
}