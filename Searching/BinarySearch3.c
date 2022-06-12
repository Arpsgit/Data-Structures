/* Name - Arpan Manna
Dept. - Data Science
Binary Search with recursion*/

#include<stdio.h>

void displayArray(int a[], int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    
}

void bubbleSort(int a[], int n)
{
    int i;
    int j;
    int temporary, var;
    for(i = 0; i < n-1; i++)
    {
        var = 0;
        for(j = 0; j< n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                temporary = a[j];
                a[j] = a[j+1];
                a[j+1] = temporary;
                var++;
            }    
        }
        if(var == 0)
        {
            break;
        }
    }
}

int binarySearch(int a[], int left, int right, int element)
{
    int mid;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(element == a[mid])
        {
            return mid;
        }
        else if (element < a[mid])
        {
            return binarySearch(a, left, mid-1, element);
        }
        else
        {
            return binarySearch(a, mid+1, right, element);
        }    
    }
    return -1; 
}

int main()
{
    int i, n, element, recieve;
    int left, right;
    char choice;
    while(1)
    {
        printf("Enter the total number of elements: ");
        scanf("%d", &n);
        printf("\n");
        int a[n];
        left = 0;
        right = n-1;
        for(i = 0; i < n; i++)
        {
            printf("Enter the element of index %d : ", i);
            scanf("%d", &a[i]);
            printf("\n");
        }
        printf("The elements are:\n");
        displayArray(a, n);
        printf("\n");
        bubbleSort(a, n);
        printf("The sorted elements are:\n");
        displayArray(a, n);
        printf("\n");
        abc:
        printf("Enter the element you want to search: ");
        scanf("%d", &element);
        recieve = binarySearch(a, left, right, element);
        if(recieve == -1)
        {
            printf("The element %d is not present in this array\n", element);
        }
        else
        {
            printf("The element %d is present at the index %d\n", a[recieve], recieve);
        }
        printf("Want to search more(y/n): ");
        scanf("%s", &choice);
        if(choice == 'y')
        {
            goto abc;
        }
        printf("\n");
        printf("---------------------------------------------------------------\n");
    }
    return 0;
}