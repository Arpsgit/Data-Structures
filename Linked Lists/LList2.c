/*Name: Arpan Manna
Dept. : Data Science
Menu Driven Linked List
Create, display, insert(begin, end, after, before, specific), delete(begin, end, specific),
sort(Ascending, descending), reverse, concatenation, search*/

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
        printf("Enter an element: ");
        scanf("%d", &a);
        printf("\n");
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
                printf("add new element?(y/n): ");
                scanf("%s", &choice);
                printf("\n");
                if(choice == 'n')
                {
                    next->link = NULL;
                }
                else
                {
                    printf("next element: ");
                    scanf("%d", &a);
                    printf("\n");
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
            
            printf("    %d\n", temporary->data);
            temporary = temporary->link;
        }
    }
}

struct element* insertAtBeginning(struct element *head)
{
    int a;
    struct element *temporary;
    temporary = (struct element *)malloc(sizeof(struct element));
    printf("Enter the new  element: ");
    scanf("%d", &a);
    printf("\n");
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
    printf("Enter the new  element: ");
    scanf("%d", &a);
    printf("\n");
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
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("\n");
    if(position == 1)
    {
        head = insertAtBeginning(head);
    }
    else
    {
        printf("Enter the new element: ");
        scanf("%d", &a);
        printf("\n");
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
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("\n");
    printf("Enter the new element: ");
    scanf("%d", &a);
    printf("\n");
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
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("\n");
    printf("Enter the new element: ");
    scanf("%d", &a);
    printf("\n");
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

struct element* deleteBeginning(struct element *head)
{
    struct element *temporary;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        temporary = head;
        head = head->link;
        free(temporary);
    }
    return head;
}

struct element* deleteEnd(struct element *head)
{
    struct element *temporary, *previousNode;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        temporary = head;
        while(temporary->link != NULL)
        {
            previousNode = temporary;
            temporary = temporary->link;
        }
        free(temporary);
        previousNode->link = 0;
    }
    return head;
}

struct element* deleteSpecific(struct element *head)
{
    struct element *temporary, *space;
    int position, i=1;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        printf("Enter the position of the element: ");
        scanf("%d", &position);
        printf("\n");
        if(position == 1)
        {
            head = deleteBeginning(head);
        }
        else
        {
            space = (struct element *)malloc(sizeof(struct element));
            temporary = head;
            while(i < position - 1)
            {
                temporary = temporary->link;
                i++;
            }
            space = temporary->link;
            temporary->link = space->link;
            free(space);
        }
    }
    return head;
}

struct element* sort(struct element *head)
{
    struct element *temporary, *next;
    int var;
    temporary = head;
    next = NULL;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        while(temporary->link != NULL)
        {
            next = temporary->link;
            while(next != NULL)
            {
                if(temporary->data > next->data)
                {
                    var = temporary->data;
                    temporary->data = next->data;
                    next->data = var;
                }
                next = next->link;
            }
            temporary = temporary->link;
        }
    }
    return head;
}

struct element* reverse(struct element *head)
{
    struct element *previous, *temporary, *next;
    previous = NULL;
    temporary = head;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        while(temporary != NULL)
        {
            next = temporary->link;
            temporary->link = previous;
            previous = temporary;
            temporary = next;
            head = previous;
        }
    }
    return head;
}

struct element* concatenation(struct element *head, struct element *head1, struct element *head2)
{
    struct element *temporary;
    temporary = head1;
    if(temporary != NULL && head2 != NULL)
    {
        while(temporary->link != NULL)
        {
            temporary = temporary->link;
        }
            temporary->link = head2;
    }
    else
    {
        printf("error\n");
    }
    head = head1;
    return head;
}

void searchElement(struct element *head, int search)
{
    int success = 0;
    int position = 1;
    struct element *temporary;
    temporary = head;
    if(head == NULL)
    {
        printf("error\n");
    }
    else
    {
        while(temporary != NULL)
        {
            if(temporary->data == search)
            {
                printf("The element %d is present at the %d position\n", search, position);
                success++;
            }
            temporary = temporary->link;
            position++;
        }
        if(success == 0)
        {
            printf("The element is not in the list\n");
        }
    }
}


int main()
{
    int option, insertOption, positionOption, deleteOption, sortOption, search;
    struct element *head = NULL;
    struct element *head1 = NULL;
    struct element *head2 = NULL;
    head = (struct element *)malloc(sizeof(struct element));
    head1 = (struct element *)malloc(sizeof(struct element));
    head2 = (struct element *)malloc(sizeof(struct element));
    printf("Linked List\n");
    while(1)
    {
        pqr:
        printf("\nEnter\n 1 for Create a List\n 2 for Display the List\n 3 for Insert New Element to the List\n 4 for Delete Element\n 5 for Sort the List\n 6 for Reverse the List\n 7 for Concatenation\n 8 for Search Element\n 9 for Exit:\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n");
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
            printf("\t Enter 4 to go back to the previous menu\n");
            printf("Enter your choice: ");
            scanf("%d", &insertOption);
            printf("\n");
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
                printf("\tEnter 4 to go back to the previous menu\n");
                printf("\nEnter your choice: ");
                scanf("%d", &positionOption);
                printf("\n");
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
            printf("\n\tEnter 1 for Delete the First Element\n");
            printf("\tEnter 2 for Delete the Last Element\n");
            printf("\tEnter 3 for Delete a Specific Element\n");
            printf("\tEnter 4 to go back to the previous menu\n");
            printf("Enter your choice: ");
            scanf("%d", &deleteOption);
            printf("\n");
            switch (deleteOption)
            {
            case 1:
                head = deleteBeginning(head);
                break;
            case 2:
                head = deleteEnd(head);
                break;
            case 3:
                head = deleteSpecific(head);
                break;
            case 4:
                goto pqr;
                break;
            default:
                break;
            }
            break;
        case 5:
            printf("Enter 1 for Ascending order\n");
            printf("Enter 2 for Descending order\n");
            printf("Enter 3 for previous menu\n");
            printf("Enter your choice: ");
            scanf("%d", &sortOption);
            printf("\n");
            switch (sortOption)
            {
            case 1:
                head = sort(head);
                break;
            case 2:
                head = sort(head);
                head = reverse(head);
                break;
            case 3:
                goto pqr;
                break;
            default:
                break;
            }
            break;
        case 6:
            head = reverse(head);
            break;
        case 7:
            printf("Create 1st Linked List:\n");
            head1 = creatList(head1);
            printf("Create 2nd Linked List:\n");
            head2 = creatList(head2);
            head = concatenation(head, head1, head2);
            break;
        case 8:
            printf("Enter the element you want to search: ");
            scanf("%d", &search);
            printf("\n");
            searchElement(head, search);
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("error\n");
            break;
        }
    }
    return 0;
}