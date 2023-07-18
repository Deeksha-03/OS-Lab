/*Write a C program to simulate multi-level queue scheduling
algorithm considering the following scenario. All the processes in the
system are divided into two categories – system processes and user
processes. System processes are to be given higher priority than user
processes. Use FCFS scheduling for the processes in each queue.*/

#include<stdio.h>

#define MAX 50

typedef struct
{
    int number;
    int p_id[MAX];
    int tat[MAX];
    int wt[MAX];
    int arrival_time[MAX];
    int cpu_time[MAX];
} Process;

void main()
{
    int n, i,j,pname[MAX],total_time=0,time=0;
    int totaltat[MAX], totalwt[MAX];
    float avgtat=0,avgwt=0;
    Process sp,up;
    printf("Enter the number of system processes: ");
    scanf("%d", &sp.number);
    printf("Enter the number of user processes: ");
    scanf("%d", &up.number);
     printf("Enter the Arrival time and the Burst time for system processes:\n");
    // Read process details
    for (i = 0; i < sp.number; i++)
    {
        //printf("Process %d\n", i + 1);
        scanf("%d", &sp.arrival_time[i]);
        scanf("%d", &sp.cpu_time[i]);

        sp.p_id[i] = 10+i + 1;
    }
    printf("Enter the Arrival time and the Burst time for user processes:\n");
    // Read process details
    for (i = 0; i < up.number; i++)
    {
        //printf("Process %d\n", i + 1);
        scanf("%d", &up.arrival_time[i]);
        scanf("%d", &up.cpu_time[i]);

        up.p_id[i] = 20+i + 1;
    }

    for(i=0;i<sp.number;i++)
        total_time+=sp.cpu_time[i];

    for(i=0;i<up.number;i++)
        total_time+=up.cpu_time[i];

    i=0,j=0;
    while(time<total_time)
    {
        if(sp.arrival_time[i]<=up.arrival_time[j])
        {
            time+=sp.cpu_time[i];
            sp.tat[i]=time-sp.arrival_time[i];
            sp.wt[i]=sp.tat[i]-sp.cpu_time[i];
            i++;
        }
        else if(up.arrival_time[j]<sp.arrival_time[i]&&sp.arrival_time[i]>time)
        {
            time+=up.cpu_time[j];
            up.tat[j]=time-up.arrival_time[j];
            up.wt[j]=up.tat[j]-up.cpu_time[j];
            j++;
        }
        else if(up.arrival_time[j]<=sp.arrival_time[i]&&sp.arrival_time[i]<time)
        {
            time+=sp.cpu_time[i];
            sp.tat[i]=time-sp.arrival_time[i];
            sp.wt[i]=sp.tat[i]-sp.cpu_time[i];
            i++;
        }
        //printf("%d",sp.tat[0]);
    }
    printf("\t PROCESS \t ARRIVAL TIME \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<sp.number;i++)
    {
        printf("\n\t S%d \t\t %d \t\t %d \t\t %d \t\t %d", i,sp.arrival_time[i], sp.cpu_time[i], sp.wt[i], sp.tat[i]);
        avgtat+=sp.tat[i];
        avgwt+=sp.wt[i];
    }
    for(i=0;i<up.number;i++)
    {
         printf("\n\t U%d \t\t %d \t\t %d \t\t %d \t\t %d", i,up.arrival_time[i], up.cpu_time[i], up.wt[i], up.tat[i]);
        avgtat+=up.tat[i];
        avgwt+=up.wt[i];
    }
    avgtat/=(sp.number+up.number);
    avgwt/=(sp.number+up.number);
    printf("\nAverage Turnaround Time -- %f", avgtat);
    printf("\nAverage Waiting Time -- %f", avgwt);
}
