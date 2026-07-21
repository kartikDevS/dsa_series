#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isBST(int arr[],int n,int i,int min,int max){
if(i>=n)return 1;
int value=arr[i];
if(value<min || value>max)return 0;
return isBST(arr,n,2*i+1,min,value) && isBST(arr,n,2*i+2,value,max);
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int root=arr[0];
	if(isBST(arr,n,0,INT_MIN,INT_MAX)){
		printf("%d YES",arr[0]);
	}
	else{
		printf("%d NO",arr[0]);
	}
	return 0;
}