#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
// Estas dos funciones corren concurrentemente.
void* print_i(void *ptr) {
 pthread_mutex_lock(&mutex1);
 pthread_mutex_lock(&mutex2);
 printf("I am in i");
 pthread_mutex_unlock(&mutex2);
 pthread_mutex_unlock(&mutex1);
}
void* print_j(void *ptr) {
 pthread_mutex_lock(&mutex2);
 pthread_mutex_lock(&mutex1);
 printf("I am in j");
 pthread_mutex_unlock(&mutex1);
 pthread_mutex_unlock(&mutex2);
}
int main() {
 pthread_t t1, t2;
 int iret1 = pthread_create(&t1, NULL, print_i, NULL);
 int iret2 = pthread_create(&t2, NULL, print_j, NULL);
while(1){}
 exit(0); //nunca alcanzado.
}
