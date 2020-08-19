#include <stdio.h>

int main(){
    int oper;
    float a,b,c;

    do{
        printf("Select the matematical operation: \n 1.)Addition.\n");
        printf("2.)Subtraction.\n");
        printf("3.)Multiplication\n");
        printf("4.)Division\n");
        printf("\n--------------------\n");
        scanf("%d", &oper);
        switch (oper)
        {
        case 1:
            printf("Enter integer 'a':");
            scanf("%f", &a);
            printf("Enter integer 'b':");
            scanf("%f", &b);
            c = a + b;
            printf("a + b = %.2f. Where a and b are %.2f and %.2f respectively.", c, a, b);
            break;
        case 2:
            printf("Enter integer 'a':");
            scanf("%f", &a);
            printf("Enter integer 'b':");
            scanf("%f", &b);
            c = a - b;
            printf("a - b = %.2f. Where a and b are %.2f and %.2f respectively.", c, a, b);
            break;
        case 3:
            printf("Enter integer 'a':");
            scanf("%f", &a);
            printf("Enter integer 'b':");
            scanf("%f", &b);
            c = a * b;
            printf("a x b = %.2f. Where a and b are %.2f and %.2f respectively.", c, a, b);
            break;
        case 4:
            printf("Enter integer 'a':");
            scanf("%f", &a);
            printf("Enter integer 'b':");
            scanf("%f", &b);
            if(b != 0){
                c = a / b;
            printf("a / b = %.2f. Where a and b are %.2f and %.2f respectively.", c, a, b);
            }else{
                printf("Division can't be performed as b = 0.");
            }
            
            break;
        
        default:
            printf("Enter valid option.");
            break;
        }
        printf("\n--------------------\n");
        printf("\n\n OPTIONS: \n1.) To continue press 5.\n2.)To exit press 6. \n");
        scanf("%d", &oper);
        printf("\n--------------------\n");
    }while(oper < 6);
}