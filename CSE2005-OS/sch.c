#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
int pid;
int arrival_time; int burst_time; int waiting_time;
int turnaround_time; int completion_time; int priority;
}Process;

void print_table(Process p[], int n){
    int i;

    puts("\n| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time | Completion Time |\n");

    for(i = 0; i < n; i++){
        printf("| %d | %d | %d | %d | %d | %d |\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
        // printf("| %d | %d | %d |\n", p[i].pid, p[i].burst_time, p[i].arrival_time);
    }
}


void getProcesses(Process pr[], int num){

    for(int i=0; i<num; i++){
        printf("\nEnter process ID:\n");
        scanf("%d", &pr[i].pid);
        
        printf("\nEnter the Burst Time:\n");
        scanf("%d", &pr[i].burst_time);

        printf("\nEnter the Arrival Time:\n");
        scanf("%d", &pr[i].arrival_time);    

        printf("\nEnter the Priority:\n");
        scanf("%d", &pr[i].priority);    
    }
}


//FCFS
void waitFCFS(Process pr[], int n){
    pr[0].waiting_time = 0;
    for(int i = 1; i < n; i++){
        pr[i].waiting_time = pr[i-1].burst_time + pr[i - 1].waiting_time;
    }
}

void tatFCFS(Process pr[], int n){
    for(int i =0; i< n; i++){
        pr[i].turnaround_time = pr[i].burst_time + pr[i].waiting_time;
    }
}

void compTimeFCFS(Process pr[], int n){
    for(int i =0; i < n; i++){
        pr[i].completion_time = pr[i].burst_time + pr[i].waiting_time + pr[i].arrival_time;
    }
}

void FCFS(Process pr[], int num, int time){
    waitFCFS(pr, num);
    tatFCFS(pr, num);
    print_table(pr, num);
}

//SJF
void sortSJF(Process pr[], int n){
    Process temp;
    for(int i =0 ; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; i++){
            if(pr[j].burst_time > pr[j + 1].burst_time){
                temp = pr[j + 1];
                pr[j + 1] = pr[j];
                pr[j] = temp;
            }
        }
    }
}

void waitSJF(Process pr[], int num){
    for(int j = 0; j < num; j++){
        pr[i].waiting_time = 0;
        for(int i = 0; i < j; i++){
            pr[i].waiting_time = pr[j].burst_time + pr[j].waiting_time;
        }
    }
}

void tatSJF(Process pr[], int n){
    for(int i = 0; i < n; i++){
        pr[i].turnaround_time = pr[i].burst_time + pr[i].waiting_time;
    }
}

void SJF(Process pr[], int num){
    sortSJF(pr, num);
    waitSJF(pr, num);
    tatSJF(pr, num);
    print_table(pr, n);
}

// //SRTF
// void SRTF(Process pr[], int n, int time){
//     sortSJF(pr, n);
//     waitSRTF(pr, n);
//     tatSRTF(pr, n);
// }

// void waitSRTF(Process pr[], int n){

// }

// void tatSRTF(Process pr[], int n){

// }

//

//Priority
void Priority(Process, pr[], int n, int time){
    sortPrior(pr, n);
    waitSJF(pr, n);
    tatSJF(pr, n);
    print_table(pr, n);
}

void sortPrior(Process pr[], int n){
    for(int i = 0; i < n; i++){
        int key = pr[i].priority;
        int j = i - 1;

        while (j >= 0 && pr[j].priority > key)
        {
            pr[j + 1].priority = pr[j].priority;
            j -= 1;
        }

        pr[j + 1].priority = key;
        
    }
}

void waitPrior(Process pr[], int n){

}

//RoundRobin
void roundRobin(Process pr[], int n, int time){

}

float avgTAT(Process pr[], int n){
    int avg = 0;
    for(int i = 0; i < n; i++){
        avg += pr[i].turnaround_time;
    }
    return avg/n;
}

float avgWT(Process pr[], int n){
    int avg = 0;
    for(int i = 0; i < n; i++){
        avg += pr[i].waiting_time;
    }
    return avg/n;
}


int main(){

    int num, time = 0;

    printf("\nHow many processes do you want to include?\n");
    scanf("%d", &num);

    Process pr[num];

    getProcesses(pr, num);
    sortSJF(pr, num);
    print_table(pr, num);

    // printf("----------Implementation of FCFS on the given processess----------");
    // FCFS(pr, num, time);
    // printf("\nThe average waiting time is %.2f.\nThe average turnaround time is %.2f.\n", avgWT(pr, num), avgTAT(pr, num));

    // printf("----------Implementation of SJF on the given processess----------");
    // FCFS(pr, num, time);
    // printf("\nThe average waiting time is %.2f.\nThe average turnaround time is %.2f.\n", avgWT(pr, num), avgTAT(pr, num));

    // printf("----------Implementation of SRTF on the given processess----------");
    // FCFS(pr, num, time);
    // printf("\nThe average waiting time is %.2f.\nThe average turnaround time is %.2f.\n", avgWT(pr, num), avgTAT(pr, num));

    // printf("----------Implementation of Priority Scheduling on the given processess----------");
    // FCFS(pr, num, time);
    // printf("\nThe average waiting time is %.2f.\nThe average turnaround time is %.2f.\n", avgWT(pr, num), avgTAT(pr, num));

    // printf("----------Implementation of Round Robin on the given processess----------");
    // FCFS(pr, num, time);
    // printf("\nThe average waiting time is %.2f.\nThe average turnaround time is %.2f.\n", avgWT(pr, num), avgTAT(pr, num));
}


