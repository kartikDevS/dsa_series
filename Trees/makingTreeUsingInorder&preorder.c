#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node*left,*right;
} Node;

Node *buildtree(int inorder[],int preorder[],int start,int end,int*preIdx){
    if(start>end)return NULL;

    Node* root=malloc(sizeof(Node));
    root->data=preorder[*preIdx];
    root->left=root->right=NULL;
    (*preIdx)++;

    if(start==end)return root;

    int index;
    for(int i=start;i<=end;i++){
        if(inorder[i]==root->data){
            index=i;
            break;
        }
    }

    root->left=buildtree(inorder,preorder,start,index-1,preIdx);
    root->right=buildtree(inorder,preorder,index+1,end,preIdx);

    return root;
}

void postorder(Node*root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d",&n);
    int inorder[n];
    int preorder[n];
    for(int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&preorder[i]);
    }
    int preIdx=0;
    Node* root=buildtree(inorder,preorder,0,n-1,&preIdx);
    postorder(root);
    return 0;
}