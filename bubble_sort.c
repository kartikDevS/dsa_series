// Bubble sort has a worst-case and average-case time complexity of O(n^2), while 
// the best case (if the array is already sorted and you use an optimization to stop 
// early) is O(n). Its space complexity is O(1), since it sorts in place.



#include <stdio.h>
void bubble(int arr[], int n);
void main(){
    int arr[20]={5,8,2,6,1,18,13,21,3};
    int n=9;
    bubble(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}
// so here in bubble sort we just do it like start comparing the two adjacent elements and thus like this till
// it moves to the end u will get the highest element placed at the last , now do the same and this keeps on
// going for n-1 loops and remember u dont have to check for j=0 to j=n-1(as we are doing arr[j] and arr[j+1])
// everytime cause u are getting the highest element placed at the end so u dont have to check for it thats why 
//we do j<(n-1)-i 

void bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}