#include <iostream> // Required for input/output operations (e.g., std::cout)
#include <string>   // Required for using std::string
#include <mutex>    // Required for std::mutex and std::lock_guard (for thread-safety)

// 1. The Logger Class: This class will implement the Singleton pattern.
class Logger
{
private:
    // 2. Static pointer to the single instance of the Logger class.
    //    It's initialized to nullptr and will hold the address of the one and only Logger object.
    static Logger *instance;

    // 3. Private constructor:
    //    Making the constructor private prevents direct instantiation of the Logger class
    //    from outside, ensuring that only the getInstance() method can create an object.
    Logger()
    {
        std::cout << "Logger instance created for the very first time!" << std::endl;
        // In a real-world scenario, you might open a log file here,
        // establish a connection to a logging service, or initialize resources.
    }

    // 4. Private copy constructor and assignment operator (deleted):
    //    These are deleted to prevent copying or assigning Logger objects.
    //    If these were not deleted, you could potentially create multiple instances
    //    by copying an existing one, which would violate the Singleton principle.
    Logger(const Logger &) = delete;            // Disallow copy construction
    Logger &operator=(const Logger &) = delete; // Disallow copy assignment

    // 5. Mutex for thread-safety:
    //    In multi-threaded applications, multiple threads might try to create the
    //    Logger instance simultaneously. A mutex ensures that only one thread
    //    can create the instance, preventing race conditions and multiple instances.
    static std::mutex mtx;

public:
    // 6. Public static method to get the single instance of the Logger:
    //    This is the global access point to the Singleton instance.
    //    It ensures that if an instance doesn't exist, it's created, and
    //    subsequent calls return the same existing instance.
    static Logger *getInstance()
    {
        // Double-checked locking pattern for thread-safe lazy initialization:
        // First check: Check if instance exists without acquiring the lock.
        // This avoids locking most of the time, improving performance.
        if (instance == nullptr)
        {
            // Acquire lock: If instance is nullptr, lock the mutex to ensure
            // only one thread enters the critical section (instance creation).
            std::lock_guard<std::mutex> lock(mtx); // std::lock_guard automatically releases the lock when it goes out of scope

            // Second check: Check again inside the lock. This is crucial because
            // another thread might have acquired the lock, created the instance,
            // and released the lock between the first check and this thread acquiring the lock.
            if (instance == nullptr)
            {
                instance = new Logger(); // Create the one and only instance
            }
        }
        return instance; // Return the single instance
    }

    // Method to log a message:
    // This is the actual functionality of our Logger class.
    void log(const std::string &message)
    {
        std::cout << "[LOG] " << message << std::endl;
        // In a real application, this would typically write the message to
        // a file, a database, or send it over a network.
    }

    // Optional: Destructor to clean up resources:
    // If the Logger had opened a file or allocated other resources,
    // they would be cleaned up here when the Logger object is destroyed.
    // For this simple example, it just prints a message.
    ~Logger()
    {
        std::cout << "Logger instance destroyed!" << std::endl;
        // In a real scenario, you might close the log file here.
    }
};

// 7. Initialization of static members outside the class definition:
//    Static members must be defined and initialized outside the class.
Logger *Logger::instance = nullptr; // Initialize the static instance pointer
std::mutex Logger::mtx;             // Initialize the static mutex

// --- Simulating different parts of your application that need logging ---

// Function representing a part of the application handling user requests.
void processUserRequest()
{
    // Get the logger instance and log a message.
    // Notice how we use Logger::getInstance() to get the shared logger.
    Logger::getInstance()->log("Processing user request for user ID: 12345");
}

// Function representing a part of the application performing database operations.
void databaseOperation()
{
    // Get the same logger instance and log a database-related message.
    Logger::getInstance()->log("Performing database query: SELECT * FROM Users WHERE active = true;");
}

// Function representing a part of the application generating reports.
void generateReport()
{
    // Get the same logger instance and log a report generation message.
    Logger::getInstance()->log("Generating daily sales report: Task started.");
}

// The main function where the application execution begins.
int main()
{
    std::cout << "--- Application Start ---" << std::endl;

    // First attempt to get the logger instance.
    // This will trigger the creation of the Logger object, and the "Logger instance created!"
    // message will be printed to the console.
    Logger *appLogger1 = Logger::getInstance();
    appLogger1->log("Application initialized successfully.");

    // Second attempt to get the logger instance.
    // The "Logger instance created!" message will NOT be printed again,
    // demonstrating that we are retrieving the *same* existing instance.
    Logger *appLogger2 = Logger::getInstance();
    appLogger2->log("Configuration loaded from settings.ini.");

    // Even though we call getInstance() multiple times,
    // the "Logger instance created!" message appears only once.
    // This visually proves that we are always getting the same instance.

    // Call functions from different parts of the "application"
    // Each of these functions will independently request the Logger instance,
    // but they will all receive the *single, same* instance.
    processUserRequest();
    databaseOperation();
    generateReport();

    // Third attempt to get the logger instance, still the same one.
    Logger *appLogger3 = Logger::getInstance();
    appLogger3->log("Application preparing for shutdown.");

    std::cout << "--- Application End ---" << std::endl;

    // Note on Modern C++ (C++11 and later) and "Meyers' Singleton":
    // For simpler singletons where you don't need explicit control over creation
    // order or complex thread-safety during destruction, C++11 guarantees
    // thread-safe static local variable initialization. This often leads to a
    // much simpler Singleton implementation. Example:
    /*
    class ModernLogger {
    public:
        static ModernLogger& getInstance() {
            // The 'static ModernLogger instance;' is guaranteed to be initialized
            // only once and in a thread-safe manner on its first use.
            static ModernLogger instance;
            return instance;
        }

        void log(const std::string& message) {
            std::cout << "[Modern LOG] " << message << std::endl;
        }

    private:
        // Private constructor and deleted copy/assignment operators remain crucial.
        ModernLogger() { std::cout << "ModernLogger instance created (modern way)!" << std::endl; }
        ModernLogger(const ModernLogger&) = delete;
        ModernLogger& operator=(const ModernLogger&) = delete;
    };

    // In main, you would use it like this:
    // ModernLogger::getInstance().log("Using the simpler modern C++ Singleton.");
    */

    return 0; // Indicate successful program execution
}
