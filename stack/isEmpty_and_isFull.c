#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1)return 1;
    else{return 0;}
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return  0;
    }
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    int val=stack_arr[top];
    top=top-1;
    return val;
}

void print(){
    if(isEmpty()){
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    push(6);
}