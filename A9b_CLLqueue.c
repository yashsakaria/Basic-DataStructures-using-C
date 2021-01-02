/* Implement queue using Circular Linked List. */
#include<stdio.h>
#include<stdlib.h>

typedef struct cllqueue {
	int data;
	struct cllqueue * ptr ;
}cllqueue;

cllqueue * front = NULL , *rear = NULL;

cllqueue * createnode() {
	cllqueue * newnode = (cllqueue *)malloc(sizeof(cllqueue));
	printf("Enter the element to be inserted : ");
	scanf("%d" , &newnode->data);
	newnode->ptr = front;
	return newnode;
}

void insert() {
	if (front == NULL) {
		front = createnode();
		front->ptr = front;
		rear = front;
	}
	else {
		cllqueue * temp = createnode();
		rear->ptr = temp;
		rear = temp;
	}
	printf("Element %d successfully inserted.\n" , rear->data);
}

void delete() {
	if(front == NULL)
		printf("Queue is empty.\n");
	else if(front->ptr == front) {
		printf("Element %d successfully deleted.\n" , front->data);
		front = NULL;
		rear = NULL;
	}
	else {
		printf("Element %d successfully deleted.\n" , front->data);
		front = front->ptr;		
		rear->ptr = front;
	}
}

void display() {
	if(front == NULL) 
		printf("Queue is empty.\n");
	else {
		cllqueue * strt = front;
		printf("Elements of queue are : ");
		do {
			printf("%d ",strt->data);
			strt = strt->ptr;
		}while(strt != front);
		printf("\n");
 	}
}

void main() {
	int choice , flag = 1 ;
	printf("Enter the operation to be performed.\n");
	while(flag) {
		printf("1.Insert \t 2.Delete \t 3.Display \t 4.Exit  : ");
		scanf("%d" , &choice);
		switch(choice) {
			case 1 : insert();
				 break;

			case 2 : delete();
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