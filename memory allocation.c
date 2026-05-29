#include <stdio.h>

#define MAX 10

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",
                   i + 1, processSize[i]);
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int best = -1;

        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (best == -1 || blockSize[j] < blockSize[best])
                    best = j;
            }
        }

        if (best != -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",
                   i + 1, processSize[i]);
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int worst = -1;

        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",
                   i + 1, processSize[i]);
    }
}

int main() {
    int blocks, processes;

    printf("Enter number of blocks: ");
    scanf("%d", &blocks);

    int blockSize[MAX], temp1[MAX], temp2[MAX];

    printf("Enter block sizes:\n");
    for (int i = 0; i < blocks; i++) {
        scanf("%d", &blockSize[i]);
        temp1[i] = temp2[i] = blockSize[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    int processSize[MAX];

    printf("Enter process sizes:\n");
    for (int i = 0; i < processes; i++)
        scanf("%d", &processSize[i]);

    firstFit(blockSize, blocks, processSize, processes);
    bestFit(temp1, blocks, processSize, processes);
    worstFit(temp2, blocks, processSize, processes);

    return 0;
}
