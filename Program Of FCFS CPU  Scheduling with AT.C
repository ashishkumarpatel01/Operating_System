#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], wt[20], tat[20], ct[20], p[20];
    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("\nProcess P%d\n", p[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time (Simple Bubble Sort)
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(at[j] > at[j+1])
            {
                // Swap Arrival Time
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // Swap Process Number
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Completion Time
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Turnaround Time & Waiting Time
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage Waiting Time = %.2f", wtavg/n);
    printf("\nAverage Turnaround Time = %.2f\n", tatavg/n);

    return 0;
}
