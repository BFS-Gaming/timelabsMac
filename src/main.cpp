
#include <iostream> 
#include <string>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <ctime>
using namespace std;
string getTimeDate()
{
    auto t = std::time(nullptr);
    auto tma = *std::localtime(&t);
    std::ostringstream oss;
    cout << std::put_time(&tma, "%d-%m-%Y %H-%M-%S") << endl;
    oss << put_time(&tma, "%d-%m-%Y-%H-%M-%S");
    return oss.str();
}
void doScreenShotOnMac(string path)
{
    string filePath = "";
    filePath += path;
    filePath+= "/";
    filePath += getTimeDate();
    filePath += ".png";
    cout << filePath << endl;

    string cmd = "screencapture -x " + filePath;
    system(cmd.c_str());
}
int main(int argc, const char* argv[])
{
    int timeinterval = 60; 
    
    if (argc < 2)
    {
        cout << "args: 1. path 2. interval(optional)" << endl;
        return 0;
    }
    string path = argv[1];
    if (argc == 3)
    {
        timeinterval = atoi(argv[2]);
        if (timeinterval == 0)
        {
            cout << "Invailed number" << endl;
            return 1;
        }
    }
    cout << "Starting interval with: " << timeinterval << "sec!" << endl;
    cout << "Using output dir: " << path << endl;
    int intervalInMicrosec = 1000000 * timeinterval;
    while (true)
    {
        usleep(intervalInMicrosec);
        cout << "Screenshoting!" << endl;
        doScreenShotOnMac(path);
    }
    return 0;
}
