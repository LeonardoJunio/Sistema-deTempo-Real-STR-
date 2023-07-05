#include <iostream>

using namespace std;

class Logs
{

public:
    void logTrain(int idTrain, int idTrack);
    void logError(int res, string message);
    void logEndLoop(int idTrain);
    
};
