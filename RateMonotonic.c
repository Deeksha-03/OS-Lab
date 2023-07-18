#include<stdio.h>

#define MAX 100

typedef struct
{
    int p_id;
    int period;
    int execution_time;
    int deadline;
} Process;

float calculate_cpu_utilization(Process tasks[], int n)
{
    float total_utilization = 0.0;

    for (int i = 0; i < n; i++)
    {
        float task_utilization = (float)tasks[i].execution_time / tasks[i].period;
        total_utilization += task_utilization;
    }

    float cpu_utilization = total_utilization * 100;
    return cpu_utilization;
}

void rate_monotonic()
{
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process tasks[MAX];

    // Read process details
    for (i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("Enter period: ");
        scanf("%d", &tasks[i].period);
        printf("Enter execution time: ");
        scanf("%d", &tasks[i].execution_time);
        printf("Enter deadline: ");
        scanf("%d", &tasks[i].deadline);

        tasks[i].p_id = i + 1;
    }

    // Calculate CPU utilization
    float cpu_utilization = calculate_cpu_utilization(tasks, n);

    printf("CPU Utilization: %.2f%%\n", cpu_utilization);
}

int main()
{
    int i,ch;

    while(1)
    {
        printf("MENU\n");
        printf("1.Rate Monotonic\n2.Earliest Deadline First\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: rate_monotonic();
                    break;
            case 2: //NonPrePriority();
                    break;
            case 3: exit(0);
            default: printf("\nWrong Choice!!Try Again");
        }
    }

    return 0;
}
