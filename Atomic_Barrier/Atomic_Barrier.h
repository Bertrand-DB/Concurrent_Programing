//made by Bertrand -> https://github.com/Bertrand-DB
#ifndef ATOMIC_BARRIER_H
#define ATOMIC_BARRIER_H

#pragma once

#include <iostream>
#include <atomic>
#include <mutex>
#include <condition_variable>

class Atomic_Barrier
{
public:
    Atomic_Barrier();
    Atomic_Barrier(unsigned barrier_level);
    ~Atomic_Barrier();
    void detain();
    unsigned detained();
    void release();

private:
    std::atomic<int> barrier_level;      // Barrier level (number of threads required for release)
    std::atomic<int> counter;            // Counter for threads that have reached the barrier
    std::atomic<bool> releaser;          // Flag to indicate barrier release
    std::mutex mutex_counter;              // Mutex to provide mutual exclusion for the counter
    std::condition_variable detainer;    // Condition variable to wait for barrier release
};
#endif
