#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}; typedef struct node* NODE;

NODE create(int x){
	NODE temp=malloc(sizeof(struct node));
	temp->value=x;
	temp->next=NULL;
	return temp;
}
NODE first=NULL;
void insert(){
	int x;
	printf("Element: ");
	scanf("%d",&x);
	if(first==NULL){
		first=create(x);
		return;
	}
	NODE ptr=first;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=create(x);
}

void delete_node(){
	int pos;
	printf("Position: ");
	scanf("%d",&pos);
	if(pos<=0){
		printf("Invalid position\n");
		return;
	}
	if(first==NULL){
		printf("List is empty. Cannot delete.\n");
		return;
	}
	if(first->next==NULL){
		if(pos==1){
			free(first);
			first=NULL;
			printf("Deleted successfully\n");
			return;
		}
		else{
			printf("Invalid position\n");
			return;
		}
	}
	if(pos==1){
		NODE temp=first;
		first=first->next;
		free(temp);
		printf("Deleted successfully\n");
		return;
	}
	NODE ptr=first;
	NODE prev;
	// pos--;
	while(pos>1 && ptr->next!=NULL){
		prev=ptr;
		ptr=ptr->next;
		pos--;
	}
	if(pos>1){
		printf("Invalid position\n");
		return;
	}
	// NODE temp=ptr->next;
	// ptr->next=temp->next;
	// free(temp);
	prev->next=ptr->next;
	free(ptr);
	printf("Deleted successfully\n");
	return;
}

// Type Content here...
void display(){
	if(first==NULL){
		printf("The list is empty\n");
		return;
	}
	printf("Elements of linked list: ");
	NODE ptr=first;
	while(ptr!=NULL){
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}
	printf("\n");
	return;
}
void count(){
	int count=0;
	if(first==NULL){
		printf("No of elements: 0\n");
		return;
	}
	NODE ptr=first;
	while(ptr!=NULL){
		ptr=ptr->next;
		count++;
	}
	printf("No of elements: %d\n",count);
	return;
}


int main() {
    int option = 0;
    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Count 5.Exit\n");
        printf("choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                delete_node();
                break;
            case 3:
                display();
                break;
            case 4:
                count(); 
                break;
            case 5:
                return 0;  // Exit the program
            default:
                printf("Enter options from 1 to 5\n");
                break;
        }
    }
    return 0;
}
