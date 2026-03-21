# Linked List Traversal Notes

## Difference between `ptr != NULL` and `ptr->next != NULL`

### 1. `ptr != NULL`
- Checks if the **current node exists**.
- Safe for traversal — prevents dereferencing a `NULL` pointer.
- Loop runs for **all nodes including the last one**.
- After processing the last node, `ptr` becomes `NULL` and the loop exits.

```c
while (ptr != NULL) {
    printf("%d ", ptr->data);  // prints every node
    ptr = ptr->next;
}