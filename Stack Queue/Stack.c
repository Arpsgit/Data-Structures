/*
Name: Arpan Manna
Dept.: Data Science
Stack using Linked List with Push, Pop, Peak, Display operations
*/
#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct element *link;
};

typedef struct element elmnt;

elmnt* push(elmnt *top)
{
    int a;
    struct element *temporary;
    temporary = (elmnt *)malloc(sizeof(elmnt));
    printf("Enter the new  element: ");
    scanf("%d", &a);
    printf("\n");
    temporary->data = a;
    temporary->link = NULL;
    temporary->link = top;
    top = temporary;
    return top;
}

elmnt* pop(elmnt *top)
{
    if(top == NULL)
    {
        //printf("The stack is empty\n");
        return top;
    }
    else
    {
        struct element *temporary;
        temporary = top;
        top = top->link;
        free(temporary);
        return top;
    }
}

void display(elmnt *top)
{
    elmnt *temporary;
    temporary = top;
    if(top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The elements are:\n");
        while(temporary != NULL)
        {
            printf("    %d\n", temporary->data);
            temporary = temporary->link;
        }
    }
}

void peak(elmnt *top)
{
    if(top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The top element is %d\n", top->data);
    }
}

void  main()
{
    int choice;
    elmnt *top = NULL;
    printf("Stack using Linked List\n");
    while(1)
    {
        printf("\nEnter 1 to push(insert) an element in the top\nEnter 2 to pop(delete) the top element\nEnter 3 to see the top most element\nEnter 4 to see the whole stack\nEnter 5 to exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            top = push(top);
            display(top);
            break;
        case 2:
            top = pop(top);
            display(top);
            break;
        case 3:
            peak(top);
            break;
        case 4:
            display(top);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}