#include <stdio.h>

struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].processId = i + 1;
    }

    int completionTime = 0;
    for (int i = 0; i < n; i++) {
        if (completionTime < processes[i].arrivalTime) {
            completionTime = processes[i].arrivalTime;
        }
        completionTime += processes[i].burstTime;
        processes[i].completionTime = completionTime;
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
    }

    printf("Process\t\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n", processes[i].processId, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].turnAroundTime, processes[i].waitingTime);
    }

    return 0;
}
