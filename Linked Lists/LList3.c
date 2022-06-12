/*Name: Arpan Manna
Dept. : Data Science
Menu Driven Linked List
Create, display, insert(begin, end, after, before, specific), delete(begin, end, after, before, specific, element),
sort(Ascending, descending), reverse, concatenation*/

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

ele* creatList(struct element *head)
{
    int a;
    char choice;
    ele *temporary, *next;
    head = (struct element *)malloc(sizeof(struct element));
    printf("Enter an element: ");
    scanf("%d", &a);
    printf("\n");
    head->data = a;
    head->link = NULL;
    temporary = head;
    up:
    next = (struct element *)malloc(sizeof(struct element));
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
    return head; 
}

void display(struct element *head)
{
    struct element *temporary;
    temporary = head;
    printf("The elements are:\n");
    while(temporary != NULL)
    {
        
        printf("    %d\n", temporary->data);
        temporary = temporary->link;
    }
}

struct element* insertAtBeginning(struct element *head)
{
    int a;
    struct element *temporary;
    temporary = (struct element *)malloc(sizeof(struct element)); //getNode()
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
    temporary = (struct element *)malloc(sizeof(struct element));//getNode()
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

struct element* insertAfterNode(struct element *head, int elmnt, int success)
{
    /*int a, position, i=1;
    struct element *temporary, *new;
   new =  (struct element *)malloc(sizeof(struct element));
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
    return head;*/
    int position = 1;
    int i = 1;
    int a;
    struct element *temporary;
    struct element *new;
    new =  (struct element *)malloc(sizeof(struct element));
    printf("Enter the new element: ");
    scanf("%d", &a);
    printf("\n");
    new->data = a;
    new->link = 0;
    temporary = head;

    while(temporary != NULL)
    {
        if(temporary->data == elmnt)
        {
            success++;
            while(i < position)
            {
                temporary = temporary->link;
                i++;
            }
            new->link = temporary->link;
            temporary->link = new;
            return head;
        }
        temporary = temporary->link;
        position++;
    }
    if(success == 0)
    {
        printf("\nThe element %d is not in the list\n", elmnt);
    }
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
    temporary = head;
    head = head->link;
    free(temporary);
    return head;
}

struct element* deleteEnd(struct element *head)
{
    struct element *temporary, *previousNode;
    temporary = head;
    while(temporary->link != NULL)
    {
        previousNode = temporary;
        temporary = temporary->link;
    }
    free(temporary);
    previousNode->link = 0;
    return head;
}

struct element* deleteSpecific(struct element *head)
{
    struct element *temporary, *space;
    int position, i=1;
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
    return head;
}

struct element* deleteAfter(struct element *head, int elmnt, int success)
{
    int position = 1;
    int i = 1;
    struct element *temporary;
    struct element *space;
    
    temporary = head;

    while(temporary != NULL)
    {
        if(temporary->data == elmnt)
        {
            success++;
            space = (struct element *)malloc(sizeof(struct element));
            while(i < position)
            {
                temporary = temporary->link;
                i++;
            }
            if(temporary->link == NULL)
            {
                printf("Operation is not possible\n");
                return head;
            }
            space = temporary->link;
            temporary->link = space->link;
            free(space);
            return head;
        }
        temporary = temporary->link;
        position++;
    }
    if(success == 0)
    {
        printf("\nThe element %d is not in the list\n", elmnt);
    }
    return head;
}

struct element* deleteBefore(struct element *head, int elmnt, int success)
{
    int position = 1;
    int i = 1;
    struct element *temporary;
    struct element *space;
    
    temporary = head;

    while(temporary != NULL)
    {
        if(temporary->data == elmnt)
        {
            success++;
            if(position == 1)
            {
                printf("Operation is not possible!\n");
            }
            else if(position == 2)
            {
                head = deleteBeginning(head);
            }
            else
            {
                space = (struct element *)malloc(sizeof(struct element));
                temporary = head;
                while(i < position - 2)
                {
                    temporary = temporary->link;
                    i++;
                }
                space = temporary->link;
                temporary->link = space->link;
                free(space);
                
            }
            return head;

        }
        temporary = temporary->link;
        position++;
    }
    if(success == 0)
    {
        printf("\nThe element %d is not in the list\n", elmnt);
    }
    return head;
}

struct element* deleteElement(struct element *head, int elmnt, int success)
{
    int position = 1;
    int i = 1;
    struct element *temporary;
    struct element *space;
    struct element *space1;
    
