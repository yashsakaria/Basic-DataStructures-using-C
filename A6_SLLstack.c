/* Stack using Singly Linked List. */
#include<stdlib.h>
#include<stdio.h>

typedef struct stack {
	int data;
	struct stack * ptr;
}stack;

stack * head = NULL;

stack * createnode() {
	stack * newnode = (stack *)malloc(sizeof(stack));
	printf("Enter the data element to be pushed : ");
	scanf("%d" , &newnode->data );
	newnode->ptr = NULL;
	return newnode;
}

void push() {
	if (head == NULL)
		head = createnode();
	else {
		stack * newnode = createnode();
		newnode->ptr = head;
		head = newnode;
	}
	printf("%d successfully pushed on to the stack.\n" , head->data);
}

void pop() {
	if (head == NULL) 
		printf("Stack is Empty.\n");
	else {
		printf("Element %d successfully deleted.\n" , head->data);
		head = head->ptr;
	}
}

void display() {
	if (head != NULL) {
		stack * strt = head;
		printf("Elements of stack are : ");
		while(strt != NULL) {
			printf("%d ", strt->data );
			strt = strt->ptr;
		}
		printf("\n");
	}
	else 
		printf("Stack is empty.\n");	
}

void main() {
	int choice , flag = 1 ;
	printf("Stack using Singly Linked List.\n");
	printf("Enter the operation to be performed.\n");
	while(flag) {
		printf("1.Push \t 2.Pop \t 3.Display \t 4.Exit  : ");
		scanf("%d" , &choice);
		switch(choice) {
			case 1 : push();
				 break;

			case 2 : pop();
				 break;

			case 3 : display();
				 break;

			case 4 : flag = 0 ;
				 break;
			 
			default : printf("Invalid input.\n");
				  break;
		}
	}
}	































