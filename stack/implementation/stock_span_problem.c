#include <stdio.h>
#define MAX 10000
int stack[MAX];
int top=-1;

void push(int x){stack[++top]=x;}
int pop(){return stack[top--];}
int peek(){return stack[top];}
int isEmpty(){return top==-1;}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int ans[n];
	ans[0]=1;
	push(0);
	for(int i=1;i<n;i++){
		while(!isEmpty() && arr[peek()]<=arr[i]){
			pop();
		}
		ans[i]=isEmpty()?(i+1):(i-peek());
		push(i);
	}
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}