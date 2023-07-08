#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <curses.h>
#include <math.h>
#include <sched.h>
#include <termio.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "ControlProcess.hpp"

using namespace std;

// Sorts according to rss: resident set size and displays 30 results
const string ControlProcess::COMMAND_INFO =
    "ps -aeo user,comm,pid,psr,pcpu,pri,ni,cputime --sort -rss | head -30";

void ControlProcess::run()
{
    int option;
    pid_t pid;

    do {
        // Displays the process information at the beginning of each choice
        system(COMMAND_INFO.c_str());

        cout << "MENU: 1-Pause; 2-Continue; 3-Stop; 4-Change CPU; 5-Change Priority; 6-Filter; 0-Exit" << endl;
        cout << "Enter a valid option: ";
        cin >> option;

        while (option > 6 || option < 0) {
            cout << "Invalid operation, type again." << endl;
            cin >> option;
        }

        if (option < 6 && option != 0) {
            cout << "Enter the process' PID: " << endl;
            cin >> pid;
        }

        switch (option) {
            case 0:
                cout << "Finishing Program." << endl;
                break;
            case 1:
                this->pidPause(pid);
                break;
            case 2:
                this->pidContinue(pid);
                break;
            case 3:
                this->pidStop(pid);
                break;
            case 4:
                this->pidChangeCpu(pid);
                break;
            case 5:
                this->pidChangePriority(pid);
                break;
            case 6:
                this->filter();
                break;
            default:
                cout << "Some error occurred, please try again." << endl;
                break;
        }
    } while (option != 0);
}

// Pauses the process according to the given pid
void ControlProcess::pidPause(int pid)
{
    if (!(kill(pid, SIGSTOP))) {
        cout << "Process paused." << endl;
    } else {
        cout << "Error when pausing process." << endl;
    }
}

// Continues the process according to the given pid
void ControlProcess::pidContinue(int pid)
{
    if (!(kill(pid, SIGCONT))) {
        cout << "Continued process." << endl;
    } else {
        cout << "Error when continuing process." << endl;
    }
}

// Stops/ends the process according to the given pid
void ControlProcess::pidStop(int pid)
{
    if (!(kill(pid, SIGKILL))) {
        cout << "Process finished." << endl;
    } else {
        cout << "Error when ending process." << endl;
    }
}

// Changes the process execution processor according to the given pid to change it faster,
// advises to pause, change cpu and then continue the process if it is not done,
// maybe it takes more time for the change, but it is done as well
void ControlProcess::pidChangeCpu(int pid)
{
    int cpu;
    cpu_set_t mask;

    cout << "Choose a CPU to take over the process: ";
    cin >> cpu;

    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);

    if ((sched_setaffinity(pid, sizeof(mask), &mask)) == 0) {
        cout << "Running processor changed." << endl;
    } else {
        cout << "Processor change error." << endl;
    }
}

// Changes the execution priority of the process according to the given pid.
// Enter a value that subtracts the current priority,
// for example: Process with priority=19, chosen_value=5, then new_priority will be 14
void ControlProcess::pidChangePriority(int pid)
{
    int prioridade;

    cout << "Define a new priority for the process: ";
    cin >> prioridade;

    if (!(setpriority(PRIO_PROCESS, pid, prioridade) == -1)) {
        cout << "Priority changed successfully." << endl;
    } else {
        cout << "Error setting new priority." << endl;
    }
}

// Displays a process according to the selected filter (process name)
void ControlProcess::filter()
{
    string filtro;

    cout << "Type a keyword for the search: ";
    cin >> filtro;

    cout << "Result: " << endl;
    system((COMMAND_INFO + " | grep " + filtro).c_str());
    // Added the command below to wait for the user to type enter,
    // because if not, it displays the information too quickly.
    system("read -p \"Press enter to exit\" leaving");
}
