/*
Name: Arpan Manna
Dept.: Data Science
Queue using Linked List with Enqueue, Dequeue, ShowFront, ShowRear, Display operations
*/
#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct element *link;
};

typedef struct element elmnt;
struct pointer{
    elmnt *front;
    elmnt *rear;
};

struct pointer* enqueue(struct pointer *abc)
{
    int a;
    elmnt *temporary;
    temporary = (elmnt *)malloc(sizeof(elmnt));
    printf("Enter an element: ");
    scanf("%d", &a);
    printf("\n");
    if(abc->front == NULL && abc->rear == NULL)
    {
        temporary->data = a;
        temporary->link = NULL;
        abc->front = temporary;
        abc->rear = temporary;
    }
    else
    {
        abc->rear->link = temporary;
        temporary->data = a;
        temporary->link = NULL;
        abc->rear = temporary;
    }
    return abc;
}

struct pointer* dequeue(struct pointer *abc)
{
    elmnt *temporary;
    elmnt *f = abc->front;
    elmnt *r = abc->rear;
    if(abc->front == NULL && abc->rear == NULL)
    {
        printf("\n");
    }
    else if(f == r)
    {
        temporary = abc->front;
        abc->front = NULL;
        abc->rear = NULL;
        free(temporary);
    }
    else
    {
        temporary = abc->front;
        abc->front = f->link;
        free(temporary);
    }
    return abc;
}

void showFront(struct pointer *abc)
{
    if(abc->front != NULL)
    {
        printf("The element is the front is %d\n", abc->front->data);
    }
    else
    {
        printf("The queue is empty\n");
    }
}

void showRear(struct pointer *abc)
{
    if(abc->rear != NULL)
    {
        printf("The element is the rear is %d\n", abc->rear->data);
    }
    else
    {
        printf("The queue is empty\n");
    }
}

void display(struct pointer *abc)
{
    elmnt *temporary;
    temporary = abc->front;
    if(abc->front == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        system("clear");
        printf("The elements are:\n");
        while(temporary != NULL)
        {
            printf(" %d ->", temporary->data);
            temporary = temporary->link;
        }
        printf("NULL\n");
    }
}

void main()
{
    int choice;
    struct pointer *abc;
    abc->front = NULL;
    abc->rear = NULL;
    printf("Queue using Linked List\n");
    while(1)
    {
        printf("\nEnter 1 to Enqueue(insert) an element in the rear\nEnter 2 to Dequeue(delete) the front element\nEnter 3 to see the front element\nEnter 4 to see the rear element\nEnter 5 to see the whole queue\nEnter 6 to exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            abc = enqueue(abc);
            display(abc);
            break;
        case 2:
            abc = dequeue(abc);
            display(abc);
            break;
        case 3:
            showFront(abc);
            break;
        case 4:
            showRear(abc);
            break;
        case 5:
            display(abc);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Wrong input\n");
            break;
        }
    }
}