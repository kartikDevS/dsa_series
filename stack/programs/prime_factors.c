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

void fact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    printf("Prime factors are: ");
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    fact(x);
}