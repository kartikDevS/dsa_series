#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

// We make head global so the function can access it directly
struct Node* head = NULL;

void add_at_end(int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    struct Node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }

    ptr->link = temp;
}

int main() {

    add_at_end(69);
    add_at_end(65);
    add_at_end(89);
    add_at_end(99);

    struct Node* printer = head;
    while (printer != NULL) {
        printf("%d ", printer->data);
        printer = printer->link;
    }

    return 0;
}

// or if u wanted to declare the head inside the main function then u have to use 
//&head while passing value in function like add_at_end(&head,data) and then when 
//declaring the function u have to write void add_at_end(struct Node**head,int data)