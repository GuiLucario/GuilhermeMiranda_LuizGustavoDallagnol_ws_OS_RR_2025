#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define CHAIRS 5

sem_t customers; 
sem_t barbers;    
sem_t mutex;     

int waiting = 0;  

void* barber(void* arg);
void* customer(void* arg);
void cut_hair();
void customer_arrived();
void get_haircut();
void giveup_haircut();

int main() {
    pthread_t barber_thread;

    sem_init(&customers, 0, 0);
    sem_init(&barbers, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&barber_thread, NULL, barber, NULL);

    while (1) {
        pthread_t customer_thread;
        pthread_create(&customer_thread, NULL, customer, NULL);
        pthread_detach(customer_thread);  
        sleep(1); 
    }

    pthread_join(barber_thread, NULL);
    return 0;
}

void* barber(void* arg) {
    while (1) {
        sem_wait(&customers);   
        sem_wait(&mutex);       
        waiting--;              
        sem_post(&barbers);     
        sem_post(&mutex);
        cut_hair();            
    }
    return NULL;
}

void* customer(void* arg) {
    sem_wait(&mutex);
    if (waiting < CHAIRS) {
        customer_arrived();
        waiting++;
        sem_post(&customers);   
        sem_post(&mutex);
        sem_wait(&barbers);     
        get_haircut();
    } else {
        sem_post(&mutex);       
        giveup_haircut();
    }
    return NULL;
}

void cut_hair() {
    printf("Barbeiro está cortando o cabelo de um cliente...\n");
    sleep(3);
}

void customer_arrived() {
    printf("Cliente chegou à barbearia.\n");
}

void get_haircut() {
    printf("Cliente está tendo o cabelo cortado.\n");
    sleep(2);
}

void giveup_haircut() {
    printf("Cliente desistiu (barbearia cheia).\n");
}