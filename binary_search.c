// NOTE: the array is already sorted 
// so here instead of taking the target and comparing it with all the elements of array we do compare it with
//the middle element and if the target is greater than middle then search in the second half of array(i.e 
// the middle element divided the arry in 2 half one before middle(1st half) and one after(2nd half)),
// and since the array is sorted its obvious that all the elements in the second half will be greater than
// middle

// so  we find middle by (starting index + last index)/2 , but here we do str + (end-str)/2 if u solve the eqn
// u will get same str + end/2 , the point that we did like this here is because suppose if the limit was n
// and now u did str+end where end =n and now ur str was =4 so it would be n+4 exceeding the limit 
//  so here we do (end-4)+4 so it always remains in the range 

#include <stdio.h>
void main(){
    int arr[20]={1,2,5,8,9,13,17,31,33};
    int target;
    scanf("%d",&target);
    int low=0;
    int high=8;
    int mid;
    int flag;
    while(low<=high){ // so we use while instead of for on this condition
        mid=low+(high-low)/2;
        if(arr[mid]==target){
            flag=1;     // this statement will only return the ans as the rest two statements just keep on updating the low,high value the ans comes only when our target matches the arr[mid]
            break;
        }
        else if(target>arr[mid]){
            low=mid+1;   // as now the starting pt for 2nd array will be the element next(right) to middle
        }
        else if(target<arr[mid]){
            high=mid-1;
        }
    }
    if(flag==1){
        printf("%d",mid);
    }
    else{
        printf("element not found");
    }

}