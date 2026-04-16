#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

// Stack implementation for storing brackets
char stack[MAX_STACK_SIZE];
int top=-1;


bool isValid(char *s){
	top=-1;
	for(int i=0;s[i]!='\0';i++){
		char ch=s[i];
		if(ch=='(' || ch=='[' || ch=='{'){
			stack[++top]=ch;
		}
		else if(ch==')' || ch==']' || ch=='}'){
			if(top==-1)return false;

			char topchar=stack[top--];
			if((ch==')' && topchar!='(') || (ch==']' && topchar!='[') || (ch=='}' && topchar!='{'))return false;
		}
	}
	return top==-1;
}


//write your code here



int main() {
    char s[MAX_STACK_SIZE];
    printf("");
    scanf("%s", s);

    if (isValid(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}