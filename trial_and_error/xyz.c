#include<stdio.h>
#include<pthread.h>

void* computation();

int main() {
	pthread_t th1;
	pthread_create(th1, NULL, compuation, NULL);
	pthread_join(th1, NULL);
	return 0;

}

void* computation() {
	printf("Computation");
	return NULL;

}
