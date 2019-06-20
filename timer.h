#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
    std::thread thread;
    bool alive = false;
    long callNumber = -1L;
    long repeat_count = -1L;
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> funct = nullptr;

    void SleepAndRun()
    {
        std::this_thread::sleep_for(interval);
        if (alive)
            Function()();
    }

    void ThreadFunc()
    {

    }
};

#endif // TIMER_H
