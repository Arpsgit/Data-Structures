/* Name - Arpan Manna
Dept. - Data Science
Insertion Sort
*/

#include<stdio.h>

void displayArray(int a[], int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    
}

void insertionSort(int a[], int n)
{
    int i;
    int j;
    int temporary;
    for(i = 1; i < n; i++)
    {
        temporary = a[i];
        j = i-1;
        while(j >= 0 && a[j] > temporary)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temporary;
    }
}


int main()
{
    int i, n;
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
        insertionSort(a, n);
        printf("The sorted elements are:\n");
        displayArray(a, n);
        printf("\n");
        printf("---------------------------------------------------------------\n");
    }
    return 0;
}