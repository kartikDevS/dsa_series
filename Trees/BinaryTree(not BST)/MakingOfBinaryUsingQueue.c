#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node*left,*right;
} Node;

typedef struct{
Node *arr[100];
int front,rear;
} Queue;

void initQueue(Queue* q){
	q->front=q->rear=0;
}

void enqueue(Queue* q, Node *node){
	q->arr[q->rear++]=node;
}

Node * dequeue(Queue* q){
	return q->arr[q->front++];
}

int isEmpty(Queue*q){
	return q->front==q->rear;
}

Node * newNode(int ele){
	Node * tmp=malloc(sizeof(Node));
	tmp->data=ele;
	tmp->left=tmp->right=NULL;
	return tmp;
}

Node *buildtree(int arr[],int n){
	Node *root=newNode(arr[0]);
	Queue q;
	initQueue(&q);
	enqueue(&q,root);

	int i=1;
	while(!isEmpty(&q) && i<n){
		Node *curr=dequeue(&q);

		if(i<n){
			curr->left=newNode(arr[i]);
			enqueue(&q,curr->left);
		}
		i++;

		if(i<n){
			curr->right=newNode(arr[i]);
			enqueue(&q,curr->right);
		}
		i++;
	}
	return root;
}

void inorder(Node*root){
	if(root==NULL)return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(Node*root){
	if(root==NULL)return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node*root){
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

int main(){
	int arr[100];
	int i=0;
	while(1){
		scanf("%d",&arr[i]);
		if(arr[i]==-1)break;
		else i++;
	}
	
	Node*root=buildtree(arr,i);
	printf("In-order: ");
	inorder(root);
	printf("\nPre-order: ");
	preorder(root);
	printf("\nPost-order: ");
	postorder(root);
	printf("\n");
	return 0;
}