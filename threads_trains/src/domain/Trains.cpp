#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string>

#include "Trains.hpp"
#include "Logs.hpp"

using namespace std;

const int MAX_LOOP_ITERATIONS = 2;

Logs logs;

// The mutex class is a synchronization primitive that can be used to protect shared data
// from being simultaneously accessed by multiple threads.
pthread_mutex_t m1, m2;

// This *args is necessary because of pthread_create
void *train1(void *arg);
void *train2(void *arg);
void *train3(void *arg);

void Trains::run(){
    int res;
    void *thread_result;
    pthread_t thread1, thread2, thread3;

    printf("-Creating mutex m1 and m2. \n");

    res = pthread_mutex_init(&m1, NULL);
    logs.logError(res, "-Mutex 1 startup failed.");

    res = pthread_mutex_init(&m2, NULL);
    logs.logError(res, "-Mutex 2 startup failed.");

    printf("-Creating and joining threads. \n");

    // Creation of thread 1 that will execute the function train1
    res = pthread_create(&thread1, NULL, &train1, NULL);
    logs.logError(res, "-Thread 1 creation failed.");

    // Creation of thread 2 that will execute the function train2
    res = pthread_create(&thread2, NULL, &train2, NULL);
    logs.logError(res, "-Thread 2 creation failed.");

    // Creation of thread 3 that will execute the function train3
    res = pthread_create(&thread3, NULL, &train3, NULL);
    logs.logError(res, "-Thread 3 creation failed.");

    // Wait for the threads to finish
    res = pthread_join(thread1, &thread_result);
    logs.logError(res, "-Thread 1 Joining Failed");

    res = pthread_join(thread2, &thread_result);
    logs.logError(res, "-Thread 2 Joining Failed");

    res = pthread_join(thread3, &thread_result);
    logs.logError(res, "-Thread 3 Joining Failed");

    printf("-Destroying mutex m1 and m2. \n");

    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
}

void *train1(void *arg)
{
    const int idTrain = 1;
    int countLoop = 0;

    while (countLoop < MAX_LOOP_ITERATIONS)
    {
        logs.logTrain(idTrain, 1);
        logs.logTrain(idTrain, 2);

        // In this case, have lock in the train2, so one of them with block the operation
        // until the other is unlocked
        pthread_mutex_lock(&m1);
        logs.logTrain(idTrain, 3);
        pthread_mutex_unlock(&m1);

        logs.logTrain(idTrain, 4);

        logs.logEndLoop(idTrain);

        countLoop++;
    }

    pthread_exit(0);
}

void *train2(void *arg)
{
    const int idTrain = 2;
    int countLoop = 0;

    while (countLoop < MAX_LOOP_ITERATIONS)
    {
        logs.logTrain(idTrain, 5);

        pthread_mutex_lock(&m2);
        logs.logTrain(idTrain, 6);
        pthread_mutex_unlock(&m2);

        // In this case, have lock in the train1, so one of them with block the operation
        // until the other is unlocked
        pthread_mutex_lock(&m1);
        logs.logTrain(idTrain, 7);
        pthread_mutex_unlock(&m1);

        logs.logTrain(idTrain, 8);

        logs.logEndLoop(idTrain);

        countLoop++;
    }

    pthread_exit(0);
}

void *train3(void *arg)
{
    const int idTrain = 3;
    int countLoop = 0;

    while (countLoop < MAX_LOOP_ITERATIONS)
    {
        logs.logTrain(idTrain, 9);
        logs.logTrain(idTrain, 10);
        logs.logTrain(idTrain, 11);

        pthread_mutex_lock(&m2);
        logs.logTrain(idTrain, 12);
        pthread_mutex_unlock(&m2);

        logs.logEndLoop(idTrain);

        countLoop++;
    }

    pthread_exit(0);
}
