/*
    Name: Arpan Manna
    Dept.: Data Science
    Double Linked List
*/
#include<stdio.h>
#include<stdlib.h>

struct element{
    int data;
    struct  element *prev;
    struct element *next;
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

int countElement(ele *head){
    ele *temp = NULL;
    temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

ele* createList(ele *head){
    char choice = 'y';
    ele *temp = NULL;
    ele *temp1 = NULL;
    head = NULL;
    while(choice == 'y'){
        temp = getNode();
        printf("Enter the element: ");
        scanf("%d", &temp->data);
        printf("\n");
        temp->prev = NULL;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            temp1 = head;
        }
        else{
            temp1->next = temp;
            temp->prev = temp1;
            temp1 = temp;
        }
        printf("Want to add more elements(y/n): ");
        scanf("%*c%c", &choice);
        printf("\n");
    }
    return head;
}

void display(ele *head){
    ele *temp = NULL;
    if(head == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        temp = head;
        printf("The elements are: \n");
        printf("NULL ");
        while(temp != NULL){
            printf("<=> %d ", temp->data);
            temp = temp->next;
        }
        printf("<=> NULL\n");
    }
}

ele* insertBeg(ele *head){
    ele *temp = NULL;
    temp = getNode();
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    printf("\n");
    temp->prev = NULL;
    temp->next = head;
    head = temp;
    return head;
}

ele* insertEnd(ele *head){
    ele *temp = NULL;
    ele *temp1 = NULL;
    temp = getNode();
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    printf("\n");
    if(head == NULL){
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        temp1 = head;
    }
    else{
        temp1 = head;
        while(temp1->next != NULL){
        temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
        temp->next = NULL;
    }
    return head;
}

/*ele* createList2(ele *head){
    char choice = 'y';
    ele *temp = NULL;
    head = NULL;
    temp = getNode();
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    printf("\n");
    temp->prev = NULL;
    temp->next = NULL;
    head = temp;
    while(choice == 'y'){
        printf("Want to add more elements(y/n): ");
        scanf("%s", &choice);
        printf("\n");
        if(choice == 'y'){
            head = insertEnd(head);
        }
    }
    return head;
}*/

ele* insertPosition(ele *head){
    int pos, count;
    int i = 1;
    ele *temp = NULL;
    ele *temp1 = NULL;
    temp1 = head;
    if(temp1 == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        temp = getNode();
        printf("Enter the position: ");
        scanf("%d", &pos);
        printf("\n");
        count = countElement(head);
        if(pos > count + 1 || pos <= 0){
            printf("Insertion at that position is not possible!!!\n");
        }
        else{
            if(pos == 1){
                head = insertBeg(head);
            }
            else if(pos ==  count + 1){
                head = insertEnd(head);
            }
            else{
                printf("\nEnter the element: ");
                scanf("%d", &temp->data);
                printf("\n");
                while(i < pos - 1){
                    temp1 = temp1->next;
                    i++;
                }
                temp->prev = temp1;
                temp->next = temp1->next;
                temp1->next = temp;
                temp1 = temp->next;
                temp1->prev = temp;
            }
        }
    }
    return head;
}

ele* deletebeg(ele *head){
    ele *temp = NULL;
    if(head == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        printf("%d has been deleted\n", head->data);
        if(head->next == NULL)
        {
            head = NULL;
        }
        else{
            temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
    return head;
}

ele* deleteEnd(ele *head){
    ele *temp = NULL;
    ele *temp1 = NULL;
    temp = head;
    if(temp == NULL){
        printf("The List is empty!!!\n");
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp1 = temp->prev;
        printf("%d has been deleted\n", temp->data);
        if(temp1 == NULL){
            head = NULL;
            free(temp);
        }
        else{
            temp1->next = NULL;
            free(temp);
        }
    }
    return head;
}

ele* deleteposition(ele *head){
    int pos, count;
    int i = 1;
    ele *temp = NULL;
    ele *temp1 = NULL;
    ele *temp2 = NULL;
    temp = head;
    if(temp == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        printf("Enter the position: ");
        scanf("%d", &pos);
        printf("\n");
        count = countElement(head);
        if(pos > count || pos <= 0){
            printf("Deletion is not possible!!!\n");
        }
        else if(pos == 1){
            head = deletebeg(head);
        }
        else if(pos == count){
            head = deleteEnd(head);
        }
        else{
            while(i < pos){
                temp = temp->next;
                i++;
            }
            temp1 = temp->prev;
            temp2 = temp->next;
            temp1->next = temp2;
            temp2->prev = temp1;
            printf("%d has been deleted from the position %d\n", temp->data, pos);
            free(temp);
        }
    }
    return head;
}

ele* sort(ele *head){
    int var;
    ele *temp = NULL;
    ele *temp1 = NULL;
    temp = head;
    if(head == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        while(temp->next != NULL){
            temp1 = temp->next;
            while(temp1 != NULL){
                if(temp->data > temp1->data){
                var = temp1->data;
                temp1->data = temp->data;
                temp->data = var;
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
    }
    return head;
}

ele* reverse(ele *head){
    ele *temp = NULL;
    ele *temp1 = NULL;
    ele *temp2 = NULL;
    if(head == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        temp = head;
        while(temp != NULL){
            temp1 = temp->next;
            temp->next = temp2;
            temp->prev = temp1;
            temp2 = temp;
            temp = temp1;
            head = temp2;
        }
    }
    return head;
}

ele* merge(ele *head1, ele *head2){
    ele *temp = NULL;
    temp = head1;
    if(head1 == NULL || head2 == NULL){
        printf("The list is empty!!!\n");
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head2;
        head2->prev = temp;
    }
    return head1;
}

void main(){
    int choice, choice1, choice2, choice3;
    ele *head = NULL;
    ele *head1 = NULL;
    while(1){
        up:
        printf("Enter 1 to Create a List\nEnter 2 to Display\nEnter 3 to Insert\nEnter 4 to Delete\nEnter 5 to Sort\nEnter 6 to Reverse\nEnter 7 to Merge\nEnter 8 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            head = createList(head);
            display(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            up1:
            printf("Enter 1 to Insert at Beginning\nEnter 2 to Insert at End\nEnter 3 to Insert at any Position\nEnter 4 to return\n");
            printf("Enter  your choice: ");
            scanf("%d", &choice1);
            printf("\n");
            switch (choice1)
            {
            case 1:
                head = insertBeg(head);
                break;
            case 2:
                head = insertEnd(head);
                break;
            case 3:
                head = insertPosition(head);
                break;
            case 4:
                goto up;
                break;
            default:
                printf("Wrong input!!!\n");
                goto up1;
                break;
            }
            break;
        case 4:
            up2:
            printf("Enter 1 to Delete at Beginning\nEnter 2 to Delete at End\nEnter 3 to Delete at any Position\nEnter 4 to return\n");
            printf("Enter  your choice: ");
            scanf("%d", &choice2);
            printf("\n");
            switch (choice2)
            {
            case 1:
                head = deletebeg(head);
                break;
            case 2:
                head = deleteEnd(head);
                break;
            case 3:
                head = deleteposition(head);
                break;
            case 4:
                goto up;
                break;
            default:
                printf("Wrong input!!!\n");
                goto up2;
                break;
            }
            break;
        case 5:
            head = sort(head);
            break;
        case 6:
            head = reverse(head);
            break;
        case 7:
            printf("Create a new list to  merge with the existing list\n");
            head1 = createList(head1);
            printf("Displaying the  new list\n");
            display(head1);
            up3:
            printf("Enter 1 to merge in the  beginning\nEnter 2 to merge at the end\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            if(choice3 == 1){
                head = merge(head1, head);
            }
            else if(choice3 == 2){
                head = merge(head, head1);
            }
            else{
                printf("Wrong input!!!\n");
                goto up3;
            }
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Wrong input!!!\n");
            break;
        }
    }
}