#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct
{
int pid;
int arrival_time;
int burst_time;
int waiting_time;
int turnaround_time;
int completion_time;
int priority;
int remaining_time;
}Process;

void print_table(Process p[], int n);

void FCFS()
{

Process p[MAX];
int n,i,j,tot_WT=0,tot_TAT=0;
int arr[MAX];
printf("Total number of processes: ");
scanf("%d",&n);
printf("Enter the values:\n");
for(i=0;i<n;i++)
{
    printf("Enter pid: ");
    scanf("%d",&p[i].pid);
    printf("\n");
    printf("Enter Arrival time: ");
    scanf("%d",&p[i].arrival_time);
    printf("\n");
    printf("Enter Burst time: ");
    scanf("%d",&p[i].burst_time);
    printf("\n");

}
arr[0]=0;
for(j=0;j<n;j++)
{
    p[j].waiting_time=0;
    p[j].turnaround_time=0;
    arr[j+1]=arr[j] + p[j].burst_time;
    p[j].waiting_time=arr[j] - p[j].arrival_time;
    p[j].turnaround_time= p[j].turnaround_time + p[j].waiting_time+p[j].burst_time;
    tot_WT=tot_WT + p[j].waiting_time;
    tot_TAT=tot_TAT  + p[j].turnaround_time;
    p[j].completion_time=p[j].turnaround_time + p[j].arrival_time;

}


puts(""); 
print_table(p, n);
puts(""); 
printf("Total Waiting Time	: %d\n", tot_WT);
printf("Average Waiting Time	: %f\n", (double)tot_WT / (double) n);
printf("Total Turnaround Time : %d\n", tot_TAT);
printf("Average Turnaround Time : %f\n", (double)tot_TAT / (double) n);



}


