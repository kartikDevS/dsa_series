#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int value,left,right;
} BSTNODE;

int result(BSTNODE* nodes[],int idx){
	if(idx==0)return 0;
	int sum=0;
	if(nodes[idx]->left!=0){
		int Left=nodes[idx]->left;
		if(nodes[Left]->left==0 && nodes[Left]->right==0){
			sum+=nodes[Left]->value;
		}
		else{
			sum+=result(nodes,Left);
		}
	}
	if(nodes[idx]->right!=0){
		sum+=result(nodes,nodes[idx]->right);
	}
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	BSTNODE *nodes[n+1];
	for(int i=1;i<=n;i++){
		nodes[i]=malloc(sizeof(BSTNODE));
		scanf("%d%d%d",&nodes[i]->value,&nodes[i]->left,&nodes[i]->right);
	}
	int ans=result(nodes,1);
	printf("%d\n",ans);
	return 0;
}