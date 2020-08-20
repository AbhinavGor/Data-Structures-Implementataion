#include <stdio.h>
#include <process.h>
#define MAX 100

int list[MAX], counter = 0;


void dispList(){
    printf("Start\t");
    for(int i = 0; i < counter; i++){
        printf("%d\t", list[i]);
    }
    printf("End.");
    return;
}

void insert(int data){
    int i;
    list[counter] = data;
    counter++;
    printf("The unordered list after inserting new element is:\n");
    dispList();
    return;
}

void delete(int pos){
    for(int i = pos; i < counter; i++){
        list[i] = list[i+1];
    }
    counter -= 1;
    printf("The unordered list after deletion is:\n");
    dispList();
    return;
}


void search(int data){
    for(int i = 0; i < counter; i++){
        if(list[i] == data){
            printf("the element is in the list");
            return;
        }
    }
    printf("The element is not in the list");
    return;
}

void main(){
    int oper, data, cont = 1;
    do{
        printf("\n-----------Implementation of Unordered List using C Language ----------\n");
        printf("1.) Insertion\n");
        printf("2.) Deletion\n");
        printf("3.) Display\n");
        printf("4.) Search\n");
        printf("5.) Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &oper);
        switch (oper)
        {
        case 1:
            printf("Enter the integer to be added to the list: \n");
            scanf("%d", &data);
            insert(data);
            break;
        
        case 2:
            printf("Enter the integer to be deleted from the list: \n");
            scanf("%d", &data);
            delete(data);
            break;
        case 3:
            dispList();
            break;
        
        case 4:
            printf("Enter the integer to be searched in the list: \n");
            scanf("%d", &data);
            search(data);
            break;

        case 5:
            printf("Exiting from the program!!");
            return;

        default:
            printf("Invalid choice!");
            break;
        }
    }while(cont != 5);

    return;
}