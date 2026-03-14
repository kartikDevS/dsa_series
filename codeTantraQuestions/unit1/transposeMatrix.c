//this only works for sqaure matrix cause here u arent making any new array u just
//updating the same array so it only works for 2*2 or 3*3 etc 
//for rectangular array u must have a new array and store elements, this cannot be
//performed without creation of a new array


#include <stdio.h>

void main(){
    int rows,cols;
    scanf("%d%d",&rows,&cols);
    int arr[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",*(arr+i)+j);
        }
    }
    printf("The original array is:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<rows;i++){
        for(int j=i;j<cols;j++){
            int temp=arr[j][i];
            arr[j][i]=arr[i][j];
            arr[i][j]=temp;
        }
    }
    printf("The transpose is: \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }

}