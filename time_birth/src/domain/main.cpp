#include <iostream>
#include "SecondsBirth.hpp"

using namespace std;

int main(void)
{
    // Set the São Paulo time zone to get the current time
    setenv("TZ", "America/Sao_Paulo", 1);
    tzset();

    SecondsBirth secondsBirth;

    const char dateBirth[] = "06.07.2023 22:05";

    secondsBirth.run(dateBirth);

    return EXIT_SUCCESS;
}
