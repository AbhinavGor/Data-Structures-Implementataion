#include <stdio.h>
#include <string.h>

int main(){
    int a,b,c, option;
    char cont;
    cont = 'y';
    do{
        printf("Enter integer 'a':");
        scanf("%d", &a);
        printf("Enter integer 'b':");
        scanf("%d", &b);
        printf("a is %d and b is %d.\n", a, b);
        printf("Swap a and b: \n 1.)Enter 1 to swap using temporary variable.\n");
        printf("\n 2.)Enter 2 to swap without temporary variable.\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            c = b;
            b = a;
            a = c;
            printf("a is %d and b is %d AFTER swapping using temporary variable.", a, b);
            break;
        case 2:
            a = a + b;
            b = a - b;
            a = a - b;
            printf("a is %d and  b is %d AFTER swapping without temporary variable.", a, b);
            break;
        
        default:
            printf("Enter valid option.");
            break;
        }
        printf("\n\n OPTIONS: \n1.) To continue press 4.\n2.)To exit press 5. \n");
        scanf("%d", &option);
        printf("\n----------\n");
    }while (option < 5);    
    
}