#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
 

void traverse()
{
    struct node* temp;
 
    
    if (start == NULL)
        printf("\nList is empty\n");
 
    
    else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}
void createList()
{
    int data, i;
    struct node *temp, *newnode;
    start = malloc(sizeof(struct node));
    printf("Enter -999 to terminate the list\n");
    if(start == NULL)
    {
        printf("Memory can't be allocated. \n");
    }
    else
    {
        printf("Input data : \n");
        scanf("%d", &data);
        start->info = data;
        start->link = NULL;
        temp = start;
        up:
        newnode = malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory can't be allocated. \n");
        }
        else
        {
            printf("Input data : \n");
            scanf("%d", &data);

            if(data == -999)
            {
                newnode->link = NULL;
            }
            else
            {
                newnode->info = data;
                newnode->link = NULL;
                temp->link = newnode;
                temp = temp->link;
                goto up;
            }
        }
    }
} 

void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;
 
    
    temp->link = start;
    start = temp;
}


void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
 
    
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
 
    
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
 

void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
 
    
    printf("\nEnter the position:\n");
    scanf("%d", &pos);
    printf("\n Enter the number: \n");
    scanf("%d", &data);
 
    
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void insertAfterPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
 
    
    printf("\nEnter the position:\n");
    scanf("%d", &pos);
    pos = pos+1;
    printf("\n Enter the number: \n");
    scanf("%d", &data);
 
    
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void insertBeforePosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
 
    
    printf("\nEnter the position:\n");
    scanf("%d", &pos);
    pos = pos-1;
    printf("\n Enter the number: \n");
    scanf("%d", &data);
 
    
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}


int main()
{
    int choice, choiceInsert, choicePosition;
    while (1) {
 
        printf("\n\t Enter 1 to create a list\n");
        printf("\t Enter 2 to insert new data\n");
        printf("\t Enter 3 to see the list \n");
        printf("\t Enter 4 to exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            printf("\n\t Enter 21 to insert new data at the beginning\n");
            printf("\t Enter 22 to insert new data at the end\n");
            printf("\t Enter 23 to insert new data at any position\n");
            printf("Enter your choice: \n");
            scanf("%d", &choiceInsert);
            switch (choiceInsert)
            {
            case 21:
                insertAtFront();
                break;
            case 22:
                insertAtEnd();
                break;
            case 23:
                printf("\n\tEnter 231 to insert after a node\n");
                printf("\tEnter 232 to insert before a node\n");
                printf("\tEnter 233 to insert at specific position\n");
                printf("\nEnter your choice: \n");
                scanf("%d", &choicePosition);
                switch (choicePosition)
                {
                case 231:
                    insertAfterPosition();
                    break;
                case 232:
                    insertBeforePosition();
                    break;
                case 233:
                    insertAtPosition();
                    break;
                default:
                    break;
                }
                break;    
            default:
                break;
            }
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
            break;    
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}