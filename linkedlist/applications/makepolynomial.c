#include <stdio.h>
#include <stdlib.h>

struct node{
    float coeff;
    int expo;
    struct node* next;
}; 
typedef struct node * NODE;

NODE createNODE(float x,int y){
    NODE temp=malloc(sizeof(struct node));
    temp->coeff=x;
    temp->expo=y;
    temp->next=NULL;
    return temp;
}

NODE insert(NODE head,float coe,int ex){
    if(head==NULL || ex>head->expo){
        NODE temp=createNODE(coe,ex);
        temp->next=head;
        head=temp;
        return head;
    }
    NODE ptr=head;
    while(ptr->next!=NULL && ptr->next->expo>ex){
        ptr=ptr->next;
    }
    NODE newP=createNODE(coe,ex);
    newP->next=ptr->next;
    ptr->next=newP;
    return head;

}

void print(NODE head){
    NODE ptr=head;
    printf("The polynomial is: ");
    while(ptr!=NULL){
        printf("%.1f x^%d",ptr->coeff,ptr->expo);
        ptr=ptr->next;
        if(ptr!=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    NODE head=NULL;
    int n,ex;
    float coe;
    printf("Enter the number of terms in polynomial\n");
    scanf("%d",&n);
    printf("Enter the polynomial\n");
    for(int i=0;i<n;i++){
        printf("Enter the coefficient of %d term: ",i+1);
        scanf("%f",&coe);
        printf("Enter the exponent of %d term: ",i+1);
        scanf("%d",&ex);
        head=insert(head,coe,ex);
    }
    print(head);
    return 0;
}