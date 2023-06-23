#include<stdio.h>

int n,at[20],cput[20];

void fcfs()
{
    int wt[20],tat[20],i,compt[20],sum=0,j,process[20],temp;
    float avgwt=0, avgtat=0;
    for(i=0;i<n;i++)
      process[i]=i;

    for(i=0;i<n;i++)
    {
        if(at[i]==at[i+1] && cput[i]>cput[i+1])
        {
            temp = cput[i];
            cput[i]=cput[i+1];
            cput[i+1]=temp;
            temp = process[i];
            process[i]=process[i+1];
            process[i+1]=temp;
        }
    }

    for(i=0;i<n;i++)
    {
        sum+=cput[i];
        compt[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        tat[i] = compt[i] -at[i];
        wt[i] = tat[i] - cput[i];
        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
    }
    avgwt=avgwt/n;
    avgtat=avgtat/n;
    printf("\nFCFS:\n");
    printf("\t PROCESS \t ARRIVAL TIME \t CPU TIME \t TURNAROUND TIME\t WAITING TIME\n");
    for(i=0;i<n;i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d\t\t\t %d", i,at[i], cput[i], tat[i], wt[i]);
    printf("\nAverage Turnaround Time : %f", avgtat);
    printf("\nAverage Waiting Time : %f", avgwt);
    for(i=0;i<n;i++)
    {

    }
}



void sjfnp()
{
    int tat[20],wt[20],cputd[20];
    float avgwt=0, avgtat=0,sum_cpu_time=0;
    int time=0,i,j, smallest, temp2;
    for (i = 0; i < n; i++)
    {
        cputd[i]=cput[i];
        sum_cpu_time += cput[i];
    }

    cputd[9]=9999;
    printf("\nSJF:\n");
    printf("\t ARRIVAL TIME \t CPU TIME \t TURNAROUND TIME\t WAITING TIME\n");
    while(time < sum_cpu_time)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && cputd[i] > 0 && cputd[i] < cputd[smallest])
                smallest = i;
        }

        //time + cput[smallest] is the completion time
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", smallest ,at[smallest],cputd[smallest], time + cputd[smallest] - at[smallest], time - at[smallest]);
        avgtat += time + cputd[smallest] - at[smallest];
        avgwt += time - at[smallest];
        time += cputd[smallest];
        cputd[smallest] = 0;
  }

    avgwt = avgwt/n;
    avgtat =avgtat/n;
    printf("\nAverage Turnaround Time : %f", avgtat);
    printf("\nAverage Waiting Time : %f", avgwt);

}



void srtf()
{
    int remaining_time[20], tat[20], wt[20], completion_time[20], smallest, time=0, i, count = 0;
    float avgwt=0,avgtat=0;

    for (i = 0; i < n; i++)
        remaining_time[i] = cput[i];

    while (count != n) {
        smallest = -1;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && remaining_time[i] > 0)
            {
                if (smallest == -1 || remaining_time[i] < remaining_time[smallest])
                    smallest = i;
            }
        }

        if (smallest == -1)
        {
            time++;
            continue;
        }

        remaining_time[smallest]--;

        if (remaining_time[smallest] == 0)
        {
            count++;
            completion_time[smallest] = time + 1;
            wt[smallest] = completion_time[smallest] - at[smallest] - cput[smallest];
            tat[smallest] = completion_time[smallest] - at[smallest];
        }

        time++;
    }
    for(i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat += tat[i];

    }
    avgwt = avgwt/n;
    avgtat =avgtat/n;

    printf("\nProcess\tArrival Time\tCPU Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, at[i], cput[i], wt[i], tat[i]);

    printf("\nAverage Turnaround Time : %f", avgtat);
    printf("\nAverage Waiting Time : %f", avgwt);
}

void main()
{
    int i,ch;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Arival Time and CPU Time for the Process %d : ", i);
        scanf("%d %d", &at[i],&cput[i]);
    }
    while(1)
    {
        printf("\nMENU\n");
        printf("1.FCFS\n2.SJF\n3.SRTF\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: fcfs();
                    break;
            case 2: sjfnp();
                    break;
            case 3: srtf();
                    break;
            case 4: exit(0);
            default: printf("\nWrong Choice!!Try Again");
        }
    }
}
