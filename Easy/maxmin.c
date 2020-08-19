#include <stdio.h>

int main(){
    int n,max,min,oper;

    do{
        
        printf("How many numbers(n) do you want to check?\n");
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i < n; i++){
            printf("\nEnter element %d\n.", i +1);
            scanf("%d", &arr[i]);
        };
        printf("What do you want to find from the n numbers?: \n 1.)Maximum.\n");
        printf("2.)Minimum.\n");
        printf("\n--------------------\n");
        scanf("%d", &oper);
        switch (oper)
        {
        case 1:
            max = arr[0];
            for(int i=0; i < n; i++){
                if(arr[i] > max){
                    max = arr[i];
                }
        };
        printf("The maximum is %d.", max);
            break;
        case 2:
            min = arr[0];
            for(int i=0; i < n; i++){
                if(arr[i] < min){
                    min = arr[i];
                }
        };
        printf("The minimum is %d.", min);
            break;
        default:
            printf("Enter valid option.");
            break;
        }
        printf("\n--------------------\n");
        printf("\n\n OPTIONS: \n1.)To continue press 3.\n2.)To exit press 4. \n");
        scanf("%d", &oper);
        printf("\n--------------------\n");
    }while(oper < 4);
}