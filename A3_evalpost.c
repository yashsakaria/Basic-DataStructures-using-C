/* Evaluation of a valid Postfix expression using stacks. */
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

int s[50] , top = -1 ;

void push(int item) {
	s[++top] = item;
}

int pop() {
	return s[top--];
}

void main() {
	printf("Enter the postfix expression : ");
	char exp[50] , *e;
	scanf("%s", exp);
	e = exp;
	
	while(*e != '\0') {
		
		if(isdigit(*e))
			push((int)(*e - '0'));
		
		else {
		
			int op1 = pop();
			int op2 = pop();
			
			switch(*e) {
				case '+' : push(op2 + op1);
									 break;
				case '-' : push(op2 - op1);
									 break;
				case '*' : push(op2*op1);
									 break;
				case '/' : if(op1 != 0)
											push(op2 / op1);
									 else {
											printf("can't divide by zero.\n");
											printf("Terminating calculation.\n");
											exit(1);
										}
									 break;
				case '^' : push((int)pow(op2,op1));
									 break;
			}
		}
		e++;
	}
	
	printf("Result : %d \n", s[top]);
}
										
										
										
										
										
										
										
										
										
										
										
										
									
