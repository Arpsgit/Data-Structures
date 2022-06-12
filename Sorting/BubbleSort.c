/* Name - Arpan Manna
Dept. - Data Science
Bubble Sort*/

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
        bubbleSort(a, n);
        printf("The sorted elements are:\n");
        displayArray(a, n);
        printf("\n");
        printf("---------------------------------------------------------------\n");
    }
    return 0;
}