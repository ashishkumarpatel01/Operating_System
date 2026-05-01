#include <stdio.h>

int main() 
{
    int ms, bs, nob, ef, n;
    int mp[20];  // memory required by processes
    int i, p = 0;
    int tif = 0; // total internal fragmentation

    // Input total memory
    printf("Enter total memory (in Bytes): ");
    scanf("%d", &ms);

    // Input block size
    printf("Enter block size (in Bytes): ");
    scanf("%d", &bs);

    // Calculate number of blocks
    nob = ms / bs;

    // External fragmentation
    ef = ms - (nob * bs);

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input memory required for each process
    for(i = 0; i < n; i++) 
    {
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNumber of blocks available = %d\n", nob);

    printf("\nPROCESS\tMEMORY\tALLOCATED\tINTERNAL FRAGMENTATION\n");

    // Allocation logic
    for(i = 0; i < n && p < nob; i++) 
    {
        printf("%d\t%d\t", i + 1, mp[i]);

        if(mp[i] > bs) 
        {
            printf("NO\t\t---\n");
        } 
        else 
        {
            printf("YES\t\t%d\n", bs - mp[i]);
            tif += (bs - mp[i]);
            p++;
        }
    }

    if(i < n) 
    {
        printf("\nMemory is full, remaining processes cannot be allocated\n");
    }

    printf("\nTotal Internal Fragmentation = %d\n", tif);
    printf("Total External Fragmentation = %d\n", ef);

    return 0;
}