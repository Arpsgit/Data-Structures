/*
    Name: Arpan Manna 
    Dept.: Data Science
    Binary Search Tree(Checking Balanced Condition)
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct element{
    int data;
    struct element *left;
    struct element *right;
};
typedef struct element ele;

ele* getNode(int node){
    ele *NODE;
    NODE = (ele*)malloc(sizeof(ele));
    NODE->data = node;
    NODE->left = NULL;
    NODE->right = NULL;
    if(NODE == NULL){
        printf("The memory is OVERFLOWING!!!\n");
        exit(1);
    }
    else{
        return NODE;
    }
}

ele* insertNode(ele *root, int node){
    if(root == NULL){
        root = getNode(node);
    }
    else if(node <= root->data){
        root->left = insertNode(root->left, node);
    }
    else{
        root->right = insertNode(root->right, node);
    }
    return root;
}

ele* minmumValue(ele *root){
    ele *temp = root;
    while(temp != NULL && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

ele* deleteNode(ele *root, int node){
    if(root == NULL){
        printf("The element is not in the tree!\n");
    }
    else if(node < root->data){
        root->left = deleteNode(root->left, node);
    }
    else if(node > root->data){
        root->right = deleteNode(root->right, node);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            ele *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            ele *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            ele *temp = minmumValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inoderTraversal(ele *root){
    if(root == NULL){
        return;
    }
    inoderTraversal(root->left);
    printf("%d ", root->data);
    inoderTraversal(root->right);
}

void preoderTraversal(ele *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preoderTraversal(root->left);
    preoderTraversal(root->right);
}

void postoderTraversal(ele *root){
    if(root == NULL){
        return;
    }
    postoderTraversal(root->left);
    postoderTraversal(root->right);
    printf("%d ", root->data);
}

void search(ele *root, int node){
    if(root == NULL){
        printf("The element is not in the tree!!!\n");
    }
    else if(node == root->data){
        printf("The element is present in the tree\n");
    }
    else if(node <= root->data){
        search(root->left, node);
    }
    else{
        search(root->right, node);
    }
}

int heightofTree(ele *root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftHeight = heightofTree(root->left);
        int rightHeight = heightofTree(root->right); 
        if(leftHeight > rightHeight){
            return(leftHeight + 1);
        }
        else{ 
            return(rightHeight + 1);
        }
    }
}

int isBalanced(ele *root){
    if(root == NULL){
        return 1;
    }
    if(isBalanced(root->left) == 0){
        return 0;
    }
    if(isBalanced(root->right) == 0){
        return 0;
    }
    int leftHeight = heightofTree(root->left);
    int rightHeight = heightofTree(root->right);
    if(abs(leftHeight - rightHeight) <= 1){
        return 1;
    }
    else{
        return 0;
    }
}

void main(){
    ele *root = NULL;
    int choice;
    int node;
    int balance;
    printf("Binary Search Tree\n");
    while(1){
        printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to inorder Traversal\nEnter 4 to preorder Traversal\nEnter 5 to postorder Traversal\nEnter 6 to Search\nEnter 7 to check if the tree is balanced or not\nEnter 8 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d", &node);
                printf("\n");
                root = insertNode(root, node);
                break;
            case 2:
                printf("Enter the element which you want to delete: ");
                scanf("%d", &node);
                root = deleteNode(root, node);
                printf("\n");
                break;
            case 3:
                printf("The inorder traversal of this tree: \n");
                inoderTraversal(root);
                break;
            case 4:
                printf("The preorder traversal of this tree: \n");
                preoderTraversal(root);
                break;
            case 5:
                printf("The postorder traversal of this tree: \n");
                postoderTraversal(root);
                break;
            case 6:
                printf("Enter the element which you want to search: ");
                scanf("%d", &node);
                search(root, node);
                printf("\n");
                break;
            case 7:
                balance = isBalanced(root);
                if(balance == 1){
                    printf("The tree is balanced\n");
                }
                else{
                    printf("The tree is not balanced\n");
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