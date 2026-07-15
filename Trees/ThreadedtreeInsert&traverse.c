void insert(int ele) {
    TBNODE ptr = root;
    TBNODE parent = NULL;

    // Find position to insert
    while (ptr != NULL) {
        if (ele == ptr->data) {
            printf("Element already exists.\n");
            return;
        }
        parent = ptr;
        if (ele < ptr->data) {
            if (ptr->leftThread == false)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rightThread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    // Create new node
    TBNODE newNode = (TBNODE)malloc(sizeof(struct ThreadedBinaryNode));
    newNode->data = ele;
    newNode->leftThread = true;
    newNode->rightThread = true;

    if (parent == NULL) {
        // First node
        root = newNode;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else if (ele < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = false;
        parent->left = newNode;
    }
    else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->rightThread = false;
        parent->right = newNode;
    }
}

// Helper: find leftmost node
TBNODE leftMost(TBNODE node) {
    if (node == NULL) return NULL;
    while (node->leftThread == false)
        node = node->left;
    return node;
}

void traverse() {
    TBNODE current = leftMost(root);
    while (current != NULL) {
        printf("%d ", current->data);

        // If rightThread is true, follow thread
        if (current->rightThread == true)
            current = current->right;
        else
            current = leftMost(current->right);
    }
    printf("\n");
}
