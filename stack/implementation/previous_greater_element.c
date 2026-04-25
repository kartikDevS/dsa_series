#include <stdio.h>

void cal(int arr[],int n,int ans[]){
	int stack[n];
	int top=-1;
	for(int i=0;i<n;i++){
		while(top!=-1 && stack[top]<=arr[i]){
			top--;
		}
		if(top==-1){
			ans[i]=-1;
		}
		else{
			ans[i]=stack[top];
		}
		stack[++top]=arr[i];
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int ans[n];
	cal(arr,n,ans);
	
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}