#include <stdio.h>

int main(){
    int A, B, ans;
    scanf("%d %d", &A, &B);
    ans = ((A- B) - (A - B)%10);
    int temp = (A - B - ans);
    if(temp != 9){
        temp += 1;
    }else{
        temp -= 1;
    }
    ans += temp;
    printf("%d", ans);
    return 0;
}