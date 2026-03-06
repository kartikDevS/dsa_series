#include <stdio.h>

int add_at_end(int arr[],int freePos,int data){
    arr[freePos]=data;
    freePos++;
    return freePos;
}

int main(){
    int arr[20];
    int n;
    printf("Enter the number of elements u want to enter in the array\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int freePos=n;
    freePos=add_at_end(arr,freePos,65);
    freePos=add_at_end(arr,freePos,69);
    freePos=add_at_end(arr,freePos,71);

    for(int i=0;i<freePos;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}