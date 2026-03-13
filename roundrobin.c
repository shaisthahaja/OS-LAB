#include <stdio.h>
int main() {
    int n, tq;
    int bt[20], rt[20], wt[20], tat[20];
    int time = 0, remain, flag = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time initially equals burst time
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    remain = n;
    int i = 0;
    while(remain != 0) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > tq) {
            rt[i] -= tq;
            time += tq;
        }
        if(rt[i] == 0 && flag == 1) {
            remain--;
            tat[i] = time;
            wt[i] = tat[i] - bt[i];
            flag = 0;
        }
        if(i == n-1)
            i = 0;
        else
            i++;
    }
    float avg_wt = 0, avg_tat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);
    return 0;
}
