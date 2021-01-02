/* Implement binary search using recursion. */
#include<stdlib.h>
#include<stdio.h>

int binarysearch(int a[] , int low ,int high , int x) {
    
        if(low>high)
            return -1;
        int mid = low + (high-low)/2;
        
        if(a[mid] == x)
            return mid;
        
        else if(x<a[mid])
            return binarysearch(a , low , mid-1 , x );
        
        else
            return binarysearch(a , mid+1 , high , x );
}

void main() {
    printf("Enter the size of array : ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements : ");
    for(int i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);
    printf("Enter the element to be searched : ");
    int x;
    scanf("%d" , &x);

    int res = binarysearch(a , 0 , n-1 , x );
    if(res == -1 )
        printf("Element %d not found.\n" , x);
    else
        printf("Element found at posistion %d.\n" , res+1);    
}