/*Name: Arpan Manna
Dept. : Data Science*/

#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct element *link;
};


struct element* creatList(struct element *head)
{
    int a;
    char choice;
    struct element *temporary, *next;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        printf("Enter an element=\n");
        scanf("%d", &a);
        head->data = a;
        head->link = NULL;
        temporary = head;
        up:
        next = (struct element *)malloc(sizeof(struct element));
        if(next == NULL)
            {
                printf("error\n");
            }
        else
            {
                printf("add new element?(y/n):\n");
                scanf("%s", &choice);
                if(choice == 'n')
                {
                    next->link = NULL;
                }
                else
                {
                    printf("next element:\n");
                    scanf("%d", &a);
                    next->data = a;
                    next->link = NULL;
                    temporary->link = next;
                    temporary = temporary->link;
                    goto up;
                }
            }
    }
    return head; 
}

void display(struct element *head)
{
    struct element *temporary;
    if(head == NULL)
    {
        printf("empty\n");
    }
    else
    {
        temporary = head;
        printf("The elements are:\n");
        while(temporary != NULL)
        {
            
            printf("%d\n", temporary->data);
            temporary = temporary->link;
        }
    }
}

struct element* insertAtBeginning(struct element *head)
{
    int a;
    struct element *temporary;
    temporary = (struct element *)malloc(sizeof(struct element));
    printf("Enter the new  element:\n");
    scanf("%d", &a);
    temporary->data = a;
    temporary->link = NULL;
    temporary->link = head;
    head = temporary;
    return head;
}

struct element* insertAtEnd(struct element *head)
{
    int a;
    struct element *temporary, *new;
    temporary = (struct element *)malloc(sizeof(struct element));
    printf("Enter the new  element:\n");
    scanf("%d", &a);
    temporary->data = a;
    temporary->link = 0;
    new = head;
    while(new->link != NULL)
    {
        new = new->link;
    }
    new->link = temporary;
    return head;
}

struct element* insertAtSpecificPosition(struct element *head)
{
    int a, position, i=1;
    struct element *temporary, *new;
    new = (struct element *)malloc(sizeof(struct element));
    printf("Enter the position:\n");
    scanf("%d", &position);
    if(position == 1)
    {
        head = insertAtBeginning(head);
    }
    else
    {
        printf("Enter the new element:\n");
        scanf("%d", &a);
        temporary= head;
        new->data = a;
        new->link = 0;
        while(i < position-1)
        {
            temporary = temporary->link;
            i++;

        }
        new->link = temporary->link;
        temporary->link = new;
        return head;
    }
}

struct element* insertAfterNode(struct element *head)
{
    int a, position, i=1;
    struct element *temporary, *new;
    new = (struct element *)malloc(sizeof(struct element));
    printf("Enter the position:\n");
    scanf("%d", &position);
    printf("Enter the new element:\n");
    scanf("%d", &a);
    new->data = a;
    new->link = 0;
    temporary= head;
    while(i < position)
    {
        temporary = temporary->link;
        i++;

    }
    new->link = temporary->link;
    temporary->link = new;
    return head;
}

struct element* insertBeforeNode(struct element *head)
{
    int a, position, i=1;
    struct element *temporary, *new;
    new = (struct element *)malloc(sizeof(struct element));
    printf("Enter the position:\n");
    scanf("%d", &position);
    printf("Enter the new element:\n");
    scanf("%d", &a);
    new->data = a;
    new->link = 0;
    temporary= head;
    while(i < position-1)
    {
        temporary = temporary->link;
        i++;

    }
    new->link = temporary->link;
    temporary->link = new;
    return head;
}
int main()
{
    int option, insertOption, positionOption;
    struct element *head = NULL;
    head = (struct element *)malloc(sizeof(struct element));
    printf("Linked List\n");
    while(1)
    {
        pqr:
        printf("Enter 1 for Create a List\n2 for Display the List\n3 for Insert New Element to the List\n4 for exit:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = creatList(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            xyz:
            printf("\n\t Enter 1 to insert new element at the beginning\n");
            printf("\t Enter 2 to insert new element at the end\n");
            printf("\t Enter 3 to insert new element at any position\n");
            printf("\t press 4 to go back to the previous menu\n");
            printf("Enter your choice: \n");
            scanf("%d", &insertOption);
            switch (insertOption)
            {
            case 1:
                head = insertAtBeginning(head);
                break;
            case 2:
                head = insertAtEnd(head);
                break;
            case 3:
                printf("\n\tEnter 1 to insert after a position\n");
                printf("\tEnter 2 to insert before a position\n");
                printf("\tEnter 3 to insert at specific position\n");
                printf("\t press 4 to go back to the previous menu\n");
                printf("\nEnter your choice: \n");
                scanf("%d", &positionOption);
                switch (positionOption)
                {
                case 1:
                    head = insertAfterNode(head);
                    break;
                case 2:
                    head = insertBeforeNode(head);
                    break;
                case 3:
                    head = insertAtSpecificPosition(head);
                    break;
                case 4:
                    goto xyz;
                    break;
                default:
                    break;
                }
                break;
            case 4:
                goto pqr;
                break;
            default:
                break;
            }
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("error\n");
            break;
        }
    }
    return 0;
}