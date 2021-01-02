/* Implement gcd using recursion. */
#include<stdio.h>
#include<stdlib.h>

int gcd(int a , int b) {

    int res = a%b;
    if(res != 0) {
        b = gcd( b , res);
        return b;
    }
    else 
        return b;
}
void main() {
    int a , b;
    printf("Enter two numbers to calculate gcd : ");
    scanf("%d %d" ,&a,&b);
    if(a<b) {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    printf("GCD of %d and %d is : %d\n", a , b , gcd(a,b) );
}