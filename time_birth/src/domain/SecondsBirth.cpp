#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <cstring>

#include "SecondsBirth.hpp"
#include "../utils/DateUtils.hpp"

using namespace std;

void SecondsBirth::run(const char dateBirth[])
{
    time_t timeBirth = 0, timeToday = 0;
    int year = 0, month = 0, day = 0, hour = 0, min = 0;
    int sscanfDateBirth = 0;

    // Structure containing a calendar date and time broken down into its components
    struct tm birth;
    // Set all fields of the struct tm object to zero
    // Just make "= {0}" was giving warnings
    memset(&birth, 0, sizeof(birth));

    sscanfDateBirth = sscanf(
        dateBirth,
        "%2d.%2d.%4d %2d:%2d",
        &day, &month, &year, &hour, &min);

    if (!this->isValidBirthDate(sscanfDateBirth))
    {
        return;
    }

    birth.tm_year = year - 1900;
    birth.tm_mon = month - 1;
    birth.tm_mday = day;
    birth.tm_hour = hour;
    birth.tm_min = min;

    // data de nascimento para segundos
    timeBirth = mktime(&birth);

    // tempo atual em segundos
    timeToday = DateUtils::getCurrentTimeSeconds();

    cout << "It's been "
         << timeToday - timeBirth
         << " seconds since the day you were born. "
         << endl;
}

// Checks if all five data are present and assigns the value to each variable
bool SecondsBirth::isValidBirthDate(int sscanfDateBirth)
{
    if (sscanfDateBirth != MAX_QTY_PARAMS_DATE || sscanfDateBirth == MIN_QTY_PARAMS_DATE)
    {
        cout << "Error when trying to capture the birth date" << endl;
        return false;
    }

    return true;
}
