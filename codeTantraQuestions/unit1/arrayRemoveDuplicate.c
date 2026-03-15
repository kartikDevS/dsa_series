#include <stdio.h>
#include <stdbool.h>

void main(){
    int arr[]={1,2,3,1,11,14,15,3,3,3,22,2,4,9,8,7,2,2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int unique[n];
    bool Arr[100]={false};
    int uniqueCount=0;

    for(int i=0;i<n;i++){
        if(!Arr[arr[i]]){
            Arr[arr[i]]=true;
            unique[uniqueCount++]=arr[i];
        }
    }

    for(int i=0;i<uniqueCount;i++){
        printf("%d ",unique[i]);
    }
}