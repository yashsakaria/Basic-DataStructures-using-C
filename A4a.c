/* Implement the following using recursion
a) Tower of Hanoi   */
#include<stdlib.h>
#include<stdio.h>

void toh(int n , char S , char D , char T) {
    if (n == 1)
    { 
        printf("Move disk 1 from peg %c to peg %c.\n" , S , D);
        return ;
    }
    toh( (n-1) , S , T , D);
    printf("Move disk %d from peg %c to peg %c.\n" , n , S , D);
    toh( (n-1) , T , D , S);
}

int main() {
    int n = 3;
    toh(n,'A' , 'C' , 'B');
    return 0;
}