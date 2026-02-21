// so basically it is like u have two sections one is a sorted part and one is unsorted region and so u pick 
// the smallest element from the unsorted region and place it in the sorted region , first u pick the 
// smallest element in from the array then u place it at the 0 index then you search for the smallest element 
// in the array from 1 to n , and similarly swap that smallest with the 1 index and so on this goes on

#include <stdio.h>
void selection(int arr[], int n){
    for(int i=0;i<n-1;i++){  
        int idx=i;    // u dont check for the last value as it would already be sorted 
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[idx]){
            idx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[idx];
        arr[idx]=temp;
    }
}                                          // time complexity O(n^2)
void main(){
    int arr[]={3,9,1,13,14,5,2,8,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    for(int a=0;a<n;a++){
        printf("%d ",arr[a]);
    }
}

