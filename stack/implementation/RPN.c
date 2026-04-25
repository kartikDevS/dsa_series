#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int stack[MAX];
int top=-1;

int main(){
    int n;
    scanf("%d",&n);
    char token[MAX];
    for(int i=0;i<n;i++){
        scanf("%s",token);
        if(strcmp(token,"+")==0){
            int a=stack[top--];
            int b=stack[top--];
            stack[++top]=a+b;
        }
        else if(strcmp(token,"-")==0){
            int a=stack[top--];
            int b=stack[top--];
            stack[++top]=a-b;
        }
        else if(strcmp(token,"*")==0){
            int a=stack[top--];
            int b=stack[top--];
            stack[++top]=a*b;
        }
        else if(strcmp(token,"/")==0){
            int a=stack[top--];
            int b=stack[top--];
            stack[++top]=a/b;
        }
        else{
            stack[++top]=atoi(token);
        }
    }
    printf("%d",stack[top]);
}
