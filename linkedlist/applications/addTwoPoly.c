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

NODE create(NODE head){
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
    return head;
}


NODE add(NODE head1,NODE head2,NODE head3){
    NODE ptr1=head1; NODE ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo==ptr2->expo){
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->next; ptr2=ptr2->next;
        }
        else if(ptr1->expo>ptr2->expo){
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;
        }
        else if(ptr2->expo>ptr1->expo){
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->next;
    }
    return head3;
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
    NODE head1=NULL;
    NODE head2=NULL;
    NODE head3=NULL;
    head1=create(head1);
    head2=create(head2);
    head3=add(head1,head2,head3);
    printf("Polynomial 1:\n");
    print(head1);
    printf("Polynomial 2:\n");
    print(head2);
    printf("Sum of the two polynomial:\n");
    print(head3);
    return 0;
}