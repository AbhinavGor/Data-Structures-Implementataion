#define SIZE 50 /* Size of Stack */
#include <ctype.h>
#include <stdio.h>

char stack[SIZE];
int top = -1; /* Global declarations */

void removeSpaces(char* source){
    char* i = source;
    char* j = source;
    while(*j != 0){
        *i = *j++;
        if(*i != ' '){
            i++;
        }
    }

    *i = 0;
}

void push(char elem){
    stack[++top] = elem;
}

char pop(){
    return(stack[top--]);
}

int pr(char elem){
    switch (elem)
    {
    case '#':
        return 0;
        break;
    
    case '(':
        return 1;
        break;

    case '+':
    case '-':
        return 2;
        break;
    
    case '/':
    case '*':
        return 3;
        break;
    
    default:
        break;
    }
}

void infixToPostfix(char *infix, char *postfix){
    char ch, elem;
    int i = 0, k = 0;

    removeSpaces(infix);
    push('#');

    while((ch = infix[i++]) != '\n'){
        if(ch == '('){
            push(ch);
        }else if(isalnum(ch)){
            postfix[k++] = ch;
        }else if(ch == ')'){
            while(stack[top] != '('){
                postfix[k++] = pop();
            }
            elem = pop();
        }else{
            while(pr(stack[top]) > pr(ch)){
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (stack[top] != '#')
    {
        postfix[k++] = pop();
    }

    postfix[k] = 0;
    
}

int evalPostfix(char *postfix){
    char ch;
    int i= 0, op1, op2;
    while((ch = postfix[i++]) != 0){
        if(isdigit(ch)){
            push(ch- '0');
        }else{
            op2 = pop();
            op1 = pop();
            switch(ch){
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;   
                case '/':
                    push(op1 / op2);
                    break;
            }
        }
    }

    return stack[top];
}

void main(){
    char infx[50], pofx[50];
    printf("\nInput the infix expression: ");
    fgets(infx, 50, stdin);
 
    infixToPostfix(infx, pofx);

    printf("\nGiven Infix Expression: %s\nPostfix Expression: %s\n", infx, pofx);
    top = -1;
    printf("\nResult of evaluation of postfix expression : %d", evalPostfix(pofx));
}