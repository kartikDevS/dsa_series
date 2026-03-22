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

NODE push(NODE head,int x){
    if(head==NULL){
        head=create(x);
        return head;
    }
    NODE temp=create(x);
    temp->next=head;
    head=temp;
    return head;
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

NODE reverse(NODE head){
    NODE current=NULL;
    NODE Next=head->next;
    head->next=NULL;
    while(Next!=NULL){
        current=Next;
        Next=Next->next;
        current->next=head;
        head=current;
    }
    return head;
}

NODE add(NODE head1,NODE head2,NODE head3){
    NODE ptr1=head1;
    NODE ptr2=head2;
    int sum=0;int carry=0;

    while(ptr1 || ptr2){
        sum=0;
        if(ptr1){
            sum+=ptr1->data;
        }
        if(ptr2){
            sum+=ptr2->data;
        }
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        head3=push(head3,sum);
        if(ptr1){
            ptr1=ptr1->next;
        }
        if(ptr2){
            ptr2=ptr2->next;
        }
    }
    if(carry){
        head3=push(head3,carry);
    }
    return head3;
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
    NODE head1=NULL;
    NODE head2=NULL;
    NODE head3=NULL;
    int n1;
    printf("Enter the 1st number:\n");
    scanf("%d",&n1);
    head1=store(head1,n1);

    int n2;
    printf("Enter the 2nd number:\n");
    scanf("%d",&n2);
    head2=store(head2,n2);

    printf("Original Number 1: ");
    print(head1);

    printf("Original Number 2: ");
    print(head2);

    head1=reverse(head1);
    // printf("Reversed Number1: ");
    // print(head1);

    head2=reverse(head2);
    // printf("Reversed Number2: ");
    // print(head2);

    head3=add(head1,head2,head3);
    printf("The sum is: ");
    print(head3);

}