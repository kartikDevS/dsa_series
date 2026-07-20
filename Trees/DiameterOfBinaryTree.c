#include <stdio.h>
#include <stdlib.h>

int height(int arr[],int n,int i,int *d){
	if(i>=n)return 0;
	int lh=height(arr,n,2*i+1,d);
	int rh=height(arr,n,2*i+2,d);

	if(lh+rh>*d){
		*d=lh+rh;
	}

	return 1+ (lh>rh?lh:rh);
}

int diameter(int arr[],int n){
	int d=0;
	height(arr,n,0,&d);
	return d;
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d\n",diameter(arr,n));
	return 0;
}