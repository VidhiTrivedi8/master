#include<stdio.h>
#include<math.h>

#define MAX 20

// requests array to store disk requests
int requests[MAX];

// frame array to store page frames
int frame[10];

// m -> store the total number of disk requests
// n -> store the total number of page frames
// current -> store the current head position
// distance -> store the total head movement
// pf -> store the total number of page faults
int m, n, current, distance, pf = 0;
int abs(int somenumber);

//display the contents of the page frames
void display() {
   int i;
   printf("\nThe Page Frames are :\n");
   for(i = 0; i < current; i++) {
      printf("%d\t", frame[i]);
   }
}

int main() {
   int i, j, k;
   printf("Enter Total Number of Disk Requests:\t");
   scanf("%d", &m);
   printf("Enter the Disk Requests:\n");
   for(i = 0; i < m; i++) {
      scanf("%d", &requests[i]);
   }
   printf("Enter the Current Head Position:\t");
   scanf("%d", &current);
   printf("Enter Total Number of Page Frames:\t");
   scanf("%d", &n);

   // loop through all disk requests
   for(i = 0; i < m; i++) {
      int flag = 0;
      distance = distance + abs(requests[i] - current);
      current = requests[i];
      // check if the request is already present in page frames
      for(j = 0; j < current; j++) {
         if(requests[i] == frame[j]) {
            flag = 1;
            break;
         }
      }
      // if the request is not present in page frames
      if(flag == 0) {
         // if there are free page frames
         if(current < n) {
            frame[current++] = requests[i];
         } 
         // if all page frames are filled
         else {
            // implement the page replacement algorithm
            // shift all page frames to the left by 1 position
            for(k = 0; k < n-1; k++) {
               frame[k] = frame[k+1];
            }
            // replace the last page frame with the current request
            frame[k] = requests[i];
         }
         // increase the page fault counter
         pf++;
      }
      // display the contents of page frames after each iteration
      display();
   }
   // display the total number of page faults and total head movement
   printf("\nTotal Number of Page Faults:\t%d\n", pf);
   printf("Total Head Movement:\t%d\n", distance);
   return 0;
}


/*
Que:  "Write a program in C to simulate a disk scheduling process in a computer system. 
The program should take as input the number of disk requests, the disk requests themselves,
the current head position, and the number of page frames. 
The program should first implement the FCFS disk scheduling algorithm to determine the total head movement, 
and then implement a page replacement algorithm to determine the number of page faults and the contents of 
the page frames after each disk request. The program should display the total number of page faults, 
the total head movement, and the contents of the page frames after each disk request."



The code implements the FCFS disk scheduling algorithm along with the page replacement algorithm in C.

First, the program takes input for the total number of disk requests, 
the disk requests themselves, the current head position, and the number of page frames.

In each iteration of the loop, 
the program calculates the distance between the current head position and the current disk request. 
The current head position is then updated to the current disk request.

Next, the program checks if the current disk request is already present in the page frames using a flag. 
If it is not present, the program checks if there are any free page frames. 
If there are, it stores the current disk request in the next available frame.

If all the page frames are filled, 
the program implements the page replacement algorithm by shifting all the page frames to the left by 1 position
and replacing the last page frame with the current disk request. 
The page fault counter is then incremented.

After each iteration, the program displays the contents of the page frames.

Finally, after all the disk requests have been processed, 
the program displays the total number of page faults and the total head movement.

Note: The code implements a basic page replacement algorithm and is not an optimal solution. 
A more complex algorithm like LRU (Least Recently Used) or Optimal algorithm can be implemented 
for better results.



*/