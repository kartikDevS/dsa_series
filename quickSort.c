// we have an array in which we choose the last element of it as pivot and we have to arrange the elements
//in the array in a way that all lesser elements then the pivot comes on the left side and greater
//comes on the right side of pivot and we dont need to arrange them in a sorted way like if 7 is pivot
//then {3,2,1,7,8,10,9} this is what we want and thus we repeat this process again for the left half and
//right half and we keep doing so 


// #include <stdio.h>
// int partition(int arr[],int str,int end){
//     int idx=str-1, pivot=arr[end],temp;
//     for(int j=str;j<end;j++){
//         if(arr[j]<pivot){
//             idx++;
//             temp=arr[idx];
//             arr[idx]=arr[j];
//             arr[j]=temp;
//         }
//     }
//     idx++;
//     temp=arr[idx];
//     arr[idx]=pivot;
//     arr[end]=temp;
//     return idx;
// }

// void quick(int arr[],int str,int end){
//     if(str<end){
//         int pivIdx=partition(arr,str,end);
//         quick(arr,str,pivIdx-1);
//         quick(arr,pivIdx+1,end);
//     }
// }

// int main(){
//     int arr[]={1,6,5,8,3,7,13,27,12,19,11};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     quick(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         printf("%d ",*(arr+i));
//     }
//     return 0;
// }


// practicing the code 

#include <stdio.h>

int partition(int arr[],int st,int end){
    int idx=st-1;
    int temp;
    int pivot=arr[end];
    for(int i=st;i<end;i++){
        if(arr[i]<pivot){
            idx++;
            temp=arr[idx];
            arr[idx]=arr[i];
            arr[i]=temp;
        }
    }
    idx++;
    temp=arr[idx];
    arr[idx]=pivot;
    arr[end]=temp;
    return idx;
}

void quick(int arr[],int st,int end){
    if(st<=end){
    int pividx=partition(arr,st,end);
    quick(arr,st,pividx-1);  // important here we are calling for pividx-1 as pivot is already at right place
    quick(arr,pividx+1,end);
    }
}

int main(){
    int arr[]={2,13,3,14,5,19,15,6,17,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,n-1);
    for(int j=0;j<n;j++){
        printf("%d ",*(arr+j));
    }
    return 0;
}