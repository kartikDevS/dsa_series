// // Type Content here...
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

void postorderTraversal(BSTNODE* node){
	if(node==NULL)return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	printf("%d ",node->data);
}

int main(){
	int arr[100000],n=0,value;
	while(scanf("%d",&value) && value!=-1){
		arr[n++]=value;
	}
	BSTNODE *nodes[n];
	for(int i=0;i<n;i++){
		nodes[i]=newNode(arr[i]);
	}
	for(int i=0;i<n;i++){
		int left=2*i+1;
		int right=2*i+2;
		if(left<n)nodes[i]->left=nodes[left];
		if(right<n)nodes[i]->right=nodes[right];
	}
	BSTNODE *root=nodes[0];
	postorderTraversal(root);
	return 0;
}
