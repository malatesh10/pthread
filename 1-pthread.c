#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> //header file for pthread

void * thread1_func(void *arg) {
	printf("Thread1 function called\n");
}

void * thread2_func(void *arg) {
	printf("Thread2 function called\n");
}
int main() {
	pthread_t thread1, thread2; //Declare thread data type

	pthread_create(&thread1, NULL, thread1_func, NULL); //Create thread


	pthread_join(thread1, NULL); //Wait for thread to finesh its execution

	return 0;
}
