#include <stdio.h>

int main(void) {
	int oper = 0;
	while(oper != 42){
	    scanf("%d", &oper);
	    if(oper != 42){
	        printf("%d\n", oper);
	    }else{
	        exit(0);
	    }
	}
	
	return 0;
}
