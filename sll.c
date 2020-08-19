#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//Display Function
void displayList(){
    struct node *ptr = head;
    printf("\n[");

    while (ptr != NULL)
    {
        printf("(%d, %d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }

    printf("]\n");    
}

//Insert at the beginning
void insertfirst(int data){
    struct node *link = NULL;
    link->data = data;

    link->next = head;
    head = link;
    printf("List after inserting the item is:\n");
    displayList();
}
//Insert at a location
void insertPos(int key, int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    link->next = head;

    head = link;
}

//Delete first record
struct node* deleteFirst(){
    struct node *tempLink = head;

    head = head-> next;

    return tempLink;
}

bool isEmpty(){
    return head == NULL;
}

int length(){
    int len = 0;
    struct node *current;
    for(current = head; current != NULL; current = current->next){
        len++;
    }

    return len;
}

//Searching for a item
struct node* find(int key){
    struct node* current = head;

    if(head == NULL){
        printf("List is empty.");
        return NULL;
    }

    while(current->key != key){
        if(current->next == NULL){
            printf("%d is not in the list.", key);
            return NULL;
        }else{
            current = current->next;
        }
    }

    return current;
}

//Position delete function
struct node* deletePos(int key){
    struct node* current = head;
    struct node* previous  = NULL;
    
    if(head == NULL){
        printf("List is empty.");
        return NULL;
    }

    while (current->key != key)
    {
        if(current->next == NULL){
            printf("%d is not in the list.", key);
            return NULL;
        }else
        {
            previous = current;
            current = current->next;
        }
    }

    if(current == head){
        head = head->next;
    }else{
        previous->next = current->next;
    }

    return current;
    
}

void main(){
//     insertFirst(1,10);
//    insertFirst(2,20);
//    insertFirst(3,30);
//    insertFirst(4,1);
//    insertFirst(5,40);
//    insertFirst(6,56); 

//    printf("Original List: "); 
	
//    //print list
//    displayList();

//    while(!isEmpty()) {            
//       struct node *temp = deleteFirst();
//       printf("\nDeleted value:");
//       printf("(%d,%d) ",temp->key,temp->data);
//    }  
	
//    printf("\nList after deleting all items: ");
//    displayList();
//    insertFirst(1,10);
//    insertFirst(2,20);
//    insertFirst(3,30);
//    insertFirst(4,1);
//    insertFirst(5,40);
//    insertFirst(6,56);
   
//    printf("\nRestored List: ");
//    displayList();
//    printf("\n");  

//    struct node *foundLink = find(4);
	
//    if(foundLink != NULL) {
//       printf("Element found: ");
//       printf("(%d,%d) ",foundLink->key,foundLink->data);
//       printf("\n");  
//    } else {
//       printf("Element not found.");
//    }

//    deletePos(4);
//    printf("List after deleting an item: ");
//    displayList();
//    printf("\n");
//    foundLink = find(4);
	
//    if(foundLink != NULL) {
//       printf("Element found: ");
//       printf("(%d,%d) ",foundLink->key,foundLink->data);
//       printf("\n");
//    } else {
//       printf("Element not found.");
//    }
	
//    printf("\n");
int oper;

printf("Implementation Singly Linked List using C\nSelect an operation\n");
printf("\n1.)Beginning Insertion\n2.)End Insertion\n3.)position Insertion4.)Beginning Deletion\n5.)End Deletion\n6.)Position Deletion\n7.)Search for a particular item\n8.)Display list\n9.)Exit from the application\n");
printf("Your choice:\t");
scanf("%d", &oper);

switch (oper)
{
case 1:
    int data;
    printf("----------------------");
    printf("\nENter the item you want to insert\n");
    scanf("%d", &data);
    insertFirst(data);
    break;

default:
    break;
}
}
