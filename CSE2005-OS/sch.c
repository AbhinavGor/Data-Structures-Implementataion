#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
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
int rem_bt;
}Process;
void print_table(Process p[], int n);
void FCFS()
{
// get values and calculate the average waiting time and turnaround time
Process p[MAX];
int n,i,j,sum_waiting_time=0,sum_turnaround_time=0;
int temp[MAX];
printf("Enter number of processes: ");
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
temp[0]=0;
for(j=0;j<n;j++)
{
p[j].waiting_time=0;
p[j].turnaround_time=0;
temp[j+1]=temp[j] + p[j].burst_time;
p[j].waiting_time=temp[j] - p[j].arrival_time;
p[j].turnaround_time= p[j].turnaround_time + p[j].waiting_time+p[j].burst_time;
sum_waiting_time=sum_waiting_time + p[j].waiting_time;
sum_turnaround_time=sum_turnaround_time + p[j].turnaround_time;
p[j].completion_time=p[j].turnaround_time + p[j].arrival_time;
}
// print table
puts(""); // Empty line
print_table(p, n);
puts(""); // Empty Line
printf("Total Waiting Time : %d\n", sum_waiting_time);
printf("Average Waiting Time : %f\n", (double)sum_waiting_time / (double) n);
printf("Total Turnaround Time : %d\n", sum_turnaround_time);
printf("Average Turnaround Time : %f\n", (double)sum_turnaround_time / (double) n);
}
void print_table(Process p[], int n)
{
int i;
puts("| PID | Burst Time | Waiting Time | Turnaround Time | Completion Time|");
for(i=0; i<n; i++)
{
printf("| %2d | %2d | %2d | %2d | %2d |\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time,p[i].completion_time );
}
}
void SJF()
{
Process p[MAX];
int n,i,j,t,sum_waiting_time=0,sum_turnaround_time=0;
int temp[MAX];
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
for(j=0;j<n-i-1;j++) //bubble sort for burst time
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
sum_waiting_time=sum_waiting_time + p[i].waiting_time;
sum_turnaround_time=sum_turnaround_time +
p[i].turnaround_time;
p[i].completion_time=p[i].turnaround_time + p[i].arrival_time;
}
puts(""); // Empty line
print_table(p, n);
puts(""); // Empty Line
printf("Total Waiting Time : %-2d\n", sum_waiting_time);
printf("Average Waiting Time : %-2.2lf\n",(double)sum_waiting_time / (double) n);
printf("Total Turnaround Time : %-2d\n", sum_turnaround_time);
printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);
}
void SRTF()
{
Process p[MAX];
int n,i,j,sum_waiting_time=0,sum_turnaround_time=0;
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
// Find process with minimum
// remaining time among the
// processes that arrives till the
// current time`
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
// Reduce remaining time by one
rt[shortest]--;
// Update minimum
minm = rt[shortest];
if (minm == 0)
    minm = INT_MAX;
// If a process gets completely
// executed
if (rt[shortest] == 0) {
// Increment complete
complete++;
check = 0;
// Find finish time of current
// process
finish_time = t + 1;
// Calculate waiting time
p[shortest].waiting_time = finish_time - p[shortest].burst_time - p[shortest].arrival_time;
if (p[shortest].waiting_time < 0)
p[shortest].waiting_time = 0;
}
// Increment time
t++;
}
for(i=0;i<n;i++)
{
p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
sum_waiting_time=sum_waiting_time + p[i].waiting_time;
sum_turnaround_time=sum_turnaround_time + p[i].turnaround_time; 
p[i].completion_time=p[i].turnaround_time ;
}
puts(""); // Empty line
print_table(p, n);
puts(""); // Empty Line
printf("Total Waiting Time : %-2d\n", sum_waiting_time);
printf("Average Waiting Time : %-2.2lf\n",
(double)sum_waiting_time / (double) n);
printf("Total Turnaround Time : %-2d\n",
sum_turnaround_time);
printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);
}
void Priority()
{
Process p[MAX];
int
n,i,j,t,b=0,min,k=1,sum_waiting_time=0,sum_turnaround_time=
0;
int temp[MAX];
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
temp[0]=0;
for(i=0;i<n;i++)
{
p[i].waiting_time=0;
p[i].turnaround_time=0;
temp[i+1]=temp[i]+p[i].burst_time;
p[i].waiting_time=temp[i] - p[i].arrival_time;
p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
sum_waiting_time=sum_waiting_time + p[i].waiting_time;
sum_turnaround_time=sum_turnaround_time +
p[i].turnaround_time;
p[i].completion_time=p[i].turnaround_time +
p[i].arrival_time;
}
puts(""); // Empty line
print_table(p, n);
puts(""); // Empty Line
printf("Total Waiting Time : %-2d\n", sum_waiting_time);
printf("Average Waiting Time : %-2.2lf\n",
(double)sum_waiting_time / (double) n);
printf("Total Turnaround Time : %-2d\n",
sum_turnaround_time);
printf("Average Turnaround Time : %-2.2lf\n",
(double)sum_turnaround_time / (double) n);
}
void RR()
{
Process p[MAX];
int n,i,j,sum_waiting_time=0,sum_turnaround_time=0,count=0,temp,qt,sq=0;
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
p[i].rem_bt=p[i].burst_time;
printf("\n");
}
printf("Enter quantum time: ");
scanf("%d",&qt);
while(1)
{
for(i=0,count=0;i<n;i++)
{
temp=qt;
if(p[i].rem_bt==0)
{
count++;
continue;
}
if(p[i].rem_bt>qt)
p[i].rem_bt=p[i].rem_bt-qt;
else
{
if(p[i].rem_bt>=0)
{
temp=p[i].rem_bt;
p[i].rem_bt=0;
}
}
sq=sq+temp;
p[i].turnaround_time=sq;
}
if(n==count)
break;
}
for(i=0;i<n;i++)
{
p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
sum_waiting_time=sum_waiting_time+p[i].waiting_time;
sum_turnaround_time=sum_turnaround_time+p[i].turnaround_time;
p[i].completion_time=p[i].turnaround_time;
}
puts(""); // Empty line
print_table(p, n);
puts(""); // Empty Line
printf("Total Waiting Time : %-2d\n", sum_waiting_time);
printf("Average Waiting Time : %-2.2lf\n",
(double)sum_waiting_time / (double) n);
printf("Total Turnaround Time : %-2d\n",
sum_turnaround_time);
printf("Average Turnaround Time : %-2.2lf\n",
(double)sum_turnaround_time / (double) n);
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
}
return 0;
}