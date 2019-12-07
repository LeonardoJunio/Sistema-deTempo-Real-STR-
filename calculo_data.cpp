#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main(void) {
    //Declaracao de variaveis 
    time_t timeBirth = 0, timeToday = 0;
    struct tm birth = {0};
    int year = 0, month = 0, day = 0, hour = 0, min = 0;
    const char dateBirth[] = "31.07.2019 10:00";

    //verifica se tem os 5 dados presentes e atribui o valor a cada variavel
    if (sscanf(dateBirth, "%2d.%2d.%4d %2d:%2d", &day, &month, &year, &hour, &min) == 5) {
        birth.tm_year = year - 1900;
        birth.tm_mon = month - 1;
        birth.tm_mday = day;
        birth.tm_hour = hour;
        birth.tm_min = min;

        //data de nascimento para segundos
        timeBirth = mktime(&birth);
 
        //tempo atual em segundos
        timeToday = time( (time_t *) 0);

        cout << "Já se passaram " << timeToday - timeBirth << " segundos desde do dia que nasceu. " << endl;

        return EXIT_SUCCESS;
    }
}
