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
void insertFirst(int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->key = rand();
    link->next = head;
    head = link;
    printf("List after inserting the item is:\n");
    displayList();
}

//Insert at the End
void insertEnd(int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    struct node* current = head;

    link->data = data;
    link->key = rand();
    link->next = NULL;

    while(current->next!=NULL){
        current = current->next;
    }
    current->next = link;
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
    printf("List after inserting the item is:\n");
    displayList();
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

//Delete first record
struct node* deleteFirst(){
    struct node *tempLink = head;

    head = head-> next;

    return tempLink;
}

//Delete end item
struct node* deleteEnd(){
    struct node* current = head;
    struct node* previous  = NULL;

    while(current->next!=NULL){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    printf("List afetr end Deletion operaions is:\n");
    displayList();
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

//Searching for a item
struct node* find(int key){
    struct node* current = head;

    if(head == NULL){
        printf("List is empty.");
        return NULL;
    }

    while(current->data != key){
        if(current->next == NULL){
            printf("%d is not in the list.", key);
            return NULL;
        }else{
            current = current->next;
        }
    }

    return current;
}


void main(){
int oper, var,pos;
do{

    printf("Implementation Singly Linked List using C\nSelect an operation\n");
    printf("\n1.)Beginning Insertion\n2.)End Insertion\n3.)Position Insertion\n4.)Beginning Deletion\n5.)End Deletion\n6.)Position Deletion\n7.)Search for a particular item\n8.)Display list\n9.)Exit from the application\n");
    printf("Your choice:\t");
    scanf("%d", &oper);
    switch (oper)
{
case 1:
    printf("----------------------");
    printf("\nEnter the item you want to insert\n");
    scanf("%d", &var);
    insertFirst(var);
    break;
case 2:
printf("----------------------");
    printf("\nEnter the item you want to insert\n");
    scanf("%d", &var);
    insertEnd(var);
    break;
case 3:
    printf("----------------------");
    printf("\nEnter the item you want to insert\n");
    scanf("%d", &var);
    printf("Enter the position you want to insert the item in:");
    scanf("%d", &pos);
    insertPos(pos, var);
    break;
case 4:
    deleteFirst();
    break;
case 5:
    deleteEnd();
    break;
case 6:
    printf("Enter the position you want to delete the item from:");
    scanf("%d", &pos);
    deletePos(pos);
    break;
case 7:
    printf("Enter the element youre seraching for:\n");
    scanf("%d", &var);
    find(var);
    break;
case 8:
    displayList();
    break;
case 9:
    printf("----------Exiting from the program----------");
    exit;
default:
    break;
}
}while(true);

}
