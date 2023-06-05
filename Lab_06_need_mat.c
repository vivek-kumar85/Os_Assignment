// Implement C program to display need matrix and safe sequence for given processes. 
// (Allocation matrix, Max matrix, available matrix are the input from user).


#include <stdio.h>

int max[10][10], allocation[10][10], need[10][10];
int available[10];
int np, nr;

void readmatrix(int matrix[10][10])
{
    int i, j;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int matrix[10][10])
{
    int i, j;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculate_need()
{
    int i, j;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void banker()
{
    int i, j, k = 0, flag;
    int finish[10], safe_seq[10];

    for (i = 0; i < np; i++)
    {
        finish[i] = 0; // Declare all process are incomplete
    }

    for (i = 0; i < np; i++)
    {
        flag = 0;
        if (finish[i] == 0) // Execute incomplete process
        {
            for (j = 0; j < nr; j++)
            {
                if (need[i][j] > available[j]) // Check if need of each process
                {
                    flag = 1; // If need is greater than available then break
                    break;
                }
            }
            if (flag == 0) // If need is less than available then execute process
            {
                finish[i] = 1;
                safe_seq[k] = i;
                k++;
                // Add allocated resources of finished process to available resources
                for (j = 0; j < nr; j++)
                {
                    available[j] += allocation[i][j];
                }

                i = -1; // Start from first process again
            }
        }
    }

    flag = 0; // flag to check if all processes are finished or not

    for (i = 0; i < np; i++)
    {
        if (finish[i] == 0)
        {
            printf("The system in in DeadLock\n");
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("The system is in Safe State\n");
        printf("The Safe Sequence is: ");
        for (i = 0; i < np; i++)
        {
            printf("P%d ", safe_seq[i]);
        }
        printf("\n");
    }
}

int main()
{
    int j;

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("\n");

    printf("Enter the number of resources: ");
    scanf("%d", &nr);

    printf("\n");

    printf("Enter the initial allocation matrix\n");
    readmatrix(allocation);

    printf("\n");

    printf("Enter the max requriment matrix\n");
    readmatrix(max);

    printf("\n");

    printf("Enter the available resources\n");
    for (j = 0; j < nr; j++)
    {
        scanf("%d", &available[j]);
    }

    printf("\n");

    //Display the entered data

    printf("\n");
    
    printf("------------------------------------------ Entered Data is: ------------------------------------------  \n\n");

    printf("Initial Allocation Matrix\n");
    display_matrix(allocation);

    printf("\n");
    
    printf("Max Requriment Matrix\n");
    display_matrix(max);

    printf("\n");

    printf("Available Resources\n");
    for (j = 0; j < nr; j++)
    {
        printf("%d\t", available[j]);
    }

    // Calculate and Display Need Matrix

    calculate_need();
    printf("\n\nNeed Matrix\n");
    display_matrix(need);

    // Execute Banker's Algorithm
    printf("\n");
    banker();

    printf("\n");
    return 0;
}