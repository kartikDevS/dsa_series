#include <stdio.h>

int linear(int arr[],int n,int target,int idx){
    if(idx>=n){
        return -1;
    }
    if(target==arr[idx]){
        return idx;
    }
    else if(target!=arr[idx]){
        return linear(arr,n,target,idx+1);
    }
}

void main(){
    int n=7;
    int target;
    scanf("%d",&target);
    int arr[20]={1,3,8,9,13,17,19};
    int a=linear(arr,n,target,0);
    if(a!=-1){
        printf("%d",a);
    }
    else{
        printf("not found");
    }
}