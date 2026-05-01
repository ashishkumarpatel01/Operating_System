#include <stdio.h>

int main()
{
    int b[25], f[25], frag[25];
    int i, j, nb, nf;
    int max_idx;
    int allocated[25] = {0};

    printf("\nMemory Management Scheme - Worst Fit\n");

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter number of files: ");
    scanf("%d", &nf);

    printf("\nEnter block sizes:\n");
    for(i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter file sizes:\n");
    for(i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++)
    {
        max_idx = -1;

        for(j = 1; j <= nb; j++)
        {
            if(allocated[j] == 0 && b[j] >= f[i])
            {
                if(max_idx == -1 || b[j] > b[max_idx])
                {
                    max_idx = j;
                }
            }
        }

        if(max_idx != -1)
        {
            frag[i] = b[max_idx] - f[i];
            allocated[max_idx] = 1;

            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i, f[i], max_idx, b[max_idx], frag[i]);
        }
        else
        {
            printf("\n%d\t\t%d\t\tNot Allocated", i, f[i]);
        }
    }

    return 0;
}