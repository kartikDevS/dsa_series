#include <stdio.h>
#include <conio.h>

int fact(unsigned int n) {
   return factTR(n, 1);
}
void main() {
	int n;
	printf("Enter a positive number : ");
	scanf("%d", &n);
	if (n > 0)
		printf("The factorial of %d is %d\n",n,fact(n));
	else
		printf("Invalid Number\n");
}

#include <stdio.h>

int factTR(int n,int acc){
	if(n==1 || n==0)return acc;
	return factTR(n-1,n*acc);
}



