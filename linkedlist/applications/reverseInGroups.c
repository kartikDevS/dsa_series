#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node*next;
};
typedef struct node*NODE;

NODE addAtEnd(NODE head,int x){
	NODE temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return head;
	}
	NODE ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	return head;
}

void print(NODE head){
	NODE ptr=head;
	while(ptr!=NULL){
		printf("%d -> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}

NODE reverse(NODE head,int k){
	NODE temp=head;
	for(int i=0;i<k;i++){
		if(temp==NULL)return head;
		temp=temp->next;
	}
	
	NODE prev=NULL;
	NODE curr=head;
	NODE next=NULL;
	int count=0;
	while(curr!=NULL && count<k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL){
		head->next=reverse(next,k);
	}
	return prev;
}

void main(){
	NODE head=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		head=addAtEnd(head,x);
	}
	int skip;
	scanf("%d",&skip);
	head=reverse(head,skip);
	print(head);
}