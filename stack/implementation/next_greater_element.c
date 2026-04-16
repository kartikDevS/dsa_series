#include <stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;

int findNextGreater(int x){
	if(top==-1){
		return -1;
	}
	while(!(top==-1) && x>stack[top]){
		top--;
	}
	if(stack[top]>x){
		return stack[top];
	}
	return -1;
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int ans[n];
	for(int i=n-1,k=0;i>=0;i--){
		ans[k++]=findNextGreater(arr[i]);
		stack[++top]=arr[i];
	}
	for(int i=n-1;i>=0;i--){
		printf("%d ",ans[i]);
	}
}