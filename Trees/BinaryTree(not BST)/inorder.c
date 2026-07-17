// Type Content here...
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node*left,*right;
} BSTNODE;

BSTNODE* newNode(int ele){
	BSTNODE* temp=malloc(sizeof(BSTNODE));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorderTraversal(BSTNODE* node){
	if(node==NULL)return;
	inorderTraversal(node->left);
	printf("%d ",node->data);
	inorderTraversal(node->right);
}

int main(){
	int n;
	scanf("%d",&n);
	BSTNODE *nodes[1001];
	BSTNODE *root=NULL;
	for(int i=0;i<n;i++){
		int value,left,right;
		scanf("%d%d%d",&value,&left,&right);
		if(value!=-1){
			if(nodes[value]==NULL){
				nodes[value]=newNode(value);
			}
		}
		if(i==0)root=nodes[value];
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
	inorderTraversal(root);
	return 0;
}