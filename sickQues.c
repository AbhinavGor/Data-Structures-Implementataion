#include <stdio.h>

int main(){
    float presD, mu, R, r;
    float ur, n;

    scanf("%f", &presD);
    printf("n");
    scanf("%f", &n);
    printf("mu");
    scanf("%f", &mu);
    printf("R");
    scanf("%f", &R);

    int parts = R/n;
    float fraction = R/n;

    printf("Fraction %.2f parts %d", fraction, parts);
    do{
        r = r + fraction;
        if(r > R){
            break;
        }
        ur = presD*(R*R - r*r)/(4*mu);
        printf("r is %.2f u(r) is %.2f\n", r, ur);
    }while(r <= R);
}