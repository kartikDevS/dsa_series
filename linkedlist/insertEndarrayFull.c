#include <stdio.h>

int add_at_end(int arr[],int Arr[],int freePos,int data){
    for(int i=0;i<freePos;i++){
        Arr[i]=arr[i];
    }
    Arr[freePos]=data;
    freePos++;
    return freePos;
}

int main(){
    int arr[3];
    int n;
    printf("Enter the number of elements u want to enter in the array\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    if(n==size){
        int freePos=n;
        int Arr[size+2];
        freePos=add_at_end(arr,Arr,freePos,65);
        for(int i=0;i<freePos;i++){
            printf("%d ",Arr[i]);
        }
    }


    return 0;
}