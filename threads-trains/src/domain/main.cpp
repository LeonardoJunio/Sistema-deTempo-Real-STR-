#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string>
#include "Trains.hpp"

using namespace std;

int main()
{
    Trains trains;

    trains.run();

    exit(EXIT_SUCCESS);
}
