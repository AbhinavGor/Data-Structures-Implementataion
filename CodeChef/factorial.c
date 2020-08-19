#include <stdio.h>

int main(){
    int num, oper, i = 0;

    scanf("%d", &num);

    while(i < num){
        int n = num;
        scanf("%d", &n);
         int count = 0; 
        for (int i = 5; n / i >= 1; i *= 5) {
            count += n / i; 
        }
        printf("%d\n", count);
        i++;
    }
}