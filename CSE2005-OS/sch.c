#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
int pid;
int arrival_time; int burst_time; int waiting_time;
int turnaround_time; int completion_time;
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
    }
}

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
    for(int i = 0; i < num; i++){

    }
}

void SJF(Process pr[], int num){
    sortSJF(pr, num);
    waitSJF(pr, num);
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


