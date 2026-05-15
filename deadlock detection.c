#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n], work[m];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    // Initialize Finish
    for(i = 0; i < n; i++) {
        int sum = 0;

        for(j = 0; j < m; j++)
            sum += alloc[i][j];

        if(sum == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    // Detection Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {
                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(req[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    for(j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    finish[i] = 1;
                }
            }
        }
    }

    // Check Deadlock
    int deadlock = 0;

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock = 1;
            printf("Process P%d is deadlocked\n", i);
        }
    }

    if(deadlock == 0)
        printf("No Deadlock");

    return 0;
}
