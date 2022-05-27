#include <iostream>
#include <random>
#include <chrono>
#include <ctime>


 int main()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> range(4,6);

    double cycleDuration = range(eng); // duration of a single simulation cycle in ms
    std::chrono::time_point<std::chrono::system_clock> lastUpdate;

    // init stop watch
    lastUpdate = std::chrono::system_clock::now();

    while (true)
    {
        // sleep at every iteration to reduce CPU usage
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // compute time difference to stop watch
        long timeSinceLastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - lastUpdate).count();
        //cout << "timeSinceLastUpdate=" << timeSinceLastUpdate << "  lastUpdate=" << lastUpdate << std::endl;
        if (timeSinceLastUpdate >= cycleDuration*1000)
        {
            std::cout << "**** TOGGLE ****  timeSinceLastUpdate=" << timeSinceLastUpdate << "  cycleDuration=" << cycleDuration << std::endl;
            // init stop watch
            lastUpdate = std::chrono::system_clock::now();
            //std::random_device rd;
            //std::mt19937 eng(rd());
            //std::uniform_int_distribution<> range(4,6);
            cycleDuration = range(eng); // duration of a single simulation cycle in ms
        }
    }
    return 0;
}

