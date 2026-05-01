#include <stdio.h>

int main()
{
    int b[25], f[25], frag[25];
    int i, j, nb, nf;
    int bf[25] = {0}, ff[25];
    int temp, lowest;

    printf("\nMemory Management Scheme - Best Fit\n");

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
        lowest = 10000;

        for(j = 1; j <= nb; j++)
        {
            if(bf[j] == 0)
            {
                temp = b[j] - f[i];

                if(temp >= 0 && temp < lowest)
                {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        frag[i] = lowest;
        bf[ff[i]] = 1;
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");

    for(i = 1; i <= nf; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i, f[i], ff[i], b[ff[i]], frag[i]);
    }

    return 0;
}