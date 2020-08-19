#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned MAX;
    int* array;
};

struct Stack* createStack(unsigned MAX) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->MAX = MAX; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->MAX * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->MAX - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)){
        printf("\nStack is full!!\n");
        return;
    }
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
void pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)){
        printf("\nStack is empty!!\n");
    }else{
        printf("%d has been popped from the stack.\n", stack->array[stack->top--]);
    }
} 
  
// Function to return the top from stack without removing it 
void peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)){
        printf("Stack is empty!!");
    }else{
        printf("The topmost element in teh stack is: %d.\n", stack->array[stack->top]);
    }
} 

void display(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
    }else{
        printf("Stack is:");
        for(int i = 0; i <= stack->top; i++){
            printf("%d\n", stack->array[i]);
        }
    }
}

int main(){
    int MAX, oper, temp;
    printf("Enter the size of stack: \n");
    scanf("%d", &MAX);
    struct Stack* stack = createStack(MAX); 
  
    // push(stack, 10); 
    // push(stack, 20); 
    // push(stack, 30); 
  
    // printf("%d popped from stack\n", pop(stack)); 
    do{
        printf("----------------------------------------------------------------------");

    printf("\n\n\tOperations avaliable are:\n");
    printf("\t1.) Push - Adds elements to the stack.\n");
    printf("\t2.) Pop - Removes the topmost element from stack and displays it.\n");
    printf("\t3.) Peek - Displays the topmost element in the stack.\n");
    printf("\t4.) Display - Displays all the data in stack.\n\n");

    printf("-----------------------------------------------------------------------");

    printf("\nSelect an opration:\n");
    scanf("%d", &oper);

    switch (oper)
    {
    case 1:
        printf("\nEnter the number to be pushed:\n");
        scanf("%d", &temp);
        push(stack, temp);
        break;

    case 2:
        pop(stack);
        break;
    
    case 3:
        peek(stack);
        break;

    case 4:
        display(stack);
        break;

    default:
        break;
    }
    }while( oper <= 4);

    printf("You have exited from the program!");
    
    return 0;
}