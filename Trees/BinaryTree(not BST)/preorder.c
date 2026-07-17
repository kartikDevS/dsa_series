// Type your code here...
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node* left,*right;
} BSTNODE;

BSTNODE* newNode(int value){
	BSTNODE* temp=malloc(sizeof(BSTNODE));
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void preorderTraversal(BSTNODE*node){
	if(node==NULL)return;
	printf("%d ",node->data);
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}

int main(){
	int n;
	scanf("%d",&n);
	BSTNODE* nodes[1001]={NULL};
	BSTNODE *root=NULL;
	for(int i=0;i<n;i++){
		int value,left,right;
		scanf("%d%d%d",&value,&left,&right);
		if(nodes[value]==NULL){
			nodes[value]=newNode(value);
		}
		if(i==0){
			root=nodes[value];
		}
		if(left!=-1){
			if(nodes[left]==NULL){
				nodes[left]=newNode(left);
			}
			nodes[value]->left=nodes[left];
		}
		if(right!=-1){
			if(nodes[right]==NULL){
				nodes[right]=newNode(right);
			}
			nodes[value]->right=nodes[right];
		}
	}
	preorderTraversal(root);
	printf("\n");
	return 0;
}
