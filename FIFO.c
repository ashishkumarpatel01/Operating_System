#include <stdio.h>

int main()
{
    int pages[] = {2,3,2,1,5,2,4,5,3,2,5,2};
    int frames[3] = {-1, -1, -1};
    int i, j, k, found, pos = 0, faults = 0;

    for(i = 0; i < 12; i++)
    {
        found = 0;

        // Check if page already in frame
        for(j = 0; j < 3; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        // If not found → page fault
        if(!found)
        {
            frames[pos] = pages[i];
            pos = (pos + 1) % 3;   // FIFO rotation
            faults++;
        }

        // Display frames
        printf("\n");
        for(k = 0; k < 3; k++)
            printf("%d\t", frames[k]);
    }

    printf("\n\nNumber of Page Faults: %d\n", faults);
    return 0;
}