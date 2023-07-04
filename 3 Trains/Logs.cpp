#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "Logs.hpp"

using namespace std;

void Logs::logError(int res, string message)
{
    if (res != 0)
    {
        perror(message.c_str());
        exit(EXIT_FAILURE);
    }
}

void Logs::logTrain(int idTrain, int idTrack)
{
    printf("Train %d, in track %d \n", idTrain, idTrack);
    sleep(1);
}

void Logs::logEndLoop(int idTrain)
{
    printf("-End loop, train %d \n", idTrain);
}
