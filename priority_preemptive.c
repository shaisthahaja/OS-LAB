#include <stdio.h>

int main()
{
    int n, bt[20], pr[20], rt[20], wt[20], tat[20];
    int time = 0, completed = 0, highest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority for P%d: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed < n)
    {
        highest = -1;

        for(int i = 0; i < n; i++)
        {
            if(rt[i] > 0 && (highest == -1 || pr[i] < pr[highest]))
                highest = i;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            completed++;
            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];

            avg_wt += wt[highest];
            avg_tat += tat[highest];
        }
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
