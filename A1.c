/* Primitive operations on Stacks using arrays. */
#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int top = -1 , a[MAX] ;

void push() {
	if( top != MAX-1 ) {
		printf("Enter the element to be pushed : ");
		int item;
		scanf("%d" , &item);
		a[++top] = item;
		printf("%d succesfully pushed onto the stack.\n" , item );
		}
	else {
		printf("Stack is full.\n");	
	}	
}

void pop() {
	if (top == -1 )
		printf("Stack is empty. No elements to pop.\n");
	else 
		printf("Element %d successfully popped out of the stack.\n" , a[top--] );
}

void display() {
	if (top != -1 ) {
		printf("Elements of Stack are : ");
		for(int i = 0 ; i <= top ; i++ ) {
			printf ("%d " , a[i]);
		}
		printf("\n");
	}
	else 
		printf("Stack is empty.\n");
}

void main() {
	int choice , flag = 1 ;
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