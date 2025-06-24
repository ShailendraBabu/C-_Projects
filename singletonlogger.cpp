#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger
{
private:
    ofstream logFile;

    // Private constructor
    Logger()
    {
        logFile.open("log.txt", ios::app); // Append mode
        if (!logFile.is_open())
        {
            cerr << "Failed to open log file!" << endl;
        }
    }

    // Delete copy constructor and assignment
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

public:
    ~Logger()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    void log(const string &message)
    {
        cout << "[LOG] " << message << endl;
        if (logFile.is_open())
        {
            logFile << "[LOG] " << message << endl;
        }
    }
};

int main()
{
    Logger &logger = Logger::getInstance();

    logger.log("Program started.");
    logger.log("Performing calculations...");

    int a = 5, b = 3;
    int sum = a + b;
    logger.log("Sum of 5 and 3 is: " + to_string(sum));

    logger.log("Program ended.");
}
