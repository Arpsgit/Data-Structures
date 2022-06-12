/*
    Name: Arpan Manna
    Dept.: Data Science
    Queue using Doubly Linked List
*/

#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct  element *prev;
    struct element *next;
};

typedef struct element ele;

ele *front = NULL;
ele *rear = NULL;

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

void enqueue()
{
    int a;
    ele *temporary;
    temporary = getNode();
    printf("Enter an element: ");
    scanf("%d", &a);
    printf("\n");
    if(front == NULL && rear == NULL)
    {
        temporary->data = a;
        temporary->prev = NULL;
        temporary->next = NULL;
        front = temporary;
        rear = temporary;
    }
    else
    {
        rear->next = temporary;
        temporary->data = a;
        temporary->prev = rear;
        temporary->next = NULL;
        rear = temporary;
    }
}

void dequeue()
{
    ele *temporary;
    if(front == NULL && rear == NULL)
    {
        printf("\n");
    }
    else if(front == rear)
    {
        temporary = front;
        front = NULL;
        rear = NULL;
        free(temporary);
    }
    else
    {
        temporary = front;
        front = front->next;
        front->prev = NULL;
        free(temporary);
    }
}

void showFront()
{
    if(front != NULL)
    {
        printf("The element in the front is %d\n", front->data);
    }
    else
    {
        printf("The queue is empty!!!\n");
    }
}

void showRear()
{
    if(rear != NULL)
    {
        printf("The element in the rear is %d\n", rear->data);
    }
    else
    {
        printf("The queue is empty!!!\n");
    }
}

void display()
{
    ele *temporary;
    temporary = front;
    system("clear");
    if(front == NULL)
    {
        printf("The queue is empty!!!\n");
    }
    else
    {
        printf("The elements are:\n");
        printf("NULL =>");
        while(temporary != NULL)
        {
            printf(" %d =>", temporary->data);
            temporary = temporary->next;
        }
        printf("NULL\n");
    }
}

void main()
{
    int choice;
    printf("Queue using Doubly Linked List\n");
    while(1)
    {
        printf("\nEnter 1 to Enqueue(insert) an element in the rear\nEnter 2 to Dequeue(delete) the front element\nEnter 3 to see the front element\nEnter 4 to see the rear element\nEnter 5 to see the whole queue\nEnter 6 to exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            enqueue();
            display();
            break;
        case 2:
            dequeue();
            display();
            break;
        case 3:
            showFront();
            break;
        case 4:
            showRear();
            break;
        case 5:
            display();
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