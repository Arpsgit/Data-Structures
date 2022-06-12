/*
    Name: Arpan Manna
    Dept.: Data Science
    Queue using Array
*/
//#include <Windows.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear = -1;

int* enqueue(int a[], int n)
{
    if(front == -1 && rear == -1)
    {
        front = front + 1;
        rear = rear + 1;
        printf("Enter the element: ");
        scanf("%d", &a[front]);
        printf("\n");
    }
    else if(front<=rear && rear < n-1)
    {
        rear = rear + 1;
        printf("Enter the element: ");
        scanf("%d", &a[rear]);
        printf("\n");
    }
    else
    {
        printf("The Queue is full!!!\n");
    }
    return a;
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\n");
    }
    else
    {
        front = front + 1;
    }
}

void display(int a[])
{
    int i;
    if(front != -1 &&  front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf(" %d->", a[i]);
        }
        printf("NULL\n");
    }
    else
    {
        printf("The Queue is empty\n");
    }
}

void main()
{
    int choice, n, i;
    int *temp;
    printf("Queue using Array\n");
    printf("Input the length of the Queue: ");
    scanf("%d", &n);
    int a[n];
    while(1)
    {
        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
        printf("\nEnter 1 to Enqueue(insert) an element in the rear\nEnter 2 to Dequeue(delete) the front element\nEnter 3 to see the front element\nEnter 4 to see the rear element\nEnter 5 to see the whole queue\nEnter 6 to exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            temp = enqueue(a, n);
            for(i = front; i < rear; i++)
            {
                a[i] = *temp;
                temp = temp + 1;
            }
            display(a);
            break;
        case 2:
            dequeue();
            display(a);
            break;
        case 3:
            if(front != -1)
            {
                printf("The element at the front is %d\n", a[front]);
            }
            else
            {   
                display(a);
            }
            break;
        case 4:
            if(rear != -1)
            {
                printf("The element at the front is %d\n", a[rear]);
            }
            else
            {   
                display(a);
            }
            break;
        case 5:
            display(a);
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
