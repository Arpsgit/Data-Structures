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

int binarySearch(int a[], int element, int count, int left, int right)
{
    int mid, temp;
    temp = right;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(element == a[mid])
        {
        printf("The element %d is at the index %d\n", a[mid], mid);
        count++;
        right = mid - 1;
        count = binarySearch(a, element, count, left, right);
        left = mid + 1;
        right = temp;
        count = binarySearch(a, element, count, left, right);
        break;
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
    return count;
    
}


int main()
{
    int i, n, element, count = 0;
    int left, right;
    while(1)
    {
        printf("Enter the total number of elements: ");
        scanf("%d", &n);
        printf("\n");
        left = 0;
        right = n-1;
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
        printf("Enter the element you want to search: ");
        scanf("%d", &element);
        count = binarySearch(a, element, count, left, right);
        if(count == 0)
        {
            printf("The element is not present in this array\n");
        }
        else
        {
            printf("The element is present %d times in the array", count);
        }
        printf("\n");
        printf("---------------------------------------------------------------\n");
    }
    return 0;
}