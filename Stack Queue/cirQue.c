/*
    Name: Arpan Manna
    Dept.: Data Science
    Queue using Circular Linked List
*/

#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct element *link;
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

void display(ele *last)
{
    ele *temporary = NULL;
    system("clear");
    if(last == NULL)
    {
        printf("The Queue is Empty!!!\n");
    }
    else
    {
        temporary = last->link;
        printf("The elements are: \n");
        printf("%d->", temporary->data);
        temporary = temporary->link;
        while(temporary != last->link)
        {
            printf("%d->", temporary->data);
            temporary = temporary->link;
        }
        printf("Last\n");
    }
}

ele* enqueue(ele *last)
{
    ele *temporary = NULL;
    temporary = getNode();
    printf("Enter an element: ");
    scanf("%d", &temporary->data);
    printf("\n");
    temporary->link = NULL;
    if(last == NULL)
    {
        last = temporary;
        last->link = last;
    }
    else
    {
        temporary->link = last->link;
        last->link = temporary;
        last = temporary;
    }
    return last;
}

ele* dequeue(ele *last)
{
    ele *temporary;
    if(last == NULL)
    {
        printf("\n");
    }
    else if(last == last->link)
    {
        free(last);
        last = NULL;
    }
    else
    {
        temporary = last->link;
        last->link = temporary->link;
        free(temporary);
    }
    return last;
}

void showFront(ele *last)
{
    if(last != NULL)
    {
        printf("The element in the front is %d\n", last->link->data);
    }
    else
    {
        printf("The queue is empty!!!\n");
    }
}

void showRear(ele *last)
{
    if(last != NULL)
    {
        printf("The element in the rear is %d\n", last->data);
    }
    else
    {
        printf("The queue is empty!!!\n");
    }
}

void main()
{
    int choice;
    ele *last = NULL;
    printf("Queue using Circular Linked List\n");
    while(1)
    {
        printf("\nEnter 1 to Enqueue(insert) an element in the rear\nEnter 2 to Dequeue(delete) the front element\nEnter 3 to see the front element\nEnter 4 to see the rear element\nEnter 5 to see the whole queue\nEnter 6 to exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            last = enqueue(last);
            display(last);
            break;
        case 2:
            last = dequeue(last);
            display(last);
            break;
        case 3:
            showFront(last);
            break;
        case 4:
            showRear(last);
            break;
        case 5:
            display(last);
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