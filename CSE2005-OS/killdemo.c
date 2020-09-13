#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int i;
    printf("Hello");
    printf("My id is %d", getpid());

    for(i=0;i<100;i++){
        sleep(1);
    }
    return 0;
}
