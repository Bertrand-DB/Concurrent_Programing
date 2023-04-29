#ifndef ATOMIC_BARRIER_H
#define ATOMIC_BARRIER_H

#pragma once

#include <iostream>
#include <atomic>
#include <mutex>
#include <condition_variable>

using namespace std;

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
    atomic<int> barrier_level;      // Barrier level (number of threads required for release)
    atomic<int> counter;            // Counter for threads that have reached the barrier
    atomic<bool> releaser;          // Flag to indicate barrier release
    mutex mtx_counter;              // Mutex to provide mutual exclusion for the counter
    condition_variable detainer;    // Condition variable to wait for barrier release
};
#endif