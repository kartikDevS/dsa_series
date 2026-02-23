// basically here we have an array which we find a mid and then about that mid we repeat same thing i.e for the
//left and right we again find the mid and this process goes on untill we get single elements at the last
//now we have to merge these sub arrays into a single sorted array 
// so merge sort happens in 2 steps 
//1. partition , 2. join (in a sorted manner)

// #include <stdio.h>

// void merge(int arr[],int st,int mid,int end){
//     int i=st,j=mid+1;
//     int temp[end-st+1];
//     int idx=0;
//     while(i<=mid && j<=end){
//         if(arr[i]<=arr[j]){
//             temp[idx]=arr[i];
//             i++;
//             idx++;
//         }
//         else{
//             temp[idx]=arr[j];
//             j++;
//             idx++;
//         }
//     }
//     while(i<=mid){
//         temp[idx]=arr[i];
//             i++;
//             idx++;
//     }
//     while(j<=end){
//         temp[idx]=arr[j];
//             j++;
//             idx++;
//     }
//     for(int k=0;k<(end-st+1);k++){
//         arr[k+st]=temp[k];
//     }
// }

// void mergesort(int arr[],int st,int end){
//     if(st<end){
//         int mid=st+(end-st)/2;
//         mergesort(arr,st,mid);
//         mergesort(arr,mid+1,end);
//         merge(arr,st,mid,end);
//     }
    
// }

// int main(){
//     int arr[]={13,2,3,14,11,9,16,8};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     mergesort(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         printf("%d ",*(arr+i));
//     }
//     return 0;
// }


//practicing the code again

#include <stdio.h>

void merge(int arr[],int st,int mid,int end){
    int i=st,j=mid+1;
    int temp[end-st+1];
    int idx=0;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[idx]=arr[i];
            i++;
            idx++;
        }
        else{
            temp[idx]=arr[j];
            j++;
            idx++;
        }
    }
    while(i<=mid){
        temp[idx]=arr[i];
        i++;
        idx++;
    }
    while(j<=end){
        temp[idx]=arr[j];
        j++;
        idx++;
    }
    for(int k=0;k<end-st+1;k++){
        arr[st+k]=temp[k];
    }
}

void mergesort(int arr[],int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

int main(){
    int arr[]={2,14,11,14,3,5,19,16,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}