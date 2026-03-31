#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top=-1;

void push(int data){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}

void print(){
    if(top==-1){
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        exit(1);
    }
    int val=stack_arr[top];
    top=top-1;
    return val;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    int data=pop();
    print();
    push(5);
    print();
}