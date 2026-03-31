#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int stack[MAX];
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
    stack[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    int val=stack[top];
    top=top-1;
    return val;
}

void print(){
    if(isEmpty()){
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void dec2bin(int x){
    int num=x;
    while(num>0){
        int rem=num%2;
        push(rem);
        num=num/2;
    }
    printf("Binary of %d is: ",x);
    while(top!=-1){
        printf("%d",pop());
    }
    printf("\n");
}

int main(){
    int x;
    printf("Enter the decimal number: ");
    scanf("%d",&x);
    dec2bin(x);
}