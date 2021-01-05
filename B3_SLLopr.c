/* 	Singly Linked List with the following operations:
	a.Inserting a node( Any desired position)
	b.Deleting a node (Any desired position)
	c.Display	*/
#include<stdlib.h>
#include<stdio.h>

typedef struct sll {
	int data;
	struct sll * link;
}sll;

sll * head = NULL;
int count = 0;

sll * createnode() {
	sll * newnode = (sll *)malloc(sizeof(sll));
	printf("Enter the roll no of student : ");
	scanf("%d" , &newnode->data);
	newnode->link = NULL;
	count++;
	return newnode;
}

void insert() {
	if (head == NULL) {
		printf("Creating the very first node.\n");
		head = createnode();
	}
	else {
		printf("Enter the posistion at which you want to insert (between 0 and %d) : " , count);
		int pos;
		scanf("%d", &pos);
		if(pos <= count && pos>-1) {
			sll * temp = createnode();
			if(pos == 0) {
				temp->link = head;
				head = temp;
			}
			else {
				sll * trav = head;
				for(int i = 0 ; i < pos-1 ; i++ ) 
					trav = trav->link;
				temp->link = trav->link;
				trav->link = temp;
			}
		}
		else 
			printf("Invalid Input.\n");
	}
}

void delete() {
	if(head == NULL) 
		printf("Singly Linked List is empty.\n");
	else {
		printf("Enter the posistion at which you want to insert (between 0 and %d) : " , count-1);
		int pos;
		scanf("%d", &pos);
		if(pos < count && pos>-1) {
			if(pos == 0) {
				printf("Element %d successfully deleted.\n" , head->data);
				head = head->link;
			}
			else {
				sll * trav = head;
				for(int i = 0 ; i < pos-1 ; i++ ) 
					trav = trav->link;
				sll * temp = trav->link;
				trav->link = temp->link;
				printf("Element %d successfully deleted.\n" , temp->data);
				free(temp);
				temp = NULL;
			}
			count--;
		}
		else 
			printf("Invalid input.\n");
	}
}

void display() {
	if(head != NULL) {
		sll * strt = head;
		printf("Elements of list are : ");
		while(strt != NULL) {
			printf("%d " , strt->data);
			strt = strt->link;
		}
		printf("\n");
	}
	else 
		printf("Singly Linked List is empty.\n");
}

void main() {
	printf("-----Singly Linked List-----\n");
	printf("We follow zero based index.\n");
	printf("Enter the operation to be performed.\n");
	int ch , flag  =1;
	while(flag) {
		printf("1.Insert \t 2.Display \t 3.Delete \t 4.Exit : ");
		scanf("%d" , &ch);
		switch(ch) {
			case 1 : insert();
					 break;
			case 2 : display();
					 break;
			case 3 : delete();
					 break;
			case 4 : flag = 0;
					 break;
			default : printf("Invalid Input.\n");
					  break;
		}
	}
}