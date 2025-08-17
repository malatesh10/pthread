/*This thread program, provides knowledge about threads creation and
 * synchronize of flow in between two thread.
 *
 * using mutex to protect critical section, example here count
 *
 * If you want to check the synchronize failure, comment all the *_mutex_* lines in the below code
 * and compile and check the output
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>  //header file for thread programming
#include<unistd.h>   //For sleep function

pthread_t thread1, thread2;  //Declare thread
pthread_mutex_t lock;
int count = 0;

void * thread1_func(void *arg) {
	printf("Thread1 function called\n");
	pthread_mutex_lock(&lock);
	for(int i = 0; i < 5; i++) {
		count++;
		sleep(1);
		printf("thread-1 value of count: %d\n", count);
	}
	pthread_mutex_unlock(&lock);
}
void * thread2_func(void *arg) {
	printf("Thread2 function called\n");
	pthread_mutex_lock(&lock);
	for(int i = 0; i < 5; i++) {
		count++;
		sleep(1);
		printf("thread-2 value of count: %d\n", count);
	}
	pthread_mutex_unlock(&lock);
}
int main() {

	pthread_mutex_init(&lock, NULL);

	pthread_create(&thread1, NULL, thread1_func, NULL);
	pthread_create(&thread2, NULL, thread2_func, NULL);


	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}

/* OUTPUT
 *
 * Thread1 function called
Thread2 function called
thread-1 value of count: 1
thread-1 value of count: 2
thread-1 value of count: 3
thread-1 value of count: 4
thread-1 value of count: 5
thread-2 value of count: 6
thread-2 value of count: 7
thread-2 value of count: 8
thread-2 value of count: 9
thread-2 value of count: 10
*/
