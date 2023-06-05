#include <stdio.h>

#define MAX_PROCESSES 10

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    int n, quantum, i, j, time, total_waiting_time = 0, total_turnaround_time = 0;
    struct process processes[MAX_PROCESSES], temp;
    float average_waiting_time, average_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the quantum: ");
    scanf("%d", &quantum);

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // sort the processes by arrival time
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // run the round robin scheduling algorithm
    printf("\nProcess execution order:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0, time = 0; i < n;)
    {
        if (processes[i].remaining_time <= quantum && processes[i].remaining_time > 0)
        {
            time += processes[i].remaining_time;
            processes[i].remaining_time = 0;
            processes[i].completion_time = time;
            processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
            total_waiting_time += processes[i].waiting_time;
            total_turnaround_time += processes[i].turnaround_time;
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
            i++;
        }
        else if (processes[i].remaining_time > 0)
        {
            processes[i].remaining_time -= quantum;
            time += quantum;
            printf("%d\t%d\t\t%d\t\t-\t\t-\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
        }
        else
        {
            i++;
        }
        if (i == n && time > processes[0].arrival_time)
        {
            i = 0;
        }
    }

    average_waiting_time = (float)total_waiting_time / n;
    average_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);

    return 0;
}