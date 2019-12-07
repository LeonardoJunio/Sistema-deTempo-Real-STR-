#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void *trem1(void *arg);
void *trem2(void *arg);
void *trem3(void *arg);
pthread_mutex_t m1, m2; /* proteção para: work_area e time_to_exit */
void L(int trem, int trilho);

int main() {
    int res;
    void *thread_result;
    pthread_t thread1, thread2, thread3;


    printf("Criando mutex m1 e m2. \n");

    res = pthread_mutex_init(&m1, NULL);
    if (res != 0) {
        perror("Iniciação do Mutex falhou");
        exit(EXIT_FAILURE);
    }

    res = pthread_mutex_init(&m2, NULL);
    if (res != 0) {
        perror("Iniciação do Mutex falhou");
        exit(EXIT_FAILURE);
    }

    printf("Criando as threads e Fazendo junção das threads. \n");

    // ------ criaçao do thread 1 que executara a funcao trem1
    res = pthread_create(&thread1, NULL, &trem1, NULL);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }
    // ------ criaçao do thread 2 que executara a funcao trem2
    res = pthread_create(&thread2, NULL, &trem2, NULL);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }

    // ------ criaçao do thread 3 que executara a funcao trem3
    res = pthread_create(&thread3, NULL, &trem3, NULL);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }

    // ------ espera o termino dos threads
    res = pthread_join(thread1, &thread_result);
    if (res != 0) {
        perror("Juncao da Thread falhou");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(thread2, &thread_result);
    if (res != 0) {
        perror("Juncao da Thread falhou");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(thread3, &thread_result);
    if (res != 0) {
        perror("Juncao da Thread falhou");
        exit(EXIT_FAILURE);
    }

    printf("Destruindo o m1 e m2. \n");

    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);

    exit(EXIT_SUCCESS);
}

void *trem1(void *arg) {

    while(1){
        L(1,1);
        sleep(1);
        L(1,2);
        sleep(1);

        pthread_mutex_lock(&m1);
        L(1,3);
        sleep(1);
        pthread_mutex_unlock(&m1);

        L(1,4);
        sleep(1);
    } 

    pthread_exit(0);
}

void *trem2(void *arg) {
    
    while(1){
        L(2,5);
        sleep(1);

        pthread_mutex_lock(&m2);
        L(2,6);
        sleep(1);
        pthread_mutex_unlock(&m2);

        L(2,7);
        sleep(1);

        pthread_mutex_lock(&m1);
        L(2,8);
        sleep(1);
        pthread_mutex_unlock(&m1);
    }  

    pthread_exit(0);
}

void *trem3(void *arg) {
    
    while(1){
        L(3,9);
        sleep(1);
        L(3,10);
        sleep(1);
        L(3,11);
        sleep(1);

        pthread_mutex_lock(&m2);
        L(3,12);
        sleep(1);
        pthread_mutex_unlock(&m2);
    }  

    pthread_exit(0);
}


void L(int trem,int trilho)
{
    printf("Trem %d, no trilho %d \n", trem, trilho);

}