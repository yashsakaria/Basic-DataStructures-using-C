/* 	Conversion  of  a  valid  Infix  expression  to  Postfix  Expression  using  stacks.Program  should support for both parenthesized and 
	parenthesize free expressions with the operators: +, -, *, /, %(Remainder),^(Power) and alphanumeric operands	*/
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

int top = -1;
char s[100];

void push (char ch) {
	s[++top] = ch;
}

char pop() {
	return s[top--];
}

int priority(char ch) {
	
	if(ch == '(')
		return 0;
	if (ch =='+' || ch =='-')
		return 1;
	if (ch =='*' || ch =='/')
		return 2;
	if(ch =='^')
		return 3;

	return 0;
}

void main () {

	char *e, x ;
	char exp[100];
	printf("Enter the infix expression : ");
	scanf("%s",exp);
	printf("Postfix Expression : ");
	e = exp;
	
	while(*e != '\0') {
		if(isalnum(*e))
			printf("%c" , *e);

		else if(*e == '(')
			push(*e);

		else if(*e == ')')
			while((x=pop()) != '(')
				printf("%c" , x);

		else {
			while(priority(s[top]) >= priority(*e))
				printf("%c" , pop());
			push(*e);
		}
		e++;
	}

	while(top != -1)
			printf("%c" , pop());
}