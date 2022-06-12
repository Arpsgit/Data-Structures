/* Name - Arpan Manna
Dept. - Data Science
Binary Search without recursion*/

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

int binarySearch(int a[], int n, int element)
{
    int left = 0;
    int right;
    int mid;
    right  = n-1;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(element == a[mid])
        {
            return mid;
        }
        else if (element < a[mid])
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }    
    }
    return -1; 
}

int main()
{
    int i, n, element, recieve;
    char choice;
    while(1)
    {
        printf("Enter the total number of elements: ");
        scanf("%d", &n);
        printf("\n");
        int a[n];
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
        recieve = binarySearch(a, n, element);
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