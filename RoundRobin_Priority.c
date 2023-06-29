#include <stdio.h>
#include <stdlib.h>

int n, at[20], cput[20];

void roundRobin()
{
    int TQ;
    int remaining_time[n], wt[n], tat[n], ready_queue[n];
    int completed_processes = 0, current_time = 0;

    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = cput[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &TQ);

    // Perform Round Robin scheduling
    while (completed_processes < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0 && at[i] <= current_time)
            {
                if (remaining_time[i] <= TQ)
                {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    completed_processes++;

                    tat[i] = current_time - at[i];
                    wt[i] = tat[i] - cput[i];
                }
                else
                {
                    current_time += TQ;
                    remaining_time[i] -= TQ;
                }
            }
        }
    }

    // Calculate average turnaround time and average waiting time
    float avgtat = 0, avgwt = 0;
    for (int i = 0; i < n; i++)
    {
        avgtat += tat[i];
        avgwt += wt[i];
    }
    avgtat /= n;
    avgwt /= n;

    // Print results
    printf("\nProcess\tCPU Time\tArrival Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, cput[i], at[i], tat[i], wt[i]);
    }
    printf("Average Turnaround Time: %.2f\n", avgtat);
    printf("Average Waiting Time: %.2f\n", avgwt);
}

void NonPrePriority()
{
    int completion_time[n], tat[n], wt[n], priority[n], cputd[n];
    float avgwt = 0, avgtat = 0, sum_cpu_time = 0;
    int time = 0, i, j, curr_hp, temp2;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum_cpu_time += cput[i];
        cputd[i] = cput[i];
    }

    while (time < sum_cpu_time)
    {
        curr_hp = -1; // -1 indicates no process selected yet
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && cputd[i] > 0)
            {
                if (curr_hp == -1 || priority[i] > priority[curr_hp])
                {
                    curr_hp = i;
                }
            }
        }

        if (curr_hp == -1)
        {
            break; // No process available to execute
        }

        printf("P[%d]\t|\t%d\t|\t%d\n", curr_hp + 1, time + cputd[curr_hp], time - at[curr_hp]);
        avgwt += time - at[curr_hp];
        avgtat += time + cputd[curr_hp] - at[curr_hp];
        time += cput[curr_hp];
        cputd[curr_hp] = 0;
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);
}

int main()
{
    int i, ch;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time and CPU Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &cput[i]);
    }

    while (1)
    {
        printf("\nMENU\n");
        printf("1. Round Robin\n2. Non-Preemptive Priority\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            roundRobin();
            break;
        case 2:
            NonPrePriority();
            break;
        case 3:
            exit(0);
        default:
            printf("\nWrong Choice! Try Again.\n");
        }
    }

    return 0;
}
