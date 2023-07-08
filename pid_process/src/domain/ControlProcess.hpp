#include <iostream>

using namespace std;

class ControlProcess
{

public:
    void run();

private:
    static const string COMMAND_INFO;

    void pidPause(int pid);
    void pidContinue(int pid);
    void pidStop(int pid);
    void pidChangeCpu(int pid);
    void pidChangePriority(int pid);
    void filter();

};
