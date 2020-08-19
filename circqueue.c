#include<stdio.h>
#define MAX 5

int cqueue[MAX];
int front=-1, rear=-1;

void enqueue(int data){
    if(( front == 0 && rear == MAX - 1 ) || ( front == rear + 1)){
        printf("Queue Overflow!!\n");
        return;
    }
    if(front == -1){
        front = 0; rear = 0;
    }else{
        if( rear = MAX - 1){
            rear = 0;
        }else{
            rear += 1;
        }
    }
    cqueue[rear] = data;
}

void dequeue(){
    if( front == -1 ){
        printf("Queue Undeflow!!\n");
        return;
    }
    printf("Element dequeued is %d.", cqueue[rear]);

    if(front == rear){
        front = -1; rear = -1;
    }else{
        if( front == MAX - 1){
            front = 0;
        }else{
            front += 1;
        }
    }
}

void display(){
    int FrontP=front;
    int  RearP=rear;
    if(front==-1){
        printf("Queue Underflow!!\n");
        return;
    }
    printf("Queue has the following elements: \n");
    if(front <= rear){
        while(FrontP <= RearP){
            printf("%d\t", cqueue[FrontP]);
            FrontP++;
        }
    }else{
        while(FrontP<= MAX - 1){
            printf("%d\t", cqueue[FrontP]);
            FrontP++;
        }
        while(RearP<front){
            printf("%d\t", cqueue[RearP]);
            RearP++;
        }
    }
}

int main(){
    int oper, data, cont = 1;
    do{
        printf("-----------Implementation of Circular Queue using C Language ----------\n");
        printf("1.) Enqueue\n");
        printf("2.) Dequeue\n");
        printf("3.) Display\n");
        printf("Enter your choice: \n");
        scanf("%d", &oper);
        switch (oper)
        {
        case 1:
            printf("Enter the integer to be added to the queue: \n");
            scanf("%d", &data);
            enqueue(data);
            break;
        
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
                
        default:
            printf("Invalid choice!");
            break;
        }
        printf("\nDo you want to continue?\n");
        printf("1.) Yes\n2.) No\n");
        scanf("%d", &cont);
    }while(cont > 0);

    return 0;
}