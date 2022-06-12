/* Name: Arpan Manna
Dept.: Data Science
Linear Search */

#include<stdio.h>
#include<stdlib.h>

void displayArray(int a[], int n)
{
    int i;
    printf("The elements of the array:\n");
    for(i = 0; i < n; i++)
    {
        
        printf("\t%d", a[i]);
        
    }
    printf("\n");
}

void linearSearch(int a[], int element, int n)
{
    int success = 0, i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == element)
        {
            printf("The element %d is present at the index %d\n", element, i);
            success++;
        }
        
    }
    if(success == 0)
    {
        printf("The element %d is not in this array\n", element);
    }
}
void main()
{
    int i, n;
    int element;
    printf("Enter the number of elements you want add in this array:\n");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
    {
        printf("Enter the element of the index %d \n", i);
        scanf("%d", &a[i]);
        
    }
    displayArray(a, n);
    while(1)
    {
        printf("Enter the element you want to search:\n");
        scanf("%d", &element);
        linearSearch(a, element, n);
    }

}