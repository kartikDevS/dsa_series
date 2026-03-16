// Type your content here...
#include <stdio.h>

void main(){
	int n;
    printf("Enter the no of elements you want in array: ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
        printf("Enter element %d:",i);
		scanf("%d",arr+i);
	}
    printf("The array entered is: ");
    for(int i=0;i<n;i++){
		printf("%d ",*(arr+i));
	}
    printf("\n");
	int sum;
    printf("Enter the sum whose pairs u want to find: ");
	scanf("%d",&sum);
	int pairsCount=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==sum){
				printf("%d %d\n",arr[i],arr[j]);
				pairsCount++;
			}
		}
	}
	printf("Total pairs found are %d",pairsCount);
}