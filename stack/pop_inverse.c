#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int first=-1;

void push(int data){
    int i;
    first+=1;
    for(i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}

int pop(){
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

int main(){
    push(5);
    push(4);
    push(3);
    print();
    int data=pop();
    printf("%d\n",data);
    print();
}