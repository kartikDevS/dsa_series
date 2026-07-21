#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
int data;
struct node*left,*right;
} NODE;

NODE* newNode(int ele){
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

typedef struct {
NODE *arr[100];
int rear,front;
} Queue;

void initQ(Queue* q){
	q->front=q->rear=0;
}

void enqueue(Queue*q,NODE*node){
	q->arr[q->rear++]=node;
}

NODE* dequeue(Queue*q){
	return q->arr[q->front++];
}

int isEmpty(Queue*q){
	return q->front==q->rear;
}

NODE* buildTree(char tokens[][10],int n){
	if(n==0 || strcmp(tokens[0],"null")==0)return NULL;
	NODE *root=newNode(atoi(tokens[0]));
	Queue q;
	initQ(&q);
	enqueue(&q,root);

	int i=1;
	while(!isEmpty(&q) && i<n){
		NODE *curr=dequeue(&q);

		if(i<n && strcmp(tokens[i],"null")!=0){
			curr->left=newNode(atoi(tokens[i]));
			enqueue(&q,curr->left);
		}
		i++;

		if(i<n && strcmp(tokens[i],"null")!=0){
			curr->right=newNode(atoi(tokens[i]));
			enqueue(&q,curr->right);
		}
		i++;
	}
	return root;
}

int mirror(NODE*t1,NODE*t2){
	if(t1==NULL && t2==NULL)return 1;
	if(t1==NULL || t2==NULL)return 0;
	return (t1->data==t2->data)&&
		mirror(t1->left,t2->right) && mirror(t1->right,t2->left);
}

int symmetry(NODE*root){
	if(root==NULL)return 1;
	return mirror(root->left,root->right);
}

int main(){
	char tokens[1000][10];
	int count=0;
	while(1){
		scanf("%s",tokens[count]);
		if(strcmp(tokens[count],"-1")==0)break;
		count++;
	}
	NODE* root=buildTree(tokens,count);
	if(symmetry(root)){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
	return 0;
}