#include <stdio.h>

int main() {
    int p, r, i, j, k;

    printf("Enter processes and resources: ");
    scanf("%d %d", &p, &r);

    int alloc[p][r], max[p][r], need[p][r], avail[r];
    int finish[p], safe[p];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i = 0; i < p; i++)
        finish[i] = 0;

    int count = 0;

    while(count < p) {
        for(i = 0; i < p; i++) {
            if(finish[i] == 0) {
                int flag = 1;

                for(j = 0; j < r; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    for(k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if(count == p) {
        printf("\nSafe Sequence: ");
        for(i = 0; i < p; i++)
            printf("P%d ", safe[i]);
    } else {
        printf("\nSystem is not safe");
    }

    return 0;
}
