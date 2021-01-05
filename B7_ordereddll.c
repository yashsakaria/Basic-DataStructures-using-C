/* To insert a given element into an ordered Doubly Linked List.	*/
#include<stdlib.h>
#include<stdio.h>

typedef struct odll {
	int data;
	struct odll * left ;
	struct odll * right;
}odll;

odll * head = NULL;
int count = 0;

odll * createnode() {
	odll * newnode = (odll*)malloc(sizeof(odll));
	printf("Enter the element : ");
	scanf("%d",&newnode->data);
	newnode->left = NULL;
	newnode->right = NULL;
	count++;
	return newnode;
}

void push() {
	if(head == NULL)
		head = createnode();
	else {
		odll * temp = createnode();
		int j = count;
		odll * trav = head;
		if(temp->data <= head->data) {
			temp->right = head;
			head->left = temp;
			head = temp;
		}
		else {
			while(temp->data > trav->data ) {
				if(trav->right == NULL ) {
					trav->right = temp;
					temp->left = trav;
					return;
				}
				else 
					trav = trav->right;
			}		
			temp->left = trav->left;
			trav->left = temp;
			trav = temp->left;
			temp->right = trav->right;
			trav->right = temp;
		}
	}
}

void display() {
	if(head == NULL) 
		printf("Doubly Linked list is empty.\n");
	else {
		odll * strt = head;
		printf("Elements of Ordered DLL are : ");
		while(strt != NULL) {
			printf("%d ",strt->data);
			strt = strt->right;
		}
		printf("\n");
	}
}

void main() {
	int choice , flag = 1 ;
	printf("Ordered Doubly Linked List.\n");
	printf("Enter the operation to be performed.\n");
	while(flag) {
		printf("1.Push \t 2.Display \t 3.Exit  : ");
		scanf("%d" , &choice);
		switch(choice) {
			case 1 : push();
				 break;

			case 2 : display();
				 break;

			case 3 : flag = 0 ;
				 break;
			 
			default : printf("Invalid input.\n");
				  break;
		}
	}
}