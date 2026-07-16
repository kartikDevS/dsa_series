void delete(int ele) {
    TBNODE dest = root->left;
    TBNODE p = root;

    // Step 1: Search for the node
    while (dest != root) {
        if (dest->data < ele) {
            if (dest->rightThread) {
                printf("Cannot find %d in the threaded binary tree.\n", ele);
                return;
            }
            p = dest;
            dest = dest->right;
        } else if (dest->data > ele) {
            if (dest->leftThread) {
                printf("Cannot find %d in the threaded binary tree.\n", ele);
                return;
            }
            p = dest;
            dest = dest->left;
        } else {
            break; // found
        }
    }

    if (dest == root) {
        printf("Cannot find %d in the threaded binary tree.\n", ele);  // this condition is for when root->left=root so above while doesnt run and basically its an empty tree
        return;
    }

    TBNODE target = dest;

    // Step 2: If node has two children
    if (!dest->leftThread && !dest->rightThread) {
        p = dest;
        target = dest->left;
        while (!target->rightThread) {
            p = target;
            target = target->right;
        }
        dest->data = target->data; // copy predecessor’s data
    }

    // Step 3: Handle deletion depending on parent side
    if (p->data > target->data) { // target is in right subtree
        if (target->leftThread && target->rightThread) {
            p->left = target->left;
            p->leftThread = 1;
        } else if (target->rightThread) { // only left child
            TBNODE largest = target->left;
            while (!largest->rightThread)
                largest = largest->right;
            largest->right = p;
            p->left = target->left;
        } else { // only right child
            TBNODE smallest = target->right;
            while (!smallest->leftThread)
                smallest = smallest->left;
            smallest->left = target->left;
            p->left = target->right;
        }
    } else { // target is in left subtree
        if (target->leftThread && target->rightThread) {
            p->right = target->right;
            p->rightThread = 1;
        } else if (target->rightThread) { // only left child
            TBNODE largest = target->left;  // ! this and
            while (!largest->rightThread)
                largest = largest->right;
            target->right = largest->right;
            p->right = target->left;
        } else { // only right child
            TBNODE smallest = target->right;  // this left to understand
            while (!smallest->leftThread)
                smallest = smallest->left;
            p->left = smallest->left;
            p->right = target->right;
        }
    }

    free(target);
}

int search(int ele) {
    TBNODE tmp = root->left;   // start from the real root

    while (tmp != root) {      // loop until we circle back to dummy root
        if (tmp->data < ele) {
            // go right
            if (tmp->rightThread) 
                return 0;      // not found
            tmp = tmp->right;
        } else if (tmp->data > ele) {
            // go left
            if (tmp->leftThread) 
                return 0;      // not found
            tmp = tmp->left;
        } else {
            // found
            return 1;
        }
    }
    return 0; // not found
}

