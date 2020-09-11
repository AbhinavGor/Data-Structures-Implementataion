#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *ptr;
}*front, *rear, *temp, *front1;

int count = 0;

void create(){
    front = rear = NULL;
}

void enqueue(int data){
    if(rear == NULL){
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }else{
        temp = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        
        rear = temp;
    }

    count++;
}

void dequeue(){
    front1 = front;
    if(front1 == NULL){
        printf("Queue is empty!!");
        return;
    }else{
        if(front1->ptr != NULL){
            printf("\nDequeued value: %d.\n", front->info);
            free(front);
            front = front1;
        }else
        {
            printf("\nDequeued value: %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
    }
}
void display(){
    front1 = front;

    if((front1 == NULL) && (rear == NULL)){
        printf("Queue is empty!!");
        return;
    }else{
        printf("\nSTART\n");
        while (front1 != rear)
        {
            printf("%d\n", front1->info);
            front1 = front1->ptr;
        }

        if(front1 == rear){
            printf("%d\n", front1->info);
            printf("END\n.");
        }
    }
}

void main(){
    int opt, data;

    create();

    while(1){

        printf("----------Implementation of Queue using SLL----------");
        printf("\n1.)Enqueue\n2.)Dequeue\n3.)Display\n4.)Exit");
        
        printf("\nEnter your choice:\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter data to be enqueued:\n");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
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