    temporary = head;

    while(temporary != NULL)
    {
        if(temporary->data == elmnt)
        {
            success++;
            if(position == 1)
            {
                space1 = temporary;
                head = temporary->link;
                free(space1);
                return deleteElement(head, elmnt, success);
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
        temporary = temporary->link;
        position++;
    }
    if(success == 0)
    {
        printf("\nThe element %d is not in the list\n", elmnt);
    }
    return head;
}


struct element* sort(struct element *head)
{
    struct element *temporary, *next;
    int var;
    temporary = head;
    next = NULL;
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
    return head;
}

struct element* reverse(struct element *head)
{
    struct element *previous, *temporary, *next;
    previous = NULL;
    temporary = head;
    
    while(temporary != NULL)
    {
        next = temporary->link;
        temporary->link = previous;
        previous = temporary;
        temporary = next;
        head = previous;
    }
    return head;
}

struct element* concatenation(struct element *head1, struct element *head2)
{
    struct element *temporary;
    temporary = head1;
    while(temporary->link != NULL)
    {
        temporary = temporary->link;
    }
        temporary->link = head2;
    return head1;
}

int main()
{
    int option, insertOption, positionOption, deleteOption, deletePosition, sortOption, search, elmnt, concateOption;
    int success = 0;
    struct element *head = NULL;
    struct element *head1 = NULL;
    struct element *head2 = NULL;
    
    printf("Linked List\n");
    while(1)
    {
        pqr:
        printf("\nEnter\n 1 for Create a List\n 2 for Display the List\n 3 for Insert New Element to the List\n 4 for Delete Element\n 5 for Sort the List\n 6 for Reverse the List\n 7 for Concatenation\n 8 for Exit:\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
        case 1:
            head = creatList(head);
            display(head);
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
                    printf("Enter the element after which you want to insert: ");
                    scanf("%d", &elmnt);
                    printf("\n");
                    head = insertAfterNode(head, elmnt, success);
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
            display(head);
            break;
        case 4:
            mno:
            printf("\n\tEnter 1 to Delete the First Element\n");
            printf("\tEnter 2 to Delete the Last Element\n");
            printf("\tEnter 3 to Delete at any position\n");
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
                printf("Enter 1 to Delete after a position\n");
                printf("Enter 2 to Delete before a position\n");
                printf("Enter 3 to Delete a specific position\n");
                printf("Enter 4 to Delete a specific element\n");
                printf("\tEnter 5 to go back to the previous menu\n");
                printf("Enter your choice: ");
                scanf("%d", &deletePosition);
                printf("\n");
                switch (deletePosition)
                {
                case 1:
                    printf("Enter the element whose next element you want to delete: ");
                    scanf("%d", &elmnt);
                    printf("\n");
                    head = deleteAfter(head, elmnt, success);
                    break;
                case 2:
                    printf("Enter the element whose previous element you want to delete: ");
                    scanf("%d", &elmnt);
                    printf("\n");
                    head = deleteBefore(head, elmnt, success);
                    break;
                case 3:
                    head = deleteSpecific(head);
                    break;
                case 4:
                    printf("Enter the element you want to delete: ");
                    scanf("%d", &elmnt);
                    printf("\n");
                    head = deleteElement(head, elmnt, success);
                    break;
                case 5:
                    goto mno;
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
            display(head);
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
            display(head);
            break;
        case 6:
            head = reverse(head);
            display(head);
            break;
        case 7:
            printf("Concate with existing list(y/n): ");
            scanf("%s", &concateOption);
            if(concateOption == 'y')
            {
                printf("Create 2nd Linked List:\n");
                head2 = creatList(head2);
                printf("Second list is :\n");
                display(head2);
                head = concatenation(head, head2);
                printf("After concatenation: \n");
                display(head);
            }
            else
            {
                printf("Create 1st Linked List:\n");
                head1 = creatList(head1);
                printf("First list is :\n");
                display(head1);
                printf("Create 2nd Linked List:\n");
                head2 = creatList(head2);
                printf("Second list is :\n");
                display(head2);
                head1 = concatenation(head1, head2);
                printf("After concatenation: \n");
                display(head1);
            }
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("error\n");
            break;
        }
    }
    return 0;
}