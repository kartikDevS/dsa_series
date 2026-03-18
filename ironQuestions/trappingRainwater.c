#include <stdio.h>

int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a,int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}

void main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int leftarr[n];int rightarr[n];
	leftarr[0]=arr[0];
	for(int i=1;i<n;i++){
		leftarr[i]=max(leftarr[i-1],arr[i]);
	}
	rightarr[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--){
		rightarr[i]=max(rightarr[i+1],arr[i]);
	}
	int trapped=0;
	int water=0;
	for(int i=0;i<n;i++){
		trapped=min(leftarr[i],rightarr[i])-arr[i];
		if(trapped>0)
			water+=trapped;
	}
	printf("%d",water);
}