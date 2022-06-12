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
            printf("Data = %d\n",
                   temp->info);
            temp = temp->link;
        }
    }
}
void createList()
{
    int data, i;
    struct node *temp, *newnode;
    start = malloc(sizeof(struct node));
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
 

void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}
 

void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}
 

void deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;
 
   
    if (start == NULL)
        printf("\nList is empty\n");
 
    
    else {
        printf("\nEnter index : ");
 
        
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
 
        
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
 
        
        position = temp->link;
        temp->link = position->link;
 
        
        free(position);
    }
}
 

void maximum()
{
    int a[10];
    int i;
    struct node* temp;
 
    
    if (start == NULL)
        printf("\nList is empty\n");
 
    
    else {
        temp = start;
        int max = temp->info;
 
        
        while (temp != NULL) {
 
            
            if (max < temp->info)
                max = temp->info;
            temp = temp->link;
        }
        printf("\nMaximum number "
               "is : %d ",
               max);
    }
}
 

void mean()
{
    int a[10];
    int i;
    struct node* temp;
 
    
    if (start == NULL)
        printf("\nList is empty\n");
 
    
    else {
        temp = start;
 
        
        int sum = 0, count = 0;
        float m;
 
        
        while (temp != NULL) {
 
            
            sum = sum + temp->info;
            temp = temp->link;
            count++;
        }
 
        
        m = sum / count;
 
        
        printf("\nMean is %f ", m);
    }
}
 

void sort()
{
    struct node* current = start;
    struct node* index = NULL;
    int temp;
 
    
    if (start == NULL) {
        return;
    }
 
    
    else {
 
        
        while (current != NULL) {
            index = current->link;
 
           
            while (index != NULL) {
 
                
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
 
            
            current = current->link;
        }
    }
}
 

void reverseLL()
{
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
 
    
    if (start == NULL)
        printf("List is empty\n");
 
    
    else {
 
       
        while (start != NULL) {
 
            
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
 
       
        temp = start;
 
        printf("Reversed linked "
               "list is : ");
 
        
        while (temp != NULL) {
            printf("%d, ", temp->info);
            temp = temp->link;
        }
    }
}
 
int main()
{
    int choice, choiceInsert, choiceDelete;
    while (1) {
 
        printf("\n\t Enter 1 to create a list\n");
        printf("\t Enter 2 to see the list\n");
        printf("\t Enter 3 to insert new data\n");
        printf("\t Enter 4 to delete a data\n");
        printf("\t Enter 5 to find the max value\n");
        printf("\t Enter 6 to find mean of the elements\n");
        printf("\t Enter 7 to sort the elements\n");
        printf("\t Enter 8 to reverse the linked list\n");
        printf("\t Enter 9 to exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            traverse();
            break;
        case 3:
            printf("\n\t Enter 31 to insert new data at the beginning\n");
            printf("\t Enter 32 to insert new data at the end\n");
            printf("\t Enter 33 to insert new data at any position\n");
            printf("Enter your choice: \n");
            scanf("%d", &choiceInsert);
            switch (choiceInsert)
            {
            case 31:
                insertAtFront();
                break;
            case 32:
                insertAtEnd();
                break;
            case 33:
                insertAtPosition();
                break;    
            default:
                break;
            }
            break;
        case 4:
            printf("\n\t Enter 41 to delete the data at beginning\n");
            printf("\t Enter 42 to delete the data at the end\n");
            printf("\t Enter 43 to delete a data at any position\n");
            printf("Enter your choice: \n");
            scanf("%d", &choiceDelete);
            switch (choiceDelete)
            {
            case 41:
                deleteFirst();
                break;
            case 42:
                deleteEnd();
                break;
            case 43:
                deletePosition();
                break;
            default:
                break;
            }
            break;
        case 5:
            maximum();
            break;
        case 6:
            mean();
            break;
        case 7:
            sort();
            break;
        case 8:
            reverseLL();
            break;
        case 9:
            exit(1);
            break;    
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}