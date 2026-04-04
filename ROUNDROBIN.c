#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remain, flag = 0;
    int at[10], bt[10], rt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter arrival time and burst time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT BT: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    for(time = 0, i = 0; remain != 0; ) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if(rt[i] == 0 && flag == 1) {
            remain--;
            tat[i] = time - at[i];
            wt[i] = tat[i] - bt[i];
            flag = 0;
        }

        if(i == n-1)
            i = 0;
        else if(at[i+1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nProcess\tAT\tBT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], tat[i], wt[i]);
    }

    return 0;
}