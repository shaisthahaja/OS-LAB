#include <stdio.h>

int main()
{
    int n,i,time=0,sm;
    int at[20],bt[20],ct[20],tat[20],wt[20];
    int completed[20]={0},count=0;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);
    }

    while(count<n)
    {
        sm=-1;
        int min=9999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0 && bt[i]<min)
            {
                min=bt[i];
                sm=i;
            }
        }

        if(sm==-1)
        {
            time++;
        }
        else
        {
            time=time+bt[sm];
            ct[sm]=time;
            tat[sm]=ct[sm]-at[sm];
            wt[sm]=tat[sm]-bt[sm];

            avgwt+=wt[sm];
            avgtat+=tat[sm];

            completed[sm]=1;
            count++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);

    return 0;
}