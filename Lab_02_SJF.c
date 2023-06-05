// Implement Round Robin CPU scheduling algorithm. Display waiting and turn round time of each process.  Also Display average waiting time and average turn around time.

#include <stdio.h>

int main()
{
    int n, i, qt, ct = 0, temp, sq = 0, bt[10], wt[10], tat[10], rbt[10];
    float awt = 0, atat = 0;

    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter burst time of process: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rbt[i] = bt[i];
    }
    printf("Enter the quatum time: ");
    scanf("%d", &qt);
    while (1)
    {
        for (i = 0, ct = 0; i < n; i++)
        {
            temp = qt;
            if (rbt[i] == 0)
            {
                ct++;
                continue;
            }
            if (rbt[i] > qt)
            {
                rbt[i] = rbt[i] - qt;
            }
            else
            {
                if (rbt[i] >= 0)
                {
                    temp = rbt[i];
                    rbt[i] = 0;
                }
                sq = sq + temp;
                tat[i] = sq;
            }
        }
        if (n == ct)
        {
            break;
        }
    }
    printf("Process\tBurst Time\tWaiting Time\t TAT\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t%d\t\t%d\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\nAverage WT = %f\n", awt);
    printf("Average TAT = %f\n", atat);
    return 0;
}

