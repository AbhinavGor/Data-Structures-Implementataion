#include<stdio.h>
#define MAX 5

int cqueue[MAX];
int front=-1, rear=-1;

int isFull(){
    if(front == (rear + 1) % MAX){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1 &&  rear == -1){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(!isFull()){
        if(isEmpty()){
            front = 0;
        }
        rear = (rear + 1)%MAX;
        cqueue[rear] = data;
        return;
    }else{
        printf("Queue Overflowed!");
    }
}

void dequeue(){
    if(!isEmpty()){
        printf("The dequeued element is %d.", cqueue[front]);
        if(front == rear){
            front = -1;
            rear = -1;
            return;
        }
        front = (front+1)%MAX;
        return;
    }
    printf("The Queue is empty (Underflow)!");
    return;
}

void dispQueue(){
    if(isEmpty()){
        printf("Queue is empty!!\n");
        return;
    }else
    {
        printf("Start\t");
        for(int i = front; 1; i=(i+1)%MAX){
            printf("%d\t", cqueue[i]);
            if(i == rear){
                break;
            }
        }
    }

    printf("End\n");
    return;
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
            dispQueue();
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