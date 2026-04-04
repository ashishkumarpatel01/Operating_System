#include <stdio.h>

int main() {
    int n, i, j;
    int at[10], bt[10], pr[10], ct[10], tat[10], wt[10];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter AT, BT and Priority:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
    }

    // Sorting based on priority (lower number = higher priority)
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                // swap AT
                int temp = at[i]; at[i] = at[j]; at[j] = temp;
                // swap BT
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // swap PR
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
            }
        }
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Calculate TAT and WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tPR\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], tat[i], wt[i]);
    }

    return 0;
}