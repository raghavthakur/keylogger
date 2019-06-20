#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
    std::thread Thread;
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
        if (callNumber == Infinite)
            while(alive)
                SleepAndRun();
        else
            while(repeat_count--)
                SleepAndRun();
    }

public:
    static const long Infinite = -1L;

    Timer(){}    // empty constructor

    Timer(const std::function<void(void)> &f) : funct (f) {}

    Timer(const std::function<void(void)> &f,
          const unsigned long &i,
          const long repeat = Timer::Infinite) : funct (f),
                                                interval(std::chrono::milliseconds(i)),
                                                callNumber(repeat) {}

    void Start(bool async = true)
    {
        if (isAlive())
            return;
        alive = true;
        repeat_count = callNumber;
        if (async)
            Thread = std::thread(ThreadFunc, this);
        else
            this->ThreadFunc();
    }

    void Stop()
    {
        alive = false;
        Thread.join();
    }

    void SetFunction(const std::function<void(void)> &f)
    {
        funct = f;
    }

    bool isAlive() const {return alive;}

    void RepeatCount(const long r)
    {
        if (alive)
            return;
        callNumber = r;
    }

    long GetLeftCount() const {return repeat_count;}

    long RepeatCount() const {return callNumber;}

    void SetInterval(const unsigned long &i)
    {
        if (alive)
            return;
        interval = std::chrono::milliseconds(i);
    }

    unsigned long Interval() const {return interval.count();}

    const std::function<void(void)> &Function() const
    {
        return funct;
    }


};

#endif // TIMER_H
