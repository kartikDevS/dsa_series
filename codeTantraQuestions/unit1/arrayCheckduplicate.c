//there are 3 ways i found to solve this question which are first is by simply running two nested loops 
// for (i = 0; i < n; i++) {
//         for (j = i + 1; j < n; j++) {
//             if (arr[i] == arr[j]) {
//                 duplicateFound = 1;       here the time complexity is n^2
//                 break;
//             }
//         }

// another method is to first this array using a quicker way than n^2 eg (quick/merge sort) -> nlogn and then 
//running a loop for 
//checking whether arr[i]=arr[i+1] and time complexity in this would be n+nlogn i.e nlogn 

// and the third one i have used to solve this  question




#include <stdio.h>
#include <stdbool.h>

void main(){
    int arr[]={1,2,3,1,11,14,15,3,3,3,22,2,4,9,8,7,2,2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool Arr[100]={false};

    // int duplicateFound=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(Arr[arr[i]]){
            printf("Duplicate is %d found at %d\n",arr[i],i);
            // duplicateFound= 1;
            count++;
            continue;
        }
        else{
            Arr[arr[i]]=true;
        }
    }
    printf("Total no of duplicates are %d .",count);
    // if(duplicateFound){
    //     printf("Duplicate exists");
    // }
    // else{
    //     printf("Duplicate does not found");
    // }
}