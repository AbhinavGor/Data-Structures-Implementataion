#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[100];

void push(char a){
    stack[top]  = a;
    top++;
};
void pop(){
    if(top == -1){
        printf("\t\nInvalid expression!!\n");
        exit(0);
    }else{
        top--;
    }
};
void findTop(){
    if(top == -1){
        printf("\t\nExpression is vaild.\n");
    }else{
        printf("\n\tExpression invalid!!\n");
    }
};

void main(){
    int i;
    char s[100];
    printf("\tEnter the expression to be checked: \n");
    scanf("%s", &s);
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            push(s[i]);
        }else if(s[i] == ')'){
            pop();
        }
    }

    findTop();
}