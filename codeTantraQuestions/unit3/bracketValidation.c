#include <stdio.h>
#include <stdbool.h>

#define MAX 1000
char stack[MAX];
int top=-1;

bool isValid(char s[]){
    top=-1;
    for(int i=0;s[i]!='\0';i++){
        char ch=s[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            stack[++top]=ch;
        }
        else if(ch==')' || ch==']' || ch=='}'){
            if(top==-1)return false;
            char lastCH=stack[top--];
            if((ch==')' && lastCH!='(') || (ch==']' && lastCH!='[') || (ch=='}' && lastCH!='{'))return false;
        }
    }
    return top==-1;
}

int main(){
    char str[MAX];
    scanf("%s",str);
    if(isValid(str))printf("true\n");
    else{printf("false\n");}
    return 0;
}