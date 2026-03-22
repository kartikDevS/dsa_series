#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};
typedef struct node* NODE;

NODE create(int x){
    NODE temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

NODE store(NODE head,int n){
    
    while(n!=0){
        if(head==NULL){
            head=create(n%10);
        }
        else{
            NODE temp=create(n%10);
            temp->next=head;
            head=temp;
        }
        n=n/10;
    }
    return head;
}

void print(NODE head){
    NODE ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

int main(){
    NODE head=NULL;
    int n;
    printf("Enter the number u want to store in linked list\n");
    scanf("%d",&n);
    head=store(head,n);
    print(head);
}