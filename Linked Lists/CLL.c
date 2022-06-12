/*
    Name: Arpan Manna
    Dept.: Data Science
    Circular Linked List(Create node, Insert Begin, Delete Begin, Search, Reverse)
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct element
{
    int data;
    struct element *link;
};
typedef struct element ele;

ele* createNode(ele *last)
{
    last = (ele *)malloc(sizeof(ele));
    printf("Enter the  element: ");
    scanf("%d", &last->data);
    printf("\n");
    last->link = last;
    return last;
}

void display(ele *last)
{
    ele *temporary = NULL;
    system("cls");
    if(last == NULL)
    {
        printf("The List is Empty!!!\n");
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
        printf("head\n");
    }
}

ele* insertBeg(ele *last)
{
    ele *temporary = NULL;
    if(last == NULL)
    {
        return createNode(last);
    }
    else
    {
        temporary = (ele *)malloc(sizeof(ele));
        printf("Enter the  element: ");
        scanf("%d", &temporary->data);
        printf("\n");
        temporary->link = last->link;
        last->link = temporary;
    }
    return last;
}

ele* deleteBeg(ele *last)
{
    ele *temp = NULL;
    if(last == NULL)
    {
        printf("The List is Empty!!!\n");
    }
    else if(last == last->link)
    {
        free(last);
        last = NULL;
    }
    else
    {
        temp = last->link;
        last->link = temp->link;
        free(temp);
    }
    return last;
}

void search(ele *last, int find)
{
    int success = 0;
    int position = 1;
    ele *temp = NULL;
    if(last == NULL)
    {
        printf("The list is empty!!!\n");
    }
    else
    {
        temp = last->link;
        if(temp->data == find)
        {
            printf("The element %d is present at the %d position\n", find, position);
            success++;
        }
        temp = temp->link;
        position++;
        while(temp != last->link)
        {
            if(temp->data == find)
            {
                printf("The element %d is present at the %d position\n", find, position);
                success++;
            }
            temp = temp->link;
            position++;
        }
        if(success == 0)
        {
            printf("The element %d is not in the list\n", find);
        }
    }
}

ele* reverse(ele *last)
{
    ele *temp = NULL;
    ele *next = NULL;
    ele *head = NULL;
    if(last == NULL)
    {
        printf("The list is empty!!!\n");
    }
    else
    {
        last = last->link;
        head = last;
        temp = last;
        next = last->link;
        last = last->link;
        while(last != head)
        {
            last = last->link;
            next->link = temp;
            temp = next;
            next = last;
        }
        next->link = temp;
    }
    return last;
}

void main()
{
    int choice, find;
    ele *last = NULL;
    while(1)
    {
        printf("\n1 for creating node\n2 for displaying the list\n3 for inserting at the beginnig\n4 for deleting from the beginnnig\n5 for searching\n6 for reversing\n7 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            last = createNode(last);
            display(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            last = insertBeg(last);
            display(last);
            break;
        case 4:
            last = deleteBeg(last);
            display(last);
            break;
        case 5:
            printf("Enter the element you want to search: ");
            scanf("%d", &find);
            printf("\n");
            search(last, find);
            break;
        case 6:
            last = reverse(last);
            display(last);
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Wrong Input!!!\n");
            break;
        }
    }
}