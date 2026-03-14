// #include <stdio.h>
// void main(){
//     int pages,rows,cols;
//     scanf("%d%d%d",&pages,&rows,&cols);
//     int arr[pages][rows][cols];
//     for(int k=0;k<pages;k++){
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 scanf("%d",*(*(arr+k)+i)+j);
//             }
//         }
//     }
//     printf("\n");
//     for(int k=0;k<pages;k++){
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 printf("%d ",*(*(*(arr+k)+i)+j));
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
// }


// now if u want to print it in a different manner do it like 

#include <stdio.h>
void main(){
    int pages,rows,cols;
    scanf("%d%d%d",&pages,&rows,&cols);
    int arr[pages][rows][cols];
    for(int k=0;k<pages;k++){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                scanf("%d",*(*(arr+k)+i)+j);
            }
        }
    }
    printf("\n");
    for(int i=0;i<rows;i++){
        for(int k=0;k<pages;k++){
            for(int j=0;j<cols;j++){
                printf("%d ",*(*(*(arr+k)+i)+j));  // element is accessed the same way cause it simple the way u stored u will use them the same way
            }
            printf(" ");
        }
        printf("\n");
    }
}


