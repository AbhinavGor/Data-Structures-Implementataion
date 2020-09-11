#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
struct node* insert(struct node* node, int key){ 
    if (node == NULL) return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node* delete(struct node* root, int key) 
{ 
  
    if (root == NULL) return root; 
  
    if (key < root->key) 
        root->left = delete(root->left, key); 
  
    else if (key > root->key) 
        root->right = delete(root->right, key); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = delete(root->right, temp->key); 
    } 
    return root; 
} 

void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     printPostorder(node->left); 
     printPostorder(node->right); 
     printf("%d ", node->key); 
} 
  
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->key);   
     printPreorder(node->left);   
     printPreorder(node->right); 
} 

int main() 
{ 
    struct node *root = NULL; 
    int data, opt;
    while(1){

        printf("----------Implementation of Binary Serach Tree----------");
        printf("\n1.)Insert\n2.)Inorder\n3.)Postorder\n4.)PreOrder\n5.)Delete\n6.)Exit\n");
        
        printf("\nEnter your choice:\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter data to be inserted:\n");
            scanf("%d", &data);
            if(root == NULL){
               root = insert(root, data);
            }
            insert(root, data);
            break;
        case 2:
            printf("Inorder\n");
            inorder(root);
            break;
        case 3:
            printf("Postorder\n");
            printPostorder(root);
            printf("\n");
            break;
        case 4:
            printf("PreOrder\n");
            printPreorder(root);
            printf("\n");
            break;
         case 5:
            printf("Enter data to be deleted:\n");
            scanf("%d", &data);
            delete(root, data);
            break;
         case 6:
            exit(0);
        
        default:
            printf("Please select a valid choice!!");
            break;
        }
    }
   
   return 0; 
} 