//this question can be done with reversing also like
// 2 1 4 8 5 9 7 -> this was the actual array
// 2 1 4 8 5 // 9 7 -> we wanted two left rotations, so we split the array in two parts with one having last 2 elements as we wanted 2 rotations and then one having rest elements
// 5 8 4 1 2 // 7 9  -> now we reverse the the two arrays
// 9 7 2 1 4 8 5 -> and the whole reverse of the whole array


#include <stdio.h>
void main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int d;
	scanf("%d",&d);
	d=d%n;
	for(int i=d;i<n;i++){
		printf("%d ",arr[i]);
	}
	for(int i=0;i<d;i++){
		printf("%d ",arr[i]);
	}
}