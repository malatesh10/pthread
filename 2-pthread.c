/*
thread-1 value of count: 1
Thread2 function called
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//pthread_t thread1, thread2; //Thrad can be declare globaly or in function as local to main function

void * thread1_func(void *arg) {
	printf("Thread1 function called\n");
}

void * thread2_func(void *arg) {
	printf("Thread2 function called\n");
}
int main() {

	pthread_t thread1, thread2; //Declare thread 
	pthread_create(&thread1, NULL, thread1_func, NULL); //Create thread1
	pthread_create(&thread2, NULL, thread2_func, NULL); //Create thread2


	pthread_join(thread1, NULL); //Wait for thread1 to finesh its execution
	pthread_join(thread2, NULL); ///Wait for thread2 to finesh its execution

	return 0;
}