void print_table(Process p[], int n)
{
int i;
puts("| PID | Burst Time | Waiting Time | Turnaround Time | Completion Time|");
for(i=0; i<n; i++)
{
printf("| %2d |	%2d	|	%2d	|	%2d	|	%2d	|\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time,p[i].completion_time );
}

}


void SJF()
{

Process p[MAX];
int n,i,j,t,tot_WT=0,tot_TAT=0;
int arr[MAX];
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter the values:\n");
for(i=0;i<n;i++)
{
    printf("Enter pid: ");
    scanf("%d",&p[i].pid);
    printf("\n");
    printf("Enter Burst time: ");
    scanf("%d",&p[i].burst_time);
    printf("\n");

}
for(i=0;i<n;i++)
{
    for(j=0;j<n-i-1;j++) 
    {
        if(p[j].burst_time>p[j+1].burst_time)
        {
            t=p[j].burst_time;
            p[j].burst_time=p[j+1].burst_time;
            p[j+1].burst_time=t;

            t=p[j].pid;
            p[j].pid=p[j+1].pid;
            p[j+1].pid=t;
        }
    }
}
for(i=0;i<n;i++)
{
    p[i].waiting_time=0;
    p[i].turnaround_time=0;
    for(j=0;j<i;j++)
    {
        p[i].waiting_time=p[i].waiting_time+p[j].burst_time;
    }

     p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
     tot_WT=tot_WT + p[i].waiting_time;
     tot_TAT=tot_TAT  + p[i].turnaround_time;
     p[i].completion_time=p[i].turnaround_time + p[i].arrival_time;
}
puts(""); 
print_table(p, n);
puts(""); 
printf("Total Waiting Time	: %-2d\n", tot_WT);
printf("Average Waiting Time	: %-2.2lf\n", (double)tot_WT / (double) n);
printf("Total Turnaround Time : %-2d\n", tot_TAT);
printf("Average Turnaround Time : %-2.2lf\n", (double)tot_TAT / (double) n);



}
void SRTF()
{
Process p[MAX];
int n,i,j,tot_WT=0,tot_TAT=0;
int rt[20];
int complete = 0, t = 0, minm = INT_MAX,check=0,shortest = 0, finish_time;




printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter the values:\n");
for(i=0;i<n;i++)
{
    printf("Enter pid: ");
    scanf("%d",&p[i].pid);
    printf("\n");
    printf("Enter Burst time: ");
    scanf("%d",&p[i].burst_time);
    printf("Enter Arrival time: ");
    scanf("%d",&p[i].arrival_time);
    printf("\n");

}
for(i = 0; i < n; i++)
{
    rt[i] = p[i].burst_time;
}
while (complete != n) {

        for (j = 0; j < n; j++) {
            if ((p[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {

            complete++;
            check = 0;

            finish_time = t + 1;

            p[shortest].waiting_time = finish_time -
                        p[shortest].burst_time -
                        p[shortest].arrival_time;

            if (p[shortest].waiting_time < 0)
                p[shortest].waiting_time = 0;
        }

        t++;
    }
    for(i=0;i<n;i++)
{



     p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
     tot_WT=tot_WT + p[i].waiting_time;
     tot_TAT=tot_TAT  + p[i].turnaround_time;
     p[i].completion_time=p[i].turnaround_time + p[i].arrival_time;
}
puts(""); 
print_table(p, n);
puts(""); 
printf("Total Waiting Time	: %-2d\n", tot_WT);
printf("Average Waiting Time	: %-2.2lf\n", (double)tot_WT / (double) n);
printf("Total Turnaround Time : %-2d\n", tot_TAT);
printf("Average Turnaround Time : %-2.2lf\n", (double)tot_TAT / (double) n);



}




void Priority()
{
Process p[MAX];
int n,i,j,t,b=0,min,k=1,tot_WT=0,tot_TAT=0;
int arr[MAX];
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter the values:\n");
for(i=0;i<n;i++)
{
    printf("Enter pid: ");
    scanf("%d",&p[i].pid);
    printf("\n");
    printf("Enter Burst time: ");
    scanf("%d",&p[i].burst_time);
    printf("\n");
    printf("Enter Arrival time: ");
    scanf("%d",&p[i].arrival_time);
    printf("Enter priority: ");
    scanf("%d",&p[i].priority);
    printf("\n");



}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
       if(p[i].arrival_time<p[j].arrival_time)
       {


        t=p[j].arrival_time;
        p[j].arrival_time=p[i].arrival_time;
        p[i].arrival_time=t;

        t=p[j].burst_time;
        p[j].burst_time=p[i].burst_time;
        p[i].burst_time=t;

       }

    }
}
for(j=0;i<n;j++)
{
    b=b+p[j].burst_time;
    min=p[k].burst_time;
    for(i=k;i<n;i++)
    {
        min=p[k].priority;
        if(b>=p[i].arrival_time)
        {
            if(p[i].priority<min)
            {
                t=p[k].arrival_time;
                p[k].arrival_time=p[i].arrival_time;
                p[i].arrival_time=t;

                t=p[k].burst_time;
                p[k].burst_time=p[i].burst_time;
                p[i].burst_time=t;

                t=p[k].priority;
                p[k].priority=p[i].priority;
                p[i].priority=t;
            }
        }
    }
    k++;
}
arr[0]=0;
for(i=0;i<n;i++)
{
    p[i].waiting_time=0;
    p[i].turnaround_time=0;
    arr[i+1]=arr[i]+p[i].burst_time;
    p[i].waiting_time=arr[i] - p[i].arrival_time;
    p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
    tot_WT=tot_WT + p[i].waiting_time;
    tot_TAT=tot_TAT  + p[i].turnaround_time;
    p[i].completion_time=p[i].turnaround_time + p[i].arrival_time;


}
puts(""); 
print_table(p, n);
puts(""); 
printf("Total Waiting Time	: %-2d\n", tot_WT);
printf("Average Waiting Time	: %-2.2lf\n", (double)tot_WT / (double) n);
printf("Total Turnaround Time : %-2d\n", tot_TAT);
printf("Average Turnaround Time : %-2.2lf\n", (double)tot_TAT / (double) n);

}

void RR()
{
Process p[MAX];
int n,i,j,tot_WT=0,tot_TAT=0,count=0,arr,qt,sq=0;
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter the values:\n");
for(i=0;i<n;i++)
{
    printf("Enter pid: ");
    scanf("%d",&p[i].pid);
    printf("\n");
    printf("Enter Burst time: ");
    scanf("%d",&p[i].burst_time);
    p[i].remaining_time=p[i].burst_time;
    printf("\n");

}
printf("Enter quantum time: ");
scanf("%d",&qt);
while(1)
{

    for(i=0,count=0;i<n;i++)
    {
        arr=qt;
        if(p[i].remaining_time==0)
        {
            count++;
            continue;
        }
        if(p[i].remaining_time>qt)
            p[i].remaining_time=p[i].remaining_time-qt;
        else
        {


            if(p[i].remaining_time>=0)
            {
                arr=p[i].remaining_time;
                p[i].remaining_time=0;

            }
        }

            sq=sq+arr;
            p[i].turnaround_time=sq;


    }
    if(n==count)
        break;
}

for(i=0;i<n;i++)
{
    p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
    tot_WT=tot_WT+p[i].waiting_time;
    tot_TAT=tot_TAT+p[i].turnaround_time;
    p[i].completion_time=p[i].turnaround_time;

}
puts(""); 
print_table(p, n);
puts(""); 
printf("Total Waiting Time	: %-2d\n", tot_WT);
printf("Average Waiting Time	: %-2.2lf\n", (double)tot_WT / (double) n);
printf("Total Turnaround Time : %-2d\n", tot_TAT);
printf("Average Turnaround Time : %-2.2lf\n", (double)tot_TAT / (double) n);




}


int main()

{


        printf("****MENU****\n");
        printf("1. FCFS\n");
        printf("2. SJF\n");
        printf("3. SRTF\n");
        printf("4. Priority Scheduling\n");
        printf("5. Round Robin\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            FCFS();
            break;
        case 2:
            SJF();
            break;
        case 3:
            SRTF();
            break;
        case 4:
            Priority();
            break;
        case 5:
            RR();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid input!");
            break;
}
        return 0;
}





