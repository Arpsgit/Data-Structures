/* Name - Arpan Manna
Dept. - Data Science
Selection Sort
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

void selectionSort(int a[], int n)
{
    int i;
    int j;
    int temporary, var;
    for(i = 0; i <= n-2; i++)
    {
        var = i;
        for(j = i+1; j <= n-1; j++)
        {
            if(a[j] < a[var])
            {
                var = j;
            }
        }
        temporary = a[i];
        a[i] = a[var];
        a[var] = temporary;
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
        selectionSort(a, n);
        printf("The sorted elements are:\n");
        displayArray(a, n);
        printf("\n");
        printf("---------------------------------------------------------------\n");
    }
    return 0;
}