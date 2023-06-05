// Implement C program to simulate any one FIFO page replacement algorithms

#include <stdio.h>
void main()
{
    int i, j, k, f, pf = 0, count = 0, res[25], m[10], n;
    
    printf("\n Enter the Length of string: ");
    scanf("%d", &n);

    printf("\n Enter the String: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &res[i]);
    }
    printf("\n Enter the Number of Frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        m[i] = -1;
    }

    printf("\n The Page Replacement Process is: \n");
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == res[i])
            {
                break;
            }
        }

        if (k == f)
        {
            m[count++] = res[i];
            pf++;
        }

        for (j = 0; j < f; j++)
        {
            printf("\t%d", m[j]);
        }

        if (k == f)
        {
            printf("\tPF No. %d", pf);
        }

        printf("\n");

        if (count == f)
        {
            count = 0;
        }
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
    printf("\n");
}