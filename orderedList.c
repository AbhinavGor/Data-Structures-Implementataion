#include <stdio.h>
#define MAX 5

int list[MAX], len = 0;

int search(int key){
    if(len == 0){
        return -1;
    }
    for(int i = 0; i < len; i ++){
        if(list[i] == key){
            return i;
        }
    }
    return -1;
}

void insert(int data){
    if(len == MAX){
        printf("List is full!!");
        return;
    }
    int temp = len;

    for(int i = 0; i < len ; i++){
        if(list[i] > data){
            temp = i;
            break;
        }
    }
    for(int i = len - 1; i >= temp; i--){
        list[i+1] = list[i];
    }
    list[temp] = data;
    len++;
    return;
}

void delete(int data){
    int found = search(data);
    if(len == 0){
        printf("List is empty!!");
    }else if(found < 0){
        printf("The entered value is not in the list.");
    }else{
        printf("%d", found);
        for(int i = found; i < len; i++){
            list[i] = list[i + 1];
        }
        len--;
    }
    return;
}

void display(){
    if(len == 0){
        printf("List is empty");
        return;
    }
    printf("Start\t");
    for(int i = 0; i < len; i++){
        printf("%d\t", list[i]);
    }
    printf("End\n");
}

void main(){
    int oper, data, pos;

    while(1){
        printf("-----------Implementation of Ordered List using C Language ----------\n");
        printf("1.) Insert\n");
        printf("2.) Delete\n");
        printf("3.) Search\n");
        printf("4.) Display\n");
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
            scanf("%d", &pos);
            delete(pos);
            break;
        case 3:
            printf("Enter the element to be searched\n");
            scanf("%d", &data);
            search(data);
            break;
        case 4:
            display();
            break;

        case 5:
            printf("Exiting from the program!!");
            return;
        
        default:
            printf("Invalid choice!");
            break;
        }
    }
}