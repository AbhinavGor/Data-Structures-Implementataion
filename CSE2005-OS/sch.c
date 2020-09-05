#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#define typename(x) _Generic((x),                                                 \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")

typedef struct{
    int pid, arrical_time, burst_time, waiting_time, turnarounf_time, completion_time;
}Process;


// void print_table(Process p[], int n);

// int waitFCFS(Process p[], int n){

// }

// void FCFS(){
//     //Get values and calculate the avg waiting and turnaround time
//     puts(""); //Empty Line
//     print_table(p, n);
//     puts(""); //Empty Line
// }

int main(){

    Process p[MAX];
    // p.pid = 1234;
    printf(ty(p));
}
