/* Primitive operations on Linear Queue using arrays. */
#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int front = 0 ,  rear = -1 , a[MAX] ;

void insert() {
	if(rear != MAX-1) {
	int item;
	printf("Enter the element to be pushed : ");
	scanf("%d" , &item);
	a[++rear] = item;
	printf("%d succesffully inserted.\n" , item);
	}
	else 
		printf("Queue is full.\n");
}

void delete() {
	if (rear == -1) {
		printf("Queue is empty.\n");
	}
	else if (front == rear) {
		printf("%d successfully deleted.\n" , a[front]);
		front = 0;
		rear = -1;
	}
	else 
		printf("%d successfully deleted.\n" , a[front++]);
}

void display() {
	if (rear != -1) {
		printf("Elements of queue are : ");
		for (int i = front ; i <= rear ; i++)
			printf("%d " , a[i]);
		printf("\n");
	}
	else
		printf("Queue is empty.\n");
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


