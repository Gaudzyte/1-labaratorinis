#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> start_time;

public:
    Timer() { reset(); }
    void reset() { start_time = clock::now(); }
    double elapsed() const
    {
        return std::chrono::duration<double>(clock::now() - start_time).count();
    }
};

#endif
