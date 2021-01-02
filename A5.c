/* Circular queue using arrays. */
#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int f = 0 , r = -1 , a[MAX] , count = 0;

void insert() {
	if(count == MAX) 
		printf("Queue is full.\n");
	else {
		int item;
		printf("Enter the element to be inserted : ");
		scanf("%d" , &item);
		r = (r+1)%MAX;
		a[r] = item;
		printf("%d succesffully inserted.\n" , item);
		count++;
	}
}

void delete() {
	if (count == 0)
		printf("Queue is empty.\n");
	else {
		printf("Element %d successfully deleted.\n" , a[f]);
		f = (f+1)%MAX;
		count--;	
	}
}

void display() {
	if (count == 0)
		printf("Queue is empty.\n");
	else {
		int temp = count;
		printf("Elements of queue are : ");
		for(int i = f ; temp > 0 ; i=(i+1)%MAX) {
			printf("%d ", a[i]);
			temp--;
		}
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
	


