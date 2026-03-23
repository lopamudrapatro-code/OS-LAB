#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], type[n], ct[n], tat[n], wt[n];
    int order[n], k = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter AT BT Type(1-System,2-User) for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &type[i]);
    }

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (type[i] == 1) {
            if (time < at[i])
                time = at[i];
            time += bt[i];
            ct[i] = time;
            order[k++] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (type[i] == 2) {
            if (time < at[i])
                time = at[i];
            time += bt[i];
            ct[i] = time;
            order[k++] = i;
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tAT\tBT\tType\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], type[i], ct[i], tat[i], wt[i]);
    }


    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", order[i] + 1);
    }

    printf("\n0");
    for (int i = 0; i < n; i++) {
        printf(" %d", ct[order[i]]);
    }

    printf("\n");
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
