// Type Content here...
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack1[MAX],stack2[MAX],stack3[MAX];
int top1=-1,top2=-1,top3=-1;
int h1=0,h2=0,h3=0;

int isEmpty(int TOP){
	if(TOP==-1)return 1;
	else return 0;
}

int isFull(int TOP){
	if(TOP==MAX-1)return 1;
	else return 0;
}

void push(int stack[],int *top,int n){
	if(isFull(*top)){
		printf("Stack overflow.\n");
		return;
	}
	(*top)++;
	stack[*top]=n;
}

int pop(int stack[],int *top){
	if(isEmpty(*top)){
		printf("Stack is underflow.\n");
		return 0;
	}
	int val=stack[*top];
	(*top)--;
	return val;
}

int Max3(int a,int b,int c){
	if(a>=b && a>=c)return a;
	else if(b>=a && b>=c)return b;
	else return c;
}

void input(int stack[], int *top, int s, int *h) {
	int vals[s];
	for (int i = 0; i < s; i++) {
		scanf("%d", &vals[i]);
		*h += vals[i];
	}
	// Push in reverse so last entered is top
	for (int i = s - 1; i >= 0; i--) {
		push(stack, top, vals[i]);
	}
}

int calculateMaxH(){
	while(h1!=0 && h2!=0 && h3!=0){
		if(h1==h2 && h2==h3)return h1;
		int x=Max3(h1,h2,h3);
		if(x==h1){
			h1-=pop(stack1,&top1);
		}
		else if(x==h2){
			h2-=pop(stack2,&top2);
		}
		else{
			h3-=pop(stack3,&top3);
		}
	}
	return 0;
}

int main(){
	int s1,s2,s3;
	scanf("%d",&s1);
	input(stack1,&top1,s1,&h1);
	scanf("%d",&s2);
	input(stack2,&top2,s2,&h2);
	scanf("%d",&s3);
	input(stack3,&top3,s3,&h3);
	int result=calculateMaxH();
	printf("%d\n",result);
	return 0;
}
