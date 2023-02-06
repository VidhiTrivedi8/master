#include<stdio.h>

#define MAX 20

int pages[MAX];
int frame[10];
int m, n, counter = 0, flag1, flag2, pf = 0;

void display() {
   int i;
   printf("\nThe Page Frames are :\n");
   for(i = 0; i < counter; i++) {
      printf("%d\t", frame[i]);
   }
}

int main() {
   int i, j, k;
   printf("Enter the Total Number of Pages:\t");
   scanf("%d", &m);
   printf("Enter the Values of Reference String:\n");
   for(i = 0; i < m; i++) {
      scanf("%d", &pages[i]);
   }
   printf("Enter Total Number of Page Frames:\t");
   scanf("%d", &n);
   for(i = 0; i < m; i++) {
      flag1 = flag2 = 0;
      for(j = 0; j < counter; j++) {
         if(pages[i] == frame[j]) {
            flag1 = flag2 = 1;
            break;
         }
      }
      if(counter < n) {
         if(flag1 == 0) {
            frame[counter++] = pages[i];
            pf++;
         }
      } else {
         if(flag2 == 0) {
            flag2 = 1;
            for(k = 0; k < n-1; k++) {
               frame[k] = frame[k+1];
            }
            frame[k] = pages[i];
            pf++;
         }
      }
      display();
   }
   printf("\nTotal Number of Page Faults:\t%d\n", pf);
   return 0;
}
