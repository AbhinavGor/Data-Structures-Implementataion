#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *ptr;
}*top, *top1, *temp;

int count = 0;

void create(){
    top = NULL;
}

// void stackCount(){
//     printf("The number of elements in the stack are: %d.", count);
// }

void push(int data){
    if(top == NULL){
        top = (struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }else{
        temp = (struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void display(){
    top1 = top;
    if(top1 == NULL){
        printf("Stack Underflowed!!");
        return;
    }else{
        printf("\nStart\n");
        while(top1 != NULL){
            printf("%d\n", top1->info);
            top1 = top1->ptr;
        }
    }
}

void pop(){
    top1 = top;

    if(top1 == NULL){
        printf("Stack Underflowed!!");
        return;
    }else{
        top1 = top1->ptr;
    }
    printf("The popped value is %d.", top->info);
    top = top1;
    count--;
}

void isEmpty(){
    if(top == NULL){
        printf("Stack is empty");
    }else{
        printf("Stack isn't empty.");
    }
}

void main(){
    int opt, data;

    create();

    while(1){

        printf("----------Implementation of Stack using SLL----------");
        printf("\n1.)Push\n2.)Pop\n3.)Display\n4.)Exit");
        
        printf("\nEnter your choice:\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter data to be pushed:\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        
        default:
            printf("Please select a valid choice!!");
            break;
        }
    }
}