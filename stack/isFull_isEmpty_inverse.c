#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int first=-1;

int isFull(){
    if(first==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(first==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isFull()){
        printf("stack overflow\n");
        exit(1);
    }
    int i;
    first+=1;
    for(i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}

int pop(){
    if(isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    int value=stack_arr[0];
    for(int i=0;i<first;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    first-=1;
    return value;
}

void print(){
    if(first==-1){
        printf("stack underflow\n");
        exit(1);
    }
    for(int i=0;i<=first;i++){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

void peek(){
    if(isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    printf("%d\n",stack_arr[0]);
}

int main(){
    push(5);
    push(4);
    push(3);
    print();
    int data=pop();
    printf("%d\n",data);
    print();
    push(3);
    push(2);
    print();
    peek();
    push(1);
}