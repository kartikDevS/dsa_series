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
    int data=pop();
    data=pop();
}