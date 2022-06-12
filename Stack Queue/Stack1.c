/*
    Name: Arpan Manna
    Dept.: Data Science
    Stack using Array
*/
//#include <Windows.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int top = -1;
int* push(int a[], int n)
{
    
    if(top < n-1)
    {
        top = top + 1;
        printf("Enter the element you want to push in the stack: ");
        scanf("%d", &a[top]);
        printf("\n");
    }
    else
    {
        system("clear");
        printf("The stack is full!!!\n");
        sleep(3);
    }
    return a;
}

void display(int a[], int n)
{
    int i;
    system("clear");
    if(top != -1)
    {
        printf("The Stack is: \n");
        for(i = top; i >= 0; i--)
        {
            printf("    %d\n", a[i]);
        }
        if(top == n-1)
        {
            printf("Stack is full\n");
        }
    }
    else
    {
        printf("The Stack is empty!\n");
    }
}

void pop(int a[])
{
    if(top == -1)
    {
        printf("\n");
    }
    else
    {
        top = top - 1;
    }
}

void main()
{
    int *temp;
    int choice, i;
    printf("Stack using Array\n");
    int n;
    printf("Input the length of the Stack: ");
    scanf("%d", &n);
    printf("\n");
    int a[n];
    while(1)
    {
        printf("\nEnter 1 to push an element in the Stack\nEnter 2 to pop the top element\nEnter 3 to see the top element\nEnter 4 to display the Stack\nEnter 5 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            temp = push(a, n);
            for(i = 0; i < top; i++)
            {
                a[i] = *temp;
                temp = temp + 1;
            }
            display(a, n);
            break;
        case 2:
            pop(a);
            display(a, n);
            break;
        case 3:
            system("clear");
            if(top == -1)
            {
                
                printf("The Stack is empty!\n");
            }
            else
            {
                printf("%d is the top most element in the stack\n", a[top]);
                break;
            }
        case 4:
            display(a, n);
            break;
        case 5:
            exit(1);
            break;
        default:
            system("clear");
            printf("Please enter a valid choice!\n");
            break;
        }
    }

}