#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

struct Node {
    struct Process data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* q, struct Process data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (q->front == NULL && q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Process dequeue(struct Queue* q) {
    struct Process data = {-1, -1, -1};
    if (q->front == NULL) {
        return data;
    }
    struct Node* temp = q->front;
    data = temp->data;
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }
    free(temp);
    return data;
}

int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Process p;
        printf("Enter details for process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p.arrival_time);
        printf("Burst Time: ");
        scanf("%d", &p.burst_time);
        p.id = i + 1;
        enqueue(&q, p);
    }
    int current_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
    while (q.front != NULL) {
        struct Process p = dequeue(&q);
        if (p.arrival_time > current_time) {
            current_time = p.arrival_time;
        }
        current_time += p.burst_time;
        turnaround_time = current_time - p.arrival_time;
        waiting_time = turnaround_time - p.burst_time;
        printf("Process\t\tAT\tBT\tCT\tTAT\tWT\n");
    
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n", p.id, p.arrival_time, p.burst_time, current_time,turnaround_time,waiting_time);
    
    }
    return 0;
}
