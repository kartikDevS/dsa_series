#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int s=arr[0];
    int h=arr[0];
    int sum=0;
    for(int i=0;i<n;i++){
        if(s>arr[i]){
            s=arr[i];
        }
        if(h<arr[i]){
            h=arr[i];
        }
        sum+=arr[i];
    }
    float avg=(s+h)/(float)n;
    printf("%d is Min and %d is Max and %.2f is Avg",s,h,avg);
}