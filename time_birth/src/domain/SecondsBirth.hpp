#include <iostream>

using namespace std;

class SecondsBirth
{

public:
    void run(const char dateBirth[]);

private:
    static const int MAX_QTY_PARAMS_DATE = 5;
    static const int MIN_QTY_PARAMS_DATE = 0;

    bool isValidBirthDate(int sscanfDateBirth);

};
