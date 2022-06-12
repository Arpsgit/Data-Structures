/*
    Name: Arpan Manna
    Dept.: Data Science
    Stack using Doubly Linked List
*/

#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct  element *prev;
    struct element *next;
};

typedef struct element ele;

ele* getNode(){
    ele *node;
    node = (ele*)malloc(sizeof(ele));
    if(node == NULL){
        printf("Overflow!!!\n");
    }
    else{
        return node;
    }
}

ele* push(ele *top)
{
    int a;
    ele *temporary = NULL;
    temporary = getNode();
    printf("Enter the new  element: ");
    scanf("%d", &temporary->data);
    printf("\n");
    if(top == NULL){
        temporary->prev = NULL;
        temporary->next = NULL;
        top = temporary;
    }
    else{
        temporary->prev = NULL;
        temporary->next = top;
        top->prev = temporary;
        top = top->prev;
    }
    return top;
}

ele* pop(ele *top)
{
    ele *temporary = NULL;
    if(top == NULL)
    {
        printf("\n");
    }
    else if(top->next == NULL){
        free(top);
        top = NULL;
    }
    else
    {
        temporary = top;
        top = top->next;
        top->prev = NULL;
        free(temporary);
    }
    return top;
}

void display(ele *top)
{
    ele *temporary = NULL;
    temporary = top;
    system("clear");
    if(top == NULL)
    {
        printf("The stack is empty!!!\n");
    }
    else
    {
        printf("The elements are:\n");
        while(temporary != NULL)
        {
            printf("    %d\n", temporary->data);
            temporary = temporary->next;
        }
    }
}

void peak(ele *top)
{
    if(top == NULL)
    {
        printf("The stack is empty!!!\n");
    }
    else
    {
        printf("The top element is %d\n", top->data);
    }
}

void  main()
{
    int choice;
    ele *top = NULL;
    printf("Stack using Doubly Linked List\n");
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