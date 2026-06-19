// we have an array in that we assume the first element to be sorted and then on the right of it we have 
//unsorted array so now we take first element from this unsorted array and place it at the right idx in
// the sorted array 

// #include <stdio.h>
// void insertion(int arr[],int n){
//     for(int i=1;i<n;i++){
//         int curr=arr[i];
//         int prev=i-1;
//         while(prev>=0 && arr[prev]>curr){
//             arr[prev+1]=arr[prev];
//             prev--;
//         }
//         arr[prev+1]=curr;
//     }
// }

// void main(){
//     int arr[]={1,3,26,7,6,8,13,4};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     insertion(arr,n);
//     for(int i=0;i<n;i++){
//         printf("%d ",*(arr+i));
//     }
// }


//practing insertion sort

#include <stdio.h>
void insertion(int arr[],int n){
    int curr;
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}

int main(){
    int arr[]={2,13,3,14,5,19,15,6,17,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    for(int j=0;j<n;j++){
        printf("%d ",*(arr+j));
    }
    return 0;
}