struct node {
	int data;
	struct node *left, *right;
};
  
typedef struct node * BSTNODE;

BSTNODE newNodeInBST(int item) {
	BSTNODE temp =  (BSTNODE)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void preorderInBST(BSTNODE root) {
	if(root==NULL)return;

	printf("%d ",root->data);
	preorderInBST(root->left);
	preorderInBST(root->right);
}

void inorderInBST(BSTNODE root){
	if(root==NULL)return;
	inorderInBST(root->left);
	printf("%d ",root->data);
	inorderInBST(root->right);
}

void postorderInBST(BSTNODE root){
	if(root==NULL)return;
	postorderInBST(root->left);
	postorderInBST(root->right);
	printf("%d ",root->data);
}

BSTNODE insertNodeInBST(BSTNODE node, int ele) {
	if (node == NULL) {
		printf("Successfully inserted.\n");
		return newNodeInBST(ele);	
	}
	if (ele < node->data)
		node->left  = insertNodeInBST(node->left,ele);
	else if (ele > node->data)
		node->right = insertNodeInBST(node->right,ele);
	else
		printf("Element already exists in BST.\n");
	return node;
}


BSTNODE minValueNode(BSTNODE node) {
	BSTNODE current=node;
	while(current!=NULL && current->left!=NULL){
		current=current->left;
	}
	return current;
}

BSTNODE deleteNodeInBST(BSTNODE root, int ele) {
	if(root==NULL){
		printf("Cannot find %d in the binary search tree.\n",ele);
		return root;
	}
	else if(ele<root->data){
		root->left=deleteNodeInBST(root->left,ele);
	}
	else if(ele>root->data){
		root->right=deleteNodeInBST(root->right,ele);
	}
	else{
		if(root->left==NULL){
			BSTNODE temp=root->right;
			printf("Deleted %d from binary search tree.\n",ele);
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			BSTNODE temp=root->left;
			printf("Deleted %d from binary search tree.\n",ele);
			free(root);
			return temp;
		}
		else{
			BSTNODE temp=minValueNode(root->right);
			root->data=temp->data;
			temp->data=ele;
			printf("Deleted %d from binary search tree.\n",ele);
			root->right=deleteNodeInBST(root->right,ele);
		}
	}
	return root;
